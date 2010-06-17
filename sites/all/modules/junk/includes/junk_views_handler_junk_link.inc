<?php 
// $Id: junk_views_handler_junk_link.inc,v 1.1 2010/03/12 16:56:57 alirasirin Exp $

/**
 * @file
 * Field handler to move node to Junk
 *
 * @ingroup views_field_handlers
 */
class junk_views_handler_junk_link extends views_handler_field {
    
  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    return l(t('Move to junk'), "node/$nid/junk", array('query' => drupal_get_destination()));
  }
}