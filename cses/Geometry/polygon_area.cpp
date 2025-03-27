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

struct Point{
    ll x, y;
};
 
int main(){
    int n;
    cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int j = (i+1) % n;
        ans += points[i].x * points[j].y;
        ans -= points[i].y * points[j].x;
    }
    cout << abs(ans) << endl;
    return 0;
}