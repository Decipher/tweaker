<?php
/**
 * @file
 * Devel module integration.
 */

/**
 * Implements hook_tweaker_rules_action_info_alter() on behalf of devel.module.
 */
function devel_tweaker_rules_action_info_alter(&$items) {
  $items['devel_debug_backtrace'] = array(
    'label' => t('Debug backtrace'),
    'group' => t('Devel'),
    'base' => 'tweaker_rules_action_devel_debug_backtrace',
  );
}

/**
 * Rules action callback for 'devel_ddebug_backtrace'.
 */
function tweaker_rules_action_devel_debug_backtrace() {
  ddebug_backtrace();
}
