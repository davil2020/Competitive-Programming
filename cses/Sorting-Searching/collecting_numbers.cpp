#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define REP(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int main(){
    int n;
    cin >> n;
    vector<ii> numbers(n);
    REP(i,0,n){
        cin >> numbers[i].f;
        numbers[i].s = i;
    }
    sort(numbers.begin(), numbers.end());

    int ans = 1;
    REP(i,1,n){
        if(numbers[i].s < numbers[i-1].s)
            ans++;
    }

    cout << ans << endl;
    return 0;
}