#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ii> points;
vector<ii> hull;

int cross(ii O, ii P, ii Q) {
	ll ans = ((P.first - O.first) * (Q.second - O.second)) - ((P.second - O.second) * (Q.first - O.first));
    return (ans > 0) - (ans < 0);
}

void monotone_chain(){

    sort(points.begin(), points.end());
    //points.erase(unique(points.begin(), points.end()), points.end());

    int n = points.size();

    if(n < 3){
        hull = points;
        return;
    }

    for(int i = 0; i < n; i++){
        while(hull.size() > 1 && cross(hull[hull.size() - 2], hull.back(), points[i]) < 0) 
            hull.pop_back();
        hull.push_back(points[i]);
    }

    auto lower_hull_length = hull.size();
    for(int i = n-2; i >= 0; i--){
        while(hull.size() > lower_hull_length && cross(hull[hull.size() - 2], hull.back(), points[i]) < 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back();
}
 
 
void solve() {
    int n;
    cin >> n;

    points.assign(n, {});
    for(auto &p : points) cin >> p.f >> p.s;

    monotone_chain();

    cout << hull.size() << endl;
    for(auto &p : hull) cout << p.f << " " << p.s << endl;
}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}