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
int depth[N], par[N][20];

void buildLCA(int u, int p = 0) {
    depth[u] = depth[p] + 1;
    par[u][0] = p;
    for(int i = 1; i <= 19; i++) {
        int x = par[u][i - 1];
        par[u][i] = par[x][i - 1];
    }
    for(int v : adj[u]) {
        if(v != p) {
            buildLCA(v, u);
        }
    }
}

int lca(int a, int b) {
    if(depth[a] > depth[b]) {
        swap(a, b);
    }
    // cout << par[4][1] << " " << a << endl;
    for(int i = 19; i >= 0; i--) {
        if(depth[par[b][i]] >= depth[a]) {
            // cout << "x " << i << endl;
            b = par[b][i];
        }
    }
    // cout << a << " " << b << endl;
    if(a == b)  return a;
    for(int i = 19; i >= 0; i--) {
        if(par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    if(a != b)  a = par[a][0];
    return a;
}

void dfs(int u, vi& sum) {
    int p = par[u][0];
    for(int v : adj[u]) {
        if(v == p)  continue;
        dfs(v, sum);
        sum[u] += sum[v];
    }
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        memset(depth, 0, sizeof depth);
        memset(par, 0, sizeof par);
        int n, m;
        cin >> n >> m;
        adj.clear();
        adj.resize(n + 1);
        for(int i = 0; i < n - 1; i++) {
            int a, b;
            b = i + 2;
            cin >> a;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        buildLCA(1);
        vi sum(n + 1, 0);
        while(m--) {
            int x, k;
            cin >> x >> k;
            for(int i = 19; i >= 0; i--) {
                int p = 1 << i;
                if(p <= k && k > 0) {
                    k -= p;
                    x = par[x][i];
                }
                if(k == 0)  break;
            }
            if(k || !x)   cout << -1 << endl;
            else    cout << x << endl;
        }
        cout << endl;
    }
	return 0;
}
