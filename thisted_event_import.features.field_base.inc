<?php
/**
 * @file
 * thisted_event_import.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function thisted_event_import_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_library'
  $field_bases['field_library'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_library',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
