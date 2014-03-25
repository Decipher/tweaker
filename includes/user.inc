<?php
/**
 * @file
 * User module integration.
 */

/**
 * Implements hook_tweaker_rules_event_info_alter() on behalf of user.module.
 */
function user_tweaker_rules_event_info_alter(&$items) {
  $items['user_access'] = array(
    'label'     => t('User menu access callback is being executed'),
    'group'     => t('User'),
    'variables' => array(
      'access'  => array(
        'label' => t('Access'),
        'type'  => 'reference<boolean>',
      ),
      'account' => array(
        'label' => t('Account'),
        'type'  => 'user',
      ),
    ),
  );
}

/**
 * Implements hook_tweaker_menu_alter() on behalf of user.module.
 */
function user_tweaker_menu_alter(&$items) {
  array_unshift($items['user/%user']['access arguments'], $items['user/%user']['access callback']);
  $items['user/%user']['access callback'] = 'tweaker_user_access';
}

/**
 * User access callback for hook_menu().
 */
function tweaker_user_access() {
  $args            = func_get_args();
  $access_callback = array_shift($args);

  $account = end($args);

  // Invoke rules event.
  $access        = new stdClass();
  $access->value = NULL;
  rules_invoke_event('user_access', $access, $account);
  if (!is_null($access->value)) {
    return $access->value;
  }

  // Pass back to the original access callback.
  if (function_exists($access_callback)) {
    return call_user_func_array($access_callback, $args);
  }

  return $access_callback;
}
