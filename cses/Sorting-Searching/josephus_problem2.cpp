#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int n, k;
    cin >> n >> k;
    ordered_set<int> children;
    for(int i = 1; i <= n; i++)
        children.insert(i);
    int StartPosition = 0;
    while(children.size() > 0)
    {
        StartPosition %= children.size();
        int positionToRemove = (StartPosition + k) % children.size();
        StartPosition = positionToRemove;
        auto it = children.find_by_order(positionToRemove);
        cout << *it << " ";
        children.erase(it);
    }
    cout << endl;
    return 0;
}
