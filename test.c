#include "ringbuf.h"

int main() {
    unsigned char item=0;
    ringbuf_t rb;

    rb_init(&rb, 4);
    rb_debug(&rb);

    for(int i=0; i<5; i++) {
        rb_push(&rb, item++);
        rb_debug(&rb);
    }

    for(int i=0; i<5; i++) {
        rb_pop(&rb, &item);
        rb_debug(&rb);
    }

    rb_free(&rb);

    return 0;
}
