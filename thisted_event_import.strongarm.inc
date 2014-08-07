<?php
/**
 * @file
 * thisted_event_import.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function thisted_event_import_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_xml_event_import';
  $strongarm->value = 0;
  $export['comment_anonymous_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_xml_event_import';
  $strongarm->value = 1;
  $export['comment_default_mode_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_xml_event_import';
  $strongarm->value = '50';
  $export['comment_default_per_page_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_xml_event_import';
  $strongarm->value = 1;
  $export['comment_form_location_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_xml_event_import';
  $strongarm->value = '1';
  $export['comment_preview_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_xml_event_import';
  $strongarm->value = 1;
  $export['comment_subject_field_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_xml_event_import';
  $strongarm->value = '2';
  $export['comment_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_xml_event_import';
  $strongarm->value = '0';
  $export['language_content_type_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_xml_event_import';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_xml_event_import';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_xml_event_import';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_xml_event_import';
  $strongarm->value = '1';
  $export['node_preview_xml_event_import'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_xml_event_import';
  $strongarm->value = 1;
  $export['node_submitted_xml_event_import'] = $strongarm;

  return $export;
}
