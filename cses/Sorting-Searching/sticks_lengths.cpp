#include <bits/stdc++.h>

using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)

int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    REP(i,0,n) cin >> numbers[i];
    sort(numbers.begin(), numbers.end());
    int middle = numbers[n/2];
    long long s = 0;
    REP(i,0,n){
        s += abs(numbers[i] - middle);
    }
    cout << s << endl;
    return 0;
}