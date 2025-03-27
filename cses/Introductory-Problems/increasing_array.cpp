#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

int main(){
    int n; 
    cin >> n;
    long long numbers[n], moves = 0;;
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
        if( i != 0 && numbers[i] < numbers[i - 1]){
            moves += (numbers[i - 1] - numbers[i]); 
            numbers[i] += (numbers[i - 1] - numbers[i]);
        }
    }
    cout << moves << endl;
    return 0;
}
