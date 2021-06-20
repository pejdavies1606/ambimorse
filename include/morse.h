#ifndef _MORSE_H_
#define _MORSE_H_

#include <stddef.h>

typedef struct morse
{
   const char *plain;
   const char *morse;
} Morse_t;

#define MORSE_TABLE_ALPHA_NUM_LEN 36
#define MORSE_TABLE_FULL_LEN 53
#define MORSE_MAX_LEN_ALPHA 4
#define MORSE_MAX_LEN_NUM 5
#define MORSE_MAX_LEN_PUNC 15 // % = 0/0

extern const Morse_t MORSE_TABLE[MORSE_TABLE_FULL_LEN];

/*
 * Match morse code.
 * @param str Test string
 * @param len Length of test string
 * @return matching morse entry, otherwise NULL
 */
const Morse_t* MorseMatch(char *str, size_t len);

#endif
