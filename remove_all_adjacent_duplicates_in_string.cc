class Solution {
public:
    string removeDuplicates(string s) {
      std::vector<char> working_set;
      for (int i = 0; i < s.length(); i++) {
        if (working_set.empty()) {
          working_set.push_back(s[i]);
          continue;
        }
        if (s[i] == working_set.back()) {
          working_set.pop_back();
          continue;
        }
        working_set.push_back(s[i]);
      }
      return std::string(working_set.begin(), working_set.end());
    }
};
