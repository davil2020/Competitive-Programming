#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> children(n);
    for(int i = 0; i < n; i++)
        children[i] = i + 1;
    while(children.size() > 1){
        vector<int> survivors;
        for(size_t i = 0; i < children.size(); i++){
            if(i%2 == 1)
                cout << children[i] << " ";
            else
            survivors.push_back(children[i]);    
        }
        if(children.size() % 2 == 0)
            children = survivors;
        else{
            int starter = survivors.back();
            survivors.pop_back();
            children.clear();
            children.push_back(starter);
            for(int child : survivors)
                children.push_back(child);
        }
    }
    cout << children[0] << endl;
    return 0;    
}