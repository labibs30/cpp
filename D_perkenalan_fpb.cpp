#include <iostream>
#include <numeric> 
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long x = a * d + b * c;
    long long y = b * d;
    long long result_gcd = std::gcd(x, y);  

    cout << x / result_gcd << " " << y / result_gcd << endl;
    return 0;
}
