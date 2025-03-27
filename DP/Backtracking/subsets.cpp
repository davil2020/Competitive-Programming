#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void findSubsets(char *input, char *output, int i, int j){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';
        if(output[j] = '\0')
            cout << "NULL\n";
        cout<<output<<endl;
        return;
    }

    //rec case
    //include the ith letter
    output[j] = input[i];
    findSubsets(input, output, i+1, j+1);
    //exclude the ith letter
    findSubsets(input, output, i+1, j);
}
 
 
int main(){
    char in[100];
    char out[100];
    cin>>in;

    findSubsets(in, out, 0, 0);
   
 
    return 0;
}