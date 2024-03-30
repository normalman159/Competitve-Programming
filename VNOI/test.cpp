#include <iostream>
#include<vector>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    vector<long long> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    vector<vector<long long> > dp(k + 1, vector<long long> (n + 1, LLONG_MIN / 100)), maxcombi = dp;

    for(int j = 0; j <= k; j++) {
        if(!j) {
            dp[0][0] = 0;
        }
        else {
            for(int i = 1; i <= n; i++) {
                dp[j][i] = maxcombi[j - 1][i - 1] + pref[i];
            }
        }

        long long maxdp = maxcombi[j][0] = dp[j][0];
        for(int i = 1; i <= n; i++) {
            maxdp = max(maxdp, dp[j][i]);
            maxcombi[j][i] = max(maxcombi[j][i - 1], maxdp - pref[i]);
        }
    }
    long long ans = LLONG_MIN / 100ll;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[k][i]);
    }
    cout << ans;
}
