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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool typable[26] = {0};
    bool a[n] = {0};
    for (int i = 0; i < k; i++){
        char c;
        cin >> c;
        typable[c - 'a'] = 1;
    }
    for(int i= 0; i < n; i++){
        if(typable[s[i] - 'a'] == 0)
            a[i] = 0;
        else 
            a[i] = 1;
    }
    ll ans = 0;
    ll F[n+1];
    F[0] = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            F[i+1] = F[i] + 1;
        } else {
            F[i+1] = 0;
        }
        ans += F[i+1];
    }
    cout << ans << endl;

    return 0;
}