#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        ll x, y;
        cin >> x >> y;

        auto it_l = upper_bound(A.begin(), A.end(), x); // > x
        auto it_r = upper_bound(A.begin(), A.end(), y); // > y

        cout << (it_r - it_l) << "\n";
    }

    return 0;
}
