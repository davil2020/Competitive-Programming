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
    int ans = 0;
    while(s.size() > 1){
        int tmp = 0;
        for (int i = 0; i < s.size(); i++) {
            tmp = max(tmp, s[i] - '0'); // Encontra o maior dígito na string
        }
        ans++;
        
        // Converte a string para inteiro e subtrai o maior dígito
        int num = stoi(s);//String TO Int -> STOI
        num -= tmp;
        
        // Converte o resultado de volta para string
        s = to_string(num);
    }
    ans++;
    cout << ans << endl;
    return 0;
}