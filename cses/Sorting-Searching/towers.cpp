#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define REP(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

int main() {
  int n, x;
  cin >> n;
  multiset<int> s;
  while (n--) {
    cin >> x;
    auto it = s.lower_bound(x + 1);
    if (it == s.end()) s.insert(x);
    else {
      s.erase(it);
      s.insert(x);
    }
  }
  cout << s.size() << endl;
}