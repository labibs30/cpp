#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, x;
    cin >> r >> c >> x;

    vector<vector<int>> arr(r, vector<int>(c));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }

    while (x--) {
        string expression;
        cin >> expression;

        if (expression == "-") {
            for (int i = 0; i < r / 2; i++) {
                for (int j = 0; j < c; j++) {
                    swap(arr[i][j], arr[r - i - 1][j]);
                }
            }
        } else if (expression == "|") {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c / 2; j++) {
                    swap(arr[i][j], arr[i][c - j - 1]);
                }
            }
        } else if (expression == "90") {
            vector<vector<int>> rotated(c, vector<int>(r));
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    rotated[j][r - i - 1] = arr[i][j];
                }
            }
            arr = rotated;
            swap(r, c); // Important to swap row and col
        } else if (expression == "180") {
            vector<vector<int>> rotated(r, vector<int>(c));
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    rotated[i][j] = arr[r - i - 1][c - j - 1];
                }
            }
            arr = rotated;
        } else if (expression == "270") {
            vector<vector<int>> rotated(c, vector<int>(r));
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    rotated[c - j - 1][i] = arr[i][j];
                }
            }
            arr = rotated;
            swap(r, c); // Important to swap row and col
        }
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
