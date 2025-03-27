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

vi sa, lcp, c;

void count_sort(vi &p, vi &c){
    int n = p.size();
    vi cnt(n),new_p(n),pos(n);
    for (auto x : c) cnt[x]++;
    pos[0] = 0;
    for (int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
    for (auto x : p){
        int i = c[x];
        new_p[pos[i]] = x;
        pos[i]++;
    }
    p = new_p;
}

void build(string s){
    int n = s.size();
    vector<pair<char, int>> a(n);
    for(int i =0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) sa[i] = a[i].second;
    c[sa[0]] = 0;
    for(int i = 1; i < n; i++) {
        if(a[i].first == a[i - 1].first) c[sa[i]] = c[sa[i - 1]];
        else c[sa[i]] = c[sa[i - 1]] + 1;
    }
    int k =0;
    while((1 << k) < n){
        for(int i = 0; i < n; i++) sa[i] = (sa[i] - (1<<k) + n) % n;
        count_sort(sa, c);
        vi c_new(n);
        c_new[sa[0]] = 0;
        for(int i = 1; i < n; i++) {
            ii prev = {c[sa[i-1]], c[(sa[i-1] + (1<<k)) % n]};
            ii now = {c[sa[i]], c[(sa[i] + (1<<k)) % n]};
            if(now == prev) c_new[sa[i]] = c_new[sa[i - 1]];
            else c_new[sa[i]] = c_new[sa[i - 1]] + 1;
        }
        c = c_new;
        k++;
    }
    int m = 0;
    for(int i = 0; i < n - 1; i++){
        int pi = c[i];
        int j = sa[pi - 1];
        while(s[i + m] == s[j + m]) m++;
        lcp[pi] = m;
        m = max(m - 1, 0);
    }
}
 
int main(){
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    sa.resize(n), lcp.resize(n), c.resize(n);
    build(s);
    for(int i = 0 ; i < n; i++)
        cout << sa[i] << " " << lcp[i] << " " <<  s.substr(sa[i],n-sa[i]) << endl;
   
    return 0;
}

