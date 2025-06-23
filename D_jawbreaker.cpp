#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MAXN = 2e5 + 5; 

vector<vector<int>> sel(MAXN);
vector<vector<bool>> visited(MAXN);
int T = 0;
int M, N;

void klik(int x, int y, int warna){
    if(x >= 0 && x < M && y >= 0 && y < N){
        if(!visited[x][y]){
            if(sel[x][y] == warna){
                T++;
                visited[x][y] = true;
                klik(x, y + 1, warna);
                klik(x, y - 1, warna);
                klik(x + 1, y, warna);
                klik(x - 1, y, warna);
            }
        }
    }
}
void solve() {

    int B, K;
    cin >> M >> N;

    sel = vector<vector<int>>(M, vector<int>(N));         
    visited = vector<vector<bool>>(M, vector<bool>(N, false)); 

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> sel[i][j];
        }
    }

    cin >> B >> K;
    klik(B, K, sel[B][K]);

    cout << T * (T-1) << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
