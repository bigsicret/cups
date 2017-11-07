/*
 * Private localization support for CUPS.
 *
 * Copyright 2007-2017 by Apple Inc.
 * Copyright 1997-2006 by Easy Software Products.
 *
 * Licensed under Apache License v2.0.  See the file "LICENSE" for more information.
 */

#ifndef _CUPS_LANGUAGE_PRIVATE_H_
#  define _CUPS_LANGUAGE_PRIVATE_H_

/*
 * Include necessary headers...
 */

#  include <stdio.h>
#  include <cups/transcode.h>
#  ifdef __APPLE__
#    include <CoreFoundation/CoreFoundation.h>
#  endif /* __APPLE__ */

#  ifdef __cplusplus
extern "C" {
#  endif /* __cplusplus */


/*
 * Macro for localized text...
 */

#  define _(x) x


/*
 * Types...
 */

typedef struct _cups_message_s		/**** Message catalog entry ****/
{
  char	*id,				/* Original string */
	*str;				/* Localized string */
} _cups_message_t;


/*
 * Prototypes...
 */

#  ifdef __APPLE__
extern const char	*_cupsAppleLanguage(const char *locale, char *language, size_t langsize);
extern const char	*_cupsAppleLocale(CFStringRef languageName, char *locale, size_t localesize);
#  endif /* __APPLE__ */
extern void		_cupsCharmapFlush(void);
extern const char	*_cupsEncodingName(cups_encoding_t encoding);
extern void		_cupsLangPrintError(const char *prefix,
			                    const char *message);
extern int		_cupsLangPrintFilter(FILE *fp, const char *prefix,
			                     const char *message, ...)
			__attribute__ ((__format__ (__printf__, 3, 4)));
extern int		_cupsLangPrintf(FILE *fp, const char *message, ...)
			__attribute__ ((__format__ (__printf__, 2, 3)));
extern int		_cupsLangPuts(FILE *fp, const char *message);
extern const char	*_cupsLangString(cups_lang_t *lang,
			                 const char *message);
extern void		_cupsMessageFree(cups_array_t *a);
extern cups_array_t	*_cupsMessageLoad(const char *filename, int unquote);
extern const char	*_cupsMessageLookup(cups_array_t *a, const char *m);
extern cups_array_t	*_cupsMessageNew(void *context);
extern void		_cupsSetLocale(char *argv[]);


#  ifdef __cplusplus
}
#  endif /* __cplusplus */

#endif /* !_CUPS_LANGUAGE_PRIVATE_H_ */
