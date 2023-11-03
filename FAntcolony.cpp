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
ll M = 1e9 + 7;

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

int a[100001];
int st[1000001][2];
void build(int x, int l, int r)
{
    if (l == r)
    {
        st[x][0] = a[l];
        st[x][1] = 1;
    }
    else
    {
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        st[x][0] = gcd(st[2 * x][0], st[2 * x + 1][0]);
        st[x][1] = 0;
        if (st[x][0] == st[2 * x][0])
            st[x][1] += st[2 * x][1];
        if (st[x][0] == st[2 * x + 1][0])
            st[x][1] += st[2 * x + 1][1];
    }
}
pi query(int x, int tl, int tr, int l, int r)
{
    if (tl >= l && tr <= r)
        return {st[x][0], st[x][1]};
    int m = (tl + tr) / 2;
    pi ret;
    if (l <= m && r > m)
    {
        pi u = query(2 * x, tl, m, l, r), v = query(2 * x + 1, m + 1, tr, l, r);
        ret.first = gcd(u.first, v.first);
        ret.second = 0;
        if (ret.first == u.first)
            ret.second += u.second;
        if (ret.first == v.first)
            ret.second += v.second;
    }
    else if (l <= m)
        ret = query(2 * x, tl, m, l, r);
    else
        ret = query(2 * x + 1, m + 1, tr, l, r);
    return ret;
}

void solve()
{
    int n, q;
    cin >> n;
    rep(i, 0, n - 1) cin >> a[i];
    build(1, 0, n - 1);
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << r - l + 1 - query(1, 0, n - 1, l - 1, r - 1).second << "\n";
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
