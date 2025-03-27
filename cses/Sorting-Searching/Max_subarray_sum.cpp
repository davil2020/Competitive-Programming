#include <bits/stdc++.h>

int main(){
    int n; 
    std::cin >> n;
    long long array[n],best = -2000000000, sum = 0;
    for(int i = 0; i < n; i++){
        std::cin >> array[i];
    }
    for (int k = 0; k < n; k++) {
        sum = std::max(array[k],sum+array[k]);
        best = std::max(best,sum);
    }
    std::cout << best << "\n";
    return 0;
};