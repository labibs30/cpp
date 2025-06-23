#include <iostream>
#include <vector>
#include <set>
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

set<ll> ans;
void backtrack(const string &N, int index, int total, int current, int sign)
{
    if(N.size() ==  index){
        total += sign * current;
        ans.insert(total);
        return;
    }

    backtrack(N, index + 1, total, current * 10 + N[index] - '0', sign);
    backtrack(N, index + 1, total + sign * current, N[index] - '0', +1);
    backtrack(N, index + 1, total + sign * current, N[index] - '0', -1);
}

void solve() {
    string S;

    cin >> S;

    backtrack(S, 1, 0, S[0] - '0', 1);

    cout << ans.size() << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
