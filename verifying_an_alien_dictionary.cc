class Solution {
public:
    // Returns   0    if l == r
    // Returns < 0    if l < r
    // Returns > 0    if l > r
    int AlienStrCmp(const string& l, const string& r, const int char_order_map[26]) {
      int l_index = 0;
      int r_index = 0;
      while (l_index < l.length() && r_index < r.length()) {
        if (l[l_index] != r[r_index]) {
          return char_order_map[l[l_index] - 'a'] - char_order_map[r[r_index] - 'a'];
        }
        l_index++;
        r_index++;
      }
      if (l_index < l.length()) {
        // This means l is greater than r
        return 1;
      }
      if (r_index < r.length()) {
        // This means l is smaller than r
        return -1;
      }
      return 0;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
      int char_order_map[26];
      for (int i = 0; i < order.length(); ++i) {
        char_order_map[order[i] - 'a'] = i;
      }
      for (int i = 1; i < words.size(); ++i) {
        if (AlienStrCmp(words[i-1], words[i], char_order_map) > 0) {
          return false;
        }
      }
      return true;
    }  
};
