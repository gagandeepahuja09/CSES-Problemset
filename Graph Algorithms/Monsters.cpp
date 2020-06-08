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
 
vector<string> v;
int n, m;
 
int dist[1001][1001];
int d[1001][1001];
 
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        memset(dist, -1, sizeof dist);
        cin >> n >> m;
        v.clear();
        v.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int x, y, c1, c2;
        queue<vi> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 'M') {
                    q.push({ i, j, 0 });
                }
                if(v[i][j] == 'A') {
                    x = i; y = j;
                }
            }
        }
        c1 = x; c2 = y;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            int x = f[0], y = f[1], steps = f[2];
            // cout << x << " " << y << endl;
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || dist[x][y] != -1) {
                continue;
            }
            dist[x][y] = steps;
            vi dx = { 0, 0, -1, 1 };
            vi dy = { -1, 1, 0, 0 };
            for(int i = 0; i < 4; i++) {
                int cx = x + dx[i], cy = y + dy[i];
                if(cx < 0 || cx > n - 1 || cy < 0 || cy > m - 1 || v[cx][cy] == 'M')
                    continue;
                q.push({ cx, cy, steps + 1 });
            }
        }
        int cnt = 0;
        string ret;
        while(!q.empty())   q.pop();
        q.push({ x, y, 0, 0 });
        memset(d, -1, sizeof d);
        bool ans = false;
        // L => 0, R => 1, U => 2, D => 3
        int p[n + 1][m + 1];
        memset(p, 0, sizeof p);
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            int x = f[0], y = f[1], steps = f[2], dir = f[3];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || d[x][y] != -1 || (dist[x][y] >= 0 && dist[x][y] <= steps))
                continue;
            d[x][y] = steps;
            p[x][y] = dir;
            if(x == n - 1 || y == m - 1 || x == 0 || y == 0) {
                // cout << d[x][y] << " " << dist[x][y] << endl;
                while(x != c1 || y != c2) {
                    cnt++;
                    if(p[x][y] == 0)    ret += 'L', y++;
                    else if(p[x][y] == 1)   ret += 'R', y--;
                    else if(p[x][y] == 2)   ret += 'U', x++;
                    else    ret += 'D', x--;
                }
                ans = true;
                break;
            }
            vi dx = { 0, 0, -1, 1 };
            vi dy = { -1, 1, 0, 0 };
            for(int i = 0; i < 4; i++) {
                int cx = x + dx[i], cy = y + dy[i];
                q.push({ cx, cy, steps + 1, i });
            }
        }
        if(ans) {
            reverse(ret.begin(), ret.end());
            cout << "YES" << endl << cnt << endl << ret;
        }
        else
            cout << "NO";
        cout << endl;
    }
}
