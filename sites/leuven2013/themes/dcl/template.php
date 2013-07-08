<?php
/**
 * Implements hook_preprocess_block().
 */
function dcl_preprocess_block(&$vars) {
  /* Set shortcut variables. Hooray for less typing! */
  $block_id = $vars['block']->module . '-' . $vars['block']->delta;
  $classes = &$vars['classes_array'];

  if (!drupal_is_front_page() && ($block_id == 'leuven2013_general-banner_to_frontpage' || $block_id == 'views-leuven2013_sponsors-block_1')) {
    $classes[] = 'col6';
  }
}

function dcl_preprocess_field(&$variables, $hook) {
  $element = $variables['element'];
  if ($element['#name'] == 'field_session_track') {
    $variables['classes_array'][] = 'BLUE';
  }
}