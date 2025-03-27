#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 100005;
struct Node {
    long long count; 
    int length;
    int link; 
    map<char, int>
        nextNodes; 
    Node(){
        count = 0;
        length = 0;
        link = -1;
    }
};
Node nodes[2 * MAX_N];
int size, last;
vector<char> result;
void init(){
    nodes[0].length = 0;
    nodes[0].link = -1;
    size = 1;
    last = 0;
}
void extend(char character){
    int current = size++;
    nodes[current].length = nodes[last].length + 1;
    int previous = last;
    while (previous != -1
           && nodes[previous].nextNodes.find(character)
                  == nodes[previous].nextNodes.end()) {
        nodes[previous].nextNodes[character] = current;
        previous = nodes[previous].link;
    }
    if (previous == -1) {
        nodes[current].link = 0;
    }
    else {
        int next = nodes[previous].nextNodes[character];
        if (nodes[previous].length + 1
            == nodes[next].length) {
            nodes[current].link = next;
        }
        else {
            int clone = size++;
            nodes[clone].length
                = nodes[previous].length + 1;
            nodes[clone].nextNodes = nodes[next].nextNodes;
            nodes[clone].link = nodes[next].link;
            while (previous != -1
                   && nodes[previous].nextNodes[character]
                          == next) {
                nodes[previous].nextNodes[character]
                    = clone;
                previous = nodes[previous].link;
            }
            nodes[next].link = nodes[current].link = clone;
        }
    }
    last = current;
}
void calculate(int nodeIndex){
    nodes[nodeIndex].count = 1;
    for (auto& entry : nodes[nodeIndex].nextNodes) {
        int nextNodeIndex = entry.second;
        if (nodes[nextNodeIndex].count == 0) {
            calculate(nextNodeIndex);
        }
        nodes[nodeIndex].count
            += nodes[nextNodeIndex].count;
    }
}
void dfs(int nodeIndex, long long k){
    if (k < 0)
        return;
    for (auto& entry : nodes[nodeIndex].nextNodes) {
        char character = entry.first;
        int nextNodeIndex = entry.second;
        if (nodes[nextNodeIndex].count <= k) {
            k -= nodes[nextNodeIndex].count;
        }
        else {
            result.push_back(character);
            dfs(nextNodeIndex, k - 1);
            return;
        }
    }
}
int main(){
    string inputString = "babaacbaab";
    long long kthSmallest = 10;
    init();
    for (char c : inputString) {
        extend(c);
    }
    calculate(0);
    dfs(0, kthSmallest - 1);
    for (char c : result) {
        cout << c;
    }
    cout << endl;
    return 0;
}

