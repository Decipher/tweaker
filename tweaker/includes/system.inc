<?php
/**
 * @file
 * System module integration.
 */

/**
 * Implements hook_tweaker_info() on behalf of system.module.
 */
function system_tweaker_info() {
  return array(

    // Hooks.
    'hooks' => array(
      'form_alter' => array(
        'arguments' => array(
          '&$form' => 'form',
          '&$form_state' => 'form_state',
          '$form_id' => 'form_id',
        ),
      ),
      'menu_alter' => array(
        'arguments' => array(
          '&$items' => 'items',
        ),
      ),
      'preprocess' => array(
        'arguments' => array(
          '&$variables' => 'variables',
          '$hook' => 'hook',
        ),
      ),
    ),

    // Arguments.
    'arguments' => array(
      'string' => array(

      ),
      'regex' => array(
        'callback' => 'tweaker_ui_arguments_regex',
        'file' => drupal_get_path('module', 'tweaker_ui') . '/includes/tweaker.arguments.inc',
      ),
      'variable' => array(
        'callback' => 'tweaker_ui_arguments_variable',
        'file' => drupal_get_path('module', 'tweaker_ui') . '/includes/tweaker.arguments.inc',
      ),
    ),

    // Conditions.
    'conditions' => array(
      'callback' => array(
        'title' => t('Callback'),
        'arguments' => array(
          'function' => array(
            'isset' => 'isset()',
            'preg_match' => 'preg_match()',
          ),
        ),
        'callbacks' => array(
          'settings form' => 'tweaker_ui_conditions_callback',
        ),
        'file' => drupal_get_path('module', 'tweaker_ui') . '/includes/tweaker.conditions.inc',
      ),
    ),
  );
}
