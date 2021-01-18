//
// Created by ukio on 30.10.2020.
//

#include "ring.h"
#include "string.h"

uint8_t *ring_block(RingBuffer * ring, int offset) {
    static uint8_t result[RING_BUFFER_SIZE];

    int bound_index;
    offset = offset % RING_BUFFER_SIZE;
    if(offset > ring->out)
        bound_index = RING_BUFFER_SIZE - (offset - ring->out);
    else
        bound_index = ring->out - offset;

    if (bound_index == 0)
        return ring->data;
    /* copy start data */
    memmove(result, ring->data+bound_index, RING_BUFFER_SIZE - bound_index);

    /* copy end data */
    memcpy(result + (RING_BUFFER_SIZE - bound_index), ring->data, bound_index);
    return result;
}

void ring_write(RingBuffer * ring, uint8_t * data, uint16_t size) {
    for (int i = 0; i < size; ++i) {
        ring->data[ring->in] = data[i];
        ring->in++;
        if(ring->in == RING_BUFFER_SIZE) {
            ring->in = 0;
        }
    }
}

void ring_move_write(RingBuffer * ring, uint8_t * data, uint8_t size) {
    for (int i = 0; i < size; ++i) {
        ring->data[ring->in] = data[i];
        ring->out = ring->in;
        ring->in++;
        if(ring->in == RING_BUFFER_SIZE) {
            ring->in = 0;
        }
    }
}

uint8_t ring_read(RingBuffer * ring){
    uint8_t result = ring->data[ring->out];
    ring->out++;
    if(ring->out == RING_BUFFER_SIZE) {
        ring->out = 0;
    }
    return result;
}

uint16_t ring_data_size(RingBuffer * ring){
    if(ring->in == ring->out) return 0;
    if (ring->in > ring->out) return (ring->in - ring->out);
    return RING_BUFFER_SIZE - ring->out + ring->in;
}

uint8_t ring_look_previous_data(RingBuffer * ring, int offset){
    int delta = (int)ring->in - offset;
    if(delta < 0)
        delta = RING_BUFFER_SIZE + delta;
    return ring->data[delta];
}

uint8_t ring_look_next_data(RingBuffer * ring, int offset){
    int read_position = (int)ring->out + offset;
    if(read_position <= RING_BUFFER_SIZE)
        read_position = read_position - RING_BUFFER_SIZE;
    return ring->data[read_position];
}

void ring_drop(RingBuffer * ring) {
    ring->out = ring->in;
}

void ring_init(RingBuffer * ring)
{
    ring->in = 0;
    ring->out = 0;
}

uint8_t ring_reverse_at(RingBuffer * ring, int offset)
{
    int delta = (int)ring->out - offset;
    if(delta < 0)
        delta = RING_BUFFER_SIZE + delta;
    return ring->data[delta];
}

uint8_t ring_look_out(RingBuffer * ring)
{
    return ring->data[ring->out];
}

uint16_t ring_distance_clockwise(RingBuffer * ring, uint16_t start, uint16_t end)
{
    start = start % RING_BUFFER_SIZE;
    end = end % RING_BUFFER_SIZE;
    if(start > end) {
        return RING_BUFFER_SIZE - start + end;
    }
    return end - start;
}

uint16_t ring_distance_non_clockwise(RingBuffer * ring, uint16_t start, uint16_t end)
{
    start = start % RING_BUFFER_SIZE;
    end = end % RING_BUFFER_SIZE;
    if(end - start)
        return RING_BUFFER_SIZE - end + start;
    return start - end;
}