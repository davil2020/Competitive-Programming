#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end());

    int count = 0, tmp = 1, i = 0;
    
    while(i != (n - tmp) && i < (n - tmp)){
        if((weights[i] + weights[n - tmp]) <= x)
            i++;
        tmp++;
        if(i == (n - tmp)) count += 2;
        else count++;
    }

    cout << count << endl;
    return 0;
}