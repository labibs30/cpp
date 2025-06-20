#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int result = arr[0];
    for (int i = 1; i < N; i++) {
        result = lcm(result, arr[i]);
    }

    cout << result << "\n";
    return 0;
}
