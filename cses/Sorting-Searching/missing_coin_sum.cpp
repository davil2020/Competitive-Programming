//basicamente soma de sub conjuntos achei dificil
//ideia genial


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<ll> numbers(n);
  for (int i = 0; i < n; i++) cin >> numbers[i];
  sort(numbers.begin(), numbers.end());

  ll R = 0; //valor máximo até o qual podemos somar sem perder nenhum valor de 0 a R

  for(int i = 0; i < n; i++){
    if((R + 1) < numbers[i]){
        cout << R + 1 << '/n';
        return 0;
    }
    R += numbers[i];
  }
  
  cout << R + 1 << '\n';
  return 0;
}