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
vector<bool> used(MAXN);

bool isValid(int kedalaman) {
    if (kedalaman < 3) return true;
    int a = hasil[kedalaman - 2];
    int b = hasil[kedalaman - 1];
    int c = hasil[kedalaman];

    if ((b > a && b > c) || (b < a && b < c)) {
        return true;
    }
    return false;
}

void coba(int kedalaman, int N) {
    if (kedalaman > N) {
        for (int i = 1; i <= N; i++) {
            cout << hasil[i];
        }
        cout << "\n";
    } else {
        for (int i = 1; i <= N; i++) {
            if (!used[i]) {
                hasil[kedalaman] = i;
                used[i] = true;

                if (isValid(kedalaman)) {
                    coba(kedalaman + 1, N);
                }

                used[i] = false;
            }
        }
    }
}

void solve() {
    int N;
    cin >> N;

    coba(1, N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}

