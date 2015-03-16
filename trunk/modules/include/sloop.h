/* vi: set sw=4 ts=4: */
/*
 * Select loop
 *
 */

#ifndef __SLOOP_HEADER_H__
#define __SLOOP_HEADER_H__

#ifdef __cplusplus
extern "C" {
#endif

/* default define */
#ifndef DEBUG_SLOOP
#define DEBUG_SLOOP			0
#endif
#ifndef DEBUG_SLOOP_DUMP
#define DEBUG_SLOOP_DUMP	1
#endif

#ifndef MAX_SLOOP_SOCKET
#define MAX_SLOOP_SOCKET	128
#endif
#ifndef MAX_SLOOP_SIGNAL
#define MAX_SLOOP_SIGNAL	16
#endif
#ifndef MAX_SLOOP_TIMEOUT
#define MAX_SLOOP_TIMEOUT	128
#endif

typedef void * sloop_handle;

typedef int (*sloop_socket_handler)(int sock, void * param, void * sloop_data);
typedef int (*sloop_signal_handler)(int sig, void * param, void * sloop_data);
typedef void (*sloop_timeout_handler)(void * param, void * sloop_data);

/* export functoin prototype */
long sloop_uptime(void);
void sloop_init(void * sloop_data);
sloop_handle sloop_register_read_sock(int sock, sloop_socket_handler handler, void * param);
sloop_handle sloop_register_write_sock(int sock, sloop_socket_handler handler, void * param);
sloop_handle sloop_register_signal(int sig, sloop_signal_handler handler, void * param);
sloop_handle sloop_register_timeout(unsigned int secs, unsigned int usecs, sloop_timeout_handler handler, void * param);
void sloop_cancel_read_sock(sloop_handle handle);
void sloop_cancel_write_sock(sloop_handle handle);
void sloop_cancel_signal(sloop_handle handle);
void sloop_cancel_timeout(sloop_handle handle);
void sloop_run(void);
void sloop_terminate(void);

#if DEBUG_SLOOP_DUMP
void sloop_dump_readers(void);
void sloop_dump_writers(void);
void sloop_dump_timeout(void);
void sloop_dump_signals(void);
void sloop_dump(void);
#endif

#ifdef __cplusplus
}
#endif

#endif
