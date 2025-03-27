#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll number_ways(ll k){
    return ll( (k*k*(k*k - 1)/2 ) - 4*(k - 1)*(k - 2) );
}

int main(){
    ll n, ways;
    cin >> n;
    for(int i = 1; i <= n; i++){
        ways = number_ways(i);
        cout << ways << endl;
    }
    return 0;
}