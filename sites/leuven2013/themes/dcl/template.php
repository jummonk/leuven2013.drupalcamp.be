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
      if (empty($item['#options']['entity'])) {
        continue;
      }
      $colors = field_get_items('taxonomy_term', $item['#options']['entity'], 'field_track_color_code');
      if (!empty($colors) && !empty($colors[0]['rgb'])) {
        $rgb = $colors[0]['rgb'];
        // $rgb = str_replace('#', '', $rgb);
        $variables['item_attributes_array'][$delta]['style'] = 'background: ' . $rgb;
      }
    }
  }
  elseif ($element['#field_name'] == 'field_experience') {
    foreach ($variables['items'] as $delta => $item) {
      if (!empty($item['#markup'])) {
        $variables['classes_array'][] = 'icon-experience-level';
        switch (strtolower($item['#markup'])) {
          case 'beginner':
            $variables['classes_array'][] = 'experience-level-1';
            break;
          case 'intermediate':
            $variables['classes_array'][] = 'experience-level-2';
            break;
          case 'advanced':
            $variables['classes_array'][] = 'experience-level-3';
            break;
        }
      }
    }
  }
  elseif ($element['#field_name'] == 'title' && $element['#bundle'] == 'schedule_item') {
    $node = $element['#object'];
    $type = field_get_items('node', $node, 'field_schedule_item_type');

    if (empty($type) || empty($type[0]['value'])) { return; }

    $variables['classes_array'][] = 'schedule_item';
    $variables['classes_array'][] = 'schedule_' . check_plain($type[0]['value']);
  }
  elseif (($element['#bundle'] == 'session' || $element['#bundle'] == 'schedule_item') && $element['#view_mode'] == 'teaser' && $element['#field_name'] == 'body') {
    $variables['items'][0]['#markup'] = strip_tags($variables['items'][0]['#markup']);
  }
}
