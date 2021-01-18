//
// Created by ukio_pc on 9/2/20.
//

#ifndef REGISTRATOR_NG_CRC_FUNCTIONS_H
#define REGISTRATOR_NG_CRC_FUNCTIONS_H

#include <cstdint>
#include <cstdio>

static uint16_t		    crc_ccitt_generic( const unsigned char *input_str, size_t num_bytes, uint16_t start_value );
static void             init_crcccitt_tab( void );

static bool             crc_tabccitt_init = false;
static uint16_t         crc_tabccitt[256];

uint16_t crc_ccitt_ffff(const unsigned char *input_str, size_t num_bytes );

#define		CRC_START_CCITT_FFFF	0xFFFF
#define		CRC_POLY_CCITT		    0x1021

#endif //REGISTRATOR_NG_CRC_FUNCTIONS_H
