
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int minwindowsize = INT_MAX;
    int currentsum = 0;
    int low = 0;
    int high = 0;

    while (high < nums.size()) {
        currentsum += nums[high];
        high++;

        while (currentsum >= target) {
            int currentwindowsize = high - low;
            minwindowsize = min(minwindowsize, currentwindowsize);

            currentsum -= nums[low];
            low++;
        }
    }

    if (minwindowsize == INT_MAX) {
        cout << 0 << endl;
    } else {
        cout << minwindowsize << endl;
    }

    return 0;
}
