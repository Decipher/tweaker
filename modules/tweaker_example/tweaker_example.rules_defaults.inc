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
  $items['rules_deny_access_nid_1'] = entity_import('rules_config', '{ "rules_deny_access_nid_1" : {
      "LABEL" : "Deny access to NID 1",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "Tweaker example" ],
      "REQUIRES" : [ "rules", "tweaker" ],
      "ON" : [ "node_access" ],
      "IF" : [
        { "data_is" : { "data" : [ "op" ], "value" : "view" } },
        { "data_is" : { "data" : [ "node:nid" ], "value" : "1" } }
      ],
      "DO" : [ { "data_set" : { "data" : [ "access:value" ], "value" : 0 } } ]
    }
  }');
  $items['rules_menu_alias'] = entity_import('rules_config', '{ "rules_menu_alias" : {
      "LABEL" : "Menu or URL alias",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "Tweaker example" ],
      "REQUIRES" : [ "rules", "tweaker" ],
      "ON" : [ "form_validate" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "form:#node" ],
            "type" : { "value" : { "article" : "article" } }
          }
        },
        { "drupal_array_get_nested_value_empty" : { "array" : [ "form-state" ], "parents" : "values:menu:enabled" } },
        { "drupal_array_get_nested_value_empty" : { "array" : [ "form-state" ], "parents" : "values:path:alias" } }
      ],
      "DO" : [
        { "form_set_error" : {
            "name" : "menu[enabled]",
            "message" : "A menu entry or a manual URL alias is required."
          }
        }
      ]
    }
  }');
  return $items;
}
