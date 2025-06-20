#include <iostream>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int arr[m][n];
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << arr[m-j-1][i] << " ";
        }
        cout << endl;
    }

    return 0;   
}