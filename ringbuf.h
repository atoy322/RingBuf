#ifndef RINGBUF_H
#define RINGBUF_H

#include <stdint.h>

typedef enum {
    RB_OK = 0,
    RB_FAIL,
    RB_FULL,
    RB_EMPTY
} rb_status_t;

typedef struct {
    uint32_t head;
    uint32_t tail;
    uint8_t *buf;
    uint32_t bufsize; // must be 2^N
} ringbuf_t;

rb_status_t rb_init(ringbuf_t *rbuf, uint32_t bufsize);
rb_status_t rb_free(ringbuf_t *rbuf);
uint8_t rb_isfull(ringbuf_t *rbuf);
uint8_t rb_isempty(ringbuf_t *rbuf);
rb_status_t rb_push(ringbuf_t *rbuf, uint8_t item);
rb_status_t rb_pop(ringbuf_t *rbuf, uint8_t *item);

void rb_debug(ringbuf_t *rbuf);

#endif