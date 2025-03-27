#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class DSU{
public:
    vi parent, size, maior;

    DSU(int n){
        parent.resize(n+2);
        size.resize(n+2, 1);
        maior.resize(n+2);
        for(int i = 0; i <= n + 1; i++) parent[i] = i, maior[i] = i;
    }

	int Find(int x) {
		return parent[x] == x ? x : (parent[x] = Find(parent[x]));
	}

    void Union(int x, int y){
        int X = Find(x);
        int Y = Find(y);
        if(X == Y) return;
        if(size[X] < size[Y]) swap(X, Y);
        size[X] += size[Y];
        parent[Y] = X;
        maior[X] = max(maior[X], maior[Y]);
    }
    int maximo(int x){
        return maior[Find(x)];
    }
};
 
 
int main(){
    int n, m;
    cin >> n >> m;
    DSU d(n);
    char c;
    int a;
    rep(i, 1, m){
        cin >> c >> a;
        if ( c == '?'){
            int x = d.Find(a);
            (d.maximo(x) > n) ? cout << "-1\n" : cout << d.maximo(x) << endl;
        } else if(c == '-'){
            d.Union(a, a+1);
        }
    }
    return 0;
}