<?php
/**
 *@file contains the configuration settings for User menu dropdown module.
 */
function user_menu_dropdown_admin_settings_form($form, &$form_state) {
  $roles = user_roles(); 
  $menus = menu_get_menus(); 
  $checked_roles = variable_get('user_menu_dropdown_selected_roles', array());
  $checked_menus = variable_get('user_menu_dropdown_selected_menus', array());
  dpm($checked_menus);
  $menus_checkbox_ticked = array();
  $roles_checkbox_ticked = array();
  if (!empty($checked_menus)) {
    foreach ($checked_menus as $key => $value) {
      if ($value != '0') {
        $menus_checkbox_ticked[] = $key;
      }
    }
  }

  if (!empty($checked_roles)) {
    foreach ($checked_roles as $key => $value) {
      if ($value != 0) {
        $roles_checkbox_ticked[] = $key;
      }
    }
  }
  $form['selected_menus'] = array(
    '#type' => 'checkboxes',
    '#options' => $menus,
    '#required' => TRUE,
    '#title' => t('Roles of the users you would like to include in the drop down link'),
    '#default_value' => $menus_checkbox_ticked,
  );

  $form['selected_roles'] = array(
    '#type' => 'checkboxes',
    '#options' => $roles,
    '#title' => t('Roles of the users you would like to include in the drop down link'),
    '#default_value' => $roles_checkbox_ticked
  );

  $form['user_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of users to be displayed on Menu dropdown'),
    '#required' => TRUE,
    '#default_value' => variable_get('user_menu_dropdown_user_limit', 10),
    '#description' => "Please max number of users to be displayed.",
    '#size' => 3,
    '#maxlength' => 3,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['submit'] = array(
    '#type' => t('submit'),
    '#value' => t('Save settings'),
  );
  return $form;
}

/*function up_admin_settings_form_validate($form, &$form_state) {
  element_validate_integer_positive(, $form_state);
}*/

function user_menu_dropdown_admin_settings_form_submit($form, &$form_state) {

  variable_set('user_menu_dropdown_selected_roles', $form_state['values']['selected_roles']);
  variable_set('user_menu_dropdown_user_limit', $form_state['values']['user_limit']);
  variable_set('user_menu_dropdown_selected_menus', $form_state['values']['selected_menus']);
  //$menus = $form_state['values']['selected_menus'];
  //dpm(user_menu_dropdown_get_selected_users());
  //$all_menus = menu_get_menus();

  /*$submenu = array(
           array(
             'menu_name' => 'menu_test_one',
             'title' => 'My Menu One',
             'description' => 'Lorem Ipsum',
            ),
            array(
              'menu_name' => 'menu_test_two',
              'title' => 'My Menu Two',
              'description' => 'Lorem Ipsum',
            ),
            array(
              'menu_name' => 'menu_test_three',
              'title' => 'My Menu Three',
              'description' => 'Lorem Ipsum',
            ),
          ); */ 
  /*foreach ($menus as $key => $value) {
    $item_exists = FALSE;
    if ($value != '0') {
      $menu_links = menu_navigation_links($key);
      foreach ($menu_links as $link_key => $link_value) {
        if ($link_key['href'] == '/users/list') {
        }
      }
    }
  }
  menu_navigation_links('first-menu');*/
  drupal_set_message(t('The settings have been saved!'));

}

