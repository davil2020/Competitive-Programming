#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

typedef complex<ll> Point;

#define X real()
#define Y imag()

 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int cross(Point a, Point b, Point c){
    ll res = (conj(b-a) * (c-a)).Y;
    return (res > 0) - (res < 0);
}

bool isMid(Point p1, Point p2, Point p3) {
    return ((min(p1.X, p2.X) <= p3.X && p3.X <= max(p1.X, p2.X)) && (min(p1.Y, p2.Y) <= p3.Y && p3.Y <= max(p1.Y, p2.Y)));
}

int check(Point a, Point b, Point c, Point d){
    int c1 = cross(a,b,c);
    int c2 = cross(a,b,d);
    int c3 = cross(c,d,a);
    int c4 = cross(c,d,b);

    if (c1*c2 < 0 && c3*c4 < 0) return 1;
    if (c3 == 0 && isMid(c, d, a) && c4 < 0) return 1; // Importante !!!! -> checagem de quando o raio infinito for
    if (c4 == 0 && isMid(c, d, b) && c3 < 0) return 1; //                   colinear com um vertice, pra não conta-lo 2x

    return 0;
}


 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<Point> points(n);
    ll a, b;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        points[i] = {a,b};
    }

    points.pb(points[0]); // Importante !!!!

    for(int i = 0; i < m; i++){
        cin >> a >> b;

        Point p = {a,b};
        Point inf = {INT_MAX, INT_MAX};

        int cnt = 0;
        bool flag = true;

        for(int j = 0; j < n; j++){
            ll cp = cross(points[j], points[j+1], p);

            if(cp == 0 && isMid(points[j], points[j+1], p)){
                cout << "BOUNDARY\n";
                flag = false;
                break;
            }

            cnt += check(points[j], points[j+1], p, inf);
        }
        if(flag){
            if(cnt&1) cout << "INSIDE\n";
            else cout << "OUTSIDE\n";
        }
        
    }

}
 
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}