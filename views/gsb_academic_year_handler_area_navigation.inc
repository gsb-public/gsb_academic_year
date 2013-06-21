<?php

/**
 * @file
 * Contains gsb_academic_year_handler_area_navigation.
 */

/**
 * Provides navigation links based on academic year.
 */
class gsb_academic_year_handler_area_navigation extends views_handler_area {

  /**
   * {@inheritdoc}
   */
  function render($empty = FALSE) {
    $build = array();

    // Find the view path without the year argument.
    $path = $this->view->get_path();
    $bits = explode('/', $path);
    if ((int) array_pop($bits)) {
      $path = implode('/', $bits);
    }

    // Determine what remaining years are left.
    $values = array_values(gsb_academic_year_get_allowed_values());
    $key = array_search(reset($this->view->args), $values);
    if ($key > 0) {
      $build['prev'] = array(
        '#type' => 'link',
        '#title' => t('Previous Academic Year'),
        '#href' => $path . '/' . $values[$key - 1],
      );
    }
    if ($key < 2) {
      $build['next'] = array(
        '#type' => 'link',
        '#title' => t('Next Academic Year'),
        '#href' => $path . '/' . $values[$key + 1],
      );
    }
    return drupal_render($build);
  }

}
