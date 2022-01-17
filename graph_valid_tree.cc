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
      bool unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
          distinct_sets--;
          root[rooty] = rootx;
          return true;
        }
        return false;
      }
      int getDistinctSets() {
        return distinct_sets;
      }
    private:
      int distinct_sets;
      vector<int> root;
  };
    bool validTree(int n, vector<vector<int>>& edges) {
      QuickUnion dset(n);
      for (auto& edge : edges) {
        if (!dset.unionSet(edge[0], edge[1])) {
          return false;
        }  
      }
      return dset.getDistinctSets() > 1 ? false : true;
    }
};
