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
  if ($element['#field_name'] == 'field_session_track') {
    foreach ($variables['items'] as $delta => $item) {
      $colors = field_get_items('taxonomy_term', $item['#options']['entity'], 'field_track_color_code');
      if (!empty($colors) && !empty($colors[0]['rgb'])) {
        $rgb = $colors[0]['rgb'];
        // $rgb = str_replace('#', '', $rgb);
        $variables['item_attributes_array'][$delta]['style'] = 'background: ' . $rgb;
      }
    }
  }
}
