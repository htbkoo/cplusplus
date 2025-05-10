#include <gtest/gtest.h>
#include <string>

#include "rot13.cc"

TEST(Rot13, Examples) {
  std::string str, rot;

  str = "EBG13 rknzcyr.";
  rot = "ROT13 example.";
  EXPECT_EQ(rot13(str), rot) << "Incorrect answer for str=\"" << str << "\"";

  str = "This is my first ROT13 excercise!";
  rot = "Guvf vf zl svefg EBG13 rkprepvfr!";
  EXPECT_EQ(rot13(str), rot) << "Incorrect answer for str=\"" << str << "\"";

  str = "123";
  rot = "123";
  EXPECT_EQ(rot13(str), rot) << "Incorrect answer for str=\"" << str << "\"";

  str = "@[`{";
  rot = "@[`{";
  EXPECT_EQ(rot13(str), rot) << "Incorrect answer for str=\"" << str << "\"";

  str = "";
  rot = "";
  EXPECT_EQ(rot13(str), rot) << "Incorrect answer for str=\"" << str << "\"";

  str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnop!@#$%^&*-+=?,qrstuvwxyz8231564970";
  rot = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabc!@#$%^&*-+=?,defghijklm8231564970";
  EXPECT_EQ(rot13(str), rot) << "Incorrect answer for str=\"" << str << "\"";
}