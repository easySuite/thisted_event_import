<?php

/**
 * Form renders mapped organizer.
 *
 * @see thisted_event_import_menu().
 */
function thisted_event_import_admin_form($form, $form_state) {
  $mapped_libraries = thisted_event_import_get_organizer_library();
  $libraries = thisted_events_import_get_libraries();

  $header = array(
    t('Organizer id'),
    t('Library'),
  );

  $rows = array();
  foreach ($mapped_libraries as $key => $val) {
    $rows[$val->library_id] = array(
      $val->organizer_id,
      $libraries[$val->library_id],
    );
  }

  $form['items'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $rows,
    '#empty' => t('No mapped data.'),
  );

  $form['actions'] = array(
    'delete' => array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('_thisted_event_import_delete_organizer_mapping'),
    ),
  );

  return $form;
}

/**
 * Form for adding mapping organizer-library.
 *
 * @see thisted_event_import_menu().
 */
function thisted_event_import_add_mapping($form, $form_state) {
  $not_mapped_organizers = thisted_event_import_not_mapped_organizer();
  $libraries = thisted_events_import_get_libraries();

  $form['add_organizer_mapping'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add organizer mapping to library.'),
    '#collapsible' => FALSE,
    '#collapsed' => TRUE,
  );

  $form['add_organizer_mapping']['organizer_id'] = array(
    '#type' => 'select',
    '#title' => t('Organizer id'),
    '#options' => $not_mapped_organizers,
    '#description' => t('Select not mapped organizer id.'),
  );

  $form['add_organizer_mapping']['library_id'] = array(
    '#type' => 'select',
    '#title' => t('Library id'),
    '#options' => $libraries,
    '#description' => t('Select library to which organizer id correspond.'),
  );

  $form['add_organizer_mapping']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#submit' => array('_thisted_event_import_add_mapping_submit'),
  );

  return $form;
}

/**
 * Submit function for mapping addition.
 *
 * @see thisted_event_import_add_mapping().
 */
function _thisted_event_import_add_mapping_submit($form, $form_state) {
  $mapping = $form_state['input'];

  db_insert('library_organizer')
    ->fields(array(
      'library_id' => $mapping['library_id'],
      'organizer_id' => $mapping['organizer_id'],
    ))
    ->execute();

  drupal_goto('admin/config/ting/events_import');
}

/**
 * Function delete selected mapping.
 */
function _thisted_event_import_delete_organizer_mapping($form, $form_state) {
  $selected_items = $form_state['input']['items'];
  foreach ($selected_items as $item) {
    if (isset($item)) {
      db_delete('library_organizer')
        ->condition('library_id', $item, '=')
        ->execute();

      db_update('event_organizer')
        ->fields(array('organizer_id' => NULL))
        ->condition('organizer_id', '$item')
        ->execute();
    }
  }
}

/**
 * Get all mapped libraries.
 */
function thisted_event_import_get_organizer_library() {
  $result = db_select('library_organizer', 'lo')
    ->fields('lo')
    ->execute()
    ->fetchAll();

  return $result;
}

/**
 * Get all library CT nodes.
 */
function thisted_events_import_get_libraries() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('n.type', 'ding_library', '=');

  $result = $query
    ->execute()
    ->fetchAllKeyed();

  return $result;
}

/**
 * Get not mapped organizers.
 */
function thisted_event_import_not_mapped_organizer() {
  $query = db_select('event_organizer', 'eo');

  $query->leftJoin('library_organizer', 'lo', 'lo.organizer_id = eo.organizer_id');
  $query->fields('eo', array('organizer_id'))
    ->distinct()
    ->condition('lo.organizer_id', NULL, 'is');
  $result = $query
    ->execute()
    ->fetchCol();

  $organisers = array();
  $amount_not_mapped_organizers = count($result);
  if ($amount_not_mapped_organizers > 0) {
    foreach ($result as $organizer_id) {
      $organisers[$organizer_id] = $organizer_id;
    }
    drupal_set_message(t('You have @amount not mapped organizers.', array('@amount' => $amount_not_mapped_organizers)), 'warning');
  }

  return $organisers;
}
