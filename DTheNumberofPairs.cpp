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
#define vvvl vector<vector<vector<ll>>>
ll M = 1e18;

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

int spf[20000001];
void sievespf(int N)
{
    memset(spf, 0, sizeof(spf));
    spf[1] = 1;
    spf[2] = 2;
    for (int i = 4; i <= N; i += 2)
        spf[i] = 2;
    for (int i = 3; i <= N; i++)
    {
        if (spf[i])
            continue;
        spf[i] = i;
        for (int j = i + i; j <= N; j += i)
            if (!spf[j])
                spf[j] = i;
    }
}
ll calc(int x)
{
    int ct = 0, t;
    while (x > 1)
    {
        ct++;
        t = spf[x];
        while (x % t == 0)
            x /= t;
    }
    return exppow(2, ct);
}
void solve()
{
    int c, d, x;
    cin >> c >> d >> x;
    ll ans = 0;
    vi a;
    rep(i, 1, sqrt(x))
    {
        if (x % i)
            continue;
        a.pb(i);
        if (x / i != i)
            a.pb(x / i);
    }
    for (auto &t : a)
    {
        int p = x / t + d;
        if (p % c)
            continue;
        p /= c;
        // cout << "[" << p << " " << sum[p] << "] ";
        ans += calc(p);
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

    sievespf(20000000);

    int tt = 1;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
