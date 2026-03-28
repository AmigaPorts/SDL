Paths: src/**/*.c, src/**/*.h

# SDL2 Backend Development Rules

## Before Implementing Any Backend Function

1. Read the relevant SDL2 contract doc (`/sdl2-api-lookup`) to understand what SDL2 core expects
2. **Search for SDL 1.2 reference:** `amiga_search("SDL 1.2 [subsystem]")` — proven working AmigaOS implementations are indexed in the KB
3. **Look up the AmigaOS API:** `amiga_api_lookup("[function]")` — includes pitfall warnings and graph data
4. **Check for pitfalls:** `amiga_pitfalls_for("[API or device]")` — 70+ documented gotchas from real development
5. **Check crash patterns:** `amiga_crash_diagnosis("[Guru code or symptoms]")` — 25+ documented crash signatures

## Function Pointer Safety

SDL2 video/audio/joystick devices use function pointer tables. Every function pointer
set in `*_CreateDevice()` MUST either:
- Point to a real implementation, OR
- Be left NULL (SDL2 core treats NULL as "not supported")

Never set a function pointer to a stub that silently does nothing without
returning the correct value. SDL2 core checks return values.

## VideoBootStrap and AudioBootStrap

Registration in `src/SDL.c` bootstrap arrays. The `Available()` function MUST:
- Return 1 only if the required libraries can be opened (cybergraphics.library, ahi.device)
- Return 0 if libraries are missing -- this lets SDL2 fall through to the next driver
- NOT leave libraries open -- just probe and close

## PumpEvents Must Be Non-Blocking

`device->PumpEvents(device)` is called from SDL_PollEvent. It must:
- Process ALL pending platform events (drain the IDCMP port)
- Return immediately when no events are pending
- Never call Wait() or any blocking function
- Translate events via SDL_SendKeyboardKey, SDL_SendMouseMotion, etc.

## Framebuffer Contract

- `CreateWindowFramebuffer`: Allocate an SDL_Surface in a format the backend can blit
- `UpdateWindowFramebuffer`: Blit the surface to screen (WritePixelArray for CyberGraphX)
- `DestroyWindowFramebuffer`: Free the surface
- The surface pixel format should match what the hardware can accept natively to avoid conversion

## Audio Callback Safety

The SDL2 audio thread calls PlayDevice/GetDeviceBuf in a tight loop. On AmigaOS with AHI:
- The AHI PlayerFunc callback runs at interrupt level
- Do NOT allocate memory, open libraries, or call dos.library from callbacks
- Use double-buffering: fill one buffer while AHI plays the other
- Signal the audio task from the callback, do heavy work in the task

## Resource Lifecycle

Every OpenLibrary must have a CloseLibrary. Every OpenScreen must have a CloseScreen.
Every OpenWindow must have a CloseWindow. Order matters -- close in reverse order of open.
The memory-checker agent audits this.
