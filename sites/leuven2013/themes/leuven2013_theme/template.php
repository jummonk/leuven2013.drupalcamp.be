<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * Preprocess field. 
 * 
 * Cannot place this in preprocess/preprocess-field.inc since the field hook is never included here.
 */
function leuven2013_theme_preprocess_field(&$variables, $hook) {
    $element = $variables['element'];
    if ($element['#entity_type'] == 'user' && $element['#field_name'] == 'field_twitter_handle') {
      $twitter_handle = field_get_items('user', $element['#object'], 'field_twitter_handle');
      if (empty($twitter_handle) || empty($twitter_handle[0]['value'])) {
        return;
      }
      $link_twitter = l($twitter_handle[0]['value'], 'http://twitter.com/' . $twitter_handle[0]['value'], array('attributes'=>array('target'=>'blank')));
      $variables['items']['0']['#markup'] = $link_twitter;
    }
}