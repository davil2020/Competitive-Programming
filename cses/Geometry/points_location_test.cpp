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

ll cross_product2D(Point p1, Point p2, Point p3){
    return ((p2.x - p1.x) * (p3.y - p1.y)) - ((p2.y - p1.y) * (p3.x - p1.x));
}
 
int main(){
    int t;
    cin >> t;
    ll res;
    while(t--){
        Point p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        res = cross_product2D(p1,p2,p3);
        if(res > 0){
            cout << "LEFT\n";
        } else if(res < 0){
            cout << "RIGHT\n";
        } else {
            cout << "TOUCH\n";
        }
    };
    return 0;
}