class Solution {
public:
  class QuickUnion {
    public:
      QuickUnion(int size) : root(size) {
        for (int i = 0; i < size; i++) {
          root[i] = i;
        }
        distinct_sets = size;
      }
      int find(int x) {
        if (x == root[x]) {
          return x;
        }
        return root[x] = find(root[x]);
      }
      int unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
          distinct_sets--;
          root[rooty] = rootx;
        }
        return distinct_sets;
      }
      int getDistinctSets() {
        return distinct_sets;
      }
    private:
      int distinct_sets;
      vector<int> root;
  };
    int earliestAcq(vector<vector<int>>& logs, int n) {
      QuickUnion dset(n);
      std::sort(logs.begin(), logs.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
      });
      for (auto& log : logs) {
        if (dset.unionSet(log[1], log[2]) == 1) {
          return log[0];
        }  
      }
      return -1;
    }
};
