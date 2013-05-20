<?php
/**
 * @file
 * leuven2013_general.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function leuven2013_general_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
