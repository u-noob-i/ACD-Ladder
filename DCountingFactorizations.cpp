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

ll factorialNumInverse[5001];
ll naturalNumInverse[5001];
ll fact[5001];
void InverseofNumber()
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= 5000; i++)
        naturalNumInverse[i] = naturalNumInverse[M % i] * (M - M / i) % M;
}
void InverseofFactorial()
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= 5000; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % M;
}
void factorial()
{
    fact[0] = 1;
    for (int i = 1; i <= 5000; i++)
        fact[i] = (fact[i - 1] * i) % M;
}

bool isprime(int x)
{
    if (x == 1)
        return 0;
    rep(i, 2, sqrt(x)) if (x % i == 0) return 0;
    return 1;
}

void solve()
{

    InverseofNumber();
    InverseofFactorial();
    factorial();

    int n, x;
    cin >> n;
    map<int, int> a;
    rep(i, 1, 2 * n)
    {
        cin >> x;
        a[x]++;
    }
    ll ans = fact[n];
    vi p;
    for (auto &itr : a)
    {
        if (isprime(itr.first))
            p.pb(itr.second);
        else
            ans = (ans * factorialNumInverse[itr.second]) % M;
    }
    if (p.size() < n)
    {
        cout << 0;
        return;
    }
    vvl dp(p.size() + 1, vl(n + 1, 0));
    dp[0][0] = 1;
    rep(i, 1, p.size())
    {
        rep(j, 0, min(n, i))
        {
            if (p.size() - i < n - j)
                continue;
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * factorialNumInverse[p[i - 1]]) % M;
            if (j)
                dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] * factorialNumInverse[p[i - 1] - 1]) % M) % M;
        }
    }
    ans = (ans * dp[p.size()][n]) % M;
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
