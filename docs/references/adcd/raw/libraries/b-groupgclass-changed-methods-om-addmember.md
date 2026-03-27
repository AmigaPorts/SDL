# B / groupgclass / Changed Methods: OM_ADDMEMBER


This method adds a gadget to the group object's list.  The group object
will increase the size of its select box to include the new gadget's
select box.  The group object moves the new member to an absolute location
(by changing the new member's [GA_Left](../Libraries_Manual_guide/node04FD.html) and [GA_Top](../Libraries_Manual_guide/node04FD.html) attributes) relative to
the group object's upper-left corner.  Note that all members of the
[groupgclass](../Libraries_Manual_guide/node052B.html) object will be deleted by [OM_DISPOSE](../Libraries_Manual_guide/node052F.html).

