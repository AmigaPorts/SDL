/* Source: ADCD 2.1
 * Section: 23-list-structure-node-structure-definition
 * Library: libraries
 * ADCD reference: libraries/23-list-structure-node-structure-definition.md
 */

    struct Interrupt
    {
        struct Node is_Node;
        APTR        is_Data;
        VOID        (*is_Code)();
    };
