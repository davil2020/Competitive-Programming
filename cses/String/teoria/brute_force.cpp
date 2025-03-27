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

int n, m;
string S, P;//P é o padrão de tamanho m

int BruteForceMatch(){
    for(int i = 0; i <= n-m; i++){
        int j = 0;
        while(j < m && S[i+j] == P[j]) j++;

        if(j == m) return i; //foi encontrado o pradrão a partir do indice i;
    }
}

int BFmatching(){
    for(int i = 0; i + P.size()<= S.size(); i++){
        if(S.substr(i,P.size()) == P){
            cout << i << endl;
        }
    }
}
 
 
int main(){
    int t;
    cin >> t;
    while(t--){
 
    cout << endl;
    };
    return 0;
}