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
ll M = 1e9 + 7;

int a[100001];
int st[21][800001];
bool lazy[21][800001];

void build(int x, int node, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        if ((1 << x)&a[l])
            st[x][node] = 1;
    }
    else
    {
        int mid = (l + r) / 2;
        build(x, node * 2, l, mid);
        build(x, node * 2 + 1, mid + 1, r);
        st[x][node] = st[x][2 * node] + st[x][2 * node + 1];
    }
}

void update(int x, int node, int tl, int tr, int l, int r)
{
    if (lazy[x][node])
    {
        lazy[x][node] = 0;
        st[x][node] = tr - tl + 1 - st[x][node];
        lazy[x][2 * node] = !lazy[x][2 * node];
        lazy[x][2 * node + 1] = !lazy[x][2 * node + 1];
    }
    if (tl > tr || tr < l || tl > r)
        return;
    if (tl >= l && tr <= r)
    {
        st[x][node] = tr - tl + 1 - st[x][node];
        lazy[x][2 * node] = !lazy[x][2 * node];
        lazy[x][2 * node + 1] = !lazy[x][2 * node + 1];
    }
    else
    {
        int mid = (tl + tr) / 2;
        update(x, 2 * node, tl, mid, l, r);
        update(x, 2 * node + 1, mid + 1, tr, l, r);
        st[x][node] = st[x][2 * node] + st[x][2 * node + 1];
    }
}

int query(int x, int node, int tl, int tr, int l, int r)
{
    if (lazy[x][node])
    {
        lazy[x][node] = 0;
        st[x][node] = tr - tl + 1 - st[x][node];
        lazy[x][2 * node] = !lazy[x][2 * node];
        lazy[x][2 * node + 1] = !lazy[x][2 * node + 1];
    }
    if (tl > tr || tr < l || tl > r)
        return 0;
    if (tl >= l && tr <= r)
        return st[x][node];
    int mid = (tl + tr) / 2;
    return query(x, 2 * node, tl, mid, l, r) +
           query(x, 2 * node + 1, mid + 1, tr, l, r);
}

void solve()
{
    memset(st, 0, sizeof(st));
    memset(lazy, 0, sizeof(lazy));
    int n, m;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 0, 20) build(i, 1, 1, n);
    cin >> m;
    rep(i, 1, m)
    {
        int t, l, r, x;
        cin >> t >> l >> r;
        if (t == 1)
        {
            ll ans = 0;
            rep(j, 0, 20) ans += (1ll << j) * query(j, 1, 1, n, l, r);
            cout << ans << "\n";
        }
        else
        {
            cin >> x;
            rep(j, 0, 20) if ((1 << j)&x) update(j, 1, 1, n, l, r);
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
