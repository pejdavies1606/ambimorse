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
         "2"
   }
};

int main(int argc, char **argv)
{
   Result_e result = RESULT_UNKNOWN;
   char *output;
   size_t outputLen;
   bool pass = false;

   for (int i = 0; i < TEST_TABLE_LEN; i++)
   {
      result = AmbiMorse(
            TEST_TABLE[i].input,
            strlen(TEST_TABLE[i].input),
            &output,
            &outputLen);
      pass = (output && outputLen > 0);
      printf("%d: %s : %s\n%s\n",
            i,
            pass ? "PASS" : "FAIL",
            TEST_TABLE[i].input,
            output);
   }

   return 0;
}
