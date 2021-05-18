/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2020 Sam Lantinga <slouken@libsdl.org>

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
#include "../../SDL_internal.h"

#ifdef SDL_FILESYSTEM_AMIGA

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* System dependent filesystem routines                                */

#include "SDL_error.h"
#include "SDL_filesystem.h"

#include "../../core/morphos/SDL_misc.h"

#include <libraries/charsets.h>
#include <proto/dos.h>

char *
SDL_GetBasePath(void)
{
	BPTR lock = Lock("PROGDIR:", ACCESS_READ);
	char *path = NULL;

	D("[%s]\n", __FUNCTION__);

	if (lock)
	{
		size_t len = 128;

		for (;;)
		{
			char *tmp = SDL_malloc(len);

			if (NameFromLock(lock, tmp, len))
			{
				path = AMIGA_ConvertText(tmp, MIBENUM_SYSTEM, MIBENUM_UTF_8);
				SDL_free(tmp);
				break;
			}

			SDL_free(tmp);

			len *= 2;

			if (IoErr() != ERROR_LINE_TOO_LONG)
				break;
		}

		UnLock(lock);
	}

	return path;
}

static char *
SDL_RemoveInvalidChars(const char *src)
{
	char *s = SDL_strdup(src);
	char *p = s;

	if (s)
	{
		char c;

		while ((c = *p))
		{
			if (c == '/' || c == ':')
				*p = ' ';

			p++;
		}
	}

	return s;
}

char *
SDL_GetPrefPath(const char *org, const char *app)
{
	char *p1 = SDL_RemoveInvalidChars(org);
	char *path = NULL;

	if (p1)
	{
		char *p2 = SDL_RemoveInvalidChars(app);

		if (p2)
		{
			int len = sizeof("ENVARC:") + strlen(p1) + strlen(p2) + 8;
			char *tmp = SDL_malloc(len);

			if (tmp)
			{
				BPTR lock;

				strcpy(tmp, "ENVARC:");
				AddPart(tmp, p1, len);

				if ((lock = CreateDir(tmp)))
					UnLock(lock);

				AddPart(tmp, p2, len);

				if ((lock = CreateDir(tmp)))
					UnLock(lock);

				path = AMIGA_ConvertText(tmp, MIBENUM_SYSTEM, MIBENUM_UTF_8);

				SDL_free(tmp);
			}

			SDL_free(p2);
		}

		SDL_free(p1);
	}

	return path;
}

#endif /* SDL_FILESYSTEM_AMIGA */

/* vi: set ts=4 sw=4 expandtab: */
