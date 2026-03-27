---
title: 6 / Setting Up Menus / Simple Menu Example
manual: libraries
chapter: libraries
section: 6-setting-up-menus-simple-menu-example
functions: []
libraries: []
---

# 6 / Setting Up Menus / Simple Menu Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Menu concepts are explained in great detail later in this chapter; for now
though it may be helpful to look at an example.  Here is a very simple
example of how to use the Intuition menu system.  The example shows how to
set up a menu strip consisting of a single menu with five menu items.  The
third menu item in the menu has two sub-items.

The example works with all versions of the Amiga OS however it assumes
that the Workbench screen is set up with the the Topaz 8 ROM font.  If the
font is different, the example will exit immediately since the layout of
the menus depends on having a monospaced font with 8 x 8 pixel characters.


```c
     [simplemenu.c](libraries/lib-examples-simplemenu-c.md) 
```
