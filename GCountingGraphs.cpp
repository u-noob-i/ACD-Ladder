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

int p[200001], sz[200001];

void dsj(int n)
{
    rep(i, 0, n - 1)
    {
        p[i] = i;
        sz[i] = 1;
    }
}

int find(int u)
{
    if (p[u] != u)
        p[u] = find(p[u]);
    return p[u];
}

ll merge(int u, int v)
{
    int x = find(u), y = find(v);
    if (x == y)
        return 0;
    ll ret = 1ll * sz[x] * sz[y] - 1;
    if (sz[x] < sz[y])
    {
        p[x] = y;
        sz[y] += sz[x];
    }
    else
    {
        p[y] = x;
        sz[x] += sz[y];
    }
    return ret;
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, s;
    cin >> n >> s;
    vvi edges(n - 1, vi(3));
    for (auto &x : edges)
        for (auto &y : x)
            cin >> y;
    sort(edges.begin(), edges.end(), [&](const vi & x, const vi & y) {
        return x[2] < y[2];
    });
    ll ans = 1;
    dsj(n);
    for (auto &x : edges)
        ans = (ans * binpow(s - x[2] + 1, merge(x[0] - 1, x[1] - 1), M)) % M;
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
