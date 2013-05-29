<?php
/**
 * @file
 * leuven2013_social.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function leuven2013_social_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'leuven2013_twitter';
  $context->description = 'Social Context';
  $context->tag = 'Leuven2013';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-tweets-block' => array(
          'module' => 'views',
          'delta' => 'tweets-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Leuven2013');
  t('Social Context');
  $export['leuven2013_twitter'] = $context;

  return $export;
}
