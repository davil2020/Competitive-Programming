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
    int n;
    int A[n][n];
    rep(i,0,n-1){
        rep(j,0,n-1){
            cin >> A[i][j];
            if(j>0){
                A[i][j] += A[i][j-1];
            }
        }
    }

    int maxSubRect = -127*100*100;
    rep(i,0,n-1){
        rep(j,i,n-1){
            int SubRect = 0;
            rep(k,0,n-1){
                if(i > 0) SubRect += A[k][j] - A[k][i-1];
                else SubRect += A[k][j];
                if(SubRect < 0) SubRect = 0;
                maxSubRect = max(maxSubRect, SubRect);
            }
        }
    }

    cout << maxSubRect << endl;

    return 0;
}