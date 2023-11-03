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
ll M = 1e9 + 7;

void solve()
{
    int n, c, x;
    cin >> n >> c;
    vi l(n), r(n), ind(n);
    vpl m(n);
    rep(i, 0, n - 1)
    {
        cin >> x;
        l[i] = x + i + 1;
        r[i] = x + n - i;
        m[i] = {min(l[i], r[i]), i};
    }
    sort(m.begin(), m.end());
    rep(i, 0, n - 1)
    {
        ind[m[i].second] = i;
        if (i)
            m[i].first += m[i - 1].first;
    }
    int ans = 0;
    rep(i, 0, n - 1)
    {
        if (l[i] > c)
            continue;
        int lo = 0, hi = n - 1, mid, v = -1, ct = 1;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (l[i] + m[mid].first <= c)
                v = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        if (v != -1)
        {
            ct += v + 1;
            if (ind[i] <= v && !(v < n - 1 && l[i] + m[v + 1].first - min(l[i], r[i]) <= c))
                ct--;
        }
        ans = max(ans, ct);
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

    int tt;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
