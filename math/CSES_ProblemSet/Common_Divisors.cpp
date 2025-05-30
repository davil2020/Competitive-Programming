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
ll cnt[1000001];
 
int main(){
    int n;
    cin >> n;
    ll nums[n];
    rep(i,0,n-1){
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    for(int i = 1000000; i >= 1; i--){
        ll d = 0;
        for(int j = i; j <= 1000000; j += i)
            d += cnt[j];
        if(d >= 2){
            cout << i << endl;
            return 0;
        }
    }
 
    return 0;
}