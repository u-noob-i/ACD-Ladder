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

vvi adj;
vi s, ch;
map<pair<int, int>, ll> dp;

ll dfs(int u, int k)
{
    if (dp.find({u, k}) != dp.end())
        return dp[ {u, k}];
    ll ret = 1ll * s[u] * k;
    if (!ch[u])
    {
        dp[ {u, k}] = ret;
        return ret;
    }
    int x = k / ch[u], y = (k + ch[u] - 1) / ch[u], z = k % ch[u];
    if (z)
        z = ch[u] - z;
    vl t;
    for (auto v : adj[u])
    {
        ll a = dfs(v, y), b = dfs(v, x);
        ret += a;
        t.pb(a - b);
    }
    sort(t.begin(), t.end());
    for (auto itr : t)
    {
        if (!z)
            break;
        ret -= itr;
        z--;
    }
    dp[ {u, k}] = ret;
    return ret;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    adj.clear();
    dp.clear();
    adj.resize(n);
    s.assign(n, 0);
    ch.assign(n, 0);

    rep(i, 1, n - 1)
    {
        int v;
        cin >> v;
        v--;
        adj[v].pb(i);
        ch[v]++;
    }
    rep(i, 0, n - 1)
    {
        cin >> s[i];
        dp[ {i, 0}] = 0;
    }
    cout << dfs(0, k);
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
