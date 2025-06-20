#include <iostream>
#include <vector>
#define LL long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL B, K;

    cin >> B >> K;

    LL selisih = K - B;
    
    vector<LL> result;
    // for (int i = 0; i <= 60; i++){
    //     if((selisih >> i) & 1){
    //         result.push_back(1LL << i);
    //     }
    // }

    // for(int i = result.size() - 1; i >= 0; i--){
    //     cout << result[i] << "\n";
    // }
    int i = 0;

    while(selisih > 0){
        if(selisih & 1){
            result.push_back(1LL << i);
        }
        selisih >>= 1;
        i++;
    }

    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << "\n";
    }
    return 0;
}