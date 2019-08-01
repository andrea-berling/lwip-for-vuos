#include <addons/socket_event/socket_event.h>
#include <stdlib.h>

int (*socket_event_callback)(int, unsigned char, void*, int*) = NULL;
void *socket_event_arg = NULL;

int my_hook_socket_event(int s, unsigned char events, int *err) {
    if (socket_event_callback)
        return socket_event_callback(s, events, socket_event_arg, err);
    else
        return -1;
}

int register_socket_event_callback(int (*cb)(int, unsigned char, void*, int*), void *arg) {
    if (!socket_event_callback)
    {
        socket_event_callback = cb;
        socket_event_arg = arg;
        return 0;
    }
    else
        return -1;
}
