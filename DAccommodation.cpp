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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    rep(i, 1, n)
    {
        cin >> a[i];
        a[i] = "#" + a[i];
    }
    int mm = 0, mx = 0;
    rep(i, 1, n)
    {
        int x = 0, y = 0, ct = 0;
        rep(j, 1, m) if (a[i][j] == '1') ct++;
        rep(j, 1, m)
        {
            if (a[i][j] == '1' && a[i][j + 1] == '1')
            {
                j++;
                x++;
            }
        }
        rep(j, 1, m - 1)
        {
            if (a[i][j] != '1' || a[i][j + 1] != '1')
            {
                j++;
                y++;
            }
        }
        mm += ct - min(m / 4, x);
        mx += ct - max(0, m / 4 - y);
    }
    cout << mm << " " << mx;
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
