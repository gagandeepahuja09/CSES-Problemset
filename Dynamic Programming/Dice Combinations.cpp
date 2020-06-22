#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

signed main() {
    int n, MOD = 1e9 + 7;
    cin >> n;
    vi dp(n + 1, 1);
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(i > 6)   dp[i] = 0;
        for(int j = max(1ll, i - 6ll); j < i; j++) {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
        // cout << dp[i] << endl;
    }
    cout << dp[n] % MOD << endl;
}
