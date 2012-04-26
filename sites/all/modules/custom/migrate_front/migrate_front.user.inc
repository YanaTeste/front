<?php

/**
 * @file
 * User accounts and content profile migration classes.
 */

/**
 * User account migration class.
 */
class FrontUserMigration extends Migration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate legacy users');

    $source_fields = array(
      'uid' => t('User ID'),
      'roles' => t('The roles assigned to a user.'),
    );

    $or = db_or()
      ->condition('u.mail', '%front.no%', 'LIKE')
      ->condition('u.mail', '%perandre%', 'LIKE');

    $query = db_select(FRONT_MIGRATION_DB . '.users', 'u')
      ->fields('u', array('uid',
                          'name',
                          'pass',
                          'mail',
                          'created',
                          'access',
                          'login',
                          'status',
                          'init',
                          'timezone',
                          'timezone_name',
                          'language',
                          'picture'))
      ->condition($or)
      ->condition('u.uid', 1, '>');

    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationUser(array('md5_passwords' => TRUE));

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique User ID',
          'alias' => 'u',
        ),
      ),
      MigrateDestinationUser::getKeySchema()
    );

    $this->addFieldMapping('name', 'name')->dedupe('users', 'name');
    $this->addFieldMapping('pass', 'pass');
    $this->addFieldMapping('mail', 'mail')->dedupe('users', 'mail');
    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('theme')->defaultValue('');
    $this->addFieldMapping('signature')->defaultValue('');
    $this->addFieldMapping('signature_format')->defaultValue('filtered_html');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('access', 'access');
    $this->addFieldMapping('login', 'login');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('picture')->defaultValue(0);
    $this->addFieldMapping('init', 'init');
    $this->addFieldMapping('timezone', 'timezone');
    $this->addFieldMapping('roles', 'roles');
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('uid', 'uid');
  }

  public function prepareRow($current_row) {
    $source_id = $current_row->uid;
    $query = db_select(FRONT_MIGRATION_DB . '.users_roles', 'r')
      ->fields('r', array('uid', 'rid'))
      ->condition('r.uid', $source_id, '=');

    $results = $query->execute();
    $roles = array();

    foreach ($results as $row) {
      $roles[$row->rid] = $row->rid;
    }
dsm($current_row->name);
    $current_row->roles = $roles;
    return TRUE;
  }
}

/**
 * Profile content type migration class.
 */
class FrontUserProfile2Migration extends Migration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Migration of customer profiles into Profile2 entities');
    $this->dependencies = array('FrontUser');

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
      MigrateDestinationProfile2::getKeySchema()
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
      ->condition('n.type', 'person', '=');

    $query->join(FRONT_MIGRATION_DB . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->addField('nr', 'format');

    $query->join(FRONT_MIGRATION_DB . '.users', 'u', 'n.uid = u.uid');
    $query->addField('u', 'name');

    $query->join(FRONT_MIGRATION_DB . '.content_type_person', 'ctp', 'n.nid = ctp.nid AND n.vid = ctp.vid');
    $query->addField('ctp','field_tittel_value');
    $query->orderBy('n.nid', 'ASC');

    $query->join(FRONT_MIGRATION_DB . '.content_field_image', 'cfi', 'n.nid = cfi.nid AND n.vid = cfi.vid');
    $query->addField('cfi', 'field_image_fid');

    $query->join(FRONT_MIGRATION_DB . '.files', 'f', 'f.fid = cfi.field_image_fid');
    $query->addField('f', 'filename');

    $source_fields = array(
      'nid' => t('The node ID of the page'),
      'uid' => t('The user ID of a user'),
      'lid' => t('The location ID of a location instance'),
    );

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationProfile2('profile');

    // Connect profile to user
    $this->addFieldMapping('uid', 'uid')->sourceMigration('FrontUser');

    $this->addFieldMapping('field_name', 'title');
    $this->addFieldMapping('field_bio', 'body');
    $this->addFieldMapping('field_title', 'field_tittel_value');
    // ->callbacks(array($this, 'dsmValue'));

    $this->addFieldMapping('field_image', 'filename');
    $this->addFieldMapping('field_image:source_dir')->defaultValue(FRONT_MIGRATION_FILES . '/media/images');

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array('id'));
    $this->addUnmigratedSources(array('vid', 'type', 'language', 'moderate', 'tnid', 'translate', 'teaser', 'format', 'name'));
  }

  protected function dsmValue($value) {
    dsm($value);
    return $value;
  }
}
