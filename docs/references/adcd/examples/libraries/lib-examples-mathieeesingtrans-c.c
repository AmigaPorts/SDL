/* Source: ADCD 2.1
 * Section: lib-examples-mathieeesingtrans-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-mathieeesingtrans-c.md
 */

    {
    f1 = IEEEDPAsin(f2);        /* Call IEEESPAsin entry */
    f1 = IEEEDPAcos(f2);        /* Call IEEESPAcos entry */
    f1 = IEEEDPAtan(f2);        /* Call IEEESPAtan entry */
    f1 = IEEEDPSin(f2);         /* Call IEEESPSin entry */
    f1 = IEEEDPCos(f2);         /* Call IEEESPCos entry */
    f1 = IEEEDPTan(f2);         /* Call IEEESPTan entry */
    f1 = IEEEDPSincos(&f3, f2); /* Call IEEESPSincos entry */
    f1 = IEEEDPSinh(f2);        /* Call IEEESPSinh entry */
    f1 = IEEEDPCosh(f2);        /* Call IEEESPCosh entry */
    f1 = IEEEDPTanh(f2);        /* Call IEEESPTanh entry */
    f1 = IEEEDPExp(f2);         /* Call IEEESPExp entry */
    f1 = IEEEDPLog(f2);         /* Call IEEESPLog entry */
    f1 = IEEEDPLog10(f2);       /* Call IEEESPLog10 entry */
    f1 = IEEEDPPow(d2, f3);     /* Call IEEESPPow entry */
    f1 = IEEEDPSqrt(f2);        /* Call IEEESPSqrt entry */

    CloseLibrary(MathIeeeSingTransBase);
    }
