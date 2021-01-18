//
// Created by ukio on 30.10.2020.
//

#ifndef SYNCHRONIZER_RING_H
#define SYNCHRONIZER_RING_H

#include <stdint.h>
#define RING_BUFFER_SIZE 32

typedef struct
{
    uint8_t data[RING_BUFFER_SIZE];
    uint16_t in;
    uint16_t out;
} RingBuffer;

uint8_t *ring_block(RingBuffer * ring, int offset);
void ring_write(RingBuffer * ring, uint8_t * data, uint16_t size);
void ring_move_write(RingBuffer * ring, uint8_t * data, uint8_t size);
uint8_t ring_read(RingBuffer * ring);
uint8_t ring_look_previous_data(RingBuffer * ring, int offset);
uint8_t ring_reverse_at(RingBuffer * ring, int offset);
uint16_t ring_data_size(RingBuffer * ring);
void ring_drop(RingBuffer * ring);
void ring_init(RingBuffer * ring);
uint8_t ring_look_next_data(RingBuffer * ring, int offset);
uint8_t ring_look_out(RingBuffer * ring);
uint16_t ring_distance_clockwise(RingBuffer * ring, uint16_t start, uint16_t end);
uint16_t ring_distance_non_clockwise(RingBuffer * ring, uint16_t start, uint16_t end);

#endif //SYNCHRONIZER_RING_H
