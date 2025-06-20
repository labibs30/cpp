#include <iostream>
#include <vector>
using namespace std;

const int MAX_PRIME = 1300000; 
vector<int> primes;

void generatePrimes() {
    vector<bool> isPrime(MAX_PRIME + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_PRIME; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAX_PRIME; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    generatePrimes(); 

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N <= 0 || N > primes.size()) {
            cout << -1 << "\n";
        } else {
            cout << primes[N - 1] << "\n"; 
        }
    }
}
