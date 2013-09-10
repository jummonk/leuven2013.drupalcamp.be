<?php
/**
 * @file
 * leuven2013_user_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function leuven2013_user_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access content overview';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_profile_first' => 'name_1',
    'field_profile_last' => 'name_1',
    'name_1' => 'name_1',
    'mail' => 'mail',
    'field_profile_org' => 'field_profile_org',
    'status' => 'status',
    'field_experience' => 'field_experience',
    'field_registration_bbq' => 'field_registration_bbq',
    'field_bbq_preferences' => 'field_bbq_preferences',
    'og_user_node' => 'og_user_node',
    'field_t_shirt_size' => 'field_t_shirt_size',
    'field_volunteer' => 'field_volunteer',
    'field_volunteer_preferences' => 'field_volunteer_preferences',
  );
  $handler->display->display_options['style_options']['default'] = 'name_1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_profile_first' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_last' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_org' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_experience' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_registration_bbq' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bbq_preferences' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_user_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_t_shirt_size' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_volunteer' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_volunteer_preferences' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_profile_first']['id'] = 'field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['table'] = 'field_data_field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['field'] = 'field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_first']['alter']['text'] = '[field_profile_first] ';
  $handler->display->display_options['fields']['field_profile_first']['element_label_colon'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_profile_last']['id'] = 'field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['table'] = 'field_data_field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['field'] = 'field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_last']['alter']['text'] = '[field_profile_last] ';
  $handler->display->display_options['fields']['field_profile_last']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = '([name_1])';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_profile_org']['id'] = 'field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['table'] = 'field_data_field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['field'] = 'field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['element_label_colon'] = FALSE;
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Field: Experience level */
  $handler->display->display_options['fields']['field_experience']['id'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['table'] = 'field_data_field_experience';
  $handler->display->display_options['fields']['field_experience']['field'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['label'] = 'Experience';
  $handler->display->display_options['fields']['field_experience']['element_label_colon'] = FALSE;
  /* Field: User: I want to attend the BBQ on saturday evening */
  $handler->display->display_options['fields']['field_registration_bbq_1']['id'] = 'field_registration_bbq_1';
  $handler->display->display_options['fields']['field_registration_bbq_1']['table'] = 'field_data_field_registration_bbq';
  $handler->display->display_options['fields']['field_registration_bbq_1']['field'] = 'field_registration_bbq';
  $handler->display->display_options['fields']['field_registration_bbq_1']['label'] = 'Attend BBQ';
  $handler->display->display_options['fields']['field_registration_bbq_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_bbq_1']['type'] = 'list_key';
  /* Field: User: BBQ Preferences */
  $handler->display->display_options['fields']['field_bbq_preferences']['id'] = 'field_bbq_preferences';
  $handler->display->display_options['fields']['field_bbq_preferences']['table'] = 'field_data_field_bbq_preferences';
  $handler->display->display_options['fields']['field_bbq_preferences']['field'] = 'field_bbq_preferences';
  $handler->display->display_options['fields']['field_bbq_preferences']['element_label_colon'] = FALSE;
  /* Field: User: I will attend... */
  $handler->display->display_options['fields']['og_user_node']['id'] = 'og_user_node';
  $handler->display->display_options['fields']['og_user_node']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_user_node']['field'] = 'og_user_node';
  $handler->display->display_options['fields']['og_user_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_user_node']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_user_node']['delta_offset'] = '0';
  /* Field: User: T-shirt size */
  $handler->display->display_options['fields']['field_t_shirt_size']['id'] = 'field_t_shirt_size';
  $handler->display->display_options['fields']['field_t_shirt_size']['table'] = 'field_data_field_t_shirt_size';
  $handler->display->display_options['fields']['field_t_shirt_size']['field'] = 'field_t_shirt_size';
  $handler->display->display_options['fields']['field_t_shirt_size']['label'] = 'T-shirt';
  $handler->display->display_options['fields']['field_t_shirt_size']['element_label_colon'] = FALSE;
  /* Field: User: I want to help in the organization of this event */
  $handler->display->display_options['fields']['field_volunteer']['id'] = 'field_volunteer';
  $handler->display->display_options['fields']['field_volunteer']['table'] = 'field_data_field_volunteer';
  $handler->display->display_options['fields']['field_volunteer']['field'] = 'field_volunteer';
  $handler->display->display_options['fields']['field_volunteer']['label'] = 'Volunteer';
  $handler->display->display_options['fields']['field_volunteer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_volunteer']['alter']['text'] = 'YES';
  $handler->display->display_options['fields']['field_volunteer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_volunteer']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_volunteer']['type'] = 'list_key';
  /* Field: User: Volunteer preferences */
  $handler->display->display_options['fields']['field_volunteer_preferences']['id'] = 'field_volunteer_preferences';
  $handler->display->display_options['fields']['field_volunteer_preferences']['table'] = 'field_data_field_volunteer_preferences';
  $handler->display->display_options['fields']['field_volunteer_preferences']['field'] = 'field_volunteer_preferences';
  $handler->display->display_options['fields']['field_volunteer_preferences']['label'] = 'Volunteer';
  $handler->display->display_options['fields']['field_volunteer_preferences']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_volunteer_preferences']['delta_offset'] = '0';
  /* Field: User: BBQ Preferences */
  $handler->display->display_options['fields']['field_bbq_preferences_1']['id'] = 'field_bbq_preferences_1';
  $handler->display->display_options['fields']['field_bbq_preferences_1']['table'] = 'field_data_field_bbq_preferences';
  $handler->display->display_options['fields']['field_bbq_preferences_1']['field'] = 'field_bbq_preferences';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: BBQ Preferences (field_bbq_preferences) */
  $handler->display->display_options['filters']['field_bbq_preferences_value']['id'] = 'field_bbq_preferences_value';
  $handler->display->display_options['filters']['field_bbq_preferences_value']['table'] = 'field_data_field_bbq_preferences';
  $handler->display->display_options['filters']['field_bbq_preferences_value']['field'] = 'field_bbq_preferences_value';
  $handler->display->display_options['filters']['field_bbq_preferences_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bbq_preferences_value']['expose']['operator_id'] = 'field_bbq_preferences_value_op';
  $handler->display->display_options['filters']['field_bbq_preferences_value']['expose']['label'] = 'BBQ Preferences';
  $handler->display->display_options['filters']['field_bbq_preferences_value']['expose']['operator'] = 'field_bbq_preferences_value_op';
  $handler->display->display_options['filters']['field_bbq_preferences_value']['expose']['identifier'] = 'field_bbq_preferences_value';
  $handler->display->display_options['filters']['field_bbq_preferences_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
  );
  /* Filter criterion: User: I want to attend the BBQ on saturday evening (field_registration_bbq) */
  $handler->display->display_options['filters']['field_registration_bbq_value']['id'] = 'field_registration_bbq_value';
  $handler->display->display_options['filters']['field_registration_bbq_value']['table'] = 'field_data_field_registration_bbq';
  $handler->display->display_options['filters']['field_registration_bbq_value']['field'] = 'field_registration_bbq_value';
  $handler->display->display_options['filters']['field_registration_bbq_value']['value'] = array(
    'all' => 'all',
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_registration_bbq_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_registration_bbq_value']['expose']['operator_id'] = 'field_registration_bbq_value_op';
  $handler->display->display_options['filters']['field_registration_bbq_value']['expose']['label'] = 'Attend BBQ';
  $handler->display->display_options['filters']['field_registration_bbq_value']['expose']['operator'] = 'field_registration_bbq_value_op';
  $handler->display->display_options['filters']['field_registration_bbq_value']['expose']['identifier'] = 'field_registration_bbq_value';
  $handler->display->display_options['filters']['field_registration_bbq_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
  );
  /* Filter criterion: User: I want to help in the organization of this event (field_volunteer) */
  $handler->display->display_options['filters']['field_volunteer_value']['id'] = 'field_volunteer_value';
  $handler->display->display_options['filters']['field_volunteer_value']['table'] = 'field_data_field_volunteer';
  $handler->display->display_options['filters']['field_volunteer_value']['field'] = 'field_volunteer_value';
  $handler->display->display_options['filters']['field_volunteer_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_volunteer_value']['expose']['operator_id'] = 'field_volunteer_value_op';
  $handler->display->display_options['filters']['field_volunteer_value']['expose']['label'] = 'Volunteer';
  $handler->display->display_options['filters']['field_volunteer_value']['expose']['operator'] = 'field_volunteer_value_op';
  $handler->display->display_options['filters']['field_volunteer_value']['expose']['identifier'] = 'field_volunteer_value';
  $handler->display->display_options['filters']['field_volunteer_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
  );
  /* Filter criterion: User: I will attend... (og_user_node) */
  $handler->display->display_options['filters']['og_user_node_target_id']['id'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_user_node_target_id']['field'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['operator_id'] = 'og_user_node_target_id_op';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['label'] = 'I will attend...';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['operator'] = 'og_user_node_target_id_op';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['identifier'] = 'og_user_node_target_id';
  $handler->display->display_options['filters']['og_user_node_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
  );
  /* Filter criterion: User: T-shirt size (field_t_shirt_size) */
  $handler->display->display_options['filters']['field_t_shirt_size_value']['id'] = 'field_t_shirt_size_value';
  $handler->display->display_options['filters']['field_t_shirt_size_value']['table'] = 'field_data_field_t_shirt_size';
  $handler->display->display_options['filters']['field_t_shirt_size_value']['field'] = 'field_t_shirt_size_value';
  $handler->display->display_options['filters']['field_t_shirt_size_value']['value'] = array(
    'S' => 'S',
    'M' => 'M',
    'L' => 'L',
    'X' => 'X',
  );
  $handler->display->display_options['filters']['field_t_shirt_size_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_t_shirt_size_value']['expose']['operator_id'] = 'field_t_shirt_size_value_op';
  $handler->display->display_options['filters']['field_t_shirt_size_value']['expose']['label'] = 'T-shirt size';
  $handler->display->display_options['filters']['field_t_shirt_size_value']['expose']['operator'] = 'field_t_shirt_size_value_op';
  $handler->display->display_options['filters']['field_t_shirt_size_value']['expose']['identifier'] = 'field_t_shirt_size_value';
  $handler->display->display_options['filters']['field_t_shirt_size_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_t_shirt_size_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: Volunteer preferences (field_volunteer_preferences) */
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['id'] = 'field_volunteer_preferences_value';
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['table'] = 'field_data_field_volunteer_preferences';
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['field'] = 'field_volunteer_preferences_value';
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['expose']['operator_id'] = 'field_volunteer_preferences_value_op';
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['expose']['label'] = 'Volunteer preferences';
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['expose']['operator'] = 'field_volunteer_preferences_value_op';
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['expose']['identifier'] = 'field_volunteer_preferences_value';
  $handler->display->display_options['filters']['field_volunteer_preferences_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
    8 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'users';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'MEMBERS-%timestamp-full-%exposed.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'users/export';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $export['users'] = $view;

  return $export;
}
