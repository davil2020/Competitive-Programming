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

const ll Hash = 257, mod = 1e9 + 7;

int n, m;
ll hashPower[200005] = {1};
ll fwdHashTable[400005];
ll bckHashTable[400005];

void updatefwd(int i, ll v) {
    for (fwdHashTable[i += n] = v; i > 1; i >>= 1)
        fwdHashTable[i >> 1] = (fwdHashTable[i] + fwdHashTable[i ^ 1]) % mod;
}

ll queryfwd(int l, int r) {
    ll res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = (res + fwdHashTable[l++]) % mod;
        if (r & 1)
            res = (res + fwdHashTable[--r]) % mod;
    }
    return res;
}

void updatebck(int i, ll v) {
    for (bckHashTable[i += n] = v; i > 1; i >>= 1)
        bckHashTable[i >> 1] = (bckHashTable[i] + bckHashTable[i ^ 1]) % mod;
}

ll querybck(int l, int r) {
    ll res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res = (res + bckHashTable[l++]) % mod;
        if (r & 1)
            res = (res + bckHashTable[--r]) % mod;
    }
    return res;
}
 
 
int main(){
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        hashPower[i] = (hashPower[i - 1] * Hash) % mod;
    }
    for(int i = 0; i < n; i++){
        char c = s[i];
        updatefwd(i, hashPower[i] * (ll)c % mod);
        updatebck(i, hashPower[n - i - 1] * (ll)c % mod);
    }
    for (int i = 0; i < m; i++) {
        int opType;
        cin >> opType;
        if (opType == 1) {
            int position;
            char newChar;
            cin >> position >> newChar;
            position--;

            updatefwd(position, hashPower[position] * (ll)newChar % mod);
            updatebck(position, hashPower[n - position - 1] * (ll)newChar % mod);
        } else if (opType == 2) {
            int left, right;
            cin >> left >> right;
            left--, right--;

            ll fwd = queryfwd(left, right);
            fwd = (fwd * hashPower[n - 1 - right]) % mod;
            ll bck = querybck(left, right);
            bck = (bck * hashPower[left]) % mod;

            if (fwd == bck)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}