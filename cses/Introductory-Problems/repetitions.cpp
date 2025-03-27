#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

int main(){
    string dna;
    int count = 1,rep = 0;
    cin >> dna;
    for( size_t i = 0; i < dna.size(); i++){
        if(dna[i] == dna[i+1]){
            count++;
        } else {
            count = 1;
        }
        rep = max(count,rep);
    }
    cout << rep << endl;
    return 0;
}