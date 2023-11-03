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
ll M = 1e9 + 7;

void solve()
{
    int n;
    ll x, y;
    string s, p;
    vi a;
    cin >> n >> x >> y >> s >> p;
    rep(i, 0, n - 1) if (s[i] != p[i]) a.pb(i);
    int m = a.size();
    if (!m)
    {
        cout << 0;
        return;
    }
    if (m % 2)
    {
        cout << -1;
        return;
    }
    if (x >= y)
    {
        if (m == 2 && a[0] + 1 == a[1])
            cout << min(x, 2 * y);
        else
            cout << y * m / 2;
        return;
    }
    vl dp(m + 1, 0);
    rep(i, 2, m)
    {
        if (i % 2 == 0)
            dp[i] = min(dp[i - 2] + x * (a[i - 1] - a[i - 2]), dp[i - 1] + y);
        else
            dp[i] = min(dp[i - 2] + x * (a[i - 1] - a[i - 2]), dp[i - 1]);
    }
    cout << dp[m];
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
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
