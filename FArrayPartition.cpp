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
#define vvb vector<vector<bool>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
ll M = 1e9 + 7;

//----------------------Template-----------------------//
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
struct DisjSet {
    int n;
    vi p, sz;
    DisjSet() {}
    DisjSet(int N)
    {
        n = N;
        p.resize(n);
        sz.assign(n, 1);
        rep(i, 0, n - 1) p[i] = i;
    }
    int find(int u)
    {
        if (p[u] != u)
            p[u] = find(p[u]);
        return p[u];
    }
    bool issame(int u, int v) { return find(u) == find(v); }
    void merge(int u, int v)
    {
        int x = find(u), y = find(v);
        if (x == y)
            return;
        if (sz[x] > sz[y])
            p[y] = x, sz[x] += sz[y];
        else
            p[x] = y, sz[y] += sz[x];
        return;
    }
};
struct SegTree {
    int n;
    vi st, lazy;
    SegTree() {}
    SegTree(int N)
    {
        n = N;
        st.assign(8 * n, 0);
        lazy.assign(8 * n, 0);
    }
    SegTree(vi &a)
    {
        n = a.size();
        st.resize(8 * n);
        lazy.resize(8 * n);
        build(1, 0, n - 1, a);
    }
    int lc(int x) { return 2 * x; }
    int rc(int x) { return 2 * x + 1; }
    void build(int x, int l, int r, vi &a)
    {
        if (l > r)
            return;
        if (l == r)
            st[x] = a[l], lazy[x] = 0;
        else
        {
            int m = (l + r) / 2;
            build(lc(x), l, m, a);
            build(rc(x), m + 1, r, a);
            st[x] = min(st[lc(x)], st[rc(x)]), lazy[x] = 0;
        }

    }
    void pushdown(int x)
    {
        if (!lazy[x])
            return;
        st[lc(x)] += lazy[x];
        lazy[lc(x)] += lazy[x];
        st[rc(x)] += lazy[x];
        lazy[rc(x)] += lazy[x];
        lazy[x] = 0;
    }
    void pushup(int x) { st[x] = st[lc(x)] + st[rc(x)]; }
    void update(int x, int tl, int tr, int l, int r, int v)
    {
        pushdown(x);
        if (tl > tr || tl > r || tr < l)
            return;
        if (tl >= l && tr <= r)
        {
            st[x] += v, lazy[x] += v;
            pushdown(x);
        }
        else
        {
            int m = (tl + tr) / 2;
            update(lc(x), tl, m, l, r, v);
            update(rc(x), m + 1, tr, l, r, v);
            pushup(x);
        }
    }
    int query(int x, int tl, int tr, int l, int r)
    {
        pushdown(x);
        if (tl > tr || tl > r || tr < l)
            return INF;
        if (tl >= l && tr <= r)
            return st[x];
        int m = (tl + tr) / 2;
        return min(query(lc(x), tl, m, l, r), query(rc(x), m + 1, tr, l, r));
    }
    void update(int l, int r, int v) { update(1, 0, n - 1, l, r, v); }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
struct BIT {
    int n;
    vi bit;
    BIT() {}
    BIT(int N)
    {
        n = N + 1;
        bit.assign(n, 0);
    }
    BIT(vi &arr)
    {
        n = arr.size() + 1;
        bit.assign(n, 0);
        rep(i, 0, arr.size() - 1) add(i + 1, arr[i]);
    }
    void add(int i, int v)
    {
        i++;
        while (i < n)
        {
            bit[i] += v;
            i += i & -i;
        }
    }
    int sum(int i)
    {
        i++;
        int ret = 0;
        while (i > 0)
        {
            ret += bit[i];
            i -= i & -i;
        }
        return ret;
    }
    int sum(int l, int r) { return sum(r) - sum(l - 1); }
};

//--------------------Template-------------------------//

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    vi nxt(n, n), prv(n, -1), pref(n, -1), suf(n, -1);
    stack<int> s;
    s.push(0);
    rep(i, 1, n - 1)
    {
        while (s.size() && a[s.top()] > a[i])
            nxt[s.top()] = i, s.pop();
        s.push(i);
    }
    while (s.size())
        s.pop();
    s.push(n - 1);
    irep(i, n - 2, 0)
    {
        while (s.size() && a[s.top()] > a[i])
            prv[s.top()] = i, s.pop();
        s.push(i);
    }
    map<int, int> p;
    int cur = a[0];
    p[cur] = 0;
    rep(i, 1, n - 2)
    {
        if (p.find(a[i]) != p.end() && p[a[i]] >= prv[i])
            pref[i] = p[a[i]] + 1;
        cur = max(cur, a[i]);
        p[cur] = i;
    }
    p.clear();
    cur = a[n - 1];
    p[cur] = n - 1;
    irep(i, n - 2, 1)
    {
        if (p.find(a[i]) != p.end() && p[a[i]] <= nxt[i])
            suf[i] = n - p[a[i]];
        cur = max(cur, a[i]);
        p[cur] = i;
    }
    rep(i, 1, n - 2)
    {
        if (pref[i] != -1 && suf[i] != -1)
        {
            cout << "YES\n" <<
                 pref[i] << " " << n - pref[i] - suf[i] << " " << suf[i];
            return;
        }
    }
    cout << "NO";
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
