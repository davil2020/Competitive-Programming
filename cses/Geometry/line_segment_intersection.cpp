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

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

ll cross_product2D(Point p1, Point p2, Point p3){
    return ((p2.x - p1.x) * (p3.y - p1.y)) - ((p2.y - p1.y) * (p3.x - p1.x));
}


bool isMid(Point p1, Point p2, Point p3) {
    return ((min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x)) && (min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y)));
}

bool intersect(Point p1, Point p2, Point p3, Point p4){
    ll d1 = cross_product2D(p1,p2,p3);
    ll d2 = cross_product2D(p1,p2,p4);
    ll d3 = cross_product2D(p3,p4,p1);
    ll d4 = cross_product2D(p3,p4,p2);
    if(d1 == 0 && isMid(p1,p2,p3))
        return true;
    if(d2 == 0 && isMid(p1,p2,p4))
        return true;
    if(d3 == 0 && isMid(p3,p4,p1))
        return true;
    if(d4 == 0 && isMid(p3,p4,p2))
        return true;
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;
    return false;
}
 
int main(){
    int t;
    cin >> t;
    Point p1,p2,p3,p4;
    while(t--){
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        if(intersect(p1,p2,p3,p4))
            cout << "YES\n";
        else
            cout << "NO\n";    
    };
    return 0;
}