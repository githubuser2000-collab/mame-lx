#include <stdlib.h>
#include <wchar.h>

#ifdef __cplusplus
#define EXT extern "C"
#else
#define EXT
#endif


EXT size_t
wcslen(const wchar_t *s) {
    const wchar_t *p;

    p = s;
    while (*p)
        p++;

    return p - s;
}

EXT wchar_t *
wcsdup(const wchar_t *str) {
    wchar_t *copy;
    size_t len;

    len = wcslen(str) + 1;
    copy = (wchar_t *)malloc(len * sizeof (wchar_t));

    if (!copy)
        return (NULL);

    return (wmemcpy(copy, str, len));
}

EXT wchar_t *
wcscpy(wchar_t *s1, const wchar_t *s2) {
    wchar_t *p;
    const wchar_t *q;

    p = s1;
    q = s2;
    while (*q)
        *p++ = *q++;
    *p = '\0';

    return s1;
}