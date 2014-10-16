<?php
/**
 * @file
 * thisted_event_import.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function thisted_event_import_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function thisted_event_import_node_info() {
  $items = array(
    'xml_event_import' => array(
      'name' => t('Xml event import'),
      'base' => 'node_content',
      'description' => t('Import events from  thy360.dk'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
