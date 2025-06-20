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

int upper_bound(vector<int> A, int key){
    int n = A.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = (left + right) /2;

        if(A[mid] <= key) left = mid + 1;
        else right = mid;
    }

    return left;
}

void solve() {
    vector <int> A = {1, 2, 3, 4, 10};

    cout << upper_bound(A, 5) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) solve();

    return 0;
}
