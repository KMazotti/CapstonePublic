/*
 * circBuffer.h
 *
 *  Created on: Feb 20, 2019
 *      Author: Kaitlin Mazotti
 */

#ifndef CIRCBUFFER_H_
#define CIRCBUFFER_H_

#include <stdint.h>

typedef struct CircBuf_t {
    volatile uint8_t* head; // Pointer to first item
    volatile uint8_t* tail; // Pointer to last item
    volatile uint32_t n;    // Number of items in buffer
    volatile uint32_t len;  // Max number of items the buffer can hold
    uint8_t* buffer;        // Pointer to beginning of buffer in heap
} CircBuf;

// Buffer creation and destruction
void init_buffer(CircBuf* buf, uint32_t len);
void clear_buffer(CircBuf* buf);
void delete_buffer(CircBuf* buf);

// Buffer status
uint8_t buffer_full(CircBuf* buf);
uint8_t buffer_empty(CircBuf* buf);

// Buffer item management
uint8_t buffer_push(CircBuf* buf, uint8_t item);
uint8_t buffer_pop(CircBuf* buf);


#endif /* CIRCBUFFER_H_ */
