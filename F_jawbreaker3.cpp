#include <iostream>
#include <vector>
#include <algorithm>
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
vector<pair<int, int>> pos;
int T = 0;
int M, N;

void klik(int x, int y, int warna){
    if(x >= 0 && x < M && y >= 0 && y < N){
        if(!visited[x][y]){
            if(sel[x][y] == warna){
                T++;
                visited[x][y] = true;
                pos.push_back({x, y});
                klik(x, y + 1, warna);
                klik(x, y - 1, warna);
                klik(x + 1, y, warna);
                klik(x - 1, y, warna);
            }
        }
    } 
}

void drop() {
    for (int col = 0; col < N; col++) {
        int writeRow = M - 1;
        for (int row = M - 1; row >= 0; row--) {
            if (sel[row][col] != 0) {
                sel[writeRow][col] = sel[row][col];
                if (writeRow != row) sel[row][col] = 0;
                writeRow--;
            }
        }
    }
}

void solve() {

    int B, K;
    cin >> M >> N;
    int max = 0;
    vector<pair<int, int>> maxPos;
    sel = vector<vector<int>>(M, vector<int>(N));
    visited = vector<vector<bool>>(M, vector<bool>(N, false)); 

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> sel[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++){
            if (visited[i][j] == false){
                klik(i, j, sel[i][j]);
                if (T > max) {
                    max = T;
                    maxPos = pos;
                }
                T = 0;
                pos.clear();
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (find(all(maxPos), make_pair(i, j)) != maxPos.end()) {
                sel[i][j] = 0;
            }
        }
    }

    drop();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if(sel[i][j] == 0){
                cout << ". ";
            } else{
                cout << sel[i][j] << " ";
            }
        }
        cout << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
