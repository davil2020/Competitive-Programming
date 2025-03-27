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

void count_sort(vi &p, vi &c){
    int n = p.size();
    vi cnt(n);
    for(auto x : c) cnt[x]++;
    vi p_new(n);
    vi pos(n);
    pos[0] = 0;
    for(int i = 1; i < n; i++)
        pos[i] = pos[i-1] + cnt[i-1];
    for(auto x : p){
        int idx = c[x];
        p_new[pos[idx]] = x;
        pos[idx]++;
    }
    p = p_new;
}

vi suffix_array(string s){
    s += "$";
    int n = s.size();
    vi p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for(int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else    
                c[p[i]] = c[p[i-1]] + 1;
        } 
    }

    int k =0;
    while((1<<k) < n) {
        for(int i = 0; i < n; i++)
            p[i] = (p[i] - (1<<k) + n) % n;
        count_sort(p, c);
        vi c_new(n);
        c_new[p[0]] = 0;
        for(int i = 1; i < n; i++) {
            pair<int, int> p1 = {c[p[i-1]], c[(p[i-1] + (1<<k)) % n]};
            pair<int, int> p2 = {c[p[i]], c[(p[i] + (1<<k)) % n]};
            if(p1 == p2){
                c_new[p[i]] = c_new[p[i - 1]];
            } else {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    return p;
}

int binary_search(vi & p, string s, string pattern) {
    int n = p.size();
    int a = pattern.size();
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        string suffix = s.substr(p[m], min(a, n - p[m]));
        
        if (suffix == pattern) {
            return p[m];  // Retorna a posição onde o padrão é encontrado
        } else if (suffix < pattern) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1; // Se o padrão não for encontrado
}

 
int main(){
    string s;
    cin >> s;
    vi p = suffix_array(s);
    string pattern;
    int n;
    cin >> n;
    rep(i,0,n-1){
        cin >> pattern;
        int ans = binary_search(p, s, pattern);
        if(ans == -1)
            cout << "No\n";
        else    
            cout << "Yes\n";
        
        //cout << (ans == 0) ? "NO\n" : "YES\n";
    }
    return 0;
}