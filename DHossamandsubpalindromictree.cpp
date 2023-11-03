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

string s;
vvi adj;
vvvi d;
int p[2001][2001], pal[2001][2001];

void dfs(int og, int u, int dist, int pp = -1)
{
    if (pp != -1)
    {
        p[og][u] = pp;
        d[dist].pb({og, u});
    }
    for (auto &v : adj[u])
        if (v != pp)
            dfs(og, v, dist + 1, u);
}

void solve()
{
    int n;
    cin >> n >> s;
    adj.clear();
    d.clear();
    adj.resize(n);
    d.resize(n);
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (n == 1)
    {
        cout << 1;
        return;
    }
    if (n == 2)
    {
        if (s[0] == s[1])
            cout << 2;
        else
            cout << 1;
        return;
    }
    rep(i, 0, n - 1) dfs(i, i, 0);
    memset(pal, 0, sizeof(pal));
    rep(i, 0, n - 1) pal[i][i] = 1;
    int ans = 1;
    for (auto &x : d[1])
    {
        int u = x[0], v = x[1];
        if (s[u] == s[v])
            pal[u][v] = pal[v][u] = 2;
        else
            pal[u][v] = pal[v][u] = 1;
        ans = max(ans, pal[u][v]);
    }
    rep(i, 2, d.size() - 1)
    {
        for (auto &x : d[i])
        {
            int u = x[0], v = x[1];
            if (s[u] == s[v])
                pal[u][v] = pal[v][u] = 2 + pal[p[u][v]][p[v][u]];
            else
                pal[u][v] = pal[v][u] = max(pal[u][p[u][v]], pal[p[v][u]][v]);
            ans = max(ans, pal[u][v]);
        }
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

    int tt = 1;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
