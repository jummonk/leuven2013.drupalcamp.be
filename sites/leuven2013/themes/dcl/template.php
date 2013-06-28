<?php
/**
 * Implements hook_preprocess_block().
 */
function dcl_preprocess_block(&$vars) {
  /* Set shortcut variables. Hooray for less typing! */
  $block_id = $vars['block']->module . '-' . $vars['block']->delta;
  $classes = &$vars['classes_array'];

  var_dump($block_id);

  if ($block_id == '' || $block_id == '') {
    $classes[] = 'col6';
  }
}