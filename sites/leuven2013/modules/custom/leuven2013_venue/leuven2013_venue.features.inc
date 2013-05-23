<?php
/**
 * @file
 * leuven2013_venue.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function leuven2013_venue_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function leuven2013_venue_node_info() {
  $items = array(
    'venue' => array(
      'name' => t('Venue'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
