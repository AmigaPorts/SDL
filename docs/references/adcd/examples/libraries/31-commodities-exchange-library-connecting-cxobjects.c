/* Source: ADCD 2.1
 * Section: 31-commodities-exchange-library-connecting-cxobjects
 * Library: libraries
 * ADCD reference: libraries/31-commodities-exchange-library-connecting-cxobjects.md
 */

    void AttachCxObj ( CxObj *headobj, CxObj *co);
    void InsertCxObj ( CxObj *headobj, CxObj *co, CxObj *co_pred );
    void EnqueueCxObj( CxObj *headobj, CxObj *co );
    void SetCxObjPri ( CxObj *co, long pri );
    void RemoveCxObj ( CxObj *co );
