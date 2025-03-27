#include <bits/stdc++.h>
using namespace std;

// BeginCodeSnip{DSU}
class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;
    vector<int> menor;
    vector<int> maior;
    vector<int> qntd;


  public:
	DisjointSets(int size) : parents(size), menor(size), maior(size), qntd(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { 
            parents[i] = i; 
            menor[i] = maior[i] = i;
            qntd[i] = 1;
        }
	}

	/** @return the "representative" node in x's component */
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
        menor[x_root] = min(menor[x_root], menor[y_root]);
        maior[x_root] = max(maior[x_root], maior[y_root]);
        qntd[x_root] += qntd[y_root];
		return true;
	}

    int minimo(int x){
        return menor[find(x)];
    }
    int maximo(int x){
        return maior[find(x)];
    }
    int quantidade(int x){
        return qntd[find(x)];
    }

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};
// EndCodeSnip

int main() {
	int node_num, query_num;
	cin >> node_num >> query_num;

	DisjointSets dsu(node_num);
	int u, v;
    string type;
	for (int i = 0; i < query_num; i++) {
		cin >> type;
		if (type == "union") {
            cin >> u >> v;
            u--, v--;
			dsu.unite(u, v);
		} else if (type == "get") {
            cin >> u;
            u--;
            cout << dsu.minimo(dsu.find(u))+1 << " " << dsu.maximo(dsu.find(u))+1 << " " << dsu.quantidade(dsu.find(u)) << endl;
		}
	}
    return 0;
}