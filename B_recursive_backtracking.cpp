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

vector<int> hasil(MAXN);

void coba(int kedalaman, int N, int K) {
    if (kedalaman > K) {
        for (int i = 1; i <= K; i++) {
            cout << hasil[i] << " ";
        }
        cout << "\n";
    } else {
        for (int i = hasil[kedalaman-1] + 1; i <= N; i++) {
            hasil[kedalaman] = i;
            coba(kedalaman + 1, N, K);
        }
    }
}
void solve() {
    int N, K;
    cin >> N >> K;

    coba(1, N, K);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
