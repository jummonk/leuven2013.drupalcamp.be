<?php
/**
 * Display the social media icons.
 */
function _leuven2013_social_block_social_sidebar() {
  $url = drupal_parse_url('http://twitter.com/drupalcampbe');
  $twitter = l('Twitter', $url['path'], array('external' => TRUE, 'attributes' => array('target'=>'_blank')));

  $url = drupal_parse_url('http://www.facebook.com/groups/241001195936454/events/');
  $facebook = l('Facebook', $url['path'], array('external' => TRUE, 'attributes' => array('target'=>'_blank')));

  $url = drupal_parse_url('http://groups.drupal.org/node/289348');
  $drupalorg = l('Drupal.org', $url['path'], array('external' => TRUE, 'attributes' => array('target'=>'_blank')));

  $block = array(
    // 'subject' => t('Social Media'),
    'subject' => '',
    'content' =>  '<div class="social-icon icon-twitter">' . $twitter . '</div> <div class="social-icon icon-facebook">' . $facebook . '</div><div class="social-icon icon-drupalorg">' . $drupalorg . '</div>',
  );

  return $block;
}