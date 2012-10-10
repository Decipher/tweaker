<?php
/**
 * @file
 * tweaker_example.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function tweaker_example_default_rules_configuration() {
  $items = array();
  $items['rules_blank_frontpage'] = entity_import('rules_config', '{ "rules_blank_frontpage" : {
      "LABEL" : "Blank frontpage",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "Tweaker example" ],
      "REQUIRES" : [ "rules", "tweaker" ],
      "ON" : [ "menu_alter" ],
      "IF" : [ { "data_is" : { "data" : [ "path" ], "value" : "node" } } ],
      "DO" : [
        { "data_set" : { "data" : [ "item:page callback" ], "value" : "strrev" } },
        { "data_set" : { "data" : [ "item:page arguments:0" ] } }
      ]
    }
  }');
  return $items;
}
