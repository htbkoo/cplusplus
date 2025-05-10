#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "coding_with_squared_strings.cc"

TEST(CodingWithSquaredStrings, Tests_CodeDecode) {
    std::string d = "What do you remember? When I looked at his streaky glasses, I wanted "
    "to leave him. And before that? He stole those cherries for me at midnight. We were walking "
    "in the rain and I loved him. And before that? I saw him coming "
    "toward me that time at the picnic, edgy, foreign.";
    std::string s = "\013ctg?.nadr d gdbW\n\013,i    lnis tl eh\n\013 mtIAakietboaara\n\013eeo nnigsoe st?t\n\013d wsddnh lfls   \n\013gaaa  gtfeoeehWd\n"
    "\013ytrwbI .o rasiho\n\013, d e i rtev,se \n\013 t hflnW h e  ny\n\013fhmioo emot Is o\n\013oeemrvt eshh tIu\n\013r   eehw eaiwr  \n"
    "\013eptc deea tmaelr\n\013iihot  rtc?.naoe\n\013gcamhhre h  tkom\n\013nntiaia meHAeyke\n\013.i ntmiwirend em";
    EXPECT_EQ(CodeSqStrings::code(d), s);
    EXPECT_EQ(CodeSqStrings::decode(s), d);

    d = "Some say the world will end in fire, Some say in ice. From what I've tasted of desire "
    "I hold with those who favor fire. But if it had to perish twice, I think I know enough of hate"
    " To say that for destruction ice Is also great And would suffice.";
    s = "fa  h ttrheI ilS\nitifakw   s'irdo\nc cotnihftivce m\neAereocaihree,we\n.n   wedroe . i \n\013dIdT , es t Sls\n\013 seoe t.eIaFola\n"
    "\013w s nIo   srm y\n\013oatso  Bwhtoee \n\013ulrautpuhoem nt\n\013lsuyghetold sdh\n\013doc hir  d wa e\n\013  tt niif ohyi \n\013sgihoksfawfa nw\n"
    "\013uroaf h vi ti o\n\013fent I iotd nfr";
    EXPECT_EQ(CodeSqStrings::code(d), s);
    EXPECT_EQ(CodeSqStrings::decode(s), d);
}