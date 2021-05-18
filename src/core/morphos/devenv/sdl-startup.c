/*
 * Copyright (C) 2004-2017 MorphOS Development Team
 *
 * $Id: sdl-startup.c,v 1.2 2017/11/25 21:56:56 itix Exp $
 */

#include <constructor.h>
#include <stdio.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/muimaster.h>
#include <proto/sdl2.h>
#include <proto/tinygl.h>

#include "SDL_error.h"
#include "SDL_rwops.h"

#include "../SDL_amigaversion.h"

#if defined(__NO_SDL_CONSTRUCTORS)
extern struct Library *SDL2Base;
#else
int _INIT_4_SDL2Base(void) __attribute__((alias("__CSTP_init_SDL2Base")));
void _EXIT_4_SDL2Base(void) __attribute__((alias("__DSTP_cleanup_SDL2Base")));
//void _INIT_4_TinyGLBase(void) __attribute__((alias("__CSTP_init_TinyGLBase")));
//void _EXIT_4_TinyGLBase(void) __attribute__((alias("__DSTP_cleanup_TinyGLBase")));

struct Library *SDL2Base;
struct Library *TinyGLBase;
GLContext      *__tglContext;

void __SDL2_OpenLibError(ULONG version, const char *name)
{
	struct Library *MUIMasterBase = OpenLibrary("muimaster.library", 0);

	if (MUIMasterBase)
	{
		size_t args[2] = { version, (size_t)name };
		MUI_RequestA(NULL, NULL, 0, "SDL 2 startup message", "Abort", "Need version %.10ld of %s.", &args);
		CloseLibrary(MUIMasterBase);
	}
}

static const char libname[] = "sdl2.library";
static BPTR OldLock, NewLock;

/*static CONSTRUCTOR_P(init_TinyGLBase, 101)
{
	CONST_STRPTR tglname = "tinygl.library";

	TinyGLBase = OpenLibrary(tglname, 50);

	if (TinyGLBase)
		SDL_InitTGL((void **) &__tglContext, (struct Library **) &TinyGLBase);
	else
		__SDL2_OpenLibError(50, tglname);

	return (TinyGLBase == NULL);
}*/

static CONSTRUCTOR_P(init_SDL2Base, 100)
{
	struct Library *base = (void *) OpenLibrary((STRPTR)libname, VERSION);

	if (base)
	{
		NewLock = Lock("PROGDIR:", ACCESS_READ); /* we let libauto open doslib */

		if(NewLock)
		{
			SDL2Base = base;
			SDL_InitTGL((void **) &__tglContext, (struct Library **) &TinyGLBase);
			OldLock = CurrentDir(NewLock);
		}
		else
		{
			CloseLibrary(base);
		}
	}
	else
	{
		__SDL2_OpenLibError(VERSION, libname);
	}

	return (base == NULL);
}

static DESTRUCTOR_P(cleanup_SDL2Base, 100)
{
	struct Library *base = SDL2Base;

	if (base)
	{
		if (NewLock)
		{
			//CurrentDir(OldLock);
			//UnLock(NewLock);
			UnLock(CurrentDir(OldLock));
		}

		CloseLibrary(base);
	}
}
#endif

#include "sdl-stubs.c"

/*
 * Custom getenv(), catches HOME requests and creates+returns PROGDIR:home
 */
#include <stdlib.h>

char *_getenv(const char *) __attribute__((alias("SDL_getenv")));

static const char home[] = "PROGDIR:home";

char *SDL_getenv(const char *name)
{
	char *var = NULL;
	char dummy[2];
	size_t len;

	/* "portability" hack++ */
	if (strcmp(name, "HOME") == 0)
	{	
		BPTR MyLock = Lock(home, ACCESS_READ);

		if (MyLock)
		{
			struct FileInfoBlock MyFIB;

			if (Examine(MyLock, &MyFIB))
			{
				if (MyFIB.fib_DirEntryType > 0)
				{
					var = (char *)home;
				}
			}

			UnLock(MyLock);
		}
		else
		{
			MyLock = CreateDir(home);
			if (MyLock)
			{
				UnLock(MyLock);
				var = (char *)home;
			}
		}

		return var;
	}

	if (GetVar((char *)name, dummy, sizeof(dummy), GVF_BINARY_VAR) == -1)
	{
		/* no var */
		return NULL;
	}

	len = IoErr() + 1;

	if ((var = SDL_malloc(len)))
	{
		if (GetVar((char *)name, var, len, GVF_BINARY_VAR) == -1)
		{
			/* should not happen */
			SDL_free(var);
			var = NULL;
		}
	}

	return var;
}

int SDL_setenv(const char *name, const char *value, int overwrite)
{
	char dummy[2];

	if (!name || SDL_strlen(name) == 0 || SDL_strchr(name, '=') != NULL || !value) {
		return (-1);
	}

	if (!overwrite && GetVar(name, dummy, sizeof(dummy), GVF_BINARY_VAR) != -1) {
		return 0;
	}
	// TODO make these global?
	if (!SetVar(name, value, -1, LV_VAR /*| GVF_GLOBAL_ONLY | GVF_SAVE_VAR*/)) {
		return -1;
	}

	return 0;
}

/* SDL_RWops() replacement
 *
 * Functions to read/write stdio file pointers. Will link with libc stdio.
 */

static Sint64 stdio_size(struct SDL_RWops *context)
{
	Sint64 size, offset;

	offset = ftello64(context->hidden.amigaio.fp.libc);
	fseeko64(context->hidden.amigaio.fp.libc, 0, SEEK_END);
	size = ftello64(context->hidden.amigaio.fp.libc);
	fseeko64(context->hidden.amigaio.fp.libc, offset, SEEK_SET);

	return size;
}

static Sint64 stdio_seek(SDL_RWops *context, Sint64 offset, int whence)
{
	if (fseeko64(context->hidden.amigaio.fp.libc, offset, whence) == 0 )
	{
		return ftello64(context->hidden.amigaio.fp.libc);
	}
	else
	{
		SDL_Error(SDL_EFSEEK);
		return -1;
	}
}
static size_t stdio_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum)
{
	size_t nread = fread(ptr, size, maxnum, context->hidden.amigaio.fp.libc);

	if (nread == 0 && ferror((FILE *)context->hidden.amigaio.fp.libc) )
	{
		SDL_Error(SDL_EFREAD);
	}

	return nread;
}
static size_t stdio_write(SDL_RWops *context, const void *ptr, size_t size, size_t num)
{
	size_t nwrote = fwrite(ptr, size, num, context->hidden.amigaio.fp.libc);

	if (nwrote == 0 && ferror((FILE *)context->hidden.amigaio.fp.libc) )
	{
		SDL_Error(SDL_EFWRITE);
	}

	return nwrote;
}
static int stdio_close(struct SDL_RWops *context)
{
	if ( context )
	{
		if ( context->hidden.amigaio.autoclose )
		{
			/* WARNING:  Check the return value here! */
			fclose(context->hidden.amigaio.fp.libc);
		}
		SDL_FreeRW(context);
	}
	return 0;
}

SDL_RWops *SDL_RWFromFP(void *fp, SDL_bool autoclose)
{
	return SDL_RWFromFP_clib(fp, autoclose, stdio_size, stdio_seek, stdio_read, stdio_write, stdio_close);
}

extern void *AmiGetGLProc(const char *proc);
void *SDL_GL_GetProcAddress(const char *proc)
{
	void *func = NULL;

	func = AmiGetGLProc(proc);

	D("[%s] proc %s func 0x%08lx\n", __FUNCTION__, proc, func);

	return func;
}
