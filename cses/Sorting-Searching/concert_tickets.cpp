#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);

/*int binarySearch(vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size() - 1;
    int result = -1;  // Inicializa com um valor impossível como marcador

    while (left <= right) {
        int mid = (left + right) / 2;

        if (vec[mid] == target) {
            // Elemento encontrado, retorna o índice
            return mid;
        } else if (vec[mid] < target) {
            // Atualiza o índice do primeiro elemento menor que o valor buscado
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}*/

int main(){
    int n, m, x;
    cin >> n >> m;

    multiset<int, greater<int>> tickets;
   
    for(int i = 0; i < n; ++i){
        cin >> x;
        tickets.insert(x);
    } 

    for(int j = 0; j < m; ++j){
        cin >> x;
        auto it = tickets.lower_bound(x);
        if(it == tickets.end())
            cout << "-1" << endl;
        else{
            cout << *it << endl;
            tickets.erase(it);
        }
    }

    return 0;
}