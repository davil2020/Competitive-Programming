#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio();cin.tie(0);

int main(){
    int n, number;
    set<int> numbers;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> number;
        numbers.insert(number);
    }
    for(int i = 1; i <= n; i++){
        if(numbers.count(i) == 0){
            cout << i << endl;
            break;
        }
    }
    return 0;
} 