#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define REP(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;

struct range
{
    ll left, right, index;
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
    vector<bool> contains(n);
    vector<bool> contained(n);
    REP(i,0,n)
    {
        cin >> ranges[i].left >> ranges[i].right;
        ranges[i].index = i;
    }

    //SORT
    sort(ranges.begin(), ranges.end());

    //Montando o vector<bool> contained
    ll MaxEnd = 0;
    for(int i = 0; i < n; i++)
    {
        if(ranges[i].right <= MaxEnd)
            contained[ranges[i].index] = true;
        MaxEnd = max(ranges[i].right,MaxEnd);
    }

    //Montando o vector<bool> contains
    ll MinEnd = 1e10;
    for(int i = n-1; i >= 0; i--)
    {
        if(ranges[i].right >= MinEnd)
            contains[ranges[i].index] = true;
        MinEnd = min(ranges[i].right,MinEnd);
    }

    REP(i,0,n)
        cout << contains[i] << " ";
    cout << endl;
    REP(i,0,n)
        cout << contained[i] << " ";
    cout << endl;

    return 0;
}