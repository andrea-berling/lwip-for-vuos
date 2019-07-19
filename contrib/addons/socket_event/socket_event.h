#ifndef SOCKET_EVENT_H
#define SOCKET_EVENT_H

extern int (*socket_event_callback)(int, int, int, int, int*);

int my_hook_socket_event(int s, int has_recvevent, int has_sendevent, int has_errevent, int *err);

int register_socket_event_callback(int (*cb)(int, int, int, int, int*));

#define LWIP_HOOK_SOCKET_EVENT(s, has_recvevent, has_sendevent, has_errevent, err) my_hook_socket_event(s, has_recvevent, has_sendevent, has_errevent, err)

#endif /* SOCKET_EVENT_H */
