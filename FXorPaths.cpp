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

ll a[21][21];
map<ll, ll> dp1[21][21], dp2[21][21];

void solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> a[i][j];
    if (n == 1 && m == 1)
    {
        cout << (a[0][0] == k);
        return;
    }
    dp1[0][0][a[0][0]] = 1;
    int x = (n + m - 1) / 2, y = n + m - 1 - x;
    rep(i, 0, n - 1)
    {
        rep(j, 0, m - 1)
        {
            if (i + j + 1 > x)
                break;
            for (auto &itr : dp1[i][j])
            {
                if (i < n - 1)
                    dp1[i + 1][j][a[i + 1][j]^itr.first] += itr.second;
                if (j < m - 1)
                    dp1[i][j + 1][a[i][j + 1]^itr.first] += itr.second;
            }
        }
    }
    dp2[n - 1][m - 1][a[n - 1][m - 1]] = 1;
    irep(i, n - 1, 0)
    {
        irep(j, m - 1, 0)
        {
            if (n - i + m - j - 1 > y)
                break;
            for (auto &itr : dp2[i][j])
            {
                if (i)
                    dp2[i - 1][j][a[i - 1][j]^itr.first] += itr.second;
                if (j)
                    dp2[i][j - 1][a[i][j - 1]^itr.first] += itr.second;
            }
        }
    }
    ll ans = 0;
    rep(i, 0, n - 1)
    {
        int j = x - i - 1;
        if (j >= 0 && j < m)
        {
            for (auto &itr : dp1[i][j])
            {
                ll t = itr.first ^ k;
                if (i + 1 < n && dp2[i + 1][j].find(t) != dp2[i + 1][j].end())
                    ans += itr.second * dp2[i + 1][j][t];
                if (j + 1 < m && dp2[i][j + 1].find(t) != dp2[i][j + 1].end())
                    ans += itr.second * dp2[i][j + 1][t];
            }
        }
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
