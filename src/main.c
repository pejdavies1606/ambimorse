#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "ambimorse.h"

typedef struct TestCase
{
   const char *input;
   const char *output;
} TestCase_t;

#define TEST_TABLE_LEN 1
static const TestCase_t TEST_TABLE[TEST_TABLE_LEN] =
{
   {
      "..---",
      "EAM\n"
         "EATT\n"
         "EEMT\n"
         "EEO\n"
         "EETM\n"
         "EETTT\n"
         "EJ\n"
         "EWT\n"
         "IMT\n"
         "IO\n"
         "ITM\n"
         "ITTT\n"
         "UM\n"
         "UTT\n"
         "2\n"
   }
};

int main(int argc, char **argv)
{
   Result_e result = RESULT_UNKNOWN;
   char *output = NULL;
   size_t outputLen = 0;
   size_t inputPos = 0;
   size_t outputPos = 0;
   bool pass = false;

   for (int i = 0; i < TEST_TABLE_LEN; i++)
   {
      outputLen = MORSE_MAX_LEN_NUM * strlen(TEST_TABLE[i].input);
      output = malloc(outputLen * sizeof(char));
      if (output)
      {
         memset(output, 0, outputLen * sizeof(char));
         result = AmbiMorse(
               TEST_TABLE[i].input,
               strlen(TEST_TABLE[i].input),
               &inputPos,
               output,
               outputLen,
               &outputPos,
               MORSE_MAX_LEN_NUM);
         pass = (output && outputLen > 0);
         printf("%d: %s : %s\n%s",
               i,
               pass ? "PASS" : "FAIL",
               TEST_TABLE[i].input,
               output);
         free(output);
         output = NULL;
      }
   }

   return 0;
}
