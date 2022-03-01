#ifndef __COMMON_DEFINES_H__
#define __COMMON_DEFINES_H__

/*
 * Help suppress some compiler warnings
 * No problem if variable is actually used
*/
#ifdef UNUSED
#elif defined(__GNUC__)
# define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__LCLINT__)
# define UNUSED(x) /*@unused@*/ UNUSED_ ## x
#else
# define UNUSED(x) UNUSED_ ## x
#endif

#ifdef UNUSED_FUNCTION
#elif __GNUC__
#  define UNUSED_FUNCTION(x) __attribute__((__unused__)) UNUSED_FUNCTION_ ## x
#else
#  define UNUSED_FUNCTION(x) UNUSED_FUNCTION_ ## x
#endif

#ifndef max
#  define max(a,b) \
       ({ __typeof__ (a) _a = (a); \
           __typeof__ (b) _b = (b); \
       _a > _b ? _a : _b; })
#endif

#ifndef min
#  define min(a,b) \
       ({ __typeof__ (a) _a = (a); \
           __typeof__ (b) _b = (b); \
       _a > _b ? _b : _a; })
#endif

#endif /* __COMMON_DEFINES_H__ */

