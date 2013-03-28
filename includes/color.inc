<?php
/**
 * @file
 * Color module integration.
 */

/**
 * Implements hook_tweaker_rules_data_info_alter() on behalf of color.module.
 */
function color_tweaker_rules_action_info_alter(&$items) {
  $items['color_set'] = array(
    'label' => t('Set color scheme'),
    'group' => t('Color'),
    'parameter' => array(
      'scheme' => array(
        'type' => 'text',
        'label' => t('Scheme'),
      ),
    ),
    'base' => 'tweaker_rules_action_color_set',
  );
}

/**
 * Rules action callback for 'color_set'.
 */
function tweaker_rules_action_color_set($scheme) {
  $theme = variable_get('theme_default', NULL);

  $form = array();
  $form_state['values'] = array(
    'theme' => $theme,
    'info' => color_get_info($theme),
    'scheme' => $scheme,
  );
  $form_state['values']['palette'] = $form_state['values']['info']['schemes'][$scheme]['colors'];

  color_scheme_form_submit($form, $form_state);
}
