#include <iostream>

using namespace std;

string isSemiPrime(int n){
    int count = 0;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            count++;
        }
        if(count >= 2)
            return "BUKAN";
    }

    return "YA";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        
        if(N < 4){
            cout << "YA\n";
        } else {
            cout << isSemiPrime(N) << '\n';
        }
    }
}