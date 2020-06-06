// Vey nicely explained by Rachit Jain: https://youtu.be/Xng1Od_v6Ug

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

int n;
vvi adj;
int in[N], out[N];

int dfsIn(int u, int p = -1) {
    in[u] = 1;
    for(int v : adj[u]) {
        if(v != p)
            in[u] = max(in[u], 1 + dfsIn(v, u));
    }
    return in[u];
}

void dfsOut(int u, int p = -1) {
    int mx1 = 0, mx2 = 0;
    for(int v : adj[u]) {
        if(v == p)  continue;
        if(in[v] >= mx1) mx2 = mx1, mx1 = in[v];
        else if(in[v] > mx2) mx2 = in[v];
    }
    for(int v : adj[u]) {
        if(v == p)  continue;
        // int par = p != -1 ? in[p] : 0;
        int use = (mx1 == in[v]) ? mx2 : mx1;
        out[v] = max(1 + out[u], 2 + use);
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
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
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
        for(int i = 1; i <= n; i++) {
            cout << max(in[i], out[i]) - 1 << " ";
        }
        cout << endl;
    }
	return 0;
}
