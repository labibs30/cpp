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

int f[10005];
int N, M;
int nB, nK;
int sB, sK;

void rec(int idx, int nb, int nk, vector<int> &ans){
    if(nk+nb == 1){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        exit(0);
    }

    if(nb > 0 && f[idx+sB - 1] != f[idx+sB]){
        ans.push_back(f[idx+sB-1]+1);
        rec(idx+sB, nb-1, nk, ans);
        ans.pop_back();
    }

    if(nk > 0 && f[idx+sK - 1] != f[idx+sK]){
        ans.push_back(f[idx+sK-1]+1);
        rec(idx+sK, nb, nk-1, ans);
        ans.pop_back();
    }
}

void solve(){
    int G;
    cin >> M;
    for (int i = 0; i < M; i++) cin >> f[i];

    cin >> N;
    nB = M % N;
    nK = N - nB;

    sK = M / N;
    sB = sK+ 1;
    sort(f, f + M);
    
    vector<int> ans;
    rec(0, nB, nK, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
