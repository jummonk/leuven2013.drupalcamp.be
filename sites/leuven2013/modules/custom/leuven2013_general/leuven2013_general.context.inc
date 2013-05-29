<?php
/**
 * @file
 * leuven2013_general.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function leuven2013_general_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'leuven2013_frontpage';
  $context->description = 'Leuven 2013 Frontpage';
  $context->tag = 'Leuven2013';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'leuven2013_general-countdown_timer' => array(
          'module' => 'leuven2013_general',
          'delta' => 'countdown_timer',
          'region' => 'header_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Leuven 2013 Frontpage');
  t('Leuven2013');
  $export['leuven2013_frontpage'] = $context;

  return $export;
}
