class Solution {
public:
  class QuickUnion {
    public:
      QuickUnion(int size) : root(size) {
        for (int i = 0; i < size; i++) {
          root[i] = i;
        }  
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
          root[rooty] = rootx;
        }
      }
      int getDistinctSets() {
        set<int> distinct_roots;
        for (int i = 0; i < root.size(); i++) {
          distinct_roots.insert(find(i));
        }
        return distinct_roots.size();
      }
    private:
      vector<int> root;
  };
  
    int findCircleNum(vector<vector<int>>& isConnected) {
      QuickUnion dset(isConnected.size());
      for (auto& row : isConnected) {
        for (int i = 0; i < row.size(); i++) {
          for (int j = i+1; j < row.size(); j++) {
            if (row[i] == 1 && row[j] == 1) {
              dset.unionSet(i, j);
            }
          }
        }
      }
      return dset.getDistinctSets();
      
    }
};
