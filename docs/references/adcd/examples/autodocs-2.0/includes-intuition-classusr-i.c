/* Source: ADCD 2.1
 * Section: includes-intuition-classusr-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-classusr-i.md
 */

    ENUM $101
    EITEM OM_NEW		; 'object' parameter is "true class"
    EITEM OM_DISPOSE		; delete self (no parameters)
    EITEM OM_SET		; set attribute (list)
    EITEM OM_GET		; return single attribute value
    EITEM OM_ADDTAIL		; add self to a List
    EITEM OM_REMOVE		; remove self from list (no parameters)
    EITEM OM_NOTIFY		; send to self: notify dependents
    EITEM OM_UPDATE		; notification message from someone
    EITEM OM_ADDMEMBER		; used by various classes with lists
    EITEM OM_REMMEMBER		; used by various classes with lists
