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

function leuven2013_theme_preprocess_taxonomy_term(&$variables) {
  $elements = $variables['elements'];
  if($elements['#entity_type'] != 'taxonomy_term' || $variables['vocabulary_machine_name'] != 'sponsorship_level' || empty($variables['tid'])) {
    return;
  }
  $tid = $variables['tid'];

  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->leftJoin('field_data_field_sponsor_sponsorship_level', 'sl', 'n.nid = sl.entity_id');
  $query->condition('sl.field_sponsor_sponsorship_level_tid', $tid);
  $query->condition('n.title', '%' . db_like('FREE') . '%', 'NOT LIKE');

  $term_obj = taxonomy_term_load($tid);

  if (empty($term_obj)) { 
    return; 
  }

  $slots_field = field_get_items('taxonomy_term', $term_obj, 'field_package_slots');

  if (!empty($slots_field)) {
    $slots = $slots_field[0]['value'];
  }
  else {
    $slots = 99;
  }
  
  $result = $query->execute()->fetchAllAssoc('nid');

  if (empty($result) || sizeof($result) < $slots) {
    $uri = entity_uri('taxonomy_term', $term_obj);
    $variables['apply_link'] = l('Apply for this package now.', 'sponsorship/' . $tid . '/apply');
  }
}