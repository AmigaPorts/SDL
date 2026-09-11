/*
  SDL2 Main -- AmigaOS 3.x entry point
  Phase 0: Minimal SDL_main wrapper for CLI launch.
  Phase 2+: WBStartup message handling, stack cookie.
*/

/* This file provides the SDL_main entry point for AmigaOS 3.x.
   On AmigaOS, SDL_main is the user's main(), called after
   platform-specific initialization. For Phase 0, this is a no-op
   passthrough -- the test programs define their own main(). */

/* Nothing needed here for Phase 0.
   The test programs call SDL_Init/SDL_Quit directly.
   Phase 2+ will add:
   - WBStartup message reply
   - __stack cookie for stack allocation
   - Workbench argument parsing
*/
