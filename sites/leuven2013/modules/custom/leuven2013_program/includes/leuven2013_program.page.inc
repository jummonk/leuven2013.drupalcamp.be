<?php

/**
 * Program page.
 */
function leuven2013_program_default_page($day) {
  // Get nids of all sessions
  $timeslots = leuven2013_program_page_get_timeslots($day);

  $output = '';

  foreach ($timeslots as $value => $timeslot) {
    $nids = leuven2013_program_page_get_content($day, $timeslot->datetime);
    // Load entities
    $entities = node_load_multiple(array_keys($nids));
    // Get teaser view of entities
    // TODO: since room is not available in teaser view, we probably need to theme nodes manually
    $nodes = entity_view('node', $entities, 'teaser');

    // Return node
    // TODO: add legend for tracks and experience level

    $utcTimezone = new DateTimeZone('UTC');
    $timezone = new DateTimeZone('Europe/Brussels');
    $dateTime = new DateTime($timeslot->datetime, $timezone);
    $offset = $timezone->getOffset($dateTime);

    $output .= '<h2>' . date('D d/m/Y H:i', $dateTime->format('U') + $offset) . '</h2>' . render($nodes);
  }


  
  return $output;
}

/**
 * Personal program page.
 * All sessions that the user has bookmarked are shown.
 */
function leuven2013_program_my_page($day) {
  return 'My program... is still to come';
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
 *
 */
function leuven2013_program_page_get_content($day, $timeslot) {
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

  return $query->execute()->fetchAllAssoc('nid');
}