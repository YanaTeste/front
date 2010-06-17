<?php 
// $Id: junk_views_handler_restore_link.inc,v 1.1 2010/03/12 16:56:57 alirasirin Exp $

/**
 * @file
 * Field handler to restore node from Junk
 *
 * @ingroup views_field_handlers
 */
class junk_views_handler_restore_link extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = array('table' => 'junk_node', 'field' => 'nid');
  }
  
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
  
  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    return l(t('Restore'), "junk/$nid/restore", array('query' => drupal_get_destination()));
  }
}