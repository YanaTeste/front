<?php

/**
 * @file
 * Migrate taxonomy vocabularies and terms classes.
 */

/**
 * Migrate vocabularies class.
 */
class FrontSectionTaxonomyMigration extends Migration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate taxonomy terms');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Term ID',
          'alias' => 'td',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $query = db_select(FRONT_MIGRATION_DB . '.term_data', 'td')
      ->fields('td', array('tid', 'vid', 'name', 'description', 'weight'))
      ->condition('td.vid', FRONT_TERM_SECTION, '=');

    $query->join(FRONT_MIGRATION_DB . '.term_hierarchy', 'th', 'td.tid = th.tid');
    $query->addField('th', 'parent');
    $query->orderBy('th.parent', 'ASC');

    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTerm(FRONT_TERM_SECTION_NAME);

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('weight', 'weight');
    $this->addFieldMapping('parent', 'parent')->sourceMigration($this->getMachineName());

    // Unmapped source fields
    $this->addUnmigratedSources(array('vid'));

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('path', 'parent_name'));
  }

  public function prepareRow($current_row) {
    if ($current_row->parent == 0) {
      unset($current_row->parent);
    }
    return TRUE;
  }
}


/**
 * Migrate vocabularies class.
 */
class FrontTopicTaxonomyMigration extends Migration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate taxonomy terms');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Term ID',
          'alias' => 'td',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $query = db_select(FRONT_MIGRATION_DB . '.term_data', 'td')
      ->fields('td', array('tid', 'vid', 'name', 'description', 'weight'))
      ->condition('td.vid', FRONT_TERM_TOPIC, '=');

    $query->join(FRONT_MIGRATION_DB . '.term_hierarchy', 'th', 'td.tid = th.tid');
    $query->addField('th', 'parent');
    $query->orderBy('th.parent', 'ASC');

    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTerm(FRONT_TERM_TOPIC_NAME);

    // Assign mappings TO destination fields FROM source fields.
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('weight', 'weight');
    $this->addFieldMapping('parent', 'parent')->sourceMigration($this->getMachineName());

    // Unmapped source fields
    $this->addUnmigratedSources(array('vid'));

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('path', 'parent_name'));
  }

  public function prepareRow($current_row) {
    if ($current_row->parent == 0) {
      unset($current_row->parent);
    }
    return TRUE;
  }
}
