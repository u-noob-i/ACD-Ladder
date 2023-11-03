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

int a[300001], d[1000001];
ll st[3000001];
bool dun[3000001];

void build(int x, int l, int r)
{
    if (l > r)
    {
        st[x] = 0;
        dun[x] = 1;
    }
    else if (l == r)
    {
        st[x] = a[l];
        dun[x] = 0;
        if (st[x] == d[st[x]])
            dun[x] = 1;
    }
    else
    {
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        st[x] = st[2 * x] + st[2 * x + 1];
        dun[x] = dun[2 * x] & dun[2 * x + 1];
    }
}

void update(int x, int tl, int tr, int l, int r)
{
    if (tl > tr || tr < l || tl > r || dun[x])
        return;
    if (tl == tr)
    {
        st[x] = d[st[x]];
        if (st[x] == d[st[x]])
            dun[x] = 1;
    }
    else
    {
        int m = (tl + tr) / 2;
        update(2 * x, tl, m, l, r);
        update(2 * x + 1, m + 1, tr, l, r);
        st[x] = st[2 * x] + st[2 * x + 1];
        dun[x] = dun[2 * x] & dun[2 * x + 1];
    }
}

ll query(int x, int tl, int tr, int l, int r)
{
    if (tl > tr || tr < l || tl > r)
        return 0;
    if (tl >= l && tr <= r)
        return st[x];
    int m = (tl + tr) / 2;
    return query(2 * x, tl, m, l, r) + query(2 * x + 1, m + 1, tr, l, r);
}

void solve()
{
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= 1000000; i++)
        for (int j = i; j <= 1000000; j += i)
            d[j]++;

    int n, m;
    cin >> n >> m;
    rep(i, 0, n - 1) cin >> a[i];
    build(1, 0, n - 1);
    rep(i, 1, m)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            update(1, 0, n - 1, l - 1, r - 1);
        else
            cout << query(1, 0, n - 1, l - 1, r - 1) << "\n";
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
