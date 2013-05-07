<?php

class OAuthScope {
  
  public static $variableName = 'github_connect_scopes';
  
  
  
  
  public static function getRequiredScopes() {
    $scopes = variable_get(self::$variableName);
    $required_scopes = array();
    
    foreach($scopes as $key => $value) {
      if ($value) {
        $required_scopes[] = $value;
      }
    }
    
    return $required_scopes;
  }

 /**
 * Returns an array of the possible scope values for the GitHub v3 API.
 * @return Array [key:[title:String,description:String]]
 */
  public static function getScopeOptions() {
    return array(
      'user' => array(
        'title' => t('User'),
        'description' => t('Read/write access to profile info only. Note: this scope includes user:email and user:follow.')
      ),
      'user:email' => array(
        'title' => t('User Email'),
        'description' => t('Read access to a user’s email addresses.')
      ),
      'user:follow' => array(
        'title' => t('User Follow'),
        'description' => t('Access to follow or unfollow other users.')
      ),
      'public_repo' => array(
        'title' => t('Public Repositories/Organizations'),
        'description' => t('Read/write access to public repos and organizations.')
      ),
      'repo' => array(
        'title' => t('Repositories/Organizations'),
        'description' => t('Read/write access to public and private repos and organizations.')
      ),
      'repo:status' => array(
        'title' => t('Repository Status'),
        'description' => t('Read/write access to public and private repository commit statuses. This scope is only necessary to grant other users or services access to private repository commit statuses without granting access to the code. The "repo" and "public_repo" scopes already include access to commit status for private and public repositories respectively.')
      ),
      'delete_repo' => array(
        'title' => t('Delete Repositories/Organizations'),
        'description' => t('Delete access to adminable repositories.')
      ),
      'notifications' => array(
        'title' => t('Notifications'),
        'description' => t('Read access to a user’s notifications. "repo" is accepted too.')
      ),
      'gist' => array(
        'title' => t('Gist'),
        'description' => t('Write access to gists.')
      ),
    );
  }

}