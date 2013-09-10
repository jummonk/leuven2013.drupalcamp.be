<?php
/**
 * @file
 * camp_bof_schedule.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function camp_bof_schedule_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'camp_bof_grid';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'camp_bof_grid';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Saturday Schedule';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'camp_bof_schedule_grid';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Feb. 2<sup>nd</sup>, 2013  <p>See the <a href="/session-room-list">room list</a> for information about the rooms when scheduling a BoF</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['id'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['field'] = 'reverse_field_session_timeslot_node';
  /* Relationship: Field collection item: Entity with the Allowed Slot Types (field_room_slots_types_allowed) */
  $handler->display->display_options['relationships']['field_room_slots_types_allowed_node']['id'] = 'field_room_slots_types_allowed_node';
  $handler->display->display_options['relationships']['field_room_slots_types_allowed_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_room_slots_types_allowed_node']['field'] = 'field_room_slots_types_allowed_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_slot_types_time_slot_target_id']['id'] = 'field_slot_types_time_slot_target_id';
  $handler->display->display_options['relationships']['field_slot_types_time_slot_target_id']['table'] = 'field_data_field_slot_types_time_slot';
  $handler->display->display_options['relationships']['field_slot_types_time_slot_target_id']['field'] = 'field_slot_types_time_slot_target_id';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_room_slots_types_allowed_node';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'p';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Date and time */
  $handler->display->display_options['fields']['field_slot_datetime']['id'] = 'field_slot_datetime';
  $handler->display->display_options['fields']['field_slot_datetime']['table'] = 'field_data_field_slot_datetime';
  $handler->display->display_options['fields']['field_slot_datetime']['field'] = 'field_slot_datetime';
  $handler->display->display_options['fields']['field_slot_datetime']['relationship'] = 'field_slot_types_time_slot_target_id';
  $handler->display->display_options['fields']['field_slot_datetime']['label'] = '';
  $handler->display->display_options['fields']['field_slot_datetime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slot_datetime']['settings'] = array(
    'format_type' => 'camp_schedule_session',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Sticky */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['relationship'] = 'field_room_slots_types_allowed_node';
  $handler->display->display_options['fields']['sticky']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sticky']['not'] = 0;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['item_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['item_id']['alter']['text'] = '<em>Add BoF Session</em>';
  $handler->display->display_options['fields']['item_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['item_id']['alter']['path'] = 'node/add/bof-session/?field_session_timeslot=[item_id]&destination=camp/session-schedule/bofs';
  $handler->display->display_options['fields']['item_id']['alter']['alt'] = 'Add a new Birds of a Feather session';
  $handler->display->display_options['fields']['item_id']['alter']['link_class'] = 'add-bof';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Types Capacity */
  $handler->display->display_options['fields']['field_slot_types_capacity']['id'] = 'field_slot_types_capacity';
  $handler->display->display_options['fields']['field_slot_types_capacity']['table'] = 'field_data_field_slot_types_capacity';
  $handler->display->display_options['fields']['field_slot_types_capacity']['field'] = 'field_slot_types_capacity';
  $handler->display->display_options['fields']['field_slot_types_capacity']['label'] = '';
  $handler->display->display_options['fields']['field_slot_types_capacity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_slot_types_capacity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slot_types_capacity']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Sort criterion: Content: Date and time (field_slot_datetime) */
  $handler->display->display_options['sorts']['field_slot_datetime_value']['id'] = 'field_slot_datetime_value';
  $handler->display->display_options['sorts']['field_slot_datetime_value']['table'] = 'field_data_field_slot_datetime';
  $handler->display->display_options['sorts']['field_slot_datetime_value']['field'] = 'field_slot_datetime_value';
  $handler->display->display_options['sorts']['field_slot_datetime_value']['relationship'] = 'field_slot_types_time_slot_target_id';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Date and time (field_slot_datetime) */
  $handler->display->display_options['filters']['field_slot_datetime_value']['id'] = 'field_slot_datetime_value';
  $handler->display->display_options['filters']['field_slot_datetime_value']['table'] = 'field_data_field_slot_datetime';
  $handler->display->display_options['filters']['field_slot_datetime_value']['field'] = 'field_slot_datetime_value';
  $handler->display->display_options['filters']['field_slot_datetime_value']['relationship'] = 'field_slot_types_time_slot_target_id';
  $handler->display->display_options['filters']['field_slot_datetime_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_slot_datetime_value']['value'] = '2013-02-02';
  $handler->display->display_options['filters']['field_slot_datetime_value']['group'] = 1;
  /* Filter criterion: Field collection item: Allowed Schedule Types (field_slot_types_allowed) */
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['id'] = 'field_slot_types_allowed_value';
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['table'] = 'field_data_field_slot_types_allowed';
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['field'] = 'field_slot_types_allowed_value';
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['value'] = 'bof_session';
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['group'] = 2;
  /* Filter criterion: Field collection item: Allowed Schedule Types (field_slot_types_allowed) */
  $handler->display->display_options['filters']['field_slot_types_allowed_value_1']['id'] = 'field_slot_types_allowed_value_1';
  $handler->display->display_options['filters']['field_slot_types_allowed_value_1']['table'] = 'field_data_field_slot_types_allowed';
  $handler->display->display_options['filters']['field_slot_types_allowed_value_1']['field'] = 'field_slot_types_allowed_value';
  $handler->display->display_options['filters']['field_slot_types_allowed_value_1']['value'] = 'schedule_item';
  $handler->display->display_options['filters']['field_slot_types_allowed_value_1']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'camp/session-schedule/bofs';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'BoFs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Sessions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['camp_bof_grid'] = $view;

  $view = new view();
  $view->name = 'camp_room_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Camp Room List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Camp Room List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'room' => 'room',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['operator'] = '!=';
  $handler->display->display_options['filters']['nid']['value']['value'] = '35';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'session-room-list';
  $export['camp_room_list'] = $view;

  $view = new view();
  $view->name = 'cod_bof_timeslot';
  $view->description = 'View representing the select field for timeslot entity references in sessions, bofs, etc';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'cod_bof_timeslot';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field collection item: Entity with the Allowed Slot Types (field_room_slots_types_allowed) */
  $handler->display->display_options['relationships']['field_room_slots_types_allowed_node']['id'] = 'field_room_slots_types_allowed_node';
  $handler->display->display_options['relationships']['field_room_slots_types_allowed_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_room_slots_types_allowed_node']['field'] = 'field_room_slots_types_allowed_node';
  $handler->display->display_options['relationships']['field_room_slots_types_allowed_node']['required'] = TRUE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_room_slots_types_allowed_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field collection item: Time Slot */
  $handler->display->display_options['fields']['field_slot_types_time_slot']['id'] = 'field_slot_types_time_slot';
  $handler->display->display_options['fields']['field_slot_types_time_slot']['table'] = 'field_data_field_slot_types_time_slot';
  $handler->display->display_options['fields']['field_slot_types_time_slot']['field'] = 'field_slot_types_time_slot';
  $handler->display->display_options['fields']['field_slot_types_time_slot']['label'] = '';
  $handler->display->display_options['fields']['field_slot_types_time_slot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slot_types_time_slot']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: Field collection item: Allowed Schedule Types (field_slot_types_allowed) */
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['id'] = 'field_slot_types_allowed_value';
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['table'] = 'field_data_field_slot_types_allowed';
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['field'] = 'field_slot_types_allowed_value';
  $handler->display->display_options['filters']['field_slot_types_allowed_value']['value'] = 'bof_session';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'cod_bof_timeslot';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_slot_types_time_slot' => 'field_slot_types_time_slot',
    'title' => 'title',
    'item_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['cod_bof_timeslot'] = $view;

  return $export;
}
