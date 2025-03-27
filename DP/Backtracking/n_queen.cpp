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

bool canPlace(int board[][20], int n, int x, int y){
    //column
    for(int k = 0; k<x; k++){
        if(board[k][y] == 1)
            return false;
    }

    //left diagonal
    int i = x;
    int j = y;
    while(i>=0 && j>=0){
        if(board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    //right diagonal
    i = x;
    j = y;
    while(i>=0 && j<=n){
        if(board[i][j] == 1)
            return false;
            i--;
            j++;
    }

    return true;
}

void printBoard(int n, int board[][20]){
    for(int i = 0; i <n; i++){
        for(int j =0; j<n; j++){
            cout << board[i][j]<<" ";

        }
        cout << endl;
    }
    cout << endl;
}

int sovlNQueen(int n, int board[][20], int i){
    //base case
    if(i == n){
        //print the board
        printBoard(n, board);
        return 1;
    }

    //rec case
    //try to place the queen in every row
    int ways = 0;
    for(int j = 0; j<n; j++){
        //whether the current i, j is safer or not
        if(canPlace(board, n, i, j)){
            board[i][j] = 1;
            ways += sovlNQueen(n, board, i+1);
            
            //backtrack
            board[i][j] = 0;
        }
    }

    return false;
}
 
int main(){
    int board [20][20] = {0};
    int n;
    cin >> n;

    sovlNQueen(n, board, 0);


    return 0;
}