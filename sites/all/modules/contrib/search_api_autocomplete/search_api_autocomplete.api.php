<?php

/**
 * @file
 * Hooks provided by the Search API autocomplete module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Inform the module about types of searches for which autocompletion is available.
 *
 * The implementation has to take care of altering the search form accordingly
 * itself. This should be done by loading the appropriate
 * SearchApiAutocompleteSearch entity and calling its alterElement() method with
 * the textfield element to which autocompletion should be added. See
 * example_form_example_search_form_alter() for an example.
 *
 * @return array
 *   An array with search types as the keys, mapped to arrays containing the
 *   following entries:
 *   - name: The category name for searches of this type.
 *   - description: A short description of this type (may contain HTML).
 *   - list searches: Callback function that returns a list of all known
 *     searches of this type for a given index. See
 *     example_list_autocomplete_searches() for the expected function signature.
 *   - create query: Callback function to create a search query for a search of
 *     this type and some user input. See example_create_autocomplete_query()
 *     for the expected function signature.
 *   - config form: (optional) Callback function for adding a form for
 *     type-specific options to a search's autocomplete settings form. See
 *     example_autocomplete_config_form() for the expected function signature.
 *     This function name will also be the base for custom validation and submit
 *     callbacks, with "_validate" or "_submit" appended, respectively.
 *
 * @see example_list_autocomplete_searches()
 * @see example_create_autocomplete_query()
 * @see example_autocomplete_config_form()
 * @see example_autocomplete_config_form_validate()
 * @see example_autocomplete_config_form_submit()
 * @see example_form_example_search_form_alter()
 */
function hook_search_api_autocomplete_types() {
  $types['example'] = array(
    'name' => t('Example searches'),
    'description' => t('Searches provided by the <em>Example</em> module.'),
    'list searches' => 'example_list_autocomplete_searches',
    'create query' => 'example_create_autocomplete_query',
    'config form' => 'example_autocomplete_config_form',
  );

  return $types;
}

/**
 * Acts on searches being loaded from the database.
 *
 * This hook is invoked during search loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param array $searches
 *   An array of search entities being loaded, keyed by machine name.
 *
 * @see hook_entity_load()
 */
function hook_search_api_autocomplete_search_load(array $searches) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Responds when a search is inserted.
 *
 * This hook is invoked after the search is inserted into the database.
 *
 * @param SearchApiAutocompleteSearch $search
 *   The search that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_search_api_autocomplete_search_insert(SearchApiAutocompleteSearch $search) {
  db_insert('mytable')
    ->fields(array(
      'id' => entity_id('search_api_autocomplete_search', $search),
      'extra' => print_r($search, TRUE),
    ))
    ->execute();
}

/**
 * Acts on a search being inserted or updated.
 *
 * This hook is invoked before the search is saved to the database.
 *
 * @param SearchApiAutocompleteSearch $search
 *   The search that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_search_api_autocomplete_search_presave(SearchApiAutocompleteSearch $search) {
  $search->name = 'foo';
}

/**
 * Responds to a search being updated.
 *
 * This hook is invoked after the search has been updated in the database.
 *
 * @param SearchApiAutocompleteSearch $search
 *   The search that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_search_api_autocomplete_search_update(SearchApiAutocompleteSearch $search) {
  db_update('mytable')
    ->fields(array('extra' => print_r($search, TRUE)))
    ->condition('id', entity_id('search_api_autocomplete_search', $search))
    ->execute();
}

/**
 * Responds to search deletion.
 *
 * This hook is invoked after the search has been removed from the database.
 *
 * @param SearchApiAutocompleteSearch $search
 *   The search that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_search_api_autocomplete_search_delete(SearchApiAutocompleteSearch $search) {
  db_delete('mytable')
    ->condition('pid', entity_id('search_api_autocomplete_search', $search))
    ->execute();
}

/**
 * Define default search configurations.
 *
 * @return
 *   An array of default searches, keyed by machine names.
 *
 * @see hook_default_search_api_autocomplete_search_alter()
 */
function hook_default_search_api_autocomplete_search() {
  $defaults['main'] = entity_create('search_api_autocomplete_search', array(
    // …
  ));
  return $defaults;
}

/**
 * Alter default search configurations.
 *
 * @param array $defaults
 *   An array of default searches, keyed by machine names.
 *
 * @see hook_default_search_api_autocomplete_search()
 */
function hook_default_search_api_autocomplete_search_alter(array &$defaults) {
  $defaults['main']->name = 'custom name';
}

/**
 * @} End of "addtogroup hooks".
 */

/**
 * Returns a list of searches for the given index.
 *
 * All searches returned must have a unique and well-defined machine name. The
 * implementing module for this type is responsible for being able to map a
 * specific search always to the same distinct machine name.
 * Since the machine names have to be globally unique, they should be prefixed
 * with the search type / module name.
 *
 * Also, name and machine name have to respect the length constraints from
 * search_api_autocomplete_schema().
 *
 * @param SearchApiIndex $index
 *   The index whose searches should be returned.
 *
 * @return array
 *   An array of searches, keyed by their machine name. The values are arrays
 *   with the following keys:
 *   - name: A human-readable name for this search.
 *   - options: (optional) An array of options to use for this search.
 *     Type-specific options should go into the "custom" nested key in these
 *     options.
 */
function example_list_autocomplete_searches(SearchApiIndex $index) {
  $ret = array();
  $result = db_query('SELECT name, machine_name, extra FROM {example_searches} WHERE index_id = :id', array($index->machine_name));
  foreach ($result as $row) {
    $id = 'example_' . $row->machine_name;
    $ret[$id] = array(
      'name' => $row->name,
    );
    if ($row->extra) {
      $ret[$id]['options']['custom']['extra'] = $row->extra;
    }
  }
  return $ret;
}

/**
 * Create the query that would be issued for the given search for the complete keys.
 *
 * @param SearchApiAutocompleteSearch $search
 *   The search for which to create the query.
 * @param $complete
 *   A string containing the complete search keys.
 * @param $incomplete
 *   A string containing the incomplete last search key.
 *
 * @return SearchApiQueryInterface
 *   The query that would normally be executed when only $complete was entered
 *   as the search keys for the given search.
 */
function example_create_autocomplete_query(SearchApiAutocompleteSearch $search, $complete, $incomplete) {
  $query = search_api_query($search->index_id);
  if ($complete) {
    $query->keys($complete);
  }
  if (!empty($search->options['custom']['extra'])) {
    list($f, $v) = explode('=', $search->options['custom']['extra'], 2);
    $query->condition($f, $v);
  }
  if (!empty($search->options['custom']['user_filters'])) {
    foreach (explode("\n", $search->options['custom']['user_filters']) as $line) {
      list($f, $v) = explode('=', $line, 2);
      $query->condition($f, $v);
    }
  }
  return $query;
}

/**
 * Form callback for configuring autocompletion for searches of the "example" type.
 *
 * The returned form array will be nested into an outer form, so you should not
 * rely on knowing the array structure (like the elements' parents) and should
 * not set "#tree" to FALSE for any element.
 *
 * @param SearchApiAutocompleteSearch $search
 *   The search whose config form should be presented.
 *
 * @see example_autocomplete_config_form_validate()
 * @see example_autocomplete_config_form_submit()
 */
function example_autocomplete_config_form(array $form, array &$form_state, SearchApiAutocompleteSearch $search) {
  $form['user_filters'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom filters'),
    '#description' => t('Enter additional filters set on the autocompletion search. ' .
        'Write one filter on each line, the field and its value separated by an equals sign (=).'),
    '#default_value' => empty($search->options['custom']['user_filters']) ? '' : $search->options['custom']['user_filters'],
  );

  return $form;
}

/**
 * Validation callback for example_autocomplete_config_form().
 *
 * The configured SearchApiAutocompleteSearch object can be found in
 * $form_state['search'].
 *
 * @param array $form
 *   The type-specific config form, as returned by the "config form" callback.
 * @param array $form_state
 *   The complete form state of the form.
 * @param array $values
 *   The portion of $form_state['values'] that corresponds to the type-specific
 *   config form.
 *
 * @see example_autocomplete_config_form()
 * @see example_autocomplete_config_form_submit()
 */
function example_autocomplete_config_form_validate(array $form, array &$form_state, array &$values) {
  $f = array();
  foreach (explode("\n", $values['user_filters']) as $line) {
    if (preg_match('/^\s*([a-z0-9_:]+)\s*=\s*(.*\S)\s*$/i', $line, $m)) {
      $f[] = $m[1] . '=' . $m[2];
    }
    else {
      form_error($form, t('Write one filter on each line, the field and its value separated by an equals sign (=).'));
    }
  }
  $values['user_filters'] = $f;
}

/**
 * Submit callback for example_autocomplete_config_form().
 *
 * After calling this function, the value of $values (if set) will automatically
 * be written to $search->options['custom']. This function just has to take care
 * of sanitizing the data as necessary. Also, values already present in
 * $search->options['custom'], but not in the form, will automatically be
 * protected from being overwritten.
 *
 * The configured SearchApiAutocompleteSearch object can be found in
 * $form_state['search'].
 *
 * @param array $form
 *   The type-specific config form, as returned by the "config form" callback.
 * @param array $form_state
 *   The complete form state of the form.
 * @param array $values
 *   The portion of $form_state['values'] that corresponds to the type-specific
 *   config form.
 *
 * @see example_autocomplete_config_form()
 * @see example_autocomplete_config_form_validate()
 */
function example_autocomplete_config_form_submit(array $form, array &$form_state, array &$values) {
  $values['user_filters'] = implode("\n", $values['user_filters']);
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Alters the example_search_form form to add autocompletion, if enabled by the
 * user.
 */
function example_form_example_search_form_alter(array &$form, array &$form_state) {
  // Compute the machine name that would be generated for this search in the
  // 'list searches' callback.
  $search_id = 'example_' . $form_state['search id'];
  // Look up the corresponding autocompletion configuration, if it exists.
  $search = search_api_autocomplete_search_load($search_id);
  // Check whether autocompletion for the search is enabled.
  if (!empty($search->enabled)) {
    // If it is, pass the textfield for the search keywords to the
    // alterElement() method of the search object.
    $search->alterElement($form['keys']);
  }
}