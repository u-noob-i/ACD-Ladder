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

int n, m;
int a[300001][8], mask[300001], t[256];

pi pos(int x)
{
    memset(mask, 0, sizeof(mask));
    memset(t, -1, sizeof(t));
    rep(i, 0, n - 1) rep(j, 0, m - 1) if (a[i][j] >= x) mask[i] |= (1 << j);
    rep(i, 0, n - 1) t[mask[i]] = i;
    rep(i, 0, n - 1)
    {
        rep(j, 0, (1 << m) - 1)
        {
            if (t[j] != -1 && (mask[i] | j) == (1 << m) - 1)
            {
                return{i + 1, t[j] + 1};
            }
        }
    }
    return { -1, -1};
}

void solve()
{
    cin >> n >> m;
    rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> a[i][j];
    int l = 0, r = 1e9, mid, x, y;
    while (l <= r)
    {
        mid = (l + r) / 2;
        pi t = pos(mid);
        if (t.first != -1)
        {
            x = t.first, y = t.second;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << x << " " << y;
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
