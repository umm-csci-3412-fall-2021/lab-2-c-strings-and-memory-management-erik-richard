#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "disemvowel.h"

/*
 * This method checks whether a given charcter is a vowel (upper or lowercase)
 * and returns true if it is, false otherwise.
*/
bool isVowel(char letter) {
  char lowercaseLetter = tolower(letter);
  if(lowercaseLetter == 'a' || lowercaseLetter == 'e'
	|| lowercaseLetter == 'i'  || lowercaseLetter == 'o' || lowercaseLetter == 'u') {
    return true;
  } else {
    return false;
  }
}


char *disemvowel(char *str) {
  
  int len = strlen(str);
  int i;
  int numOfConsonants = 0;
  for(i = 0; i < len; i++) {
    if(!isVowel(str[i])) {
      numOfConsonants++;
    }
  }

  char *disemvoweledString = (char*) calloc(numOfConsonants + 1, sizeof(char));

  int j;
  int currentIndex = 0;
  for(j = 0; j < len; j++) {
    if(!isVowel(str[j])) {
      disemvoweledString[currentIndex] = str[j];
      currentIndex++;
    }
  }
  disemvoweledString[numOfConsonants] = '\0';
  return disemvoweledString;
}
