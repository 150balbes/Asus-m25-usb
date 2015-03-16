/* vi: set sw=4 ts=4: */
/*
 * dtrace.h
 *
 * A debug/trace helper module.
 *
 * Created by david_hsieh@alphanetworks.com
 * 
 */

#ifndef __DTRACE_HEADER_FILE__
#define __DTRACE_HEADER_FILE__

#include <stdio.h>

/* debug level definitions */
#define DBG_ALL		0
#define DBG_DEBUG	10
#define DBG_INFO	20
#define DBG_WARN	30
#define DBG_ERROR	40
#define DBG_FATAL	50
#define DBG_NONE	100

#ifndef DBG_DEFAULT
#define DBG_DEFAULT	DBG_ERROR
#endif

/* MACROs use for debug/trace/ */
#ifndef DDEBUG

#define dtrace(x, args...)		{}	/* output the debug message. */
#define dassert(x)				{}	/* well, my assert functoin */
#define d_output_file(f)		{}	/* where the output message goes, default is stderr. */
#define d_dbg_level(l)			{}	/* assign the debug level. */

#define d_dbg(x, args...)		{}
#define d_info(x, args...)		{}
#define d_warn(x, args...)		{}
#define d_error(x, args...)		{}
#define d_fatal(x, args...)		{}
#define d_die(x, args...)		{ exit(9); }

#else

#define dtrace(x, args...)		__dtrace(DBG_ALL, x, ##args)
#define dassert(exp)			(void)((exp) || (__dassert(#exp,__FILE__,__LINE__),0))
#define d_output_file(f)		__set_output_file(f)
#define d_dbg_level(l)			__set_dbg_level(l)

#define d_dbg(x, args...)		__dtrace(DBG_DEBUG, x, ##args)
#define d_info(x, args...)		__dtrace(DBG_INFO, x, ##args)
#define d_warn(x, args...)		__dtrace(DBG_WARN, x, ##args)
#define d_error(x, args...)		__dtrace(DBG_ERROR, x, ##args)
#define d_fatal(x, args...)		__dtrace(DBG_FATAL, x, ##args)
#define d_die(x, args...)		{	\
	__dtrace(DBG_FATAL, "DIE, line: %d @ file: %s\n",__LINE__,__FILE__);	\
	__dtrace(DBG_FATAL, x, ##args);	\
	exit(9);						\
	}

#endif /* end of #ifdef DDEBUG */


/***********************************************************************/

#ifdef DDEBUG
#ifdef __cplusplus
extern "C" {
#endif
/*
 * exported function from dtrac.c
 *
 * DO NOT call the following exported function directly.
 * Use the macros above instead.
 */
void	__dtrace(int level, const char * format, ...);
void	__dassert(char * exp, char * file, int line);
FILE *	__set_output_file(const char * fname);
int		__set_dbg_level(int level);

#ifdef __cplusplus
}
#endif

#endif

#endif /* end of #ifndef __DTRACE_HEADER_FILE__ */
