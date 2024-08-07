#include <bits/stdc++.h>
using namespace std;
// kth smallest number again
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n, q;
        cin >> n >> q;
        vector<pair<long long int, long long int>> v;
        for (long long int i = 0; i < n; i++) {
            long long int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end()); // sort
        long long int idx = 0;    // merge
        for (long long int i = 1; i < v.size(); i++) {
            if (v[idx].second >= v[i].first) {
                v[idx].second = max(v[idx].second, v[i].second);
            } else {
                idx++;
                v[idx] = v[i];
            }
        }
        while (q--) {
            long long int k;
            cin >> k;
            long long int ans = -1;
            for (long long int i = 0; i <= idx; i++) { // what it is doing here
                if ((v[i].second - v[i].first + 1) >= k) { // understanding this is important
                    ans = v[i].first + k - 1;
                    break;
                } else {
                    k = k - (v[i].second - v[i].first + 1);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
