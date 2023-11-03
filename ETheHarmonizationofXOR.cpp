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

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vvi ans;
    vi t;
    vb a(n + 1, 0);
    rep(i, 1, n)
    {
        if (ans.size() == k - 1)
            break;
        if (a[i])
            continue;
        if (i == x)
        {
            a[i] = 1;
            ans.pb({x});
        }
        else
        {
            int y = i ^ x;
            if (y <= n && !a[y])
            {
                a[y] = a[i] = 1;
                ans.pb({i, y});
            }
        }
    }
    ans.pb({});
    int y = 0;
    rep(i, 1, n)
    {
        if (!a[i])
        {
            y ^= i;
            ans[ans.size() - 1].pb(i);
        }
    }
    if (ans.size() == k && y == x)
    {
        cout << "YES";
        for (auto &i : ans)
        {
            cout << "\n" << i.size() << " ";
            for (auto &j : i)
                cout << j << " ";
        }
    }
    else
        cout << "NO";
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
