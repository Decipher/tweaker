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
  $items['tweaker_callback'] = array(
    'label' => t('PHP callback'),
    'group' => t('Tweaker'),
    'base' => 'tweaker_rules_action_tweaker_callback',
    'parameter' => array(
      'function' => array(
        'type' => 'text',
        'label' => t('Callback function'),
        'options list' => 'tweaker_rules_action_options_tweaker_callback_function',
      ),
      'arguments' => array(
        'type' => 'text',
        'label' => t('Callback arguments'),
        'optional' => TRUE,
      ),
    ),
  );
}

/**
 * Implements hook_tweaker_rules_data_info_alter() on behalf of tweaker.module.
 */
function tweaker_tweaker_rules_data_info_alter(&$items) {
  $items['array'] = array(
    'label' => t('array'),
  );
}

/**
 * Rules action callback for 'tweaker_callback'.
 */
function tweaker_rules_action_tweaker_callback($function, $arguments) {
  if (function_exists($function)) {
    call_user_func_array($function, array($arguments));
  }
}

/**
 * Options list for Rules 'tweaker_callback' action parameter 'function'.
 */
function tweaker_rules_action_options_tweaker_callback_function() {
  return array(
    'dpm' => 'dpm',
    'ddebug_backtrace' => 'ddebug_backtrace',
  );
}
