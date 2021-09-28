#include <gtest/gtest.h>

#include "disemvowel.h"

void assert_disemvowel(char* input, char* expectedOutput) {
  char* disemvoweled = disemvowel(input);
  ASSERT_STREQ(expectedOutput, disemvoweled);
  free(disemvoweled);
}

TEST(Disemvowel, HandleEmptyString) {
  assert_disemvowel((char*) "",(char*)  "");
}

TEST(Disemvowel, HandleNoVowels) {
  assert_disemvowel((char*) "pqrst",(char*)  "pqrst");
}

TEST(Disemvowel, HandleOnlyVowels) {
  assert_disemvowel((char*) "aeiouAEIOUOIEAuoiea",(char*)  "");
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  assert_disemvowel((char*) "Morris, Minnesota",(char*)  "Mrrs, Mnnst");
}

TEST(Disemvowel, HandlePunctuation) {
  assert_disemvowel((char*) "An (Unexplained) Elephant!",(char*)  "n (nxplnd) lphnt!");
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char* disemvoweled_str = disemvowel(str);
  ASSERT_STREQ("xyz", disemvoweled_str);

  free(disemvoweled_str);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
