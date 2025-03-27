#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,n;
    cin >> x >> n;
    set<int> TrafficLights;
    multiset<int> distances;
    TrafficLights.insert(0);
    TrafficLights.insert(x);
    distances.insert(x);
    for(int i = 0; i < n; i++){
        int light;
        cin >> light;
        TrafficLights.insert(light);
        auto it = TrafficLights.find(light);
        int it_L = *prev(it);
        int it_R = *next(it);
        distances.erase(distances.find(it_R - it_L));
        distances.insert(it_R - light);
        distances.insert(light - it_L);
        cout << *distances.rbegin() << " ";
    }
}