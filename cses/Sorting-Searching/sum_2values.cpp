#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

auto customCompare = [](const std::pair<int, int>& lhs, int rhs) {
    return lhs.first < rhs;
};

int main(){
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i].first;
        numbers[i].second = i + 1;
    }
    sort(numbers.begin(), numbers.end());

    int target, count = 0, i = 0;
    while(numbers[i].first <= x/2 && i < n){
        target = x - numbers[i].first;
        auto it = lower_bound(numbers.begin(), numbers.end(), target, customCompare);
        if(it != numbers.end() && it->first == target && it->second != numbers[i].second){
            count++;
            cout << min(numbers[i].second,it->second) << " " << max(numbers[i].second,it->second) << endl;
        }
        i++;
    }

    if(count == 0) cout << "IMPOSSIBLE" << endl;
    return 0;
}