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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    read(a);
    vi b(m);
    read(b);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(j < m && b[j] < a[i] - k)
            j++;
        if(j < m && b[j] <= a[i] + k && b[j] >= a[i] - k) {
            cnt++;
            j++;
        }
    }
    cout << cnt << endl;
}
