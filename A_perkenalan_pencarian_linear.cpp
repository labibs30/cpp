#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, X;
    cin >> N >> X;

    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    ll best = A[0];
    ll minDiff = abs(A[0] - X);

    for (int i = 1; i < N; i++) {
        ll diff = abs(A[i] - X);
        if (diff < minDiff || (diff == minDiff && A[i] < best)) {
            minDiff = diff;
            best = A[i];
        }
    }

    cout << best << "\n";
    return 0;
}
