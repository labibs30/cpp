#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> messages(3);

    for (int i = 0; i < 3; i++) {
        cin >> messages[i];
    }

    unordered_map<char, char> mapping;         
    unordered_map<char, char> reverseMapping;  

    int size = messages[0].size();

    for (int i = 0; i < size; i++) {
        char to = messages[0][i];
        char from = messages[1][i];

        if (mapping.count(from)) {
            if (mapping[from] != to) {
                cout << "Pak Dengklek bingung\n";
                return 0;
            }
        } else {
            mapping[from] = to;
        }

        if (reverseMapping.count(to)) {
            if (reverseMapping[to] != from) {
                cout << "Pak Dengklek bingung\n";
                return 0;
            }
        } else {
            reverseMapping[to] = from;
        }
    }

    string result = "";
    for (char c : messages[2]) {
        if (mapping.count(c)) {
            result += mapping[c];
        } else {
            result += '?';
        }
    }

    cout << result << '\n';
    return 0;
    
}
