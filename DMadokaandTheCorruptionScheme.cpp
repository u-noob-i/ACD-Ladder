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

ll factorialNumInverse[100001], naturalNumInverse[100001], fact[100001];
void InverseofNumber()
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= 100000; i++)
        naturalNumInverse[i] = naturalNumInverse[M % i] * (M - M / i) % M;
}
void InverseofFactorial()
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= 100000; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % M;
}
void factorial()
{
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++)
        fact[i] = (fact[i - 1] * i) % M;
}
ll Binomial(ll N, ll R)
{
    ll ans = ((fact[N] * factorialNumInverse[R]) % M * factorialNumInverse[N - R]) % M;
    return ans;
}

void solve()
{
    InverseofNumber();
    InverseofFactorial();
    factorial();

    int n, k;
    cin >> n >> k;
    ll ans = 0;
    rep(i, 0, min(n, k)) ans = (ans + Binomial(n, i)) % M;
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
