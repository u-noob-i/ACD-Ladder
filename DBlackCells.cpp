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
    int n, k;
    cin >> n >> k;
    vpl a(n);
    rep(i, 0, n - 1) cin >> a[i].first;
    rep(i, 0, n - 1) cin >> a[i].second;
    ll ans = INF, ct = 0;
    priority_queue<ll, vl, greater<ll>> pq;
    for (auto &x : a)
    {
        ll t = x.second - x.first + 1;
        // cout << ct << " " << t << "\n";
        if (t + ct < k)
        {
            ct += t;
            pq.push(t);
            continue;
        }
        ans = min(ans, x.second - (t + ct - k) + 2 * (pq.size() + 1));
        if (!pq.size())
        {
            ct += t;
            pq.push(t);
            continue;
        }
        if (ct >= k && t < pq.top())
            continue;
        if (ct + t >= k)
        {
            while (pq.size() && ct + t - pq.top() >= k)
            {
                ct -= pq.top();
                pq.pop();
                ans = min(ans, x.second - ct - t + k + 2 * (pq.size() + 1));
            }
            ct += t;
            pq.push(t);
            ans = min(ans, x.second - ct + k + 2 * pq.size());
            continue;
        }
        while (pq.size() && ct - pq.top() >= k)
            ct -= pq.top(), pq.pop();
    }
    if (ans == INF)
        ans = -1;
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
