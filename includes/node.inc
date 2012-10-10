<?php
/**
 * @file
 * Node module integration.
 */

/**
 * Implements hook_tweaker_rules_event_info_alter() on behalf of node.module.
 */
function node_tweaker_rules_event_info_alter(&$items) {
  $items['node_access'] = array(
    'label' => t('Node access callback is being executed'),
    'group' => t('Node'),
    'variables' => array(
      'access' => array(
        'label' => t('Access'),
        'type' => 'reference<boolean>',
      ),
      'node' => array(
        'label' => t('Node'),
        'type' => 'node',
      ),
      'op' => array(
        'label' => t('Operation'),
        'type' => 'text',
      ),
      'account' => array(
        'label' => t('Account'),
        'type' => 'user',
      ),
    ),
  );
}

/**
 * Implements hook_node_access().
 */
function tweaker_node_access($node, $op, $account) {
  $node = is_object($node) ? $node : (object) array('type' => $node);
  $access = new stdClass();
  $access->value = NODE_ACCESS_IGNORE;
  rules_invoke_event('node_access', $access, $node, $op, $account);

  // Return access value.
  if ($access->value !== NODE_ACCESS_IGNORE) {
    return $access->value == TRUE ? NODE_ACCESS_ALLOW : NODE_ACCESS_DENY;
  }
  return $access->value;
}
