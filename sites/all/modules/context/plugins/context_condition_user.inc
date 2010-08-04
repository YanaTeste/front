<?php
// $Id: context_condition_user.inc,v 1.1.2.6 2010/07/28 22:02:42 yhahn Exp $

/**
 * Expose current user role as a context condition.
 */
class context_condition_user extends context_condition {
  function condition_values() {
    $values = array();
    foreach (user_roles() as $rid => $role_name) {
      if ($rid == DRUPAL_ANONYMOUS_RID) {
        $values['anonymous user'] = $role_name;
      }
      elseif ($rid == DRUPAL_AUTHENTICATED_RID) {
        $values['authenticated user'] = $role_name;
      }
      else {
        $values[$role_name] = $role_name;
      }
    }
    return $values;
  }

  function execute($account) {
    $roles = $account->roles;
    foreach ($roles as $rid => $role) {
      foreach ($this->get_contexts($role) as $context) {
        $this->condition_met($context, $role);
      }
    }
  }
}
