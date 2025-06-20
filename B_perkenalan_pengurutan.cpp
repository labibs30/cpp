#include <iostream>
#include <vector>
#include <iomanip>

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

    sort(arr.begin(), arr.end());

    double result = 0.0;

    if (N%2 == 0) {
        result = (arr[N/2] + arr[N/2 - 1])/2.0;
    } else {
        result = arr[N/2];
    }

    cout << fixed << setprecision(1) << result << "\n";
    return 0;
}