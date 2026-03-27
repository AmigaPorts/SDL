---
title: 27 / / Monitors, Modes and the Display Database / ModeID Identifiers
manual: libraries
chapter: libraries
section: 27-monitors-modes-and-the-display-database-modeid
functions: []
libraries: []
---

# 27 / / Monitors, Modes and the Display Database / ModeID Identifiers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following definitions appear in the include file
<graphics/[displayinfo.h](autodocs-2.0/includes-graphics-displayinfo-h.md)>.  These values form the 32-bit ModeID which
consists of a _MONITOR_ID in the upper word, and a _MODE_KEY in the lower
word.  Never interpret these bits directly.  Instead use them with the
display database to obtain the information you need about the display mode.


    /* normal identifiers */

    #define MONITOR_ID_MASK                         0xFFFF1000

    #define DEFAULT_MONITOR_ID                      0x00000000
    #define NTSC_MONITOR_ID                         0x00011000
    #define PAL_MONITOR_ID                          0x00021000

    /* the following 20 composite keys are for Modes on the default */
    /* Monitor NTSC & PAL "flavors" of these particular keys may be */
    /* made by OR'ing  the NTSC or PAL MONITOR_ID with the desired  */
    /* MODE_KEY... */

    #define LORES_KEY                               0x00000000
    #define HIRES_KEY                               0x00008000
    #define SUPER_KEY                               0x00008020
    #define HAM_KEY                                 0x00000800
    #define LORESLACE_KEY                           0x00000004
    #define HIRESLACE_KEY                           0x00008004
    #define SUPERLACE_KEY                           0x00008024
    #define HAMLACE_KEY                             0x00000804
    #define LORESDPF_KEY                            0x00000400
    #define HIRESDPF_KEY                            0x00008400
    #define SUPERDPF_KEY                            0x00008420
    #define LORESLACEDPF_KEY                        0x00000404
    #define HIRESLACEDPF_KEY                        0x00008404
    #define SUPERLACEDPF_KEY                        0x00008424
    #define LORESDPF2_KEY                           0x00000440
    #define HIRESDPF2_KEY                           0x00008440
    #define SUPERDPF2_KEY                           0x00008460
    #define LORESLACEDPF2_KEY                       0x00000444
    #define HIRESLACEDPF2_KEY                       0x00008444
    #define SUPERLACEDPF2_KEY                       0x00008464
    #define EXTRAHALFBRITE_KEY                      0x00000080
    #define EXTRAHALFBRITELACE_KEY                  0x00000084

    /* vga identifiers */

    #define VGA_MONITOR_ID                          0x00031000

    #define VGAEXTRALORES_KEY                       0x00031004
    #define VGALORES_KEY                            0x00039004
    #define VGAPRODUCT_KEY                          0x00039024
    #define VGAHAM_KEY                              0x00031804
    #define VGAEXTRALORESLACE_KEY                   0x00031005
    #define VGALORESLACE_KEY                        0x00039005
    #define VGAPRODUCTLACE_KEY                      0x00039025
    #define VGAHAMLACE_KEY                          0x00031805
    #define VGAEXTRALORESDPF_KEY                    0x00031404
    #define VGALORESDPF_KEY                         0x00039404
    #define VGAPRODUCTDPF_KEY                       0x00039424
    #define VGAEXTRALORESLACEDPF_KEY                0x00031405
    #define VGALORESLACEDPF_KEY                     0x00039405
    #define VGAPRODUCTLACEDPF_KEY                   0x00039425
    #define VGAEXTRALORESDPF2_KEY                   0x00031444
    #define VGALORESDPF2_KEY                        0x00039444
    #define VGAPRODUCTDPF2_KEY                      0x00039464
    #define VGAEXTRALORESLACEDPF2_KEY               0x00031445
    #define VGALORESLACEDPF2_KEY                    0x00039445
    #define VGAPRODUCTLACEDPF2_KEY                  0x00039465
    #define VGAEXTRAHALFBRITE_KEY                   0x00031084
    #define VGAEXTRAHALFBRITELACE_KEY               0x00031085

    /* a2024 identifiers */

    #define A2024_MONITOR_ID                        0x00041000

    #define A2024TENHERTZ_KEY                       0x00041000
    #define A2024FIFTEENHERTZ_KEY                   0x00049000

    /* prototype identifiers */

    #define PROTO_MONITOR_ID                        0x00051000
