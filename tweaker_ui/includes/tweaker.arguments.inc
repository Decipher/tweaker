<?php
/**
 * #file
 */

function tweaker_ui_arguments_regex(&$form, &$form_state, $value) {
  $form['value'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($value['value']) ? $value['value'] : '',
    '#description' => 'Regex description',
  );
}

function tweaker_ui_arguments_variable(&$form, &$form_state, $value) {
  $info = tweaker_get_info();

  $form['value'] = array(
    '#type' => 'select',
    '#options' => array(),
    '#default_value' => isset($value['value']) ? $value['value'] : '',
    '#description' => 'Variable description',
  );
  foreach (array_values($info['hooks'][$form_state['item']->hook]['arguments']) as $key) {
    $form['value']['#options'][$key] = $key;
  }

  $form['index'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($value['index']) ? $value['index'] : '',
    '#description' => 'Variable index description',
  );
}
