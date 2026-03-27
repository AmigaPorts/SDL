/* Source: ADCD 2.1
 * Section: include-devices-cd-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-devices-cd-h.md
 */

    struct MinNode    Node;	       /* double linkage		  */
    char	     *Buffer;	       /* data destination (word aligned) */
    LONG	      Length;	       /* must be even # bytes		  */
    LONG	      Actual;	       /* bytes transferred		  */
    APTR	      IntData;	       /* interrupt server data segment   */
    VOID	      (*IntCode)();    /* interrupt server code entry	  */
    };
