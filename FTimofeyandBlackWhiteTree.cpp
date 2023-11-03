#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 1e9
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

int ans;
vb a;
vvi adj;
vi dp;

void dfs(int u, int p = -1)
{
    if (dp[u] >= ans)
        return;
    if (a[u])
        ans = min(ans, dp[u]);
    for (auto &v : adj[u])
        if (v != p)
        {
            if (dp[v] > dp[u] + 1)
            {
                dp[v] = dp[u] + 1;
                dfs(v, u);
            }
            else
                ans = min(ans, 1 + dp[u] + dp[v]);
        }
}

void solve()
{
    int n, x;
    cin >> n >> x;
    adj.clear();
    adj.resize(n);
    vi op(n - 1);
    for (auto &i : op)
        cin >> i;
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans = INF;
    a.assign(n, 0);
    dp.assign(n, INF);
    a[x - 1] = 1;
    dfs(x - 1);
    for (auto &i : op)
    {
        dp[i - 1] = 0;
        dfs(i - 1);
        a[x - 1] = 1;
        cout << ans << " ";
    }
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
