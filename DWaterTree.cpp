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
#define vvvl vector<vector<vector<ll>>>
ll M = 1e9 + 7;

//---------------------------------------------//
ll getrandom(int range)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(0, range);
    return dist6(rng);
}
ll gcd(ll XX, ll YY) { return YY == 0 ? XX : gcd(YY, XX % YY);}
ll exppow(ll XX, ll YY)
{
    XX %= M;
    ll ret = 1;
    while (YY > 0) {
        if (YY % 2)
            ret = (ret * XX) % M;
        XX = (XX * XX) % M;
        YY /= 2;
    }
    return ret;
}
ll fracmod(ll XX, ll YY)
{
    ll ZZ = gcd(XX, YY);
    XX = XX / ZZ;
    YY = YY / ZZ;
    return (XX * exppow(YY, M - 2)) % M;
}
//---------------------------------------------//

struct segmenttree {
    int n;
    vi st, lazy;

    segmenttree(int N)
    {
        n = N;
        st.assign(8 * n + 5, 0);
        lazy.assign(8 * n + 5, 0);
    }

    segmenttree() {}

    void pushdown(int u)
    {
        if (!lazy[u])
            return;
        st[2 * u] = st[2 * u + 1] = lazy[2 * u] = lazy[2 * u + 1] = lazy[u];
        lazy[u] = 0;
    }

    void update(int u, int tl, int tr, int l, int r, int v)
    {
        pushdown(u);
        if (tl > tr || tl > r || tr < l)
            return;
        if (tl >= l && tr <= r)
            st[u] = lazy[u] = v;
        else
        {
            int m = (tl + tr) / 2;
            update(2 * u, tl, m, l, r, v);
            update(2 * u + 1, m + 1, tr, l, r, v);
            st[u] = max(st[2 * u], st[2 * u + 1]);
        }
    }

    int query(int u, int tl, int tr, int l, int r)
    {
        pushdown(u);
        if (tl > tr || tl > r || tr < l)
            return 0;
        if (tl >= l && tr <= r)
            return st[u];
        else
        {
            int m = (tl + tr) / 2;
            return max(query(2 * u, tl, m, l, r), query(2 * u + 1, m + 1, tr, l, r));
        }
    }

} white, black;

vvi adj;
vi tin, tout;
int tmr;

void dfs(int u, int p = -1)
{
    tin[u] = ++tmr;
    for (auto &v : adj[u])
        if (v != p)
            dfs(v, u);
    tout[u] = tmr;
}

void solve()
{
    int n, q;
    cin >> n;
    white = segmenttree(n);
    black = segmenttree(n);
    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    tmr = 0;
    dfs(0);
    cin >> q;
    rep(i, 1, q)
    {
        int t, v;
        cin >> t >> v;
        int l = tin[v - 1], r = tout[v - 1];
        if (t == 1)
            white.update(1, 1, n, l, r, i);
        else if (t == 2)
            black.update(1, 1, n, l, l, i);
        else
            cout << (white.query(1, 1, n, l, l) > black.query(1, 1, n, l, r)) << "\n";
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
