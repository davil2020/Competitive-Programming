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
 
 
int main(){
    _;
    int n, m;
    cin >> n >> m;
    vector<bool> root(n+1, true);
    root[0] = false;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        root[b] = false;
        root[a] = false;
    }
    int Root = 0;
    for(int i = 1; i <= n; i++){
        if(root[i]){
            Root = i;
            break;
        }
    }
    cout << n - 1 << endl;
    for(int i = 1; i <= n; i++){
        if(i != Root){
            cout << Root << " " << i << endl;
        }
    }
    return 0;
}