#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent, size;

public:
    // Constructor
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]); // path compression
        }
        return parent[x];
    }

    // Union by size
    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rootX == rootY) return;

        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
};

int main() {
    DSU dsu(3);

    cout << dsu.Find(1) << endl;
    cout << dsu.Find(2) << endl;
    cout << dsu.Find(3) << endl;

    dsu.Union(1, 2);
    cout << "After Union(1,2):\n";
    cout << dsu.Find(1) << endl;
    cout << dsu.Find(2) << endl;

    return 0;
}
