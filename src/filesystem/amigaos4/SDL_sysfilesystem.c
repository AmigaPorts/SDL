/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2025 Sam Lantinga <slouken@libsdl.org>

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

#ifdef SDL_FILESYSTEM_AMIGAOS4

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* System dependent filesystem routines                                */

#include "SDL_error.h"
#include "SDL_filesystem.h"
#include "../../video/amigaos4/SDL_os4library.h"

#include "../../main/amigaos4/SDL_os4debug.h"

#include <proto/dos.h>

const char *
SDL_SYS_GetBasePath(void)
{
    char* buffer = NULL;
    const char* const basePath = "PROGDIR:";

    size_t len = SDL_strlen(basePath) + 1;

    buffer = (char *) SDL_malloc(len);
    if (!buffer) {
        SDL_OutOfMemory();
        return NULL;
    }

    SDL_memset(buffer, 0, len);
    SDL_snprintf(buffer, len, "%s", basePath);

    return buffer;
}

static bool
OS4_CreateDirTree(const char* path)
{
    bool success = false;

    if (!IDOS) {
        dprintf("IDOS nullptr\n");
        return false;
    }

    char* temp = SDL_strdup(path);

    if (!temp) {
        dprintf("Failed to create temporary path\n");
        return false;
    }

    const size_t len = SDL_strlen(temp);

    if (len < 1) {
        dprintf("Empty string\n");
        return false;
    }

    if (temp[len - 1] == '/') {
        temp[len - 1] = '\0';
    }

    BPTR lock = IDOS->CreateDirTree(temp);
    if (lock) {
        success = true;
        IDOS->UnLock(lock);
    } else {
        const int32 err = IDOS->IoErr();
        dprintf("Failed to create dir tree '%s' (err %d)\n", temp, err);
        if (err == ERROR_OBJECT_EXISTS) {
            dprintf("Object already exists -> success\n");
            success = true;
        }
    }

    SDL_free(temp);

    return success;
}

const char *
SDL_SYS_GetPrefPath(const char *org, const char *app)
{
    const char* const envPath = "ENVARC:";
    size_t len = SDL_strlen(envPath) + 1;
    char* buffer = NULL;

    if (org) {
        len += SDL_strlen(org) + 1;
    }

    if (app) {
        len += SDL_strlen(app) + 1;
    }

    buffer = (char *) SDL_malloc(len);
    if (!buffer) {
        SDL_OutOfMemory();
        return NULL;
    }

    SDL_memset(buffer, 0, len);
    SDL_snprintf(buffer, len, envPath);

    if (org) {
        SDL_snprintf(buffer + SDL_strlen(buffer), len - SDL_strlen(buffer), "%s/", org);
    }

    if (app) {
        SDL_snprintf(buffer + SDL_strlen(buffer), len - SDL_strlen(buffer), "%s/", app);
    }

    if (OS4_CreateDirTree(buffer)) {
        return buffer;
    }

    SDL_free(buffer);
    return NULL;
}

const char *
SDL_SYS_GetUserFolder(SDL_Folder folder)
{
    const char* const path = "PROGDIR:";
    const size_t pathLen = strlen(path) + 1;
    char* folderPath = NULL;

    switch (folder) {
        case SDL_FOLDER_HOME:
        case SDL_FOLDER_DOCUMENTS:
            folderPath = SDL_malloc(pathLen);
            if (folderPath) {
                SDL_snprintf(folderPath, pathLen, "%s", path);
            } else {
                SDL_OutOfMemory();
            }
            break;
        default:
            dprintf("Unsupported user folder %d\n", folder);
            SDL_SetError("Unsupported user folder");
            break;
    }

    return folderPath;
}

char *SDL_SYS_GetCurrentDirectory(void)
{
    if (!IDOS) {
        dprintf("IDOS nullptr\n");
        return NULL;
    }

    BPTR lock = IDOS->GetCurrentDir();
    if (lock) {
        char buffer[MAX_DOS_PATH];
        const int32 success = IDOS->NameFromLock(lock, buffer, sizeof(buffer));
        if (success) {
            const size_t len = SDL_strlen(buffer) + 1;
            char* result = SDL_malloc(len);
            if (result) {
                SDL_snprintf(result, len, "%s", buffer);
                dprintf("Current dir: %s\n", result);
                return result;
            } else {
                SDL_OutOfMemory();
                dprintf("Failed to allocate path buffer\n");
            }
        } else {
            dprintf("Failed to get name from lock (err %d)\n", IDOS->IoErr());
        }
    } else {
        dprintf("Failed to get the lock to the current directory\n");
    }

    return NULL;
}

int SDL_SYS_EnumerateDirectory(const char *path, const char *dirname, SDL_EnumerateDirectoryCallback cb, void *userdata)
{
    if (!IDOS) {
        dprintf("IDOS nullptr\n");
        return -1;
    }

    APTR context = IDOS->ObtainDirContextTags(EX_StringNameInput, path, EX_DataFields, (EXF_NAME|EXF_LINK|EXF_TYPE), TAG_DONE);

    int success = 0;

    if (context) {
        struct ExamineData *data;

        while ((data = IDOS->ExamineDir(context))) {
            // TODO: link handling
            if (EXD_IS_FILE(data) || EXD_IS_DIRECTORY(data)) {
                const int result = cb(userdata, dirname, data->Name);
                if (result == 0) {
                    dprintf("Enumerating dir '%s' stopped after item '%s'\n", dirname, data->Name);
                    success = 0;
                    break;
                } else if (result == -1) {
                    dprintf("Callback returned error while enumerating dir '%s', item '%s'\n", dirname, data->Name);
                    SDL_SetError("Callback returned error");
                    success = -1;
                    break;
                }
            }
        }

        const int32 err = IDOS->IoErr();

        if (ERROR_NO_MORE_ENTRIES != err) {
            dprintf("Error %d while examining path '%s'\n", err, path);
            SDL_SetError("Error while examining path");
            success = -1;
        }

        IDOS->ReleaseDirContext(context);
    } else {
        dprintf("Failed to obtain dir context for '%s' (err %d)\n", path, IDOS->IoErr());
        SDL_SetError("Failed to obtain dir context");
        success = -1;
    }

    return success;
}

bool SDL_SYS_RemovePath(const char *path)
{
    if (!IDOS) {
        dprintf("IDOS nullptr\n");
        return false;
    }

    const int32 success = IDOS->Delete(path);

    if (success) {
        dprintf("'%s' deleted\n", path);
    } else {
        const int32 err = IDOS->IoErr();
        dprintf("Failed to delete '%s' (err %d)\n", path, err);
        if (err == ERROR_OBJECT_NOT_FOUND) {
            dprintf("Object doesn't exist -> success\n");
        } else {
            SDL_SetError("Failed to delete path");
            return false;
        }
    }

    return true;
}

bool SDL_SYS_RenamePath(const char *oldpath, const char *newpath)
{
    if (!IDOS) {
        dprintf("IDOS nullptr\n");
        return false;
    }

    const int32 success = IDOS->Rename(oldpath, newpath);

    if (success) {
        dprintf("'%s' renamed to '%s'\n", oldpath, newpath);
    } else {
        dprintf("Failed to rename '%s' to '%s' (err %d)\n", oldpath, newpath, IDOS->IoErr());
        SDL_SetError("Failed to rename path");
        return false;
    }

    return true;
}

bool SDL_SYS_CopyFile(const char *oldpath, const char *newpath)
{
    if (!IDOS) {
        dprintf("IDOS nullptr\n");
        return false;
    }

    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "Copy CLONE BUFFER=32768 %s %s", oldpath, newpath);

    const int32 result = IDOS->SystemTags(buffer, TAG_DONE);

    if (result == 0) {
        dprintf("File %s copied to %s\n", oldpath, newpath);
        return true;
    }

    dprintf("System(%s) failed with %d\n", buffer, result);
    return false;
}

bool SDL_SYS_CreateDirectory(const char *path)
{
    return OS4_CreateDirTree(path);
}

bool SDL_SYS_GetPathInfo(const char *path, SDL_PathInfo *info)
{
    if (!IDOS) {
        dprintf("IDOS nullptr\n");
        return false;
    }

    struct ExamineData *data = IDOS->ExamineObjectTags(EX_StringNameInput, path, TAG_DONE);

    if (data) {
        if (EXD_IS_FILE(data)) {
            info->type = SDL_PATHTYPE_FILE;
            info->size = data->FileSize;
        } else if (EXD_IS_DIRECTORY(data)) {
            info->type = SDL_PATHTYPE_DIRECTORY;
        } else {
            info->type = SDL_PATHTYPE_OTHER;
        }

        // TODO: time fields are nanoseconds since Jan 1, 1970.

        IDOS->FreeDosObject(DOS_EXAMINEDATA, data);
    } else {
        dprintf("Failed to examine object '%s' (err %d)\n", path, IDOS->IoErr());
        SDL_SetError("Failed to examine object");
        info->type = SDL_PATHTYPE_NONE;
        return false;
    }

    return true;
}

#endif /* SDL_FILESYSTEM_AMIGAOS4 */

/* vi: set ts=4 sw=4 expandtab: */
