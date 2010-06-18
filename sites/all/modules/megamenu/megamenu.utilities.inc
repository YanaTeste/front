<?php

/**
 * @file
 *
 * Helper/utility functions
 */

/**
 * function menu_list()
 *
 * helper function lists menu machine names except 'navigation'
 * I think this will have to be changed to some stored value, but maybe not? could still be 1 function?
 */
function _megamenu_menulist() {
  $menu_list = menu_get_menus();
  unset($menu_list['navigation']);
  return array_keys($menu_list);
}

function _megamenu_enabled_menus() {
  $result = db_query("SELECT menu_name FROM {megamenu} WHERE enabled = 1");
  $menus = db_fetch_array($result);

  if (is_array($menus)){
    return array_values($menus);
  }
}

/**
 * Retrieve a menu and pre-style before theming
 *
 * This function currently removes all "hidden" items, which could be
 * handled in the single iteration of the theme function.  But, I forsee
 * a need for other prep work that might be simmplfied with this second function
 *
 * Will be used in the future to add/alter attributes prior to theming
 *
 * @param $menuname
 *    The name of the menu to extract
 *
 * @return
 *    The pre-styled menu tree
 */
function _megamenu_get_menu_tree($menuname) {
  $menutree = menu_tree_all_data($menuname);
  foreach ($menutree as $t1key => $branch) {
    if ($branch['link']['hidden'] == 1) {
      unset($menutree[$t1key]);
    }
    else if ($branch['below']){
      foreach ($branch['below'] as $t2key => $twig) {
        if ($twig['link']['hidden'] == 1) {
            unset($menutree[$t1key]['below'][$t2key]);
        }
        else if ($twig['below']){
          foreach ($twig['below'] as $t3key => $leaf) {
            if ($leaf['link']['hidden'] ==1) {
                unset($menutree[$t1key]['below'][$t2key]['below'][$t3key]);
            }
            else if ($leaf['below']){
                unset($menutree[$t1key]['below'][$t2key]['below'][$t3key]['below']);
            }
          } //end t3 iteration
  	    }
      } //end t2 iteration
    }
  } //end t1 iteration
  return $menutree;
}

/**
 * Determine the zebra, half, and order attributes of an item.
 *
 * This is a helper function to generate count based classes
 * based on an items position in the sequence and the total count of
 * items. These classes consist of an item's zebra (even/odd), half (half1/half2),
 * and order (first/last).
 *
 * @param $count
 *    An item's numerical position within a sequence.
 * @param $leafcount
 *    The total count of items
 * @return
 *    zebra (event/odd), halves (half1/half2), and order (first/last). clases are
 *    returned as a space delimited list.
 */
function _megamenu_count_attributes($position,$total_count) {
  $zebra = ($position % 2) ? ' even' : ' odd';
  $halves = ($position < $total_count/2) ? ' half-1' : ' half-2';
  if ($position == 0) {
    $order = ' first';
  }
  else if ($position == $total_count-1) {
    $order = ' last';
  }
  else {
    $order = '';
  }
  return $zebra.$halves.$order;
}

function _megamenu_is_enabled($menu_name) {
  $result = db_result(db_query("SELECT enabled FROM {megamenu} WHERE menu_name = '%s'", $menu_name));

  return $result; 
}

function _megamenu_get_menu_orientation_by_name($menu_name) {
  $result = db_result(db_query("SELECT menu_orientation FROM {megamenu} WHERE menu_name = '%s'", $menu_name));
  return $result;
}

function _megamenu_get_skin_by_name($menu_name) {
  $result = db_result(db_query("SELECT skin FROM {megamenu} WHERE menu_name = '%s'", $menu_name));
  return $result;
}

function _megamenu_get_slot_orientation_by_name($menu_name) {
  $result = db_result(db_query("SELECT slot_orientation FROM {megamenu} WHERE menu_name = '%s'", $menu_name));
  return $result;
}

function _megamenu_get_slot_attributes_by_name($menu_name) {
  // TODO: Query db
  return '';
}

/**
 * Verify Menu Entry
 * Check to see if an entry exists for the givn menu name. If not, then insert a default row.
 * 
 * @param <string> $menu_name
 */
function _megamenu_verify_menu_entry($menu_name) {
  $result = db_result(db_query("SELECT menu_name FROM {megamenu} WHERE menu_name = '%s'", $menu_name));
  
  if (!$result) {
    db_query("INSERT INTO {megamenu} (menu_name, enabled) VALUES ('%s', %d)", $menu_name, 0);
  }
}

/**
 * Determine if a particular mega menu is using a default supplied skin.
 *
 * TODO: Rewrite this function! This is just a quick and dirty solution.
 *
 * @param <string> $menu_name
 */
function _megamenu_is_skin_default($menu_name) {
  $result = db_result(db_query("SELECT skin FROM {megamenu} WHERE menu_name = '%s'", $menu_name));

  if ($result == 'minimal' || $result == 'friendly') {
    return true;
  }

  return false;
}