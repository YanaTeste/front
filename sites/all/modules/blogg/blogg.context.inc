<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function blogg_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blogg';
  $context->description = 'Den komplette blogg';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'blog' => 'blog',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ds-548ab248bb581703a23dbe0c47397efc' => array(
          'module' => 'ds',
          'delta' => '548ab248bb581703a23dbe0c47397efc',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-Emner-block_1' => array(
          'module' => 'views',
          'delta' => 'Emner-block_1',
          'region' => 'right',
          'weight' => 1,
        ),
        'apachesolr-mlt-001' => array(
          'module' => 'apachesolr',
          'delta' => 'mlt-001',
          'region' => 'right',
          'weight' => 2,
        ),
        'apachesolr-sort' => array(
          'module' => 'apachesolr',
          'delta' => 'sort',
          'region' => 'right',
          'weight' => 3,
        ),
      ),
    ),
    'menu' => 'blogg',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Den komplette blogg');

  $export['blogg'] = $context;
  return $export;
}
