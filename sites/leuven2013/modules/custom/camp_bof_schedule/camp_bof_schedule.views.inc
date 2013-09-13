<?php
/**
 * @file
 * Views hooks for camp_schedule feature
 */

/**
 * Implements hook_views_plugins().
 */
function camp_bof_schedule_views_plugins() {
  return array(
    'module' => 'camp_bof_schedule',
    'style' => array(
      'camp_bof_schedule_grid' => array(
        'title' => t('Camp BoF schedule grid'),
        'help' => t('Display view as a table with room columns and time slot rows'),
        'handler' => 'camp_schedule_views_plugin_style_schedule',
        'theme' => 'camp_bof_schedule_grid',
        'uses row plugin' => FALSE,
        'uses row class' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
        'use ajax' => FALSE,
        'type' => 'normal',
        'even empty' => TRUE, // Make the View render when there are no results.
        ),
      ),
    );
}
