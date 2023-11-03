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
ll M = 1e18;

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

vvi adj, lift, d;
vi r, tin, tout, depth;
int ind;

void init(int N)
{
    adj.clear();
    adj.resize(N);
    lift.clear();
    lift.resize(N, vi(25));
    d.clear();
    d.resize(N);
    depth.resize(N);
    tin.resize(N);
    tout.resize(N);
    r.clear();
    ind = 0;
}

void dfs1(int u, int l, int p)
{
    tin[u] = ++ind;

    lift[u][0] = p;
    rep(i, 1, 24) lift[u][i] = lift[lift[u][i - 1]][i - 1];

    depth[u] = l;
    d[l].pb(tin[u]);
    for (auto &v : adj[u])
        dfs1(v, l + 1, u);

    tout[u] = ++ind;
}

int find(int u, int p)
{
    if (depth[u] < p)
        return -1;
    irep(i, 24, 0) if ((1 << i)&p) u = lift[u][i];
    return u;
}

int gets(int h, int l, int r)
{
    int x = -1, y = -1;
    int lo = 0, hi = d[h].size() - 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (d[h][mid] > l)
            x = mid, hi = mid - 1;
        else
            lo = mid + 1 ;
    }
    lo = 0, hi = d[h].size() - 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (d[h][mid] < r)
            y = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    return y - x;
}

void solve()
{
    int n, q;
    cin >> n;
    init(n);
    rep(i, 0, n - 1)
    {
        int x;
        cin >> x;
        if (x)
            adj[x - 1].pb(i);
        else
            r.pb(i);
    }
    for (auto &u : r)
        dfs1(u, 0, u);
    for (auto &i : d)
        sort(i.begin(), i.end());
    cin >> q;
    while (q--)
    {
        int u, p;
        cin >> u >> p;
        u--;
        u = find(u, p);
        if (u == -1)
            cout << 0 << " ";
        else
            cout << gets(depth[u] + p, tin[u], tout[u]) << " ";
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
