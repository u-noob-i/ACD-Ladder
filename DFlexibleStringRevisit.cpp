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
ll M = 998244353;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll binpow(ll a, ll b)
{
    a %= M;
    ll ret = 1;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ret;
}
ll fracmod(ll a, ll b)
{
    ll c = gcd(a, b);
    a = a / c;
    b = b / c;
    return (a * binpow(b, M - 2)) % M;
}

void solve()
{
    int n;
    string s, p;
    cin >> n >> s >> p;
    int same = 0, dif = n;
    rep(i, 0, n - 1) if (s[i] == p[i]) same++, dif--;
    if (!dif)
    {
        cout << 0;
        return;
    }
    vector<ll> dp(dif + 1);
    dp[0] = 0;
    dp[1] = (binpow(2, n) - 1 + M) % M;
    rep(i, 1, dif - 1)
    {
        dp[i + 1] = ((n * dp[i]) % M - (i * dp[i - 1]) % M - n + M + M) % M;
        dp[i + 1] = fm(dp[i + 1], n - i);
    }
    cout << dp[dif];
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
