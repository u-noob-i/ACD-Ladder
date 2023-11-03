#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 1e18
#define pb push_back
#define pr pop_back
#define rep(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define irep(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
ll M = 998244353;

int a[301];

void solve()
{
    int n, x, v;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int dp[200001], t[200001];
    memset(dp, 0, sizeof dp);
    dp[a[2] + 100000] = 1;
    rep(i, 2, n - 1)
    {
        memset(t, 0, sizeof t);
        rep(j, -100000, 100000)
        {
            v = dp[j + 100000];
            if (!v)
                continue;
            t[100000 + a[i + 1] - j] = (t[100000 + a[i + 1] - j] + v) % M;
            if (j)
                t[100000 + a[i + 1] + j] = (t[100000 + a[i + 1] + j] + v) % M;
        }
        swap(dp, t);
    }
    int ans = 0;
    rep(i, 0, 200000) ans = (ans + dp[i]) % M;
    cout << ans;
}

int main()
{
    cin.sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt = 1;
    // cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
