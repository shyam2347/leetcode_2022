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
      void unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
          distinct_sets--;
          root[rooty] = rootx;
        }
      }
      int getDistinctSets() {
        return distinct_sets;
      }
    private:
      int distinct_sets;
      vector<int> root;
  };
    int countComponents(int n, vector<vector<int>>& edges) {
      QuickUnion dset(n);
      for (auto& edge : edges) {
        dset.unionSet(edge[0], edge[1]);
      }
      return dset.getDistinctSets();
    }
};
