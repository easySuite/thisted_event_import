<?php
/**
 * @file
 * thisted_event_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function thisted_event_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'thisted';
  $feeds_importer->config = array(
    'name' => 'Thisted',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '300',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:1' => '../../title[text()]',
          'xpathparser:2' => '../../created[text()]',
          'xpathparser:3' => '../../deleted[text()]',
          'xpathparser:4' => '../../entrancefee[text()]',
          'xpathparser:5' => 'date[text()]',
          'xpathparser:6' => 'endtime[text()]',
          'xpathparser:7' => '../../intro[text()]',
          'xpathparser:8' => '../../description[text()]',
          'xpathparser:9' => '../../categories/category[1]/name[text()]',
          'xpathparser:10' => '../../files',
          'xpathparser:12' => 'uniqueid[text()]',
          'xpathparser:13' => '../../organizer/id[text()]',
          'xpathparser:14' => '../../place2book[text()]',
          'xpathparser:15' => '../../internal[text()]',
          'xpathparser:21' => '../../location/address/address[text()]',
          'xpathparser:17' => '../../location/address/address[text()]',
          'xpathparser:18' => '../../location/address/zipcode[text()]',
          'xpathparser:19' => '../../location/address/city[text()]',
          'xpathparser:20' => '../../location/name[text()]',
          'xpathparser:22' => '../../links/link/url[text()]',
        ),
        'rawXML' => array(
          'xpathparser:10' => 'xpathparser:10',
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:21' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:20' => 0,
          'xpathparser:22' => 0,
        ),
        'context' => '//event/dates/date',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:21' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:20' => 0,
            'xpathparser:22' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'status',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_ding_event_price',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_ding_event_date:start',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_ding_event_date:end',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_ding_event_lead',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_ding_event_body',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_ding_event_category',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_ding_event_list_image',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:12',
            'target' => 'guid',
            'unique' => 1,
          ),
          11 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_organizer_id',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_place2book_tickets',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_internal',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_ding_event_location:name_line',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_ding_event_location:thoroughfare',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_ding_event_location:postal_code',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_ding_event_location:locality',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_ding_event_location:first_name',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:22',
            'target' => 'url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'ding_wysiwyg',
        'skip_hash_check' => 1,
        'bundle' => 'ding_event',
      ),
    ),
    'content_type' => 'xml_event_import',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['thisted'] = $feeds_importer;

  return $export;
}
