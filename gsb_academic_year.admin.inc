<?php

/**
 * @file
 * Provides administrative pages for GSB Academic Year.
 */

/**
 * Form constructor for the academic year settings form.
 *
 * @see gsb_academic_year_settings_form_validate()
 * @see gsb_academic_year_settings_form_submit()
 */
function gsb_academic_year_settings_form(array $form, array &$form_state) {
  $form['gsb_academic_year'] = array(
    '#type' => 'select',
    '#title' => t('Current academic year'),
    '#options' => gsb_academic_year_get_allowed_labels(),
    '#default_value' => gsb_academic_year_get_value(),
  );
  $form['#validate'][] = 'gsb_academic_year_settings_form_validate';
  $form['#submit'][] = 'gsb_academic_year_settings_form_submit';
  return system_settings_form($form, $form_state);
}

/**
 * Form validation handler for gsb_academic_year_settings_form().
 *
 * @see gsb_academic_year_settings_form_submit()
 */
function gsb_academic_year_settings_form_validate(array &$form, array &$form_state) {
  $year = $form_state['values']['gsb_academic_year'];
  $query = new EntityFieldQuery();
  $result = $query
    ->fieldCondition('field_academic_year', 'value', gsb_academic_year_get_allowed_values($year), 'NOT IN')
    ->range(0, 1)
    ->execute();
  if (!empty($result)) {
    form_error($form['gsb_academic_year'], t('The academic year cannot be changed until all previous events have been deleted.'));
  }
}

/**
 * Form submission handler for gsb_academic_year_settings_form().
 *
 * @see gsb_academic_year_settings_form_validate()
 */
function gsb_academic_year_settings_form_submit(array &$form, array &$form_state) {
  views_invalidate_cache();
}
