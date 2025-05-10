#include <string>

int ORD_UPPER_A = (int) 'A';
int ORD_UPPER_Z = (int) 'Z';
int ORD_LOWER_A = (int) 'a';
int ORD_LOWER_Z = (int) 'z';

int ROT_13_ROTATION = 13;

char decipherCh(char ch) {
    int o = (int) ch;

    if (ORD_UPPER_A <= o && o <= ORD_UPPER_Z) {
        return (char) (ORD_UPPER_A + ((o - ORD_UPPER_A) + ROT_13_ROTATION) % (ORD_UPPER_Z - ORD_UPPER_A + 1));
    }

    if (ORD_LOWER_A <= o && o <= ORD_LOWER_Z) {
        return (char) (ORD_LOWER_A + ((o - ORD_LOWER_A) + ROT_13_ROTATION) % (ORD_LOWER_Z - ORD_LOWER_A + 1));
    }

    return ch;
}

std::string rot13(const std::string &str) {
    //your code here
    std::string deciphered(str);

    for (int i = 0; i < deciphered.length(); ++i) {
        deciphered[i] = decipherCh(str[i]);
    }

    return deciphered;
}
