#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 2e18
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

int a[300001], c[300001], h[300001];
ll st[4000001], lazy[4000001];

void build(int x, int l, int r)
{
    if (l > r)
        return;
    st[x] = INF;
    lazy[x] = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
    }
}
void pushdown(int x)
{
    if (!lazy[x])
        return;
    st[x] += lazy[x];
    lazy[2 * x] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
    lazy[x] = 0;
}
void pushup(int x)
{
    st[x] = min(st[2 * x], st[2 * x + 1]);
}
void update(int x, int tl, int tr, int l, int r, ll v)
{
    pushdown(x);
    if (tl > r || tr < l)
        return;
    if (tl >= l && tr <= r)
    {
        lazy[x] += v;
        pushdown(x);
    }
    else
    {
        int m = (tl + tr) / 2;
        update(2 * x, tl, m, l, r, v);
        update(2 * x + 1, m + 1, tr, l, r, v);
        pushup(x);
    }
}

ll query(int x, int tl, int tr, int t)
{
    pushdown(x);
    if (tl == tr)
        return st[x];
    int m = (tl + tr) / 2;
    if (t <= m)
        return query(2 * x, tl, m, t);
    else
        return query(2 * x + 1, m + 1, tr, t);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, k) cin >> c[i];
    rep(i, 1, k) cin >> h[i];
    build(1, 0, k);
    update(1, 0, k, 0, 0, c[a[1]] - INF);
    rep(i, 2, n)
    {
        ll hot = h[a[i]], cold = c[a[i]];
        ll v = min(st[1] + cold, query(1, 0, k, a[i]) + hot);
        if (a[i - 1] == a[i])
            update(1, 0, k, 0, k, hot);
        else
            update(1, 0, k, 0, k, cold);
        ll x = query(1, 0, k, a[i - 1]);
        if (v < x)
            update(1, 0, k, a[i - 1], a[i - 1], v - x);
    }
    cout << st[1];
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
