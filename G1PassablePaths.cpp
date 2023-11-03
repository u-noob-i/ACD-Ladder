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

vvi adj, dp;
vi h, a, tin, tout;
int n, q, k, ct, ind;

void dfs1(int u, int d, int p = 0)
{
    tin[u] = ++ind;
    dp[u][0] = p;
    rep(i, 1, 25) dp[u][i] = dp[dp[u][i - 1]][i - 1];
    h[u] = d;
    for (auto v : adj[u])
        if (v != p)
            dfs1(v, d + 1, u);
    tout[u] = ++ind;
}

bool isanc(int u, int v)
{
    return tin[v] < tin[u] && tout[v] > tout[u];
}

int lca(int u, int v)
{
    if (isanc(u, v))
        return v;
    if (isanc(v, u))
        return u;
    irep(i, 25, 0) if (!isanc(v, dp[u][i])) u = dp[u][i];
    return dp[u][0];
}

void solve()
{
    int u, v, x;
    cin >> n;
    adj.resize(n);
    dp.resize(n, vi(26));
    tin.resize(n);
    tout.resize(n);
    h.resize(n);
    rep(i, 0, n - 2)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ind = 0;
    dfs1(0, 0);
    cin >> q;
    while (q--)
    {
        cin >> k;
        a.resize(k);
        rep(i, 0, k - 1)
        {
            cin >> a[i];
            a[i]--;
        }
        if (k <= 2)
        {
            cout << "YES\n";
            continue;
        }
        sort(a.begin(), a.end(),
        [&](const int &aa, const int &bb) {return h[aa] < h[bb];});
        vi c1, c2;
        c1.pb(a[k - 1]);
        bool f = 1;
        irep(i, k - 2, 0)
        {
            if (!isanc(c1.back(), a[i]))
            {
                if (!c2.size())
                    c2.pb(a[i]);
                else if (!isanc(c2.back(), a[i]))
                {
                    f = 0;
                    break;
                }
                else
                    c2.pb(a[i]);
            }
            else
                c1.pb(a[i]);
        }
        if (!f)
            cout << "NO\n";
        else if (!c2.size() || (!isanc(c1.back(), c2.back()) &&
                                !isanc(c2.back(), c1.back())))
            cout << "YES\n";
        else if (isanc(c1.back(), c2.back()))
        {
            if (c2.size() == 1 || lca(c2[c2.size() - 2], c1.back()) == c2.back())
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            if (c1.size() == 1 || lca(c1[c1.size() - 2], c2.back()) == c1.back())
                cout << "YES\n";
            else
                cout << "NO\n";
        }
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
    // cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
