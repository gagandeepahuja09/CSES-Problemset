#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";
#define pb push_back
#define pql priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pqlv priority_queue<vi>
#define pqsv priority_queue<vi, vvi, greater<vi>>
#define endl '\n'
#define N 1234567
#define MOD 1000000007

int f(int val, vi& a, int ret = 0) {
    for(int i = 0; i < a.size(); i++) {
        ret += abs(val - a[i]);
    }
    return ret;
}

signed main() {
    int n;
    cin >> n;
    map<int, int> mp;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = f(a[n / 2], a);
    if(n % 2 == 0) {
        ans = min(ans, f(a[n / 2 - 1], a));
    }
    cout << ans << endl;
    return 0;
}
