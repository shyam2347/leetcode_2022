class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int string_length = s.size();
        std::map<char, int> active_map;
        int start_index = 0;
        int output = 0;
        for (int i = 0; i < string_length; i++) {
            if (active_map.find(s[i]) != active_map.end()) {
                // Clear only conflicting entries
                int conflicting_index = active_map[s[i]];
                for (int j = start_index; j <= conflicting_index; j++) {
                    active_map.erase(s[j]);
                }
                start_index = conflicting_index + 1;
            }
            active_map[s[i]] = i;
            if (active_map.size() > output) {
                output = active_map.size();
            }
        }
        return output;
    }
};

// Version 2
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int string_length = s.size();
        int map[256]; // Map of char to index
        std::fill_n(map, 256, -1);
        int start_index = 0;
        int result = 0;
        for (int i = 0; i < string_length; i++) {
          if (map[s[i]] != -1 && map[s[i]] >= start_index) {
            start_index = map[s[i]] + 1;
          }
          map[s[i]] = i;
          if (i - start_index + 1 > result) {
            result = i - start_index + 1;
          }
        }
        return result;
    }
};
