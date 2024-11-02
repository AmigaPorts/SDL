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

#ifdef SDL_PROCESS_AMIGAOS4

#include "../SDL_sysprocess.h"

#include "../../main/amigaos4/SDL_os4debug.h"

#include <proto/dos.h>

// TODO: IOStream AmigaOS 4 implementation

struct SDL_ProcessData {
    uint32 pid;
    int32 exitCode;
};

static char* OS4_MakeCommandLine(char* const *args)
{
    uint32 index = 0;

    size_t len = 0;

    while(args[index]) {
        len += SDL_strlen(args[index]) + 1;
        index++;
    }

    dprintf("Command buffer length %zu\n", len);

    char *command = SDL_calloc(len, 1);

    if (!command)
    {
        dprintf("Failed to allocate command line buffer\n");
        return NULL;
    }

    for (index = 0; args[index]; index++) {
        SDL_strlcat(command, args[index], len);
        if (args[index + 1]) {
            SDL_strlcat(command, " ", len);
        }
    }

    dprintf("Command buffer '%s'\n", command);

    return command;
}

static char** OS4_MakeEnvVariables(char **envp)
{
    // Convert from "variable=value" to "variable", "value" form

    uint32 index = 0;
    while (envp[index]) {
        char* p = envp[index++];

        while (*p) {
            if (*p == '=') {
                *p = '\0';
                break;
            }
            p++;
        }
    }

    dprintf("%u variables found\n", index);

    char** result = SDL_calloc(sizeof(char*) * (2 * index + 1), 1);

    if (result) {
        index = 0;
        while(envp[index]) {
            result[2 * index] = SDL_strdup(envp[index]);
            result[2 * index + 1] = SDL_strdup(envp[index] + SDL_strlen(envp[index]) + 1);
            dprintf("'%s': '%s'\n", result[2 * index], result[2 * index +1]);
            index++;
        }
    } else {
        dprintf("Failed to allocate memory\n");
    }

    SDL_free(envp);

    return result;
}

static void OS4_FreeEnvVariables(char** variables)
{
    int index = 0;
    while (variables[index]) {
        SDL_free(variables[index]);
        index++;
    }
    SDL_free(variables);
}

static void OS4_FinalCode(int32 returnCode, int32 finalData, struct ExecBase *sysbase)
{
    SDL_ProcessData *data = (SDL_ProcessData *)finalData;
    if (!data) {
        dprintf("NULL pointer");
        return;
    }

    dprintf("Process %u return code %d, final data %p\n", data->pid, returnCode, finalData);

    data->exitCode = returnCode;
}

bool SDL_SYS_CreateProcessWithProperties(SDL_Process *process, SDL_PropertiesID props)
{
    if (!IDOS) {
        return SDL_SetError("IDOS nullptr");
    }

    char * const *args = SDL_GetPointerProperty(props, SDL_PROP_PROCESS_CREATE_ARGS_POINTER, NULL);

    SDL_Environment *env = SDL_GetPointerProperty(props, SDL_PROP_PROCESS_CREATE_ENVIRONMENT_POINTER, SDL_GetEnvironment());
    char **envp = SDL_GetEnvironmentVariables(env);
    if (!envp) {
        dprintf("envp NULL\n");
        return false;
    }

    SDL_ProcessData *data = SDL_calloc(1, sizeof(*data));
    if (!data) {
        dprintf("Failed to allocate process data\n");
        SDL_free(envp);
        return SDL_OutOfMemory();
    }

    char *command = OS4_MakeCommandLine(args);
    char **variables = OS4_MakeEnvVariables(envp);

    if (!command) {
        OS4_FreeEnvVariables(variables);
        return SDL_OutOfMemory();
    }

    process->internal = data;

    BPTR inputHandle = IDOS->DupFileHandle(IDOS->Input());
    BPTR outputHandle = IDOS->DupFileHandle(IDOS->Output());
    BPTR errorHandle = IDOS->DupFileHandle(IDOS->ErrorOutput());

    if (inputHandle == ZERO)  {
        dprintf("input ZERO\n");
    }

    if (outputHandle == ZERO) {
        dprintf("output ZERO\n");
    }

    if (errorHandle == ZERO) {
        dprintf("error ZERO\n");
    }

    const int32 error = IDOS->SystemTags(command,
                                   SYS_Asynch, TRUE,
                                   SYS_Input, inputHandle,
                                   SYS_Output, outputHandle,
                                   SYS_Error, errorHandle,
                                   NP_Child, TRUE,
                                   NP_CloseInput, inputHandle != ZERO,
                                   NP_CloseOutput, outputHandle != ZERO,
                                   NP_CloseError, errorHandle != ZERO,
                                   NP_FinalData, data,
                                   NP_FinalCode, OS4_FinalCode,
                                   NP_LocalVars, variables,
                                   TAG_DONE);

    const int32 ioErr = IDOS->IoErr();

    SDL_free(command);
    OS4_FreeEnvVariables(variables);

    if (error == -1) {
        dprintf("Failed to start process '%s' (error %d)\n", args[0], ioErr);
        return SDL_SetError("Failed to start process");
    }

    data->pid = ioErr; // DOS 51.77

    dprintf("'%s' started with pid %u\n", args[0], data->pid);

    SDL_SetNumberProperty(process->props, SDL_PROP_PROCESS_PID_NUMBER, data->pid);

    return true;
}

bool SDL_SYS_KillProcess(SDL_Process *process, bool force)
{
    if (!IDOS) {
        return SDL_SetError("IDOS nullptr");
    }

    struct SignalSemaphore* sem = IExec->FindSemaphore("DosCliProc");

    bool result = false;

    if (sem) {
        const uint32 pid = process->internal->pid;
        IExec->ObtainSemaphoreShared(sem);

        struct Process *proc = IDOS->FindCliProc(pid);

        if (proc) {
            dprintf("Send SIGBREAKF_C to PID %u\n", pid);
            IExec->Signal((struct Task*)process, SIGBREAKF_CTRL_C);
            result = true;
        } else {
            dprintf("Process %u not found\n", pid);
        }

        IExec->ReleaseSemaphore(sem);
    } else {
        return SDL_SetError("Failed to find DosCliProc semaphore");
    }

    return result;
}

bool SDL_SYS_WaitProcess(SDL_Process *process, bool block, int *exitcode)
{
    if (!IDOS) {
        return SDL_SetError("IDOS nullptr");
    }

    const uint32 pid = process->internal->pid;

    dprintf("Waiting for process %u\n", pid);

    if (block) {
        const int32 found = IDOS->WaitForChildExit(pid);
        if (found) {
            dprintf("Found, exitCode %d\n", process->internal->exitCode);
            *exitcode = process->internal->exitCode;
        } else {
            dprintf("Failed, error %d\n", IDOS->IoErr());
            //return SDL_SetError("Failed to wait process");
        }
    } else {
        const int32 found = IDOS->CheckForChildExit(pid);
        if (found) {
            dprintf("Process %u is running\n", pid);
            return false;
        } else {
            dprintf("Process %u not found, error %d\n", pid, IDOS->IoErr());
        }
    }
    return true;
}

void SDL_SYS_DestroyProcess(SDL_Process *process)
{
    dprintf("\n");

    SDL_free(process->internal);
}

#endif // SDL_PROCESS_AMIGAOS4

