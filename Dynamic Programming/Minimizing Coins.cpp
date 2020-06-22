#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

// dp[x]
int dp[1000001];

signed main() {
    int n, x;
    cin >> n >> x;
    vi c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for(int j = 1; j <= x; j++) {
        for(int i = 0; i < n; i++) {
            if(c[i] <= j && dp[j - c[i]] != -1) {
                if(dp[j] == -1 || (dp[j] > 1 + dp[j - c[i]])) {
                    dp[j] = 1 + dp[j - c[i]];
                }
            }
        }
    }
    cout << dp[x] << endl;
}
