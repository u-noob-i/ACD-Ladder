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

void solve()
{
    int n, x;
    cin >> n;
    vi ans(n);
    vvi r(n, vi(3));
    rep(i, 1, n)
    {
        cin >> x;
        r[i - 1][2] = i - 1;
        r[i - 1][0] = i / (x + 1) + 1;
        if (!x)
            r[i - 1][1] = n;
        else
            r[i - 1][1] = i / x;
        // cout << r[i - 1][0] << " " << r[i - 1][1] << "\n";
    }
    sort(r.begin(), r.end(), [&](const vi & x, const vi & y) {
        return x[0] < y[0];
    });
    priority_queue<pi, vpi, greater<pi>> pq;
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < n && r[j][0] == i)
        {
            pq.push({r[j][1], r[j][2]});
            j++;
        }
        ans[pq.top().second] = i;
        pq.pop();
    }
    for (auto &x : ans)
        cout << x << " ";
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
