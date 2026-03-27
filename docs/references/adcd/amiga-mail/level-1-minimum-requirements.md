---
title: Level 1 Minimum Requirements
manual: amiga-mail
chapter: amiga-mail
section: level-1-minimum-requirements
functions: []
libraries: []
---

# Level 1 Minimum Requirements

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

1. No program crashes.  The application should not crash, guru or
  otherwise cease to be functional.  Test, retest and test again till you
  are sure your application is robust.

2. No logic or flow errors.  The application cannot take a path other
  than the one requested or expected by the user.  For example, if the
  user asks for a map, but instead gets a picture of a tree, a logic or
  flow error has occurred.

3. All images presented should be free of error and look clean.  For
  example, a title should not have a garbled picture or a video sequence
  that exhibits solarization, i.e., a color picture that looks like a
  negative.

4. No low quality images.  All still images should be high quality,
  preferably digitized interlaced HAM images.  Drawings or animations
  should be detailed and free of major color banding.  All still images
  should be overscanned unless a conscious effort is made to provide a
  colored border.

5. User interface.  The program should follow generally accepted CDTV
  interface rules including:


```c
      A button for action, B button for backup, arrow keys move in
      direction of arrow.

      Single click to select an object.

      Use highlighted hitboxes rather than a pointer where possible.

      Highlighted hitboxes should be accessible by cursor keys in any
      direction.

      If a pointer is used for products with invisible hot boxes or for
      special purposes such as coloring, the pointer should change when
      it is over an invisible hot box and be in a form relevant to the
      application (paint brush, wand, etc.).

      Numbered items should allow use of the numeric keypad on the
      controller.

      Selectable items should stand out (e.g., 3D buttons) from
      non-selectable items, and they should give audio/visual feedback
      when selected.

      Selectable items should give appropriate, consistent, and
      predictable results.

      There should be no references to a computer keyboard (e.g., F1 key).
```
6. The application should look good on any television.  This means you
  should buy a cheap television for testing.

7. There should be no signs of AmigaDOS.  Examples include the AmigaDOS
  cursor, Workbench screen, system requesters, sleep icon, pull down
  menus, flashing title bar, front/back gadgets, or jargon (x memory
  free, loading next module, etc.).

8. Efforts must be made to reduce perceived boot-up time.  The
  titlescreen should appear within five seconds of the appearance of the
  CDTV Interactive Multimedia logo.  (See Discis' products) The program
  should show a title screen before doing anything else.  It should not
  show CLI, Workbench, or any pointer.

9. It must have a screen blanker tied to preferences.  We recommend the
  screen blanker supplied as part of the OS.

10. Applications must work under AmigaDOS 1.3 and 2.0 in both NTSC and
  PAL. Programs should be able to successfully pass enforcer and mungwall
  testing.

11. The program must be designed for use on a PAL or NTSC TV, which
  means care must be taken in regard to all graphic elements (fonts,
  symbols, pictures, animations, video) with respect to size, style,
  color combinations, and contrast.  Test your applications on those two
  environments, not just with a monitor and one of the two standards.
  Specific suggestions include:


```c
      Fonts should be simple with no thin lines, anti-aliased, easy to
      read on a television and at least 20 point size.

      Text should generally be highly contrasted to its background.

      Text should have borders or drop shadows to make it more readable.

      Don't use pure colors (R, G, B values should be less than or equal
      to 13 out of a range of 0--15) because they bleed on television
      sets.

      Be careful of the colors used as some colors show up very
      differently on NTSC versus PAL.  For example, deep red in NTSC
      comes out pale pink in PAL.  The only way to find this out is to
      test on both systems.

      Avoid stark contrasts when using thin horizontal lines since this
      will not look good in an interlaced medium (TV), and avoid single
      pixel horizontal lines entirely.

      Do not base instructions solely on color, i.e., don't state ``Pick
      the orange button'' since TV sets will be adjusted differently.
      This could also be a problem for colorblind users.

      There should be no more than nine selectable (by cursor or by
      pointer) items on a screen unless the individual items are
      recognizable because they are part of a set (i.e., alphabet,
      numbers, states). Nine items fit well with the font size required
      for television.
```
12. Products must not substitute repetitiveness for depth by reusing
  the same elements in different places.  If a product is perceptually
  redundant, it is boring.  For example, using a passage from Beethoven's
  Piano Concerto No. 5 as an example of his music, and as an example of
  how a piano sounds, and as an example of a piano concerto is a lack of
  depth.

13. Eliminate all spelling and grammatical errors; people will not want
  to use a product, especially an education product, if they cannot trust
  something elementary like its spelling. Run your text through a spell
  checker and a grammar checker. Some of these titles are available in UK
  English or American English only, and these are acceptable, at least
  for the initial shipment.

14. Programs should reboot when the disc is removed unless the program
  disc needs to be removed for the product to be usable (CD-Remix).  The
  program should reboot when the eject button is pushed, and the reboot
  should occur even if the disk is being accessed or Amiga audio is
  playing.

15. Sound quality should match the application requirement. Use Amiga
  sounds for audio feedback; CD-DA for game background, dramatic intro
  music and other sections designed to evoke an emotional response. All
  sounds should be clear and free from hiss or other extraneous problems.
  Speech must be ungarbled and unclipped and digitized at a reasonable
  level or be CD-DA.

16. Volume levels of speech, music, and sound effects should be uniform
  throughout the product.  All audio must come through both channels
  unless there is a compelling reason to do otherwise.  Note that
  compelling does not mean being unwilling to take the time to code so
  that the sound comes through both channels nor does it mean that your
  authoring system only works with one channel.  Compelling does mean
  trying to add depth to the sound by having one person come through the
  right channel and another through the left channel.

17. Interruptability.  All titles need to be interruptable at any time,
  including title and credit screens, introduction, during accesses, or
  animations.

18. Products must use preferences for language selections.  Unless the
  language chosen in preferences is unavailable, the user should not
  normally see language selection screens.

19. All programs that can save to a floppy must be able to format a
  disk.

20. All programs should test for joystick/mouse mode.  If the
  controller is not in the proper mode, it should ask the user to change
  modes.

21. Programs should disable keys that are not functional in the
  product. Typically this means disabling the audio keys for CD control.

22. Controller responsiveness.  The product should not queue up button
  presses, it should react and give feedback immediately, and any cursor
  or highlight should move quickly enough for that specific application.
  In many cases, if a pointer is used it should include an accelerator
  feature.  If a user feels compelled to repeat an operation because
  there is no response, the application is at fault.

23. The products should not have any dead time, i.e., time when nothing
  is occurring.  Accesses should first give audio and visual feedback
  that a selection has been made, then have a transition of some sort,
  then begin the load during the transition. The transition interlude can
  consist of music, color cycling, a voice over, a fade to a colored
  screen, or in some way distract the user.  A sleep or load symbol is
  generally insufficient to improve the perception.

24. Test that your product works properly with a trackball and a mouse.

25. They should also not be adversely affected by the presence of video
  peripherals such as genlocks.

