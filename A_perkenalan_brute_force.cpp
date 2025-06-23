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
    string A, B;
    cin >> A >> B;
    int nA = A.size();
    int nB = B.size();
    if (B.size()+1 > nA){
        cout << "Wah, tidak bisa :(\n";
        return;
    }

    for (int i = 0; i < nB; i++){
        if(A[i] != B[i] && A[i+1] != B[i]){
            cout << "Wah, tidak bisa :(\n";
            return;
        }
    }
    cout << "Tentu saja bisa!\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
