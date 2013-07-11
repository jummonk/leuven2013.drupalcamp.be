<?php

/**
 * Program page.
 */
function leuven2013_program_default_page($day, $favorite = FALSE) {
  // Get nids of all sessions
  $timeslots = leuven2013_program_page_get_timeslots($day);

  $output = '<div id="conf-program">';

  $timezone = new DateTimeZone('Europe/Brussels');

  foreach ($timeslots as $value => $timeslot) {
    $nids = leuven2013_program_page_get_content($day, $timeslot->datetime, $favorite);
    // Load entities
    $entities = node_load_multiple(array_keys($nids));

    // Get teaser view of entities
    $nodes = entity_view('node', $entities, 'teaser');

    $dateTime = new DateTime($timeslot->datetime, $timezone);
    $offset = $timezone->getOffset($dateTime);

    $output .= '<h2>' . date('D d/m/Y H:i', $dateTime->format('U') + $offset) . '</h2>' . render($nodes);
  }

  $output .= '</div>';

  return $output;
}

/**
 * Personal program page.
 * All sessions that the user has bookmarked are shown.
 */
function leuven2013_program_my_page($day) {
  return leuven2013_program_default_page($day, TRUE);
}

function leuven2013_program_page_get_timeslots($day) {
  $query = db_select('node', 'node');
  $query->addField('datetime', 'field_slot_datetime_value', 'datetime');
  $query->innerJoin('field_data_field_session_timeslot', 'timeslot', 'timeslot.entity_id = node.nid');
  $query->innerJoin('field_data_field_slot_types_time_slot', 'time_slot', 'time_slot.entity_id = timeslot.field_session_timeslot_target_id');
  $query->innerJoin('field_data_field_slot_datetime', 'datetime', 'datetime.entity_id = time_slot.field_slot_types_time_slot_target_id');
  $query->innerJoin('og_membership', 'og', 'og.etid = datetime.entity_id');
  $query->innerJoin('field_data_field_accepted', 'accepted', 'accepted.entity_id = node.nid');
  $query->condition('og.gid', $day);
  $query->condition('node.status', 1);
  $query->condition('accepted.field_accepted_value', 1);
  // $query->groupBy('datetime.field_slot_datetime_value');
  $query->orderBy('datetime.field_slot_datetime_value');

  return $query->execute()->fetchAllAssoc('datetime');
}

/**
 * Get all sessions for a specific day.
 */
function leuven2013_program_page_get_content($day, $timeslot, $favorite) {
  global $user;

  // Get all session of the given day
  $query = db_select('node', 'node');
  $query->addField('node', 'nid', 'nid');
  $query->innerJoin('field_data_field_session_timeslot', 'timeslot', 'timeslot.entity_id = node.nid');
  $query->innerJoin('field_data_field_slot_types_time_slot', 'time_slot', 'time_slot.entity_id = timeslot.field_session_timeslot_target_id');
  $query->innerJoin('field_data_field_slot_datetime', 'datetime', 'datetime.entity_id = time_slot.field_slot_types_time_slot_target_id');
  $query->innerJoin('og_membership', 'og', 'og.etid = datetime.entity_id');
  $query->innerJoin('field_data_field_accepted', 'accepted', 'accepted.entity_id = node.nid');
  $query->condition('og.gid', $day);
  $query->condition('node.status', 1);
  $query->condition('accepted.field_accepted_value', 1);
  $query->condition('datetime.field_slot_datetime_value', $timeslot);
  // $query->groupBy('datetime.field_slot_datetime_value');
  $query->orderBy('datetime.field_slot_datetime_value');

  // If we only want bookmarked session.
  if ($favorite) {
    $query->innerJoin('flag_content', 'flag_content', 'flag_content.content_id = node.nid');
    $query->innerJoin('flags', 'flags', 'flags.fid = flag_content.fid');
    $query->condition('flags.name', 'session_schedule');
    $query->condition('flag_content.uid', $user->uid);
  }

  return $query->execute()->fetchAllAssoc('nid');
}