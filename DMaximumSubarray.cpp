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

void solve()
{
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vl a(n + 1);
    vector<vvl> dp(n + 1, vvl(k + 1, vl(2, -INF)));
    rep(i, 1, n) cin >> a[i];
    dp[0][0][0]  = 0;
    ll ans = 0;
    rep(i, 1, n) rep(j, 0, min(i, k))
    {
        if (n - i < k - j)
            continue;
        dp[i][j][0] = 0;
        if (j < i)
            dp[i][j][1] = max(dp[i - 1][j][0] + a[i] - x, dp[i - 1][j][1] + a[i] - x);
        if (j)
            dp[i][j][1] = max(dp[i][j][1], max(dp[i - 1][j - 1][0] + a[i] + x,
                                               dp[i - 1][j - 1][1] + a[i] + x));
        ans = max(ans, dp[i][j][1]);
    }
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

    int tt;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
