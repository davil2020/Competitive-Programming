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
    int n , k;
    cin >> k >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        pq.push(a);
    }
    ll ans = 0;
    for(int i = 1; i < n; i++){
        int b = pq.top();
        pq.pop();
        int c = pq.top();
        pq.pop();
        pq.push(b+c);
        ans += (b+c); 
    }
    cout << ans << endl;
    return 0;
}