<?php
/**
 * @file
 */

/**
 *
 */
function tweaker_ui_conditions_callback(&$form, &$form_state, $condition) {
  $info = tweaker_get_info();

  $form['function'] = array(
    '#title' => t('Function'),
    '#type' => 'select',
    '#options' => $info['conditions']['callback']['arguments']['function'],
    '#default_value' => isset($condition['function']) ? $condition['function'] : '',
  );

  $form['arguemnts'] = array(
    '#type' => 'container',
  );

  // Arguments.
  switch ($condition['function']) {
    case 'preg_match':
      $form['arguments'][0]['type'] = array(
        '#type' => 'value',
        '#value' => 'regex',
      );
      tweaker_ui_arguments_attach($form['arguments'][0], $form_state, 'regex', $condition['arguments'][0]);

      $form['arguments'][1]['type'] = array(
        '#type' => 'value',
        '#value' => 'variable',
      );
      tweaker_ui_arguments_attach($form['arguments'][1], $form_state, 'variable', $condition['arguments'][1]);
      break;

    case 'isset':
      $form['arguments'][0]['type'] = array(
        '#type' => 'value',
        '#value' => 'variable',
      );
      $form['arguments'][0]['value'] = array(
        '#type' => 'select',
        '#options' => $info['hooks'][$form_state['item']->hook]['arguments'],
        '#default_value' => $condition['arguments'][0]['value'],
      );
      $form['arguments'][0]['index'] = array(
        '#type' => 'textfield',
        '#default_value' => $condition['arguments'][0]['index'],
      );
      break;
  }
}
