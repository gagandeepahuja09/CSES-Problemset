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
    int n, m;
    cin >> n >> m;
    vi h(n);
    multiset<int> st; 
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        st.insert(h[i]);
    }
    vi t(m);
    for(int i = 0; i < m; i++) {
        cin >> t[i];
        auto it = st.lower_bound(t[i]);
        // cout << *it << endl;
        if(it != st.end()) {
            // cout << "yes";
            if(*it > t[i]) {
                if(it != st.begin())
                    it--;
            }
            if(*it > t[i])
                cout << -1 << endl;
            else {
                cout << *it << endl;
                st.erase(it);
            }
        }
        else {
            if(st.size()) {
                auto it = st.end();
                it--;
                cout << *(it) << endl;
                st.erase(it);
            }
            else
                cout << -1 << endl;
        }
    }
    cout << endl;
}
