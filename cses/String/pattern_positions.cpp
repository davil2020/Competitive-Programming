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
const int kmax = 500005;

string s;
int n, nodeIndex = 1, patternFound[kmax], firstOccurrence[kmax];

vector<int> trieAdjList[kmax];
vector<string> patterns(n);

struct TrieNode{
    int failureLink, child[26] = {}, occurrences = 0;
    bool is_end = false;
    vector<int> patternIndices;
} trie[kmax];

void insertPattern(string pattern, int index){

    int node = 1;
    for(int i = 0; i < (int) pattern.size(); i++){
        if(trie[node].child[pattern[i] - 'a'] == 0)
            trie[node].child[pattern[i] - 'a'] = ++nodeIndex;
        
        node = trie[node].child[pattern[i] - 'a'];
    }

    trie[node].patternIndices.pb(index);
    trie[node].is_end = true;
    firstOccurrence[index] = -1;
}

void buildFailureLinks(){
    queue<int> nodeQueue;
    int node = 1;
    trie[1].failureLink = 1;
    for(int i = 0; i < 26; i++){
        if(trie[node].child[i]){
            trie[trie[node].child[i]].failureLink = node;
            nodeQueue.push(trie[node].child[i]);
        } else 
            trie[node].child[i] = 1;
    }
    while(!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        for(int i = 0; i < 26; i++){
            if(trie[node].child[i]){
                trie[trie[node].child[i]].failureLink = trie[trie[node].failureLink].child[i];
                nodeQueue.push(trie[node].child[i]);
            } else 
                trie[node].child[i] = trie[trie[node].failureLink].child[i];
        }
    }

    for(int i = 2; i <= nodeIndex; i++)
        trieAdjList[trie[i].failureLink].pb(i);
}

void runAhoCorasick(string s){
    for(int i = 0, node = 1; i < (int) s.size(); i++){
        node = trie[node].child[s[i] - 'a'];
        for(auto pi : trie[node].patternIndices){
            if(firstOccurrence[pi] == -1 && trie[node].is_end)
                firstOccurrence[pi] = i+1;
        }

        trie[node].occurrences++;
    }    
}

int dfs(int u){
    int totalOccurences = trie[u].occurrences;
    for(int v : trieAdjList[u]){    
        totalOccurences += dfs(v);
    }
    for(int patternIndex : trie[u].patternIndices)
        patternFound[patternIndex] = totalOccurences;
    return totalOccurences;
}
 
 
int main(){
    cin >> s;
    cin >> n;
    string p;
    rep(i,0,n-1){
        cin >> p;
        patterns.pb(p);
        insertPattern(p, i);
    }
    buildFailureLinks();
    runAhoCorasick(s);
    dfs(1);

    for(int i = 0; i < n; i++){
        if(patternFound[i])
            cout << firstOccurrence[i] << endl;
        else    
            cout << "-1\n";
    }

    return 0;
}