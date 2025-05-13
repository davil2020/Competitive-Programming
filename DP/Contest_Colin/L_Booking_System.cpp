#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
 
const int N=2002;
const int mod=1e9+7;
int n,k;
multiset<pair<int,int> >ms;
vector<pair<int,pair<int,int> > >v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int c,p;cin>>c>>p;
		v.pb({-p,{c,i+1}});
	}

	sort(v.begin(),v.end());
	cin>>k;
	for(int i=0;i<k;i++){
		int a;cin>>a;
		ms.insert({a,i+1});
	}
    
	ll ans=0;
	vector<pair<int,int>> s;
	for(int i=0;i<n;i++){
		int c=v[i].se.fi,p=-v[i].fi,ind=v[i].se.se;
		auto it=ms.lower_bound({c,0});
		if(it!=ms.end()){
			s.pb({ind,(*it).se});
			ms.erase(it);
			ans+=p;
		}
	}
	cout<<s.size()<<" "<<ans<<endl;
	for(auto u:s){
		cout<<u.fi<<" "<<u.se<<endl;
	}
}