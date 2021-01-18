//
// Created by ukio_pc on 9/2/20.
//
#include "crc_functions.h"

uint16_t crc_ccitt_ffff(const unsigned char *input_str, size_t num_bytes ) {
    return crc_ccitt_generic( input_str, num_bytes, CRC_START_CCITT_FFFF );
}  /* crc_ccitt_ffff */

/*
 * static uint16_t crc_ccitt_generic( const unsigned char *input_str, size_t num_bytes, uint16_t start_value );
 *
 * The function crc_ccitt_generic() is a generic implementation of the CCITT
 * algorithm for a one-pass calculation of the CRC for a byte string. The
 * function accepts an initial start value for the crc.
 */

static uint16_t crc_ccitt_generic( const unsigned char *input_str, size_t num_bytes, uint16_t start_value ) {

    uint16_t crc;
    uint16_t tmp;
    uint16_t short_c;
    const unsigned char *ptr;
    size_t a;

    if ( ! crc_tabccitt_init ) init_crcccitt_tab();

    crc = start_value;
    ptr = input_str;

    if ( ptr != NULL ) for (a=0; a<num_bytes; a++) {

            short_c = 0x00ff & (unsigned short) *ptr;
            tmp     = (crc >> 8) ^ short_c;
            crc     = (crc << 8) ^ crc_tabccitt[tmp];

            ptr++;
        }

    return crc;

}

/* crc_ccitt_generic */

/*
 * uint16_t update_crc_ccitt( uint16_t crc, unsigned char c );
 *
 * The function update_crc_ccitt() calculates a new CRC-CCITT value based on
 * the previous value of the CRC and the next byte of the data to be checked.
 */

uint16_t update_crc_ccitt( uint16_t crc, unsigned char c ) {

    int16_t tmp;
    int16_t short_c;

    short_c  = 0x00ff & (uint16_t) c;

    if ( ! crc_tabccitt_init ) init_crcccitt_tab();

    tmp = (crc >> 8) ^ short_c;
    crc = (crc << 8) ^ crc_tabccitt[tmp];

    return crc;

}  /* update_crc_ccitt */

/*
 * static void init_crcccitt_tab( void );
 *
 * For optimal performance, the routine to calculate the CRC-CCITT uses a
 * lookup table with pre-compiled values that can be directly applied in the
 * XOR action. This table is created at the first call of the function by the
 * init_crcccitt_tab() routine.
 */

static void init_crcccitt_tab( void ) {

    uint16_t i;
    uint16_t j;
    uint16_t crc;
    uint16_t c;

    for (i=0; i<256; i++) {

        crc = 0;
        c   = i << 8;

        for (j=0; j<8; j++) {

            if ( (crc ^ c) & 0x8000 ) crc = ( crc << 1 ) ^ CRC_POLY_CCITT;
            else                      crc =   crc << 1;

            c = c << 1;
        }

        crc_tabccitt[i] = crc;
    }

    crc_tabccitt_init = true;

}  /* init_crcccitt_tab */
