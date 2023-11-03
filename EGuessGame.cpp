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

vvi t;

ll binpow(ll a, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1ll) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        n >>= 1;
    }
    return ans;
}
ll getm(ll a, ll b)
{
    return ((a * binpow(b, M - 2) % M) * binpow(b, M - 2)) % M;
}

void ins(int x)
{
    int cur = 0;
    irep(i, 29, 0)
    {
        t[cur][0]++;
        if ((1 << i)&x)
        {
            if (t[cur][1] == -1)
            {
                t[cur][1] = t.size();
                t.pb({0, -1, -1});
            }
            cur = t[cur][1];
        }
        else
        {
            if (t[cur][2] == -1)
            {
                t[cur][2] = t.size();
                t.pb({0, -1, -1});
            }
            cur = t[cur][2];
        }
    }
    t[cur][0]++;
}

void dfs(int x, int l, ll &a)
{
    if (t[x][1] == -1 && t[x][2] == -1)
        a = (a + (1ll * (l + 1) * t[x][0] * t[x][0]) % M) % M;
    if (t[x][1] != -1 && t[x][2] != -1)
    {
        a = (a + (1ll * (l + 1) * t[t[x][1]][0] * t[t[x][2]][0]) % M) % M;
        a = (a + (1ll * (l + 2) * t[t[x][1]][0] * t[t[x][2]][0]) % M) % M;
    }
    if (t[x][1] != -1)
        dfs(t[x][1], l + 1, a);
    if (t[x][2] != -1)
        dfs(t[x][2], l, a);
}

void solve()
{
    t.clear();
    int n, x;
    cin >> n;
    t.pb({0, -1, -1});
    rep(i, 1, n)
    {
        cin >> x;
        ins(x);
    }
    ll a = 0;
    dfs(0, 0, a);
    cout << getm(a, n);
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
