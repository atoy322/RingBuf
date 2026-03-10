#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ringbuf.h"


rb_status_t rb_init(ringbuf_t *rbuf, uint32_t bufsize) {
    rbuf->head = 0;
    rbuf->tail = 0;
    rbuf->bufsize = bufsize;
    rbuf->buf = (uint8_t *)calloc(bufsize, sizeof(uint8_t));
    if(rbuf->buf == NULL) {
        return RB_FAIL;
    }

    return RB_OK;
}

rb_status_t rb_free(ringbuf_t *rbuf) {
    free(rbuf->buf);
    return RB_OK;
}

// head
// [ 0] [ 1] [ 2] [ 3] [ 4] [ 5]   -> full
//      tail
uint8_t rb_isfull(ringbuf_t *rbuf) {
    return ((rbuf->head+1) & (rbuf->bufsize-1)) == rbuf->tail;
}

//      head
// [ 0] [ 1] [ 2] [ 3] [ 4] [ 5]   -> empty
//      tail
uint8_t rb_isempty(ringbuf_t *rbuf) {
    return rbuf->head == rbuf->tail;
}

rb_status_t rb_push(ringbuf_t *rbuf, uint8_t item) {
    if(rb_isfull(rbuf)) {
        return RB_FULL;
    }

    rbuf->buf[rbuf->head] = item;
    rbuf->head++;

    rbuf->head = rbuf->head & (rbuf->bufsize-1); // 繰り上げを無視

    return RB_OK;
}

rb_status_t rb_pop(ringbuf_t *rbuf, uint8_t *item) {
    if(rb_isempty(rbuf)) {
        return RB_EMPTY;
    }

    *item = rbuf->buf[rbuf->tail];
    rbuf->tail++;

    rbuf->tail = rbuf->tail & (rbuf->bufsize-1); // 繰り上げを無視

    return RB_OK;
}

void rb_debug(ringbuf_t *rbuf) {
    for(uint32_t i=0; i<rbuf->bufsize; i++) {
        printf("%3d ", rbuf->buf[i]);
    }
    printf("Head:%d Tail:%d Empty:%d Full:%d\r\n", rbuf->head, rbuf->tail, rb_isempty(rbuf), rb_isfull(rbuf));
}