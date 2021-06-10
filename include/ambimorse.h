#ifndef _AMBIMORSE_H_
#define _AMBIMORSE_H_

#include <stddef.h>

typedef enum result
{
   RESULT_SUCCESS,
   RESULT_FAILURE,
   RESULT_UNKNOWN
} Result_e;

/* Decodes ambiguous morse into possible translations.
 * @param input Morse to decode.
 * @param inputLen Length of input string.
 * @param output Newline delimited string of possible translations.
 * @param outputLen Length of output string.
 * @return result.
 */
Result_e AmbiMorse(
   const char *input,
   size_t inputLen,
   char **output,
   size_t *outputLen);

#endif
