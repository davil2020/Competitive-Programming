#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

bool customCompare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    // Primeiro, compare pelo segundo elemento
    if (a.second != b.second) {
        return a.second < b.second;
    }

    // Se os segundos elementos são iguais, compare pelo primeiro elemento
    return a.first < b.first;
}

int main(){
    int n, x , y;
    cin >> n;

    //leitura
    vector<ii> m_d;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        m_d.push_back({x, y});
    }

    sort(m_d.begin(), m_d.end(), customCompare);

    

    int movie = 0, s = 0;
    for(int i = 0; i < n ; i++){
        if(m_d[i].f >= s){
            movie++;
            s = m_d[i].s;
        }
    }

    cout << movie << endl;
    return 0;
}