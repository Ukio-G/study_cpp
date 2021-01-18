#include "string.h"
#include "stdio.h"
#include "ring.h"
#include "crc_functions.h"

#define PRINTMEMORY_CHAR_PER_LINE 18
#define UMRR11_SOME_BYTE_RECEIVED 0
#define UMRR11_HEADER_RECEIVED 1
#define UMRR11_CYCLE_COUNT_RECEIVED 2

void print_memory(uint8_t * buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        if(i % PRINTMEMORY_CHAR_PER_LINE == 0 && i > 0)
            printf("\n");
        if (i > 0 && i % PRINTMEMORY_CHAR_PER_LINE != 0)
            printf(" ");
        printf("%02X", buffer[i]);
    }
    printf("\n");
}

int header_received(RingBuffer * ring)
{
    uint8_t result;

    if (ring_reverse_at(ring, 14) == 0x7E && ring_reverse_at(ring, 2) == 0x05) {
        result =  UMRR11_SOME_BYTE_RECEIVED;
        uint8_t *header_block = ring_block(ring, 14);
        print_memory(header_block, RING_BUFFER_SIZE);
        uint16_t crc_calculated = crc_ccitt_ffff(header_block, 10);
        uint16_t crc_in_header = (uint16_t) header_block[10] << 8 | (uint16_t) header_block[11];
        bool crc_match = (crc_calculated == crc_in_header);
        if (crc_match)
            printf("/* crc match! */ %04X, %04X\n", crc_calculated, crc_in_header);
        if (crc_match && header_block[12] == 0x05 && header_block[13] == 0x00 && header_block[14] == 0x08)
            result =  UMRR11_HEADER_RECEIVED;
        else
            result =  UMRR11_SOME_BYTE_RECEIVED;
    }

    return result;
}


int main() {
    RingBuffer ring;

    uint8_t correct_header[12] = {0x7E, 0x01, 0x0C, 0x00, 0x62, 0x04, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x86};

    uint8_t data[49] = { 0x00, 0xA0, 0x86,
            /* 3 */  0x05, 0x00, 0x08, 0x00, 0x00, 0xC3, 0x2E,          0x00, 0x00, 0x07, 0x82,
            /* 14 */ 0x05, 0x01, 0x08, 0x2C, 0x01, 0xC7, 0xE6, /* 21 */ 0x02, 0x00, 0x92, 0x8A,

                         0x19, 0x07, 0x80, 0x04, 0x00, 0x09, 0x00, 0x00, 0x80, 0x08, 0x89, 0x0B};

    memcpy(ring.data, data, RING_BUFFER_SIZE);
    ring.in = ring.out = 24;
    print_memory(ring.data, RING_BUFFER_SIZE);

//    for (int i = 0; i < RING_BUFFER_SIZE; ++i)
//        print_memory(ring_block(&ring,i), RING_BUFFER_SIZE);
//
//    printf("===== // ===== \n");
//
//    for (int j = 0; j < 10; ++j) {
//        ring_move_write(&ring, data +RING_BUFFER_SIZE + j, 1);
//        print_memory(ring.data, RING_BUFFER_SIZE);
//    }
    printf("last added element %02X\n", ring_reverse_at(&ring,3));
    print_memory(ring_block(&ring,3), RING_BUFFER_SIZE);
    return 0;
}
