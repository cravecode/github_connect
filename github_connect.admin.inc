<?php


/**
 * @file
 * Administration page callbacks for the GitHub connect module.
 */

/**
 * Implements hook_admin_settings().
 */
function github_connect_admin_settings_form($form_state) {

  $form['github_connect_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Github settings'),
    '#description' => t('Fill in the form below. You will first have to create an application at https://github.com/account/applications/new. Main URL should be set to your domain name and Callback URL to your domain name /github/register/create (http://example.com/github/register/create). After saving the application you will be given the Client ID and Client secret.'),
  );

  $form['github_connect_settings']['github_connect_client_id'] = array(
    '#title' => t('Client ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('github_connect_client_id'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );

  $form['github_connect_settings']['github_connect_client_secret'] = array(
    '#title' => t('Client secret'),
    '#type' => 'textfield',
    '#default_value' => variable_get('github_connect_client_secret'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );
  
  $form['github_connect_settings'][OAuthScope::$variableName] = array(
    '#title' => t('Required Scopes'),
    '#type' => 'checkboxes',
    '#theme' => 'github_connect_checkboxes',
  );
  foreach(OAuthScope::getScopeOptions() as $key => $value) {
    $form['github_connect_settings'][OAuthScope::$variableName]['#options'][$key] = 0;
  }
  
  $form = system_settings_form($form);
  return $form;
}

function theme_github_connect_checkboxes($variables) {
  
  $elements = array();
  foreach($variables as $key => $settings) {
    $name = OAuthScope::$variableName . '[' . $key . ']';
    $elements[] = array(
      '#attributes' => array(
        'name' => $name,
        'id' => drupal_clean_css_identifier($name),
      ),
      '#type' => 'checkbox',
      '#return_value' => $key,
      '#title' => $settings['title'],
      '#parents' => array(OAuthScope::$variableName),
      '#description' => $settings['description'],
    );
  }
  
  return drupal_render($elements);
}




