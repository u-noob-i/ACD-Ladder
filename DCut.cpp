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

int spf[100001], a[100001], nxt[100001][25];
bool pp[100001];

void sieve(int N)
{
    memset(spf, -1, sizeof(spf));
    spf[1] = 1;
    spf[2] = 2;
    for (int i = 4; i <= N; i += 2)
        spf[i] = 2;
    for (int i = 3; i <= N; i++)
    {
        if (spf[i] != -1)
            continue;
        spf[i] = i;
        for (int j = i + i; j <= N; j += i)
            if (spf[j] == -1)
                spf[j] = i;
    }
}

void solve()
{

    sieve(100000);

    int n, q;
    cin >> n >> q;
    rep(i, 0, n - 1) cin >> a[i];
    memset(pp, 0, sizeof(pp));
    rep(i, 0, n - 1)
    {
        if (!i)
            nxt[i][0] = -1;
        else
            nxt[i][0] = nxt[i - 1][0];
        while (nxt[i][0] < n - 1)
        {
            bool f = 1;
            int x = a[nxt[i][0] + 1];
            vi y;
            while (x > 1)
            {
                int t = spf[x];
                if (pp[t])
                {
                    f = 0;
                    break;
                }
                y.pb(t);
                while (x % t == 0)
                    x /= t;
            }
            if (f)
            {
                for (auto &x : y)
                    pp[x] = 1;
                nxt[i][0]++;
            }
            else
                break;
        }
        int x = a[i];
        while (x > 1)
        {
            pp[spf[x]] = 0;
            x /= spf[x];
        }
    }
    rep(i, 1, 24) rep(j, 0, n - 1)
    {
        if (nxt[j][i - 1] == n - 1)
            nxt[j][i] = n - 1;
        else
            nxt[j][i] = nxt[nxt[j][i - 1] + 1][i - 1];
    }

    rep(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 1;
        irep(i, 24, 0)
        {
            if (nxt[l][i] < r)
            {
                ans += 1 << i;
                l = nxt[l][i] + 1;
            }
        }
        cout << ans << "\n";
    }
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
