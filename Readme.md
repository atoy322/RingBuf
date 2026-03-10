# Ring buffer implementation

```C:example.c
uint8_t i=10;
ringbuf_t rb;

rb_init(&rb, 1024); // must be 2^N
rb_push(&rb, i); // returns RB_FULL if there is no space to store data
rb_pop(&rb, &i); // returns RB_EMPTY if there is no data

rb_free(&rb);
```
