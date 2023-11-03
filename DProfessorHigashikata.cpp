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

int st[800001];
string p;

void build(int x, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
        st[x] = p[l] - '0';
    else
    {
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        st[x] = st[2 * x] + st[2 * x + 1];
    }
}

void upd(int x, int tl, int tr, int i)
{
    if (tr < i || tl > i)
        return;
    if (tl == tr)
        st[x] = 1 - st[x];
    else
    {
        int m = (tl + tr) / 2;
        if (i <= m)
            upd(2 * x, tl, m, i);
        else
            upd(2 * x + 1, m + 1, tr, i);
        st[x] = st[2 * x] + st[2 * x + 1];
    }
}

int query(int x, int tl, int tr, int l, int r)
{
    if (tl >= l && tr <= r)
        return st[x];
    if (tr < l || tl > r)
        return 0;
    int m = (tl + tr) / 2;
    return query(2 * x, tl, m, l, r) + query(2 * x + 1, m + 1, tr, l, r);
}

void solve()
{
    memset(st, 0, sizeof(st));
    int n, m, q;
    string s;
    cin >> n >> m >> q >> s;
    set<int> arr;
    map<int, int> ind;
    int o = 0;
    rep(i, 0, n - 1)
    {
        arr.insert(i);
        o += s[i] - '0';
    }
    p = "";
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        auto itr = arr.lower_bound(l);
        while (itr != arr.end() && *itr <= r)
        {
            p += s[*itr];
            ind[*itr] = p.length() - 1;
            auto jtr = itr;
            jtr++;
            arr.erase(*itr);
            itr = jtr;
        }
    }
    m = p.length();
    build(1, 0, m - 1);
    while (q--)
    {
        int x;
        cin >> x;
        x--;
        s[x] = '0' + 1 - s[x] + '0';
        if (s[x] == '1')
            o++;
        else
            o--;
        if (ind.find(x) != ind.end())
        {
            upd(1, 0, m - 1, ind[x]);
            p[ind[x]] = '0' + 1 - p[ind[x]] + '0';
        }
        cout << min(o, m) - query(1, 0, m - 1, 0, min(o, m) - 1) << "\n";
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

    int tt;
    tt = 1;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
