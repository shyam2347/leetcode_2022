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
