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

int a[101][101];
int dp[101][101];

void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n) rep(j, i, n) cin >> a[i][j];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 2;
    rep(i, 1, n)
    {
        rep(j, 0, i - 1)
        {
            bool f = 1;
            rep(k, 1, i)
            {
                if ((k <= j & a[k][i] == 1) || (k > j && a[k][i] == 2))
                {
                    f = 0;
                    break;
                }
            }
            if (f)
                dp[i][j] = dp[i - 1][j];
        }
        rep(j, 0, i - 1) dp[i][i] = (dp[i][i] + dp[i][j]) % M;
    }
    cout << dp[n][n];
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
