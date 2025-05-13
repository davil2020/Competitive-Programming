#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e15;
 
int n,m;
int dists[1005][1005];
int product[1005][1005];
int A[1005][1005];
 
int hungarian(int n, int m){
	vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
	for (int i=1; i<=n; ++i) {
	    p[0] = i;
	    int j0 = 0;
	    vector<int> minv (m+1, INF);
	    vector<bool> used (m+1, false);
	    do {
	        used[j0] = true;
	        int i0 = p[j0],  delta = INF,  j1;
	        for (int j=1; j<=m; ++j)
	            if (!used[j]) {
	                int cur = A[i0][j]-u[i0]-v[j];
	                if (cur < minv[j])
	                    minv[j] = cur,  way[j] = j0;
	                if (minv[j] < delta)
	                    delta = minv[j],  j1 = j;
	            }
	        for (int j=0; j<=m; ++j)
	            if (used[j])
	                u[p[j]] += delta,  v[j] -= delta;
	            else
	                minv[j] -= delta;
	        j0 = j1;
	    } while (p[j0] != 0);
	    do {
	        int j1 = way[j0];
	        p[j0] = p[j1];
	        j0 = j1;
	    } while (j0);
	}
	int cost = -v[0];
	return cost;
}
 
int32_t main() {
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>product[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			int w;
			cin>>w;
			dists[i][j]=(w<0?1e9:w);
		}
	}
	for (int k = 0; k < n; ++k)
	    for (int i = 0; i < n; ++i)
	        for (int j = 0; j < n; ++j)
	            dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]); 

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<m;++k)
				A[k+1][i+1] += dists[j][i]*product[j][k];

	cout<<hungarian(m,n)<<endl;
	return 0;
}