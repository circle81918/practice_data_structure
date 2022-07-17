#include <vector>
#include <unordered_set>

class UnionFind {
  public:
    UnionFind(int n) {
      parents = std::vector<int>(n);
      ranks = std::vector<int>(n, 0);
      for(int i=0; i<n; i++)
        parents[i] = i;
    }

    void Union(int u, int v) {
      int parent_u = Find(u);
      int parent_v = Find(v);
      if (parent_u == parent_v)
        return;
      if (ranks[u] > ranks[v])
        parents[v] = parent_u;
      else if (ranks[u] < ranks[v])
        parents[u] = parent_v;
      else {
        parents[u] = parent_v;
        ranks[v]++;
      }
    }

    int Find(int u) {
      if (parents[u] != u)
        parents[u] = Find(parents[u]);
      return parents[u];
    }

  private:
    std::vector<int> parents;
    std::vector<int> ranks;
};

int main() {
  std::vector<std::pair<int,int>> group{{10,9}, {1,2}, {3,4}, {5,2}, {4,6}, {2,6}, {8,7}, {9,7}, {1,6}, {2,4}};
  UnionFind uf(group.size());
  for (auto g : group)
    uf.Union(g.first-1, g.second-1);

  std::unordered_set<int> sub_group;
  for (int i = 0; i < group.size(); ++i)
    sub_group.insert(uf.Find(i));

  printf("size : %zu", sub_group.size());

  system("pause");
  return 0;
}