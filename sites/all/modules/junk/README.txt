$Id

-- SUMMARY --

The Junk module adds the ability to move a node to junk before deleting permanently. It integrates with CTools Page Manager, Views and Rules modules.

For a full description of the module, visit the project page:
  http://drupal.org/project/junk

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/junk


-- REQUIREMENTS --

The Junk module is dependent on CTools which you can download here:
  http://drupal.org/project/ctools


-- INSTALLATION --

Install as usual along with CTools (CTools core and CTools Page Manager are required), see http://drupal.org/node/70151 for further information.

If you have any other modules using CTools Page Manager installed (Panels for example) then after installation of Junk navigate to 'admin/build/pages/' and make sure that 'node view' and 'node edit' templates are ordered properly. That means that on 'admin/build/pages/edit/node_view' (in case of 'node view' template) the Junk template should have the highest priority. Same with 'node edit'.

-- CONFIGURATION --

* Configure user permissions in Administer >> User management >> Permissions >>
  junk module:

  - administer junk

    Users in roles with the "administer junk" permission will be able to edit Junk module settings

  - clear junk

    Users in roles with the "clear junk" permission will be able access junk page and delete junked nodes

  - junk any node
    
    Users in roles with the "junk any node" permission will be able to put nodes to junk

* Customize the Junk settings in Administer >> Site configuration >>
  Junk settings.


-- TROUBLESHOOTING --

* If the junked node is accessable to all users:

  - Check: If you have any other modules using CTools Page Manager installed (Panels for example) then navigate to 'admin/build/pages/' and make sure that 'node view' and 'node edit' templates are ordered properly. That means that on 'admin/build/pages/edit/node_view' (in case of 'node view' template) the Junk template should have the highest priority. Same with 'node edit'.

