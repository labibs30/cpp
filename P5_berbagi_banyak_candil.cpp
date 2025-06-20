#include <iostream>
#define LL long long 
using namespace std;

int main() {

    LL B, C, D;
    cin >> B >> C >> D;
    LL count = 0;

    if(C == D){
        if(B > C){
            count += B-C;
        } else {
            count = 0;
        }
    } else {
        LL N = C - D;
        for (LL i = 1; i * i <= N; i++){
            LL bil1 = i;
            LL bil2 = N / bil1;

            if(C%bil1 == D && bil1 <= B) count++;
            if(C%bil2 == D && bil2 <= B && bil1 != bil2) count++;
        }
    }
    
    cout << count << "\n";

    return 0;
}
