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
ll M = 1e9 + 7;

ll a[101], dp[101][101], ni[101], nni[101], fact[101];
void InverseofNumber()
{
    nni[0] = nni[1] = 1;
    for (int i = 2; i <= 100; i++)
        nni[i] = nni[M % i] * (M - M / i) % M;
}
void InverseofFactorial()
{
    ni[0] = ni[1] = 1;
    for (int i = 2; i <= 100; i++)
        ni[i] = (nni[i] * ni[i - 1]) % M;
}
void factorial()
{
    fact[0] = 1;
    for (int i = 1; i <= 100; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
}
ll ncr(ll N, ll R)
{
    ll ans = ((fact[N] * ni[R]) % M * ni[N - R]) % M;
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep(i, 1, n)
    {
        rep(j, 1, i)
        {
            int ct = 1;
            irep(p, i - 1, 0)
            {
                if (ct >= k)
                    dp[i][j] = (dp[i][j] + (dp[p][j - 1] * ncr(ct - 1, k - 1)) % M) % M;
                if (a[p] == a[i])
                    ct++;
            }
        }
    }
    int ans = 0;
    irep(i, n, 0)
    {
        rep(j, 0, n) ans = (ans + dp[j][i]) % M;
        if (ans)
            break;
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

    InverseofNumber();
    InverseofFactorial();
    factorial();

    int tt = 1;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
