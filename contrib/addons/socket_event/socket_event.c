#include <addons/socket_event/socket_event.h>
#include <stdlib.h>

int (*socket_event_callback)(int, int, int, int, int*) = NULL;

int my_hook_socket_event(int s, int has_recvevent, int has_sendevent, int has_errevent, int *err) {
    if (socket_event_callback)
        return socket_event_callback(s, has_recvevent, has_sendevent, has_errevent, err);
    else
        return -1;
}

int register_socket_event_callback(int (*cb)(int, int, int, int, int*)) {
    if (!socket_event_callback)
    {
        socket_event_callback = cb;
        return 0;
    }
    else
        return -1;
}
