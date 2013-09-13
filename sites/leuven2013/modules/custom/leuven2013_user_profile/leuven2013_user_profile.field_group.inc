<?php
/**
 * @file
 * leuven2013_user_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function leuven2013_user_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal|user|user|form';
  $field_group->group_name = 'group_personal';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_registration';
  $field_group->data = array(
    'label' => 'Personal information',
    'weight' => '3',
    'children' => array(
      0 => 'field_twitter_handle',
      1 => 'field_t_shirt_size',
      2 => 'field_privacy',
      3 => 'ckeditor',
      4 => 'timezone',
      5 => 'picture',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Personal information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'last-page',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $export['group_personal|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_registration|user|user|form';
  $field_group->group_name = 'group_registration';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Registration',
    'weight' => '0',
    'children' => array(
      0 => 'group_basic',
      1 => 'group_preferences',
      2 => 'group_personal',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'Registration',
      'instance_settings' => array(
        'classes' => '',
        'page_header' => '1',
        'page_counter' => '1',
        'move_button' => '1',
        'move_additional' => '1',
      ),
    ),
  );
  $export['group_registration|user|user|form'] = $field_group;

  return $export;
}
