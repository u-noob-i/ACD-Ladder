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

vvi a;
int st[5000001], lazy[5000001];

void pushdown(int x)
{
    if (!lazy[x])
        return;
    st[x] += lazy[x];
    lazy[2 * x] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
    lazy[x] = 0;
}

void update(int x, int tl, int tr, int l, int r, int v)
{
    pushdown(x);
    if (tr < l || tl > r)
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
        st[x] = min(st[2 * x], st[2 * x + 1]);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(n, vi(3));
    rep(i, 0, n - 1) rep(j, 0, 2) cin >> a[i][j];
    sort(a.begin(), a.end(), [&](const vi & x, const  vi & y) {
        return x[2] < y[2];
    });
    memset(st, 0, sizeof(st));
    memset(lazy, 0, sizeof(lazy));
    int ans = a[n - 1][2] - a[0][2];
    for (int i = 0, j = 0; i < n; i++)
    {
        if (i)
            update(1, 1, m - 1, a[i - 1][0], a[i - 1][1] - 1, -1);
        j = max(j, i);
        while (j < n && !st[1])
        {
            update(1, 1, m - 1, a[j][0], a[j][1] - 1, 1);
            j++;
        }
        if (st[1])
            ans = min(ans, a[j - 1][2] - a[i][2]);
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
    // cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
