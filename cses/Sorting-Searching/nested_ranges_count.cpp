#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

struct range
{
    int left, right, index;
    bool operator < (const range &other) const
    {
        if(left == other.left)
            return right > other.right;
        return left < other.left;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<range> ranges(n);
    vector<int> contains(n);
    vector<int> contained(n);
    ordered_set<pair<int, int>> rightBounderies;
    for(int i = 0; i < n; i++)
    {
        cin >> ranges[i].left >> ranges[i].right;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end());

    for(int i = 0; i < n ; i++)
    {
        rightBounderies.insert({ranges[i].right, -1*i});
        contained[ranges[i].index] = 
            rightBounderies.size() - rightBounderies.order_of_key({ranges[i].right, -1*i}) - 1;
    }
    rightBounderies.clear();
    for(int i = n - 1; i >= 0 ; i--)
    {
        rightBounderies.insert({ranges[i].right, -1*i});
        contains[ranges[i].index] = rightBounderies.order_of_key({ranges[i].right, -1*i});
    }
    for(int i =0; i < n ; i++)
        cout << contains[i] << " ";
    cout << endl;
    for(int i =0; i < n ; i++)
        cout << contained[i] << " ";
    cout << endl;

    return 0;

}