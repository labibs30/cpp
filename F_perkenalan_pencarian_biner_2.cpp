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

void solve() {
    int N, Q;
    cin >> N;
    vector<int> A(N);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        count += n;
        A[i] = count;
    }

    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        auto it = lower_bound(all(A), n);

        cout << (it - A.begin()) + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
