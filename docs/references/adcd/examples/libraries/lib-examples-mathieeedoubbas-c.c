/* Source: ADCD 2.1
 * Section: lib-examples-mathieeedoubbas-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-mathieeedoubbas-c.md
 */

    {

    i1 = IEEEDPFix(d1);                /* Call IEEEDPFix entry */
    fi = IEEEDPFlt(i1);                /* Call IEEEDPFlt entry */
    switch (IEEEDPCmp(d1, d2)) {};     /* Call IEEEDPCmp entry */
    switch (IEEEDPTst(d1)) {};         /* Call IEEEDPTst entry */
    d1 = IEEEDPAbs(d2);                /* Call IEEEDPAbs entry */
    d1 = IEEEDPNeg(d2);                /* Call IEEEDPNeg entry */
    d1 = IEEEDPAdd(d2, d3);            /* Call IEEEDPAdd entry */
    d1 = IEEEDPSub(d2, d3);            /* Call IEEEDPSub entry */
    d1 = IEEEDPMul(d2, d3);            /* Call IEEEDPMul entry */
    d1 = IEEEDPDiv(d2, d3);            /* Call IEEEDPDiv entry */
    d1 = IEEEDPCeil(d2);               /* Call IEEEDPCeil entry */
    d1 = IEEEDPFloor(d2);              /* Call IEEEDPFloor entry */

    CloseLibrary(MathIeeeDoubBasBase);
    }
