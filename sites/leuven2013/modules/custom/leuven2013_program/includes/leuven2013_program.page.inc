<?php

/**
 * Default Program page (without flags).
 */
function leuven2013_program_default_page($day) {
  $output = _leuven2013_program_create_page($day);

  if (!$output) {
    $text = t('At the moment, there are no sessions accepted for this day.');

    // Create message
    $output = theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#value' => '<p>' . $text . '</p>',
        '#attributes' => array('class' => drupal_html_class('conf-message')),
      )
    ));
  }

  return $output;
}

/**
 * Personal program page.
 * All sessions that the user has bookmarked are shown.
 */
function leuven2013_program_my_page($day) {
  $output = _leuven2013_program_create_page($day, TRUE);

  if (!$output) {
    $text = t("You haven't bookmarked any sessions.
    Sessions can be bookmarked on the !program_page or the detail page of a session.", array(
      '!program_page' => l(t('program page'), 'program'),
    ));

    // Create message
    $output = theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#value' => '<p>' . $text . '</p>',
        '#attributes' => array('class' => drupal_html_class('conf-message')),
      )
    ));
  }

  return $output;
}

/**
 * Create program page.
 */
function _leuven2013_program_create_page($day, $favorite = FALSE) {
  // Get nids of all sessions
  $timeslots = _leuven2013_program_page_get_timeslots($day);

  $timezone = new DateTimeZone('Europe/Brussels');

  $output = '';
  foreach ($timeslots as $value => $timeslot) {
    $nids = _leuven2013_program_page_get_content($day, $timeslot->datetime, $favorite);

    if (empty($nids)) {
      continue;
    }

    // Load entities
    $entities = node_load_multiple(array_keys($nids));

    // Get teaser view of entities
    $nodes = entity_view('node', $entities, 'teaser');

    $dateTime = new DateTime($timeslot->datetime, $timezone);
    $offset = $timezone->getOffset($dateTime);

    $output .= theme('html_tag', array(
      'element' => array(
        '#tag' => 'h2',
        '#attributes' => array('class' => drupal_html_class('timeslot-title')),
        '#value' => date('D d/m/Y H:i', $dateTime->format('U') + $offset),
      ),
    ));

    $output .= render($nodes);
  }

  if (!empty($output)) {
    // Put everything in a div
    return theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#attributes' => array('id' => drupal_html_id('conf-program')),
        '#value' => $output,
      ),
    ));
  }
  else {
    return FALSE;
  }
}

function _leuven2013_program_page_get_timeslots($day) {
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
function _leuven2013_program_page_get_content($day, $timeslot, $favorite) {
  global $user;

  // Sorry - hardcoded because of the incapability to create a better query :-(
  // (And COD created ugly fugly references and OG references that do NOT make any sense!)
  // The session is frikkin related to one day (gid) and still sessions from other days appear RAAAARRARRARARARARA;;;;
  switch ($day) {
    case 13:
      $date_day = '2013-09-15';
      break;
    case 1:
    default:
      $date_day = '2013-09-14';
  }

  $date_timeslot = date('Y-m-d', strtotime($timeslot));
  if ($date_timeslot != $date_day) {
    return;
  }

  // Get all session of the given day
  $query = db_select('node', 'node')->distinct();
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
  // $query->where('DATE(datetime.field_slot_datetime_value) = ' . $date_day);
  // $query->groupBy('datetime.field_slot_datetime_value');
  $query->orderBy('datetime.field_slot_datetime_value');

  // dsm($query->__toString());
  // dsm($timeslot);

  // If we only want bookmarked session.
  if ($favorite) {
    $query->innerJoin('flag_content', 'flag_content', 'flag_content.content_id = node.nid');
    $query->innerJoin('flags', 'flags', 'flags.fid = flag_content.fid');
    $query->condition('flags.name', 'session_schedule');
    $query->condition('flag_content.uid', $user->uid);
  }

  return $query->execute()->fetchAllAssoc('nid');
}