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

pair<vi, vi> suffix_array(string s){
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

    vi lcp(n);
    k = 0;
    for(int i = 0; i < n - 1; i++){
        int pi = c[i];
        int j = p[pi - 1];
        while(s[i + k] == s[j + k]) k++;
        lcp[pi] = k;
        k = max(k-1, 0);
    }
    return {p, lcp};
}

int main(){
    string s;
    cin >> s;
    vi p, lcp;
    pair<vi, vi> sa = suffix_array(s);
    p = sa.f;
    lcp = sa.s;
    int n = p.size();
    int ans = -1;
    string res;
    for(int i = 1; i < n; i++){
        if(lcp[i] > ans){
            ans = lcp[i];
            res = s.substr(p[i], lcp[i]);
        }
    }
    if(ans == 0)
        cout << "-1" << endl;
    else
        cout << res << endl;
        
    return 0;
}