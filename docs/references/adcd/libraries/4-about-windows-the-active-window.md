---
title: 4 / About Windows / The Active Window
manual: libraries
chapter: libraries
section: 4-about-windows-the-active-window
functions: []
libraries: []
---

# 4 / About Windows / The Active Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There is only one window in the system active at any time.  The active
window receives all user input, including keyboard and mouse events.  This
is also known as the input focus, as all input is focused at this single
point.

Some areas of the active window are displayed more boldly than those on
inactive windows.  The active window's borders are filled in with a color
which is designed to stand out from the background while inactive windows
have their borders filled with the background color.  The specific
coloring of active and inactive windows is dependent on the screen on
which the window is opened.  See the section "[DrawInfo and the 3D Look](libraries/3-intuition-screens-drawinfo-and-the-3d-look.md)" in
the "Intuition Screens" chapter for more information.

Windows have two optional titles:  one for the window and one for the
screen.  The window title appears in the top border of the window,
regardless of whether the window is active or inactive.  The window's
screen title appears in the screen's title bar only when the window is
active.  This gives the user a secondary clue as to what application is
active in the screen.

The active window's menus are displayed on the screen when the right mouse
button (the menu button ) is pressed.  If the active window has no menus,
then none will be displayed.

Each window may also have its own mouse-pointer image.  Changing the
active window will change the pointer to the one currently set for the new
active window.

