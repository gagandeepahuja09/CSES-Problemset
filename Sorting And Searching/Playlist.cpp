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
    int j = 0, mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] == 2) {
            while(j < n && a[j] != a[i]) {
                mp[a[j++]]--;
            }
            if(j < n)
                mp[a[j++]]--;
        }
        mx = max(mx, i - j + 1);
        // cout << i << " " << j << endl;
    }
    cout << mx << endl;
    return 0;
}
