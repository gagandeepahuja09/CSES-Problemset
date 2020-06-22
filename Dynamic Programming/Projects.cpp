#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

const int MOD = 1e9 + 7, N = 2e5 + 1;
int n, x;

int dp[N];

int bs(vvi& a, int i, int target) {
    int low = i + 1, high = a.size() - 1, ans = a.size();
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid][0] > target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans; 
}

int f(int i, vvi &a) {
    if(i == a.size())   return 0;
    if(dp[i] != -1) return dp[i];
    int op1 = f(i + 1, a);
    int idx = bs(a, i, a[i][1]);
    int op2 = f(idx, a) + a[i][2];
    return dp[i] = max(op1, op2);
}

signed main() {
    cin >> n;
    vvi a(n, vi(3, 0));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    memset(dp, -1, sizeof dp);
    sort(a.begin(), a.end());
    cout << f(0, a) << endl;
}
