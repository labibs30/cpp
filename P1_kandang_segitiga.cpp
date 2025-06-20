#include <iostream>
#include <vector>
using namespace std;

int combination(int n, int r){
    vector<vector<int>> C(n+1, vector<int>(n+1, 0));
    for (int i = 0; i <= n; i++){
        C[i][0] = 1;
        for (int j = i; j > 0; j--){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) ;
        }
    }
    if (r > n) return 0;
    return C[n][r];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i <= N; i++){
        int n, r;
        cin >> n >> r;
    }
    cout << combination(N, 3) << endl;
    return 0;
}