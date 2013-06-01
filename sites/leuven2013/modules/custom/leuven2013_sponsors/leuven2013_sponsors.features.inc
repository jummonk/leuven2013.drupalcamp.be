<?php
/**
 * @file
 * leuven2013_sponsors.features.inc
 */

/**
 * Implements hook_views_api().
 */
function leuven2013_sponsors_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function leuven2013_sponsors_image_default_styles() {
  $styles = array();

  // Exported image style: sponsor_full_logo.
  $styles['sponsor_full_logo'] = array(
    'name' => 'sponsor_full_logo',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '810',
          'height' => '250',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
