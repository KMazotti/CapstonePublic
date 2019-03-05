/*
 * circBuffer.c
 *
 *  Created on: Feb 20, 2019
 *      Author: Kaitlin Mazotti
 */

#include "circBuffer.h"
#include <stdlib.h>

void init_buffer(CircBuf* buf, uint32_t len) {
    buf->len = len;
    buf->n = 0;

    // Allocate memory for buffer
    buf->buffer = malloc(len);
    buf->head = buf->buffer;
    buf->tail = buf->buffer;
}

void clear_buffer(CircBuf* buf) {
    // Clear the buffer by setting parameters to initial state
    buf->n = 0;
    buf->head = buf->buffer;
    buf->tail = buf->buffer;
}

void delete_buffer(CircBuf* buf) {
    free(buf->buffer);
}

uint8_t buffer_full(CircBuf* buf) {
    return (buf->n == buf->len) ? 1 : 0;
}

uint8_t buffer_empty(CircBuf* buf) {
    return (buf->n == 0) ? 1 : 0;
}

uint8_t buffer_push(CircBuf* buf, uint8_t item) {
    if (buffer_full(buf)) {
        return 0;
    }

    uint8_t* new_head = buf->tail + buf->n;
    if (new_head > (buf->buffer + buf->len - 1)) {
        // Wrap the buffer around if need be
        new_head -= buf->len;
    }

    buf->head = new_head;
    *(buf->head) = item;
    buf->n++;
    return 1;
}

uint8_t buffer_pop(CircBuf* buf) {
    if (buf->n == 0) {
        return 0;
    }

    uint8_t item = *(buf->tail);
//  *(buf->tail) = '#'; // Temporary testing line

    buf->tail++;
    if (buf->tail > (buf->buffer + buf->len - 1)) {
        buf->tail -= buf->len;
    }

    buf->n--;
    return item;
}
