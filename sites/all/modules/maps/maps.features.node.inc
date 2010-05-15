<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _maps_node_info() {
  $items = array(
    'place' => array(
      'name' => t('Sted'),
      'module' => 'features',
      'description' => t('Et sted som kan knyttes til et kart'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'has_body' => '1',
      'body_label' => t('Beskrivelse'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
