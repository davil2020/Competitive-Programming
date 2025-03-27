#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

int main(){
    int n;
    set<long long> numbers;
    cin >> n;
    long long tmp;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        numbers.insert(tmp);
    }

    cout << numbers.size() << endl;
    return 0;
}