---
title: 23 / List Functions / Searching by Name
manual: libraries
chapter: libraries
section: 23-list-functions-searching-by-name
functions: [FindName]
libraries: [exec.library]
---

# 23 / List Functions / Searching by Name

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Because many lists contain nodes with symbolic names attached (via the
[ln_Name](libraries/23-list-structure-node-structure-definition.md) field), it is possible to find a node by its name.  This naming
technique is used throughout Exec for such nodes as tasks, libraries,
devices, and resources.

The [FindName()](autodocs-2.0/exec-library-findname.md) function searches a list for the first node with a given
name.  For example, FindName([header](libraries/23-exec-lists-and-queues-list-functions.md), "Furrbol") returns a pointer to the
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

---

## See Also

- [FindName — exec.library](../autodocs/exec.library.md#findname)
