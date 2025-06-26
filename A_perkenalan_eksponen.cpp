#include <iostream>
#include <iomanip>
#define ll long long
#define MOD 1000000
using namespace std;

ll a, b;
bool flag; 

ll rec(ll base, ll exp) {
    if (exp == 0) return 1;
    ll res = rec(base, exp / 2);
    res = (res * res);
    if (res >= MOD) flag = true;
    res %= MOD;

    if (exp % 2) {
        res = res * base;
        if (res >= MOD) flag = true;
        res %= MOD;
    }

    return res;
}

int main() {
    cin >> a >> b;
    flag = false;
    ll res = rec(a, b);

    if (flag)
        cout << setfill('0') << setw(6) << res << "\n";
    else
        cout << res << "\n";

    return 0;
}
