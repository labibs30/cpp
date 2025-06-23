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

int GLOBALMAX = 0;
int M, N;

void klik(int x, int y, int warna, vector<vector<int>>& sel, vector<pii>& pos, vector<vector<bool>>& visited) {
    if(x >= 0 && x < M && y >= 0 && y < N){
        if(!visited[x][y]){
            if(sel[x][y] == warna){
                visited[x][y] = true;
                pos.push_back({x, y});
                klik(x, y + 1, warna, sel, pos, visited);
                klik(x, y - 1, warna, sel, pos, visited);
                klik(x + 1, y, warna, sel, pos, visited);
                klik(x - 1, y, warna, sel, pos, visited);
            }
        }
    } 
}

void drop(vector<vector<int>>& sel) {
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

int jawbreaker(vector<vector<int>>& sel, int si, int sj) {
    if(sel[si][sj] == 0) return 0;
    
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    vector<pii> pos;
    klik(si, sj, sel[si][sj], sel, pos, visited);

    if(pos.size() < 2) return 0;

    int score1 = pos.size() * (pos.size() - 1);
    for (auto& p : pos) sel[p.F][p.S] = 0;
    drop(sel);

    int best2 = 0;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if(sel[i][j] == 0) continue;

            vector<vector<bool>> visited2(M, vector<bool>(N, false));
            vector<pii> pos2;
            klik(i, j, sel[i][j], sel, pos2, visited2);

            if(pos2.size() >= 2) {
                int score2 = (int)pos2.size() * (pos2.size() - 1);
                best2 = max(best2, score2);
            }
        }
    }
    return score1 + best2;
}

void solve() {

    cin >> M >> N;

    vector<vector<int>> sel(M, vector<int>(N));
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> sel[i][j];
        }
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            GLOBALMAX = max(GLOBALMAX, jawbreaker(sel, i, j));
        }
    }

    
    cout << GLOBALMAX << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
