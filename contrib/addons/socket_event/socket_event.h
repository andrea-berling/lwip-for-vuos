#ifndef SOCKET_EVENT_H
#define SOCKET_EVENT_H

#define SOCKEVENT_POLLIN 0x1
#define SOCKEVENT_POLLOUT 0x2
#define SOCKEVENT_POLLERR 0x4

#define SOCKEVENT_IS_POLLIN(event) ((event) & SOCKEVENT_POLLIN)
#define SOCKEVENT_IS_POLLOUT(event) ((event) & SOCKEVENT_POLLOUT)
#define SOCKEVENT_IS_POLLERR(event) ((event) & SOCKEVENT_POLLERR)

#define SOCKEVENT_NULL 0
#define SOCKEVENT_SET_POLLIN(event) ((event) |= SOCKEVENT_POLLIN)
#define SOCKEVENT_SET_POLLOUT(event) ((event) |= SOCKEVENT_POLLOUT)
#define SOCKEVENT_SET_POLLERR(event) ((event) |= SOCKEVENT_POLLERR)
#define SOCKEVENT_UNSET_POLLIN(event) ((event) &= ~SOCKEVENT_POLLIN)
#define SOCKEVENT_UNSET_POLLOUT(event) ((event) &= ~SOCKEVENT_POLLOUT)
#define SOCKEVENT_UNSET_POLLERR(event) ((event) &= ~SOCKEVENT_POLLERR)

extern int (*socket_event_callback)(int, unsigned char, void*, int*);

int my_hook_socket_event(int s, unsigned char events, int *err);

int register_socket_event_callback(int (*cb)(int, unsigned char, void* ,int*), void *arg);

#define LWIP_HOOK_SOCKET_EVENT(s, events, err) my_hook_socket_event(s, events, err)

#endif /* SOCKET_EVENT_H */
