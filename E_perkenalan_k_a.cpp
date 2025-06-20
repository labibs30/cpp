#include <iostream>
#include <vector>

using namespace std;
const int divisor = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, A, B;

    cin >> N >> A >> B;

    vector<vector<int>> C(N+1, vector<int>(N+1, 0));

    for (int i = 0; i <= N; i++){
        C[i][0] = 1;
        for (int j = i; j > 0; j--){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % divisor;
        }
    }

    int total = 0;
    for (int i = A; i <= B; i++){
        total = (total +  C[N][i]) % divisor;
    }

    cout << total % divisor << "\n";

    return 0;
}