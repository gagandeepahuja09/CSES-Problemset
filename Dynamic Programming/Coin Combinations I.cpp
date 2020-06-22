#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

// dp[x]
int dp[1000001];

signed main() {
    int n, x, MOD = 1e9 + 7;
    cin >> n >> x;
    vi c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int j = 1; j <= x; j++) {
        for(int i = 0; i < n; i++) {
            if(c[i] <= j) {
                    dp[j] += dp[j - c[i]];
                    dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << endl;
}
