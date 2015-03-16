/* vi: set sw=4 ts=4: */
/*
 * APIs to use unix domain socket with DGRAM
 * by david_hsieh@alphanetworks.com
 */

#ifndef __USOCK_HEADER__
#define __USOCK_HEADER__

typedef void * usock_handle;

#ifdef __cplusplus
extern "C" {
#endif
/***********************************************************************/

int usock_fd(usock_handle usock);
usock_handle usock_open(int server, const char * name);
void usock_close(usock_handle usock);
int usock_send(usock_handle usock, const void * buf, unsigned int len, int flags);
int usock_recv(usock_handle usock, void * buf, unsigned int len, int flags);
int usock_recv_timed(usock_handle usock, void * buf, unsigned int len, int flags, int timeout);

/***********************************************************************/
#ifdef __cplusplus
}
#endif

#endif	// #ifndef __USOCK_HEADER__
