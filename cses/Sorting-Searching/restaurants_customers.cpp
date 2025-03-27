#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

int main() {
   int n, x, y;
   cin >> n;

   //leitura
   vector<pair<int, bool>> arriving_or_leaving;
   for(int i = 0; i < n; i++){
    cin >> x >> y;
    arriving_or_leaving.push_back({x,true});
    arriving_or_leaving.push_back({y,false});
   }

   sort(arriving_or_leaving.begin(), arriving_or_leaving.end());
   int custumers = 0, ans = 0;

    for(auto hour : arriving_or_leaving){
        if(hour.second) custumers += 1;
        else custumers -= 1;
        ans = max(ans, custumers);
    }

    cout << ans << endl;
    return 0;
}
