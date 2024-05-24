/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2024 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "SDL_internal.h"

#include "../../thread/SDL_systhread.h"
#include "../../main/amigaos4/SDL_os4debug.h"

#include <proto/asl.h>

typedef struct
{
    const SDL_DialogFileFilter *filters;
    const char* title;
    const char* default_file;
    const char* default_dir;
    SDL_Window* window;
    SDL_bool allow_many;
    SDL_bool save;
    SDL_bool dir_only;
    SDL_DialogFileCallback callback;
    void* userdata;
} OS4_DialogArgs;

static void OS4_HandleMultiselection(struct FileRequester *req, OS4_DialogArgs *args)
{
    SDL_DialogFileCallback callback = args->callback;

    char **paths = SDL_calloc(sizeof(char*), req->fr_NumArgs + 1);

    if (paths) {
        size_t pathLen = strlen(req->fr_Drawer);
        const char* separator = "/";

        if (pathLen > 0) {
            // Try to handle existing path separators
            const char lastChar = req->fr_Drawer[pathLen - 1];
            if (lastChar == ':' || lastChar == '/') {
                separator = "";
            }

            pathLen++; // Include separator
        }

        for (int i = 0; i < req->fr_NumArgs; i++) {
            const char* filename = req->fr_ArgList[i].wa_Name;
            const size_t totalLen = pathLen + strlen(filename) + 1;

            paths[i] = SDL_calloc(totalLen, 1);

            if (paths[i]) {
                if (pathLen) {
                    snprintf(paths[i], totalLen, "%s%s%s", req->fr_Drawer, separator, filename);
                } else {
                    snprintf(paths[i], totalLen, "%s", filename);
                }
                dprintf("[%d] '%s'\n", i, paths[i]);
            } else {
                dprintf("Failed to allocate memory\n");
            }
        }

        paths[req->fr_NumArgs] = NULL;
        callback(args->userdata, (const char* const*)paths, -1);

        for (int i = 0; i < req->fr_NumArgs; i++) {
            SDL_free(paths[i]);
        }

        SDL_free(paths);
    } else {
        dprintf("Failed to allocate memory\n");
        callback(args->userdata, NULL, -1);
    }
}

static void OS4_HandleSingleFile(struct FileRequester *req, OS4_DialogArgs *args)
{
    SDL_DialogFileCallback callback = args->callback;

    size_t pathLen = strlen(req->fr_Drawer);

    if (pathLen > 0) {
        const char* separator = "/";

        // Try to handle existing path separators
        const char lastChar = req->fr_Drawer[pathLen - 1];
        if (lastChar == ':' || lastChar == '/') {
            separator = "";
        }

        pathLen++; // Include separator

        const char* filename = req->fr_File;
        const size_t totalLen = pathLen + strlen(filename) + 1;
        char* path = SDL_calloc(totalLen, 1);

        if (path) {
            snprintf(path, totalLen, "%s%s%s", req->fr_Drawer, separator, filename);
            dprintf("'%s'\n", path);

            const char *paths[2] = { path, NULL };
            callback(args->userdata, paths, -1);
            SDL_free(path);
        } else {
            dprintf("Failed to allocate memory\n");
            callback(args->userdata, NULL, -1);
        }
    } else {
        const char *paths[2] = { req->fr_File, NULL };
        callback(args->userdata, paths, -1);
    }
}

static void OS4_ShowDialog(OS4_DialogArgs *args)
{
    SDL_DialogFileCallback callback = args->callback;

    struct Window *syswin = NULL;

    if (args->window) {
        SDL_PropertiesID props = SDL_GetWindowProperties(args->window);
        syswin = SDL_GetProperty(props, "SDL.window.amigaos4.window", NULL);
        dprintf("Syswin %p\n", syswin);
    }

    dprintf("default_dir '%s', default_file '%s'\n", args->default_dir, args->default_file);

    struct FileRequester *req = IAsl->AllocAslRequestTags(ASL_FileRequest,
        ASLFR_Window, syswin,
        ASLFR_TitleText, args->title,
        ASLFR_InitialFile, args->default_file ? args->default_file : "",
        ASLFR_InitialDrawer, args->default_dir ? args->default_dir : "",
        //ASLFR_InitialPattern, TODO: filters
        ASLFR_DoMultiSelect, args->allow_many,
        ASLFR_DoSaveMode, args->save,
        ASLFR_DrawersOnly, args->dir_only,
        ASLFR_PrivateIDCMP, TRUE,
        TAG_DONE);

    if (req) {
        const BOOL result = IAsl->AslRequestTags(req, TAG_DONE);

        dprintf("Result %d\n", result);

        if (result) {
            dprintf("Drawer '%s', file '%s', args %d\n", req->fr_Drawer, req->fr_File, req->fr_NumArgs);

            if (req->fr_NumArgs > 0) {
                OS4_HandleMultiselection(req, args);
            } else {
                if (args->dir_only) {
                    const char *paths[2] = { req->fr_Drawer, NULL };
                    callback(args->userdata, paths, -1);
                } else {
                    OS4_HandleSingleFile(req, args);
                }
            }
        } else {
            // User cancelled operation
            const char *files[1] = { NULL };
            callback(args->userdata, files, -1);
        }

        IAsl->FreeAslRequest(req);
    } else {
        callback(args->userdata, NULL, -1);
    }
}

static int OS4_DialogThread(void* ptr)
{
    OS4_ShowDialog(ptr);
    SDL_free(ptr);
    return 0;
}

void SDL_ShowOpenFileDialog(SDL_DialogFileCallback callback, void* userdata, SDL_Window* window, const SDL_DialogFileFilter *filters, const char* default_location, SDL_bool allow_many)
{
    OS4_DialogArgs *args = SDL_calloc(sizeof(OS4_DialogArgs), 1);

    if (args == NULL) {
        SDL_OutOfMemory();
        callback(userdata, NULL, -1);
        return;
    }

    args->title = "Open file...";
    args->filters = filters;
    args->default_file = default_location;
    args->default_dir = NULL;
    args->window = window;
    args->allow_many = allow_many;
    args->save = SDL_FALSE;
    args->dir_only = SDL_FALSE;
    args->callback = callback;
    args->userdata = userdata;

    SDL_Thread *thread = SDL_CreateThread(OS4_DialogThread, "SDL_ShowOpenFileDialog", (void *) args);

    if (thread == NULL) {
        callback(userdata, NULL, -1);
    }
}

void SDL_ShowSaveFileDialog(SDL_DialogFileCallback callback, void* userdata, SDL_Window* window, const SDL_DialogFileFilter *filters, const char* default_location)
{
    OS4_DialogArgs *args = SDL_calloc(sizeof(OS4_DialogArgs), 1);

    if (args == NULL) {
        SDL_OutOfMemory();
        callback(userdata, NULL, -1);
        return;
    }

    args->title = "Save file...";
    args->filters = filters;
    args->default_file = default_location;
    args->default_dir = NULL;
    args->window = window;
    args->allow_many = SDL_FALSE;
    args->save = SDL_TRUE;
    args->dir_only = SDL_FALSE;
    args->callback = callback;
    args->userdata = userdata;

    SDL_Thread *thread = SDL_CreateThread(OS4_DialogThread, "SDL_ShowSaveFileDialog", (void *) args);

    if (thread == NULL) {
        callback(userdata, NULL, -1);
    }
}

void SDL_ShowOpenFolderDialog(SDL_DialogFileCallback callback, void* userdata, SDL_Window* window, const char* default_location, SDL_bool allow_many)
{
    OS4_DialogArgs *args = SDL_calloc(sizeof(OS4_DialogArgs), 1);

    if (args == NULL) {
        SDL_OutOfMemory();
        callback(userdata, NULL, -1);
        return;
    }

    args->title = "Open folder...";
    args->filters = NULL;
    args->default_file = NULL;
    args->default_dir = default_location;
    args->window = window;
    args->allow_many = allow_many; // Multi-selection doesn't seem to work in DrawersOnly mode.
    args->save = SDL_TRUE;
    args->dir_only = SDL_TRUE;
    args->callback = callback;
    args->userdata = userdata;

    SDL_Thread *thread = SDL_CreateThread(OS4_DialogThread, "SDL_ShowOpenFolderDialog", (void *) args);

    if (thread == NULL) {
        callback(userdata, NULL, -1);
    }
}

