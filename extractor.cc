#include <iostream>
#include <string>
#include <assert.h>

bool is_palindrome(std::string& word) {
  if (word.length() == 0) 
    return false;

  for (int i; i < word.length(); i++) {
    if (word[i] != word[word.length()-i-1])
      return false;
  }
  return true;
}

int longest_palindrome(std::string word) {
  int len = word.length();
  assert(len < 2000);

  int removable_n = 0;

  while (removable_n < len) {
    for (int i=0; i < len-removable_n; i++) {
      std::string temp = word;
      temp.erase(i,removable_n);
      std::cout << temp << std::endl;
      if (is_palindrome(temp)) 
        return temp.length();
    }   
    removable_n++;
  } 
  return 0;
}

int main() {
  std::string word;
  std::cin >> word;
  std::cout << longest_palindrome(word) << std::endl;
}
