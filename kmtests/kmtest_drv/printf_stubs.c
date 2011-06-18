/*
 * PROJECT:         ReactOS kernel-mode tests
 * LICENSE:         GPLv2+ - See COPYING in the top level directory
 * PURPOSE:         Kernel-Mode Test Suite stub functions for any-IRQL vsnprintf
 * PROGRAMMER:      Thomas Faber <thfabba@gmx.de>
 */

#undef wctomb
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

int __cdecl KmtWcToMb(char *mbchar, wchar_t wchar)
{
    *mbchar = wchar;
    return 1;
}

int __cdecl streamout(FILE *stream, const char *format, va_list argptr);

int __cdecl KmtVSNPrintF(char *buffer, size_t count, const char *format, va_list argptr)
{
    int result;
    FILE stream;

    stream._base = (char *)buffer;
    stream._ptr = stream._base;
    stream._charbuf = 0;
    stream._cnt = count;
    stream._bufsiz = 0;
    stream._flag = _IOSTRG | _IOWRT;
    stream._tmpfname = 0;

    result = streamout(&stream, format, argptr);

    /* Only zero terminate if there is enough space left */
    if (stream._cnt) *(char *)stream._ptr = '\0';

    return result;
}
