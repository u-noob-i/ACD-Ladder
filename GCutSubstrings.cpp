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

void solve()
{
    string s, p;
    cin >> s >> p;
    int n = s.length(), m = p.length();
    vi a;
    rep(i, 0, n - m)
    {
        bool f = 1;
        rep(j, 0, m - 1)
        {
            if (s[i + j] != p[j])
            {
                f = 0;
                break;
            }
        }
        if (f)
            a.pb(i);
    }
    if (!a.size())
    {
        cout << 0 << " " << 1;
        return;
    }
    n = a.size();
    int moves = 0;
    rep(i, 0, n - 1)
    {
        int r = a[i] + m - 1;
        while (i < n - 1 && a[i + 1] <= r)
            i++;
        r = a[i] + m - 1;
        while (i < n - 1 && a[i + 1] <= r)
            i++;
        moves++;
    }
    vvl dp(n + 1, vl(moves + 1, 0));
    dp[0][0] = 1;
    rep(i, 1, n)
    {
        ll l = i, r = i;
        while (l > 1 && a[l - 2] + m - 1 >= a[i - 1])
            l--;
        while (r < n && a[r] <= a[i - 1] + m - 1)
            r++;
        rep(j, 1, moves)
        {
            dp[i][j] = dp[i][j] + dp[l - 1][j - 1];
            if (dp[i][j] > M)
                dp[i][j] -= M;
            rep(k, i + 1, r)
            {
                dp[k][j] = dp[k][j] + dp[l - 1][j - 1];
                if (dp[k][j] > M)
                    dp[k][j] -= M;
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << moves << " " << dp[n][moves];
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
