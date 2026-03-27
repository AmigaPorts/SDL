/* Source: ADCD 2.1
 * Section: layers-library-locklayerinfo
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/layers-library-locklayerinfo.md
 */

    Before doing an operation that requires the LayerInfo
    structure, make sure that no other task is also using the
    LayerInfo structure.  LockLayerInfo() returns when the
    LayerInfo belongs to this task.  There should be
    an [UnlockLayerInfo](../Includes_and_Autodocs_2._guide/node03A7.html) for every LockLayerInfo.

    Note: All layer routines presently LockLayerInfo() when they
    start up and [UnlockLayerInfo()](../Includes_and_Autodocs_2._guide/node03A7.html) as they exit.  Programmers
    will need to use these Lock/Unlock routines if they wish
    to do something with the LayerStructure that is not
    supported by the layer library.
