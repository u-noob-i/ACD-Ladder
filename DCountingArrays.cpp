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

int spf[300001];

void sieve()
{
    rep(i, 0, 300000) spf[i] = i;
    for (int i = 4; i <= 300000; i += 2)
        spf[i] = 2;
    for (int i = 3; i <= 300000; i += 2)
        if (spf[i] == i)
            for (int j = i + i; j <= 300000; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

void solve()
{
    sieve();
    ll n, m;
    cin >> n >> m;
    ll ans = 0, cur = 1, ct = 1, t;
    rep(i, 1, n)
    {
        if (spf[i] == i)
            cur *= 1ll * i;
        t = (m / cur) % M;
        ct = (ct * t) % M;
        ans = (ans + ct) % M;
        if (!ct)
            break;
    }
    m %= M;
    t = cur = m;
    rep(i, 2, n)
    {
        cur = (cur * m) % M;
        t = (t + cur) % M;
    }
    cout << ((t - ans) % M + M) % M;
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
