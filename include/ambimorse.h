#ifndef _AMBIMORSE_H_
#define _AMBIMORSE_H_

#include <stddef.h>
#include <stdlib.h>
#include "morse.h"

typedef enum result
{
   RESULT_SUCCESS,
   RESULT_FAILURE,
   RESULT_UNKNOWN
} Result_e;

/* Decodes ambiguous morse into possible translations.
 * @param input Morse to decode.
 * @param inputLen Length of input string.
 * @param inputPos Pointer to position in input string.
 * @param output Newline delimited string of possible translations.
 * @param outputLen Length of output string.
 * @param outputPos Pointer to position in output string.
 * @return result.
 */
Result_e AmbiMorse(
   const char *input,
   size_t      inputLen,
   size_t     *inputPos,
   char       *output,
   size_t      outputLen,
   size_t     *outputPos,
   int         morseLenMax);

#endif
