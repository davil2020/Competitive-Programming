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
    string s;
    cin >> s;
    int n;
    cin >> n;
    unordered_set<int> sp;
    rep(i,0,n-1){
        int x;
        cin >> x;
        sp.insert(x-1);
    }

    ii dp[s.length()][s.length()];

    //inicialização da matriz dp
    for(int i = 0; i < s.length(); i++){
        dp[i][i].f = sp.count(i) ? 1 : 0; // Quantidade de posições especiais
        dp[i][i].s = 1; //tamanho da maior subsequencia palindromica
    }

    //preenchimento da matriz dp:
    for (int i = 1; i < s.length(); i++) {
        for (int j = 0; j + i < s.length(); j++) {

            dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1]);//dp[j][j+i] representa a substring s[j ... j+i] -> seja s = ABCD, dp[0][1] = AB, dp[0][2] = ABC

            if (s[j] == s[j+i]) {
                ii auxi;
                auxi.first = (sp.count(j) ? 1 : 0) + (sp.count(j+i) ? 1 : 0) + dp[j+1][j+i-1].first; // numero de posições especiais
                auxi.second = 2 + dp[j+1][j+i-1].second; // tamanho da maior subsequencia palindromica
                
                dp[j][j+i] = max(dp[j][j+i], auxi);
            }
        }
    }

    cout << dp[0][s.length() - 1].s << endl;

    return 0;
}