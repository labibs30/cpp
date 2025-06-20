#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, x;

    cin >> N >> x;

    vector<int> arr;

    while (N > 0){
        arr.push_back(N % x);
        N /= x;
    }
    
    for (int i = arr.size() - 1; i >= 0; i--){
        cout << arr[i];
    }
    
    cout << "\n";
    return 0;
}