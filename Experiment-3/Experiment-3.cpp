//UID - 24BCS12059
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P')
            sum += 1;
        else
            sum -= 1;

        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    cout << maxLen << endl;
    return 0;
}