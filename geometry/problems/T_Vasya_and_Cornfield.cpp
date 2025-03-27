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
    int n,d;
    cin >> n >> d;

    vector<Point> v(5);

    v[0] = {0,d}, v[1] = {d,0}, v[2] = {n,n-d}, v[3] = {n-d, n};
    v[4] = v[0];


    int m;
    cin >> m;

    int x,y;

    for(int i = 0; i < m; i++){

        cin >> x >> y;

        Point p = {x,y};
        Point inf = {INT_MAX, INT_MAX};

        bool flag = true;
        int cnt = 0;

        for(int j = 0; j < 4; j++){
            int cp = cross(v[j], v[j+1],p);
            if(cp == 0 && isMid(v[j], v[j+1],p)){
                flag = false;
                break;
            }

            if(check(v[j], v[j+1],p,inf)) cnt++;
        }

        if(flag){ // nao está  na borda
            if(cnt & 1) cout << "YES\n";
            else cout << "NO\n";
        } else {
            cout << "YES\n";
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