#include <iostream>

using namespace std;

int R, C;
char arr[30][10];

int erase(){
    int last = -1;
    for (int i = last + 1; i < R; i++){
        bool full = true;
        for (int j = 0; j < C; j++){
            if(arr[i][j] == '0'){
                full = false;
            }
        }
        if(full){
            last = i;
            for (int j = 0; j < C; j++){
                arr[i][j] = '0';
            }
        }
    }
    return last;
}

void drop(int last){
    for (int i = last - 1; i >= 0;i--){
        for (int j = 0; j < C; j++){
            if(arr[i][j] == '1'){
                arr[i][j] = '0';
                int idx = i;
                while(idx < R && arr[idx][j] == '0'){
                    idx++;
                }
                arr[idx-1][j] = '1';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++){
        cin >> arr[i];
    }
    int last = -1;
    while ((last = erase()) != -1){
        drop(last);
    }
    for (int i = 0; i < R; i++){
        cout << arr[i] << endl;
    }
}