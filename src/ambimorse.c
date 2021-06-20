#include "ambimorse.h"
#include "morse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Result_e AmbiMorse(
   const char *input,
   size_t      inputLen,
   size_t     *inputPos,
   char       *output,
   size_t      outputLen,
   size_t     *outputPos,
   int         morseLenMax)
{
   Result_e result = RESULT_FAILURE;
   if (input && 
       inputLen > 0 &&
       inputPos &&
       *inputPos < inputLen &&
       output &&
       outputLen > 0 &&
       outputPos &&
       *outputPos < outputLen &&
       morseLenMax > 0 &&
       morseLenMax <= MORSE_MAX_LEN_NUM)
   {
      for (int morseLen = morseLenMax; morseLen > 0; morseLen--)
      {
         if (*inputPos == 0)
         {
            printf("*:%s\n", input);
         }
         const Morse_t *morse = NULL;
         char test[MORSE_MAX_LEN_NUM + 1] = { 0 };
         size_t inputPosNext = *inputPos + morseLen;
         if (inputPosNext <= inputLen)
         {
            memset(test, 0, MORSE_MAX_LEN_NUM + 1);
            memcpy(test, &input[*inputPos], morseLen);
            printf(" :%*s%s", *inputPos, "", test);
            morse = MorseMatch(test, morseLen);
            if (morse)
            {
               printf("[%s]\n", morse->plain);
               output[*outputPos] = morse->plain[0];
               *outputPos += 1;
               // TODO call AmbiMorse recursively
               if (inputPosNext < inputLen)
               {
                  result = AmbiMorse(
                      input, inputLen, &inputPosNext,
                      output, outputLen, outputPos,
                      morseLen);
               }
            }
            else
            {
               printf("\n");
            }
         }
         else
         {
            output[*outputPos] = '\n';
            *outputPos += 1;
         }
      }
   }
   return result;
}

