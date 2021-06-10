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
         printf("i:%s\n", input);
         int start = 0;
         int m = 0;
         int f = 0;
         memset(test, 0, MORSE_MAX_LEN_NUM);
         while (start + morseLen <= inputLen &&
               m < MORSE_TABLE_ALPHA_NUM_LEN)
         {
            memcpy(test, &input[start], morseLen);
            printf("t:%*s%s", start, "", test);
            // TODO Create MorseFind(str,morseLen)
            // Catch short tail
            // if (start + morseLen > inputLen) morseLen--;
            // Repeat MorseFind with reduced morseLen
            // until (start == (inputLen - 1)) || (morseLen == 0)
            for (m = 0; m < MORSE_TABLE_ALPHA_NUM_LEN; m++)
            {
               const Morse_t *morse = &MORSE_TABLE[m];
               if (morse)
               {
                  if (strlen(morse->morse) == morseLen)
                  {
                     //printf("m:%*s%s", start, "", morse->morse);
                     char *found = strstr(test, morse->morse);
                     if (found)
                     {
                        printf("[%s]", morse->plain);
                        buffer[plain++] = morse->plain[0];
                        start += morseLen;
                        f = 1;
                        break;
                     }
                     //printf("\n");
                  }
               }
            }
            printf("\n");
         }
         if (f) buffer[plain++] = '\n';
      }
      *outputLen = strlen(buffer);
      *output = buffer;
   }
   return result;
}

