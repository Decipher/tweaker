<?php
/**
 * @file
 * Rules module integration.
 */

/**
 * Implements hook_rules_action_info().
 */
function tweaker_rules_action_info() {
  $items = array();
  drupal_alter('tweaker_rules_action_info', $items);
  return $items;
}

/**
 * Implements hook_rules_data_info().
 */
function tweaker_rules_data_info() {
  $items = array();
  drupal_alter('tweaker_rules_data_info', $items);
  return $items;
}

/**
 * Implements hook_rules_event_info().
 */
function tweaker_rules_event_info() {
  $items = array();
  drupal_alter('tweaker_rules_event_info', $items);
  return $items;
}
