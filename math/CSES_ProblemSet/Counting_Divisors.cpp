#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i < b; i++)
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
ll d[1000005]; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=1;i<1000005;i++)
    {
        for(int j=i;j<1000005;j+=i)
        {
            d[j]++;
        }
    }
    ll n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        cout<<d[x]<<"\n";
    }
}
