#include <string>
#include <vector>

std::string encrypt(std::string text, int n)
{
    if (n <= 0 || text.size() == 0) {
      return text;
    }
    
    std::string odd;
    std::string even;

    for (int i = 0; i < text.size(); i++) {
      if (i % 2 == 0) {
        even += text[i];
      } else {
        odd += text[i];
      }
    }

    return encrypt(odd + even, n - 1);
}

std::string decrypt(std::string encryptedText, int n)
{
    if (n <= 0 || encryptedText.size() == 0) {
      return encryptedText;
    }
    
    int oddSize = encryptedText.size() / 2;
    int o = 0, e = oddSize;
    
    std::string text;
    for (int i = 0; i < oddSize; i++) {
      text += encryptedText[e + i];
      text += encryptedText[o + i];
    }

    if (encryptedText.size() % 2 != 0) {
      text += encryptedText[encryptedText.size() - 1];
    }

    return decrypt(text, n - 1);
}