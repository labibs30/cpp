#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string result = "";
    for (int i = 2; i <= N; i++){
        int count = 0;
        while (N % i == 0){
            N /= i;
            count++;
        }
        if(count > 1){
            result += to_string(i) + "^" + to_string(count) + " x ";
        } else if (count == 1) {
            result += to_string(i) + " x ";
        }
    }
    cout << result.erase(result.size() - 2, 2) << "\n";
    return 0;
}