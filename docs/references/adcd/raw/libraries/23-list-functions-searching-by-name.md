# 23 / List Functions / Searching by Name


Because many lists contain nodes with symbolic names attached (via the
[ln_Name](../Libraries_Manual_guide/node02D9.html#line38) field), it is possible to find a node by its name.  This naming
technique is used throughout Exec for such nodes as tasks, libraries,
devices, and resources.

The [FindName()](../Includes_and_Autodocs_2._guide/node034E.html) function searches a list for the first node with a given
name.  For example, FindName([header](../Libraries_Manual_guide/node02DD.html#line21), "Furrbol") returns a pointer to the
first node named "Furrbol." If no such node exists, a NULL is returned.
The case of the name characters is significant; "foo" is different from
"Foo."

  _______________________________________________________________________
 |   ___________       ___________       ___________       ___________   |
 |  |           |____\|           |____\|           |____\|           |__|
 |  |  lh_Head  |/_  /|  ln_Succ  |/_  /|  ln_Succ  |/_  /|  ln_Succ  |/_
 |  |___________|\ \  |___________|\ \  |___________|\ \  |___________|\ |
 |_\|           |   \ |           |   \ |           |   \ |           |  |
   /| lh_Tail=0 |    \|  ln_Pred  |    \|  ln_Pred  |    \|  ln_Pred  |  |

    |___________|     |___________|     |___________|     |___________|  |
    |           |     |           |     |           |     |           |  |
    |lh_TailPred|__   |  ln_Type  |     |  ln_Type  |     |  ln_Type  |  |
    |_ _ _ _ _ _|  |  |___________|     |___________|     |___________|  |
    |     |     |  |  |           |     |           |     |           |  |
    |     |     |  |  |  ln_Pri   |     |  ln_Pri   |     |  ln_Pri   |  |
    |_ _ _|_ _ _|  |  |___________|     |___________|     |___________|  |
                   |  |           |     |           |     |           |  |
                   |  |  ln_Name  |     |  ln_Name  |     |  ln_Name  |  |
                   |  |_ _ _ _ _ _|     |_ _ _ _ _ _|     |_ _ _ _ _ _|  |
                   |  |           |     |           |     |           |  |
                   |  |   Node    |     |   Node    |     |   Node    |  |
                   |  |  Content  |     |  Content  |     |  Content  |  |
                   |  |_ _ _ _ _ _|     |_ _ _ _ _ _|     |_ _ _ _ _ _|  |
                   |_____________________________________________________|


      Figure 23-4: Complete Sample List Showing all Interconnections
