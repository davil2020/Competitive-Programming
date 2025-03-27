#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define f first
#define s second

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll results[n];
    pair<ll, ll> coordinates;
    for(int i = 0; i < n; i++){
        cin >> coordinates.f >> coordinates.s;
        if(coordinates.f < coordinates.s){
            if(coordinates.s % 2 == 0)
                results[i] = ((coordinates.s - 1)*(coordinates.s - 1) + coordinates.f);
            else
                results[i] = ((coordinates.s * coordinates.s) - (coordinates.f - 1));
        } else {
            if(coordinates.f % 2 == 0)
                results[i] = ((coordinates.f * coordinates.f) - (coordinates.s - 1));
            else
                results[i] = ((coordinates.f - 1)*(coordinates.f - 1) + coordinates.s);
        }
    }
    for(int i = 0; i < n; i++)
        cout << results[i] << endl;
    return 0;
}