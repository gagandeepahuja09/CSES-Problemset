// New Concept: Helpful YT Video: https://www.youtube.com/watch?v=ZcYI6ZVsu2w&t=660s

#include<bits/stdc++.h>
using namespace std;

#define N 2000004

#define int long long int
int const M = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    int prevprev = 0, prev = 1;
    if(n == 1) {
        cout << 0 << endl;
    }
    else if(n == 2) {
        cout << 1 << endl;
    }
    else {
        int ans = 0;
        for(int i = 3; i <= n; i++) {
            ans = ((i - 1) * (prev + prevprev)) % M;
            prevprev = prev;
            prev = ans;
        }
        cout << ans << endl;
    }
}
