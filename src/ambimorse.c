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
         int morseLenTest = morseLen;
         int i = 0;
         Morse_t *morse = NULL;
         do
         {
            memset(test, 0, MORSE_MAX_LEN_NUM);
            memcpy(test, &input[i], morseLenTest);
            printf(" :%*s%s", i, "", test);
            // TODO
            // Catch short tail
            // if (i + morseLen > inputLen) morseLen--;
            // Repeat MorseFind with reduced morseLen
            // until (i >= (inputLen - 1)) || (morseLen == 0)
            morse = MorseMatch(test, morseLenTest);
            if (morse)
            {
               printf("[%s]", morse->plain);
               buffer[plain++] = morse->plain[0];
               i += morseLen;
            }
            printf("\n");
            if (i + morseLen > inputLen) morseLenTest--;
         }
         while (i + morseLenTest <= inputLen &&
               morse &&
               morseLenTest > 0);
         buffer[plain++] = '\n';
      }
      *outputLen = strlen(buffer);
      *output = buffer;
   }
   return result;
}

