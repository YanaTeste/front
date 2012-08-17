<?php
/**
 * @file
 * front_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function front_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:drupal
  $menu_links['main-menu:drupal'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'drupal',
    'router_path' => 'drupal',
    'link_title' => 'Drupal',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:løsninger
  $menu_links['main-menu:løsninger'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'løsninger',
    'router_path' => 'løsninger',
    'link_title' => 'Løsninger',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:om-oss
  $menu_links['main-menu:om-oss'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'om-oss',
    'router_path' => 'om-oss',
    'link_title' => 'Om oss',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: main-menu:prosjekter
  $menu_links['main-menu:prosjekter'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'prosjekter',
    'router_path' => 'prosjekter',
    'link_title' => 'Prosjekter',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: main-menu:tjenester
  $menu_links['main-menu:tjenester'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tjenester',
    'router_path' => 'tjenester',
    'link_title' => 'Tjenester',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: user-menu:blogg
  $menu_links['user-menu:blogg'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'blogg',
    'router_path' => 'blogg',
    'link_title' => 'Blogg',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '5',
  );
  // Exported menu link: user-menu:kontakt
  $menu_links['user-menu:kontakt'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'kontakt',
    'router_path' => 'kontakt',
    'link_title' => 'Kontakt',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '7',
  );
  // Exported menu link: user-menu:kurs
  $menu_links['user-menu:kurs'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'kurs',
    'router_path' => 'kurs',
    'link_title' => 'Kurs',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: user-menu:node/1657
  $menu_links['user-menu:node/1657'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/1657',
    'router_path' => 'node/%',
    'link_title' => 'Jobb i Front',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: user-menu:support
  $menu_links['user-menu:support'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'support',
    'router_path' => 'support',
    'link_title' => 'Support',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '7',
  );
  // Exported menu link: user-menu:user
  $menu_links['user-menu:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-10',
  );
  // Exported menu link: user-menu:user/logout
  $menu_links['user-menu:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '10',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blogg');
  t('Drupal');
  t('Jobb i Front');
  t('Kontakt');
  t('Kurs');
  t('Log out');
  t('Løsninger');
  t('Om oss');
  t('Prosjekter');
  t('Support');
  t('Tjenester');
  t('User account');


  return $menu_links;
}
