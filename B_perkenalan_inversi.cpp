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

vector<ll> v(MAXN);
int T = 0;

ll merge(int left, int mid, int right){
    ll n1 = mid - left + 1;
    int n2 = right - mid;

    vector<ll> L(n1), R(n2);

    for (ll i = 0; i < n1; i++){
        L[i] = v[left + i];
    }

    for (ll i = 0; i < n2; i++){
        R[i] = v[mid + 1 + i];
    }

    ll i = 0, j = 0;
    ll k = left;
    ll inversions = 0;
    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j]){
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
            inversions += n1 - i;
        }
        k++;
    }

    while(i < n1){
        v[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        v[k] = R[j];
        j++;
        k++;
    }

    return inversions;
}

ll mergeSort( ll left, ll right){
    if (left >= right)
        return 0;

    ll mid = left + (right - left) / 2;
    ll inversions = 0;
    inversions += mergeSort(left, mid);
    inversions += mergeSort(mid + 1, right);
    inversions += merge(left, mid, right);

    return inversions;
}

void solve()
{
    ll N;
    cin >> N;
    v = vector<ll>(N);
    for (ll i = 0; i < N; i++) cin >> v[i];

    ll res = mergeSort(0, N - 1);

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
