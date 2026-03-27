---
title: Amiga® Hardware Reference Manual: E I/O Connectors And Interfaces
manual: hardware
chapter: hardware
section: amiga-hardware-reference-manual-e-i-o-connectors-and
functions: []
libraries: []
---

# Amiga® Hardware Reference Manual: E I/O Connectors And Interfaces

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This appendix consists of four distinct parts, related to the way in which
the Amiga talks to the outside world.

The first part specifies the pinouts of the externally accessible
connectors and the power available at each connector. It does not,
however, provide timing or loading information.

The second part briefly describes the functions of those pins whose
purpose may not be evident.

The third part contains a list of the connections for certain internal
connectors, notably the disk.

The fourth part specifies how various signals relate to the available
ports of the 8520. This information enables the programmer to relate the
port addresses to the outside-world items (or internal control signals)
that are to be affected.

The third and fourth parts are primarily for the use of the systems
programmer and should generally not be utilized by applications
programmers.

Systems software normally is configured to handle the setting of
particular signals, no matter how the physical connections may change. In
other words, if you have a version of the system software that matches the
revision level of the machine (normally a true condition), when you ask
that a particular bit be set, you don't care which port that bit is
connected to. Thus, applications programmers should rely on system
documentation rather than going directly to the ports.

   Warning:
   --------
   In a multitasking operating system, many different tasks may be
   competing for the use of the system resources. Application
   programmers should follow the established rules for resource access
   in order to assure compatibility of their software with the system.
   Don't just hit the hardware registers directly, ask the system for
   exclusive control first.

 [Part 1 - Amiga I/O Connector Pins](hardware/e-i-o-connectors-and-interfaces-part-1-amiga-i-o-connector.md) 
 [Part 2 - Explanation of Amiga I/O Connectors](hardware/e-i-o-connectors-and-interfaces-explanation-of-amiga-i-o.md) 
 [Part 3 - Internal Connectors](hardware/e-i-o-connectors-and-interfaces-part-3-internal-connectors.md) 
 [Part 4 - Port Signal Assignments for 8520 CIAS](hardware/e-connectors-and-interfaces-port-signal-assignments-for.md) 

