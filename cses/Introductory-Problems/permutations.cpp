#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

int main(){
    int n;
    cin >> n;
    if (n == 1)
        cout << "1\n";
    else if (n < 4)
        cout << "NO SOLUTION\n";
    else if (n == 4)
        cout << "3 1 4 2\n";
    else {
        for(int i = 1; i <= n; i+=2)
            cout << i << " ";
        for(int i = 2; i <= n; i+=2){
            cout << i;
            if(i < n - 1)
                cout << " ";
            else
                cout << endl;
        }
    return 0;
    }

}
