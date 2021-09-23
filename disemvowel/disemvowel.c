#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "disemvowel.h"

char *disemvowel(char *str) {

  int i;
  for(i = 0; i < strlen(str); i++) {
  }
  return (char*) "";
}

/*
 * This method checks whether a given charcter is a vowel (upper or lowercase)
 * and returns true if it is, false otherwise.
*/
bool isVowel(char letter) {
  char lowercaseLetter = tolower(letter);
  if(lowercaseLetter == "a" || lowercaseLetter == "e"
	|| lowercaseLetter == "i"  || lowercaseLetter == "o" || lowercaseLetter == "u") {
    return true;
  } else {
    return false;
  }
}
