class Solution {
public:
  bool isValidCharacter(char c) {
    if (c >= 'a' && c <= 'z') {
      return true;
    }
    if (c >= 'A' && c <= 'Z') {
      return true;
    }
    if (c >= '0' && c <= '9') {
      return true;
    }
    return false;
  }
    bool isPalindrome(string s) {
      int left = 0; 
      int right = s.length() - 1;
      while (left < right) {
        if (!isValidCharacter(s[left])) {
          left++;
          continue;
        }
        if (!isValidCharacter(s[right])) {
          right--;
          continue;
        }
        if (tolower(s[left]) != tolower(s[right])) {
          return false;
        }
        left++;
        right--;
      }
      return true;
    }
};
