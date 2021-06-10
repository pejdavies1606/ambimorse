#include "ambimorse.h"
#include "morse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Result_e AmbiMorse(
   const char *input,
   size_t      inputLen,
   char      **output,
   size_t     *outputLen)
{
   Result_e result = RESULT_FAILURE;
   size_t oLen = 1;
   if (input && inputLen > 0 && output)
   {
      char *buffer = malloc(MORSE_MAX_LEN_NUM * inputLen * sizeof(char));
      memset(buffer, 0, MORSE_MAX_LEN_NUM * inputLen * sizeof(char));
      char test[MORSE_MAX_LEN_NUM] = { 0 };
      int plain = 0;
      for (int morseLen = 1; morseLen <= MORSE_MAX_LEN_NUM; morseLen++)
      {
         printf("*:%s\n", input);
         int start = 0;
         int f = 0;
         memset(test, 0, MORSE_MAX_LEN_NUM);
         Morse_t *morse = NULL;
         do
         {
            memcpy(test, &input[start], morseLen);
            printf(" :%*s%s", start, "", test);
            // TODO
            // Catch short tail
            // if (start + morseLen > inputLen) morseLen--;
            // Repeat MorseFind with reduced morseLen
            // until (start == (inputLen - 1)) || (morseLen == 0)
            morse = MorseMatch(test, morseLen);
            if (morse)
            {
               printf("[%s]", morse->plain);
               buffer[plain++] = morse->plain[0];
               start += morseLen;
               f = 1;
            }
            printf("\n");
         }
         while (start + morseLen <= inputLen && morse);
         if (f) buffer[plain++] = '\n';
      }
      *outputLen = strlen(buffer);
      *output = buffer;
   }
   return result;
}

