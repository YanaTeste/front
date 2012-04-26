<?php

/**
 * @file
 * Migrate content types classes.
 */

/**
 * Article migration class.
 */
class FrontArticleMigration extends Migration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate xdeb pages nodes.');
    $this->dependencies = array('FrontUser', 'FrontTaxonomy');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = db_select(FRONT_MIGRATION_DB . '.node', 'n')
      ->fields('n', array('nid',
                          'vid',
                          'type',
                          'language',
                          'title',
                          'uid',
                          'status',
                          'created',
                          'changed',
                          'comment',
                          'promote',
                          'moderate',
                          'sticky',
                          'tnid',
                          'translate'))
      ->condition('n.type', 'artikkel', '=');

    $query->join(FRONT_MIGRATION_DB . '.node_revisions', 'nr', 'n.nid = nr.nid AND n.changed = nr.timestamp');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->addField('nr', 'format');
    $query->addField('nr', 'log');

    $query->join(FRONT_MIGRATION_DB . '.users', 'u', 'nr.uid = u.uid');
    $query->addField('u', 'name');
    $query->orderBy('n.nid', 'ASC');

    // Field Subheading
    $query->leftJoin(FRONT_MIGRATION_DB . '.content_field_subheading', 'fs', 'n.vid = fs.vid');
    $query->addField('fs', 'field_subheading_value');

    // Terms for Section vocabulary.
    $query->leftJoin(FRONT_MIGRATION_DB . '.term_node', 'tn', 'n.vid = tn.vid');
    $query->addField('tn', 'tid');

    $query->leftJoin(FRONT_MIGRATION_DB . '.term_data', 'td', 'td.tid = tn.tid AND td.vid = ' . FRONT_TERM_SECTION);
    $query->addField('td', 'name');

    $source_fields = array(
      'nid' => t('The node ID of the node'),
      'url_alias' => t('The url alias of the node'),
    );

    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('artikkel');

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('nid', 'nid');
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('revision')->defaultValue(TRUE);
    $this->addFieldMapping('revision_uid', 'uid');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'changed');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('promote', 'promote');
    $this->addFieldMapping('sticky', 'sticky');
    $this->addFieldMapping('comment', 'comment');

    $this->addFieldMapping('path', 'url_alias');
    $this->addFieldMapping('pathauto')->defaultValue(0);

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('tnid', 'tnid');

    $this->addFieldMapping('field_subheading', 'field_subheading_value');
    $this->addFieldMapping('field_section', 'td_name')->separator(',');
    // $this->addFieldMapping('field_tags', 'tags')->separator(',');

    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'teaser');
    $this->addFieldMapping('body:format', 'format');
    $this->addFieldMapping('body:language', 'language');
    $this->addFieldMapping('log', 'log');

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array('field_tags'));

    // Unmapped source fields
    $this->addUnmigratedSources(array('vid',
                                      'type',
                                      'moderate',
                                      'tnid',
                                      'translate',
                                      'teaser',
                                      'format',
                                      'name',
                                      'tid'));
  }

  public function prepareRow($current_row) {
    // Don't migrate articles with empty a body text.
    if (empty($current_row->body)) {
      // put this back to FALSE once there's no need to debug.
      // return FALSE;
    }

    $text_formats = array(
      0 => 'filtered_html',
      1 => 'filtered_html',
      2 => 'full_html',
      3 => 'full_html',
    );

    // Don't save automatic teasers, leave this to D7 config.
    $breakpos = strpos($current_row->body, '<!--break-->');
    if ($breakpos === false) {
      $current_row->teaser = '';
    }

    // Set Full HTML filter on body without format.
    if (is_numeric($current_row->format)) {
      $current_row->format = $text_formats[$current_row->format];
    }

    // Set revision author if the node author is anonymous.
    if ($current_row->uid < 1) {
      if (isset($current_row->nr_uid)) {
        $current_row->uid = $current_row->nr_uid;
      }
      else {
        $current_row->uid = 1;
      }
    }

    // Set neutral if no language code.
    if (empty($current_row->language)) {
      $current_row->language = LANGUAGE_NONE;
    }

    return TRUE;
  }
}
