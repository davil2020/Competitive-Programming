#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n,k;cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
 
	int ans=0;
	int lo=0,indx=-1;
	for(int hi=0;hi<n;hi++){
		if(v[hi]==0){
			if(k==0){
				while(v[lo]==1)
					lo++;
				lo++;
			}
			else
				k--;
		}
		if(ans<hi-lo+1){
			ans=hi-lo+1;
			indx=lo;
		}
	}
 
	cout<<ans<<"\n";
	for(int i=indx;i>=0 && i<indx+ans;i++)
		v[i]=1;
	for(int x: v)
		cout<<x<<" ";
 
	return 0;
}