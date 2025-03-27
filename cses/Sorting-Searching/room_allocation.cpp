#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i < b; i++)
#define endl '\n'
#define f first
#define s second
#define pb push_back

int main()
{
    int n;
    cin >> n;
    vector<tuple<int,int,int>> days;
    int x, y;
    rep(i,0,n)
    {
        cin >> x >> y;
        days.pb({x,0,i});
        days.pb({y,1,i});
    }

    sort(days.begin(), days.end());

    int c = 0;
    int ans[n];
    vector<int> av; //esses são os quartos que estavam ocupados mas depois foram liberados
    for(auto [x,y,i] : days)
    {
        if(y == 0) // tá entrando
        {
            c++;
            if(av.empty())
                ans[i] = c;
            else
            {
                ans[i] = av.back();
                av.pop_back();
            }
        }
        else
        {
            c--;
            av.pb(ans[i]);
        }
    }

    cout << *max_element(ans, ans + n) << endl;
    
    rep(i,0,n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}