<?php

/**
 * Form renders mapped organizer.
 *
 * @see thisted_event_import_menu().
 */
function thisted_event_import_admin_form($form, $form_state) {
  $mapped_libraries = variable_get('mapped_libraries', array());
  $libraries = thisted_events_import_get_libraries();

  $header = array(
    t('Library'),
    t('Url'),
  );

  $rows = array();
  foreach ($mapped_libraries as $key => $val) {
    $rows[$key] = array(
      $libraries[$key],
      $val,
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
  $libraries = thisted_event_import_get_not_mapped_libraries();

  $form['add_organizer_mapping'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add organizer mapping to library.'),
    '#collapsible' => FALSE,
    '#collapsed' => TRUE,
  );

  $form['add_organizer_mapping']['events_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('Uri to feed'),
    '#description' => t('Feed uri which correspond to selected library. E.g. @uri_example', array('@uri_example' => 'http://www.thy360.dk/api/a6d6bbf4-336a-4705-be97-7abdaaaf06fb')),
    '#required' => TRUE,
  );

  $form['add_organizer_mapping']['library_id'] = array(
    '#type' => 'select',
    '#title' => t('Library id'),
    '#options' => $libraries,
    '#description' => t('Select library to which organizer id correspond.'),
    '#required' => TRUE,
  );

  $form['add_organizer_mapping']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#submit' => array('_thisted_event_import_add_mapping_submit'),
  );

  $form['#validate'] = array('_thisted_event_import_add_mapping_validate');

  return $form;
}

/**
 * Validate function for mapping addition.
 *
 * @see thisted_event_import_add_mapping().
 */
function _thisted_event_import_add_mapping_validate($form, $form_state) {
  if (!(valid_url($form_state['values']['events_uri'], TRUE))) {
    form_set_error('events_uri', t('Invalid URI to events XML.'));
  }
}

/**
 * Submit function for mapping addition.
 *
 * @see thisted_event_import_add_mapping().
 */
function _thisted_event_import_add_mapping_submit($form, $form_state) {
  $values = $form_state['values'];
  $mapped_libraries = variable_get('mapped_libraries', array());

  $mapped_libraries[$values['library_id']] = $values['events_uri'];

  variable_set('mapped_libraries', $mapped_libraries);

  drupal_goto('admin/config/ting/events_import');
}

/**
 * Function delete selected mapping.
 */
function _thisted_event_import_delete_organizer_mapping($form, $form_state) {
  $selected_items = $form_state['input']['items'];
  $mapped_libraries = variable_get('mapped_libraries', array());
  foreach ($selected_items as $key => $selected_item) {
    if (!empty($selected_item)) {
      unset($mapped_libraries[$key]);
    }
  }
  variable_set('mapped_libraries', $mapped_libraries);
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
 * Get not mapped libraries.
 *
 * @return array $not_mapped
 *  key = id of library CT, value = library name.
 */
function thisted_event_import_get_not_mapped_libraries() {
  $all_libraries = thisted_events_import_get_libraries();
  $mapped_libraries = variable_get('mapped_libraries', array());

  $not_mapped = array_diff_key($all_libraries, $mapped_libraries);

  return $not_mapped;
}
