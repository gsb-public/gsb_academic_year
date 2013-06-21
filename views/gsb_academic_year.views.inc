<?php

/**
 * Implements hook_views_data().
 */
function gsb_academic_year_views_data() {
  $data = array();
  $data['gsb_academic_year']['table'] = array(
    'group' => t('GSB Academic Year'),
    'join' => array('#global' => array()),
  );
  $data['gsb_academic_year']['navigation'] = array(
    'title' => t('Navigation'),
    'help' => t('Provides navigation between academic years'),
    'area' => array(
      'handler' => 'gsb_academic_year_handler_area_navigation',
    ),
  );
  return $data;
}
