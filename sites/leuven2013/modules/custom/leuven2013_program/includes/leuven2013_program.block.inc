<?php

/**
 * Display a message on the program page.
 */
function _leuven2013_program_block_program_message() {
  global $user;

  if (user_is_anonymous()) {
    $text = t('You can create your own program by bookmarking different sessions.
    To use this functionality, you must be !registered and !logged_in.', array(
      '!registered' => l(t('registered'), 'user/register'),
      '!logged_in' => l(t('logged in'), 'user'),
    ));
  }
  else {
    $text = t('You can create your !own_program by bookmarking different sessions.
    An overview of all bookmarked sessions can be found on your !profile_page.', array(
      '!own_program' => l(t('own program'), 'program/my_program'),
      '!profile_page' => l(t('profile page'), "user/$user->uid/sessions"),
    ));
  }

  return array(
    'content' => array(
      '#theme' => 'html_tag',
      '#tag' => 'div',
      '#value' => '<p>' . $text . '</p>',
      '#attributes' => array('class' => drupal_html_class('conf-message')),
    )
  );
}