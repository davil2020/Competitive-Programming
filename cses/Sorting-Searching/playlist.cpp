#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define REP(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> songs(n);
    set<int> songs_unique;
    REP(i,0,n){
        cin >> songs[i];
    }
    int i = 0, j = 0,  best = 1;

    while(j < n){
        if(songs_unique.count(songs[j])){
            best = max(best, j - i);
            while(songs[i] != songs[j]){
                songs_unique.erase(songs[i]);
                i++;
            }
            i++;
        } else {
            songs_unique.insert(songs[j]);
        }

        j++;
    }

    best = max(best, j - i);
    cout << best << endl;

    return 0;
}