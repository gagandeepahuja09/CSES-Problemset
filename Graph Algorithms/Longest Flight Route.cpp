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

vector<set<int>> adj;
vi par, vis, p;
int n, mx;

void dfs(int u, int d = 0) {
    if(vis[u])
        return;
    vis[u] = 1;
    if(u == n) {
        return;
    }
    for(int v : adj[u])
        dfs(v);
    p.push_back(u);
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        int m;
        cin >> n >> m;
        adj.clear();
        adj.resize(n + 1);
        mx = 0;
        par.resize(n + 1);
        p.clear();
        vis.assign(n + 1, 0);
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].insert(b);
        }
        vi dp(n + 1, -1);
        dfs(1);
        reverse(p.begin(), p.end());
        for(int i = 0; i < p.size(); i++) {
            int u = p[i]; 
            cout << u << endl;
            if(dp[u] == -1) dp[u] = 1;
            for(int v : adj[u]) {
                if(dp[v] < 1 + dp[u]) {
                    dp[v] = 1 + dp[u];
                    par[v] = u;
                }
            }
        }
        if(dp[n] == -1) {
            cout << "IMPOSSIBLE";
        }
        else {
            vi r;
            int u = n;
            while(u != 1) {
                r.pb(u);
                u = par[u];
            }
            r.pb(1);
            reverse(r.begin(), r.end());
            cout << r.size() << endl;
            for(int i : r)  cout << i << " "; 
        }
        cout << endl;
    }
	return 0;
}
