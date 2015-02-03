<?php
/**
 * @file
 * Tweaker module integration.
 */

/**
 * Implements hook_tweaker_rules_action_info_alter() on behalf of
 * tweaker.module.
 */
function tweaker_tweaker_rules_action_info_alter(&$items) {
  $items['drupal_array_set_nested_value'] = array(
    'label'   => t('Array set nested value'),
    'parameter' => array(
      'data'   => array(
        'type'        => '*',
        'label'       => t('Array'),
        'restriction' => 'selector',
        'wrapped'     => TRUE,
        'allow null'  => TRUE,
      ),
      'parents' => array(
        'type'       => 'text',
        'label'      => t('Parents'),
        'allow null' => TRUE,
      ),
      'value'   => array(
        'type'        => 'text',
        'label'       => t('Data value'),
        'description' => t('The value to set.'),
        'allow null'  => TRUE,
      ),
    ),
    'group'   => t('Data'),
    'base'    => 'tweaker_rules_action_drupal_array_set_nested_value',
  );

//  $items['tweaker_callback'] = array(
//    'label'     => t('PHP callback'),
//    'group'     => t('Tweaker'),
//    'base'      => 'tweaker_rules_action_tweaker_callback',
//    'parameter' => array(
//      'function'  => array(
//        'type'         => 'text',
//        'label'        => t('Callback function'),
//        'options list' => 'tweaker_rules_action_options_tweaker_callback_function',
//      ),
//      'arguments' => array(
//        'type'     => 'text',
//        'label'    => t('Callback arguments'),
//        'optional' => TRUE,
//      ),
//    ),
//  );
}

/**
 * Implements hook_tweaker_rules_condition_info_alter() on behalf of
 * tweaker.module.
 */
function tweaker_tweaker_rules_condition_info_alter(&$items) {
  $items['drupal_array_nested_key_exists'] = array(
    'label' => t('Nested array key exists'),
    'parameter' => array(
      'array' => array(
        'type' => '*',
        'label' => t('Array'),
        'allow null' => TRUE,
      ),
      'parents' => array(
        'type' => 'text',
        'label' => t('Parents'),
        'allow null' => TRUE,
      ),
    ),
    'group' => t('Data'),
    'base' => 'tweaker_rules_condition_drupal_array_nested_key_exists',
  );

  $items['drupal_array_get_nested_value_is'] = array(
    'label' => t('Nested array data comparison'),
    'parameter' => array(
      'array' => array(
        'type' => '*',
        'label' => t('Array'),
        'allow null' => TRUE,
      ),
      'parents' => array(
        'type' => 'text',
        'label' => t('Parents'),
        'allow null' => TRUE,
      ),
      'op' => array(
        'type' => 'text',
        'label' => t('Operator'),
        'description' => t('The comparison operator.'),
        'optional' => TRUE,
        'default value' => '==',
        'options list' => 'rules_condition_data_is_operator_options',
        'restriction' => 'input',
      ),
      'value' => array(
        'type' => 'text',
        'label' => t('Data value'),
        'description' => t('The value to compare the data with.'),
        'allow null' => TRUE,
      ),
    ),
    'group' => t('Data'),
    'base' => 'tweaker_rules_condition_drupal_array_get_nested_value_is',
  );

  $items['drupal_array_get_nested_value_empty'] = array(
    'label' => t('Nested array value is empty'),
    'parameter' => array(
      'array' => array(
        'type' => '*',
        'label' => t('Array'),
        'allow null' => TRUE,
      ),
      'parents' => array(
        'type' => 'text',
        'label' => t('Parents'),
        'allow null' => TRUE,
      ),
    ),
    'group' => t('Data'),
    'base' => 'tweaker_rules_condition_drupal_array_get_nested_value_is_empty',
  );
}

/**
 *
 */
function tweaker_rules_action_drupal_array_set_nested_value($wrapper, $parents, $value, $settings, RulesState $state, RulesPlugin $element) {
  module_load_include('inc', 'rules', 'modules/data.eval');
  if ($wrapper instanceof EntityMetadataWrapper) {
    $data = $wrapper->value();
    drupal_array_set_nested_value($data, explode(':', $parents), $value);
  }
  else {
    // Do this.
  }
  rules_action_data_set($wrapper, $data, $settings, $state, $element);
}

///**
// * Rules action callback for 'tweaker_callback'.
// */
//function tweaker_rules_action_tweaker_callback($function, $arguments) {
//  if (function_exists($function)) {
//    call_user_func_array($function, array($arguments));
//  }
//}

// /**
//  * Options list for Rules 'tweaker_callback' action parameter 'function'.
//  */
// function tweaker_rules_action_options_tweaker_callback_function() {
//   return array(
//     'dpm' => 'dpm',
//     'ddebug_backtrace' => 'ddebug_backtrace',
//   );
// }

/**
 *
 */
function tweaker_rules_condition_drupal_array_nested_key_exists($array, $parents) {
  return drupal_array_nested_key_exists($array, explode(':', $parents));
}

/**
 *
 */
function tweaker_rules_condition_drupal_array_get_nested_value_is($array, $parents, $op, $value) {
  module_load_include('inc', 'rules', 'modules/data.eval');
  $data = drupal_array_get_nested_value($array, explode(':', $parents));
  return rules_condition_data_is($data, $op, $value);
}

/**
 *
 */
function tweaker_rules_condition_drupal_array_get_nested_value_is_empty($array, $parents) {
  $data = drupal_array_get_nested_value($array, explode(':', $parents));
  return empty($data);
}
