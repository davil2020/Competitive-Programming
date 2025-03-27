#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> aplications(n), apartaments(m);

    for(int i = 0; i < n; ++i) cin >> aplications[i];
    for(int i = 0; i < m; ++i) cin >> apartaments[i];

    sort(aplications.begin(), aplications.end());
    sort(apartaments.begin(), apartaments.end());

    
    int count = 0, apl = 0, apt = 0;

    while(apl < n && apt < m){
        if(apartaments[apt] - k > aplications[apl]) 
            apl++;
        else if(apartaments[apt] + k < aplications[apl])
            apt++;
        else 
            {apl++; apt++; count++;}
    }

    cout << count << endl;
    return 0;
}