---
title: 2 / User Interfaces / Elements of the Graphical User Interface System
manual: libraries
chapter: libraries
section: 2-user-interfaces-elements-of-the-graphical-user-interface
functions: []
libraries: []
---

# 2 / User Interfaces / Elements of the Graphical User Interface System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There is more to the Amiga user interface than Intuition.  To build a
complete user interface, application writers need to understand these
other elements of the system software.


    Table 2-1: Elements of the Amiga Graphical User Interface System
  ______________________________________________________________________
 |                                                                      |
 |  System Element     Purpose                                          |
 |======================================================================|
 |  Intuition          The main toolkit and function library for        |
 |                     creating a graphical user interface (GUI) on the |
 |                     Amiga.                                           |
 |                                                                      |
 |  [Workbench](libraries/14-workbench-and-icon-library.md)          The Amiga file system GUI in which icons         |
 |                     represent applications and files.                |
 |                                                                      |
 |  [Preferences](libraries/13-preferences.md)        A family of editors and configuration files for  |
 |                     setting Amiga system options.                    |
 |                                                                      |
 |  [BOOPSI](libraries/12-boopsi-object-oriented-intuition.md)             Subsystem of Intuition that allows applications  |
 |                     to add extensions to Intuition through           |
 |                     object-oriented techniques (Release 2 only).     |
 |----------------------------------------------------------------------|
 |  [Gadtools Library](libraries/15-gadtools-library.md)   A support library for creating Intuition gadgets |
 |                     and menus (Release 2 only).                      |
 |                                                                      |
 |  [ASL Library](libraries/16-asl-library.md)        A support library for creating Intuition         |
 |                     requesters (Release 2 only).                     |
 |                                                                      |
 |  [Icon Library](libraries/14-workbench-and-icon-library-the-icon-library.md)       Main library for using Workbench icons.          |
 |                                                                      |
 |  [Workbench Library](libraries/14-workbench-and-icon-library-the-workbench-library.md)  A support library for Workbench icons and menus  |
 |                     (Release 2 only).                                |
 |----------------------------------------------------------------------|
 |  [Console Device](libraries/9-intuition-input-and-output-methods-console-device-i-o.md)     An I/O support module which allows windows to be |
 |                     treated as text-based virtual terminals.         |
 |                                                                      |
 |  [Graphics Library](libraries/27-graphics-primitives-introduction.md)   The main library of rendering and drawing        |
 |                     routines.                                        |
 |                                                                      |
 |  [Layers Library](libraries/30-layers-library-layers.md)     A support library that manages overlapping,      |
 |                     rectangular drawing areas which Intuition uses   |
 |                     for windows.                                     |
 |______________________________________________________________________|


As you read about Intuition in the chapters to follow, you will be
introduced to each of these elements of the Amiga user interface in more
detail.

