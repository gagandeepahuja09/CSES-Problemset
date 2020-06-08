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

// Great question for set and multiset practice, find is also logN
 
signed main() {
    int x, n;
    cin >> x >> n;
    vi a(n);
    set<int> idx;
    multiset<int> len;
    idx.insert(0);
    idx.insert(x);
    len.insert(x);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        auto l = idx.lower_bound(a[i]);
        auto r = idx.upper_bound(a[i]);
        if(*l >= a[i])
            l--;
        idx.insert(a[i]);
        int d = *r - *l;
        // cout << d << endl;
        // cout << *r << " " << *l << endl;
        auto it = len.find(d);
        if(it != len.end()) {
            len.erase(it);
        }
        len.insert(a[i] - *l);
        len.insert(*r - a[i]);
        cout << *--len.end() << endl;
    }
}
