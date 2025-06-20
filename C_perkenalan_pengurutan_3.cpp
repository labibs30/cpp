#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<string, int>> MP;

    for (int i = 0; i < N; i++){
        string S;
        cin >> S;
        MP.push_back(make_pair(S, S.size()));
    }

    sort(MP.begin(), MP.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second)
            return a.first < b.first; 
        return a.second < b.second;   
    });

    for (auto x : MP) {
        cout << x.first << "\n";
    }

    return 0;
}
