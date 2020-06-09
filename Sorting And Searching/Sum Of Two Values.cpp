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

signed main() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int val = mp[k - a[i]];
        if(val) {
            cout << val << " " << i + 1 << endl;
            return 0;
        }
        mp[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
