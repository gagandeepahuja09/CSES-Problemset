#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

const int MOD = 1e9 + 7, N = 2e5 + 1;
int n;

int dp[101][100001];

int f(int i, int sum, vi& a) {
    if(sum == 0)    return 1;
    if(sum < 0 || i == n)  return 0;
    if(dp[i][sum] != -1)    return dp[i][sum];
    int op1 = f(i + 1, sum, a);
    int op2 = f(i + 1, sum - a[i], a);
    return dp[i][sum] = (op1 || op2);
}

signed main() {
    cin >> n;
    vi a(n);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vi v;
    for(int i = 100000; i >= 1; i--) {
        if(f(0, i, a)) {
            v.pb(i);
        }
    }
    cout << v.size() << endl;
    for(int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}
