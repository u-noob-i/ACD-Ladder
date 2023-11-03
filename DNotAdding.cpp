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

int gcd(int x, int y)
{
    if (!y)
        return x;
    return gcd(y, x % y);
}

void solve()
{
    int n;
    cin >> n;
    vb a(1000001, 0);
    rep(i, 1, n)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= 1000000; i++)
    {
        if (a[i])
            continue;
        int g = -1;
        for (int j = i + i; j <= 1000000; j += i)
        {
            if (!a[j])
                continue;
            if (g == -1)
                g = j;
            else
                g = gcd(g, j);
        }
        if (g == i)
            ans++;
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
