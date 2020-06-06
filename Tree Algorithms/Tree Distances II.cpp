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
#define N 200005
#define MOD 1000000007

int n, total;
vvi adj;
int in[N];
int cnt[N];
int out[N];

// Bottom-Up
void dfsIn(int u, int p = -1) {
    cnt[u] = 1;
    for(int v : adj[u]) {
        if(v == p)  continue;
        dfsIn(v, u);
        cnt[u] += cnt[v];
        in[u] += (in[v] + cnt[v]);
        total++;
    }
}

// Top Down
void dfsOut(int u, int p = -1) {
    for(int v : adj[u]) {
        if(v == p)  continue;
        in[v] = in[u] + (n - cnt[v]) - (cnt[v]); 
        dfsOut(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        total = 0;
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        // memset(cnt, 0, sizeof cnt);
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfsIn(1);
        dfsOut(1);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            cout <<  in[i] << " ";
        }
        cout << endl;
    }
	return 0;
}
