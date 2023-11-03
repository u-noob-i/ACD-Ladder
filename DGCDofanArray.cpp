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

int a[200001], spf[200001];
map<int, int> st[1000001];

void build(int x, int l, int r)
{
    st[x].clear();
    if (l > r)
        return;
    if (l == r)
    {
        int v = a[l];
        while (v > 1)
        {
            st[x][spf[v]]++;
            v /= spf[v];
        }
    }
    else
    {
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        for (auto &itr : st[2 * x])
            if (st[2 * x + 1].find(itr.first) != st[2 * x + 1].end())
                st[x][itr.first] = min(itr.second, st[2 * x + 1][itr.first]);
    }
}

map<int, int> update(int x, int tl, int tr, int t, int v)
{
    map<int, int> ct;
    if (tl == tr)
    {
        while (v > 1)
        {
            st[x][spf[v]]++;
            ct[spf[v]]++;
            v /= spf[v];
        }
        return ct;
    }
    int m = (tl + tr) / 2;
    if (t <= m)
        ct = update(2 * x, tl, m, t, v);
    else
        ct = update(2 * x + 1, m + 1, tr, t, v);
    for (auto itr = ct.begin(); itr != ct.end();)
    {
        int val = itr->first, count = itr->second;
        if (st[2 * x].find(val) == st[2 * x].end() ||
                st[2 * x + 1].find(val) == st[2 * x + 1].end())
        {
            auto jtr = itr;
            jtr++;
            ct.erase(val);
            itr = jtr;
        }
        else
        {
            int change = min(st[2 * x][val], st[2 * x + 1][val]) - st[x][val];
            if (change > 0)
            {
                st[x][val] += change;
                ct[val] = change;
                itr++;
            }
            else
            {
                auto jtr = itr;
                jtr++;
                ct.erase(val);
                itr = jtr;
            }
        }
    }
    return ct;
}

void solve()
{

    memset(spf, 0, sizeof(spf));
    spf[1] = 1;
    for (int i = 2; i <= 200000; i += 2)
        spf[i] = 2;
    for (int i = 3; i <= 200000; i += 2)
        if (!spf[i])
            for (int j = i; j <= 200000; j += i)
                if (!spf[j])
                    spf[j] = i;

    int n, q;
    cin >> n >> q;
    rep(i, 0, n - 1) cin >> a[i];
    build(1, 0, n - 1);
    ll ans = 1;
    for (auto &itr : st[1])
        ans = (ans * exppow(itr.first, itr.second)) % M;
    while (q--)
    {
        int i, x;
        cin >> i >> x;
        map<int, int> t = update(1, 0, n - 1, i - 1, x);
        for (auto &itr : t)
            ans = (ans * exppow(itr.first, itr.second)) % M;
        cout << ans << "\n";
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
