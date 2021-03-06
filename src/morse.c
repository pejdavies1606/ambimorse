#include <string.h>
#include "morse.h"

const Morse_t MORSE_TABLE[MORSE_TABLE_FULL_LEN] = 
{
   { "A", ".-" },
   { "B", "-.." },
   { "C", "-.-." },
   { "D", "-.." },
   { "E", "." },
   { "F", "..-." },
   { "G", "--." },
   { "H", "...." },
   { "I", ".." },
   { "J", ".---" },
   { "K", "-.-" },
   { "L", ".-.." },
   { "M", "--" },
   { "N", "-." },
   { "O", "---" },
   { "P", ".--." },
   { "Q", "--.-" },
   { "R", ".-." },
   { "S", "..." },
   { "T", "-" },
   { "U", "..-" },
   { "V", "...-" },
   { "W", ".--" },
   { "X", "-..-" },
   { "Y", "-.--" },
   { "Z", "--.." },
   { "0", "-----" },
   { "1", ".----" },
   { "2", "..---" },
   { "3", "...--" },
   { "4", "....-" },
   { "5", "....." },
   { "6", "-...." },
   { "7", "--..." },
   { "8", "---.." },
   { "9", "----." },
   { "&", ".-..." },
   { "'", ".----." },
   { "@", ".--.-." },
   { ")", "-.--.-" },
   { "(", "-.--." },
   { ":", "---..." },
   { ",", "--..--" },
   { "=", "-...-" },
   { "!", "-.-.--" },
   { ".", ".-.-.-" },
   { "-", "-....-" },
   { "*", "-..-" },
   { "%", "------..-.-----" },
   { "+", ".-.-." },
   { "\"", ".-..-." },
   { "?", "..--.." },
   { "/", "-..-." },
};

const Morse_t* MorseMatch(char *str, size_t len)
{
   const Morse_t *morse = NULL;
   if (str && len > 0)
   {
      for (int m = 0; m < MORSE_TABLE_ALPHA_NUM_LEN; m++)
      {
         const Morse_t *morse_table = &MORSE_TABLE[m];
         if (morse_table &&
               (strlen(morse_table->morse) == len))
         {
            char *match = strstr(str, morse_table->morse);
            if (match)
            {
               morse = morse_table;
               break;
            }
         }
      }
   }
   return morse;
}
