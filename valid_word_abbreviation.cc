class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
      int word_index = 0;
      int number = 0;
      for (int i = 0; i < abbr.length(); ++i) {
        if (word_index >= word.length()) {
          return false;
        }
        if (isdigit(abbr[i])) {
          number = number * 10;
          number += abbr[i] - '0';
          if (number <= 0 || number > (word.length() - word_index)) {
            return false;
          }
          continue;
        } 
        if (number > 0) {
          word_index += number;
          number = 0;
        }
        if (word[word_index] != abbr[i]) {
            return false;
        }
        ++word_index;
      }
      
      return word_index + number == word.length();  
    }
};
