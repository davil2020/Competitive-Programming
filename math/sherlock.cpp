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

int sieve[100005];
 
int main(){
    int n;
    cin >> n;
    for (int i = 2; i <= n+1; i++){
        if (sieve[i] == 0){
            for (int j = 2*i; j <= n+1; j += i)
                sieve[j] = 1;
        }
    }
    if(n > 2)
        cout << "2\n";
    else    
        cout << "1\n";
    for(int i = 2; i <= n+1; i++){
        if(sieve[i] == 0)
            cout << "1 ";
        else
            cout << "2 ";
    }
    cout << endl;
    return 0;
}