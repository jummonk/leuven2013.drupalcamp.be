<?php
/**
 * Display the general countdown timer.
 */
function _leuven2013_general_block_countdown_timer() {
  $block = array(
    'subject' => NULL,
    'content' => 'Static countdown to 14/15 September 2013 (JS to be added!)',
  );

  return $block;
}

/**
 * Display block with How-to propose a session
 */
function _leuven2013_general_block_how_to_propose_session() {
  $numbered = theme('html_tag', array(
    'element' => array(
      '#tag' => 'span',
      '#value' => '1',
      '#attributes' => array(
        'class' => drupal_html_class('how-to-propose-session-step-count'),
      ),
    )
  ));

  $step1 = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => $numbered . t('Make sure you are !registered and !loggedin on this website.', array(
        '!registered' => l(t('registered'), 'user/register'),
        '!loggedin' => l(t('logged in'), 'user/login'),
      )),
      '#attributes' => array(
        'class' => drupal_html_class('how-to-propose-session-step'),
        'id' => drupal_html_id('how-to-propose-session-step1')
      ),
    )
  ));

  $numbered = theme('html_tag', array(
    'element' => array(
      '#tag' => 'span',
      '#value' => '2',
      '#attributes' => array(
        'class' => drupal_html_class('how-to-propose-session-step-count'),
      ),
    )
  ));

  $step2 = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => $numbered . t('!fillin (make sure you are logged in!).', array(
        '!fillin' => l(t('Fill in the session proposal form'), 'node/add/session'),
      )),
      '#attributes' => array(
        'class' => drupal_html_class('how-to-propose-session-step'),
        'id' => drupal_html_id('how-to-propose-session-step2')
      ),
    )
  ));

  $numbered = theme('html_tag', array(
    'element' => array(
      '#tag' => 'span',
      '#value' => '3',
      '#attributes' => array(
        'class' => drupal_html_class('how-to-propose-session-step-count'),
      ),
    )
  ));

  $step3 = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => $numbered . t('Wait for feedback or !contact in case you have questions.', array(
        '!contact' => l(t('contact us'), 'contact'),
      )),
      '#attributes' => array(
        'class' => drupal_html_class('how-to-propose-session-step'),
        'id' => drupal_html_id('how-to-propose-session-step3')
      ),
    )
  ));

  return array(
    'subject' => t('Propose a session:'),
    'content' => array(
      '#theme' => 'html_tag',
      '#tag' => 'div',
      '#value' => $step1 . $step2 . $step3,
      '#attributes' => array(
        'id' => drupal_html_id('how-to-propose-session-wrapper'),
      ),
    )
  );
}

/**
 * Print a block that displays the banner to link to the frontpage.
 */
function _leuven2013_general_block_banner_to_frontpage() {
  $block = array();

  $block['subject'] = '';
  $block['content'] = l(t('Frontpage'), '<front>', array('attributes' => array('class' => 'frontpage-banner-link')));

  return $block;
}