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

void solve()
{
    int q, t;
    ll a, b, n, x, l = -1, r;
    cin >> q;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b >> n;
            ll tl = (a - b) * (n - 1) + 1, tr = a + (a - b) * (n - 1);
            if (n > 1)
                tl = max(tl, a + (a - b) * (n - 2) + 1);
            if (l == -1)
            {
                l = tl;
                r = tr;
            }
            if (tl > r || tr < l)
                cout << 0 << " ";
            else
            {
                cout << 1 << " ";
                l = max(l, tl);
                r = min(r, tr);
            }
        }
        else
        {
            cin >> a >> b;
            if (l == -1)
                cout << -1 << " ";
            else if (a >= l && a >= r)
                cout << 1 << " ";
            else if (a >= l)
                cout << -1 << " ";
            else if ((l - b - 1) / (a - b) == (r - b - 1) / (a - b))
                cout << (l - b - 1) / (a - b) + 1 << " ";
            else
                cout << -1 << " ";
        }
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

    int tt;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
