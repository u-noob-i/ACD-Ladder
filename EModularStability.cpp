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

ll factorialNumInverse[500001];
ll naturalNumInverse[500001];
ll fact[500001];
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= 500000; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= 500000; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= 500000; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll Binomial(ll N, ll R, ll p)
{
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

void solve()
{
    InverseofNumber(M);
    InverseofFactorial(M);
    factorial(M);

    int n, k;
    cin >> n >> k;
    int ans = 0;
    rep(i, 1, n)
    {
        int x = n / i;
        if (x < k)
            break;
        ans = (ans + Binomial(x - 1, k - 1, M)) % M;
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
