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

struct cmp1 {
    bool operator()(const pl &x, const pl &y)
    {
        if (x.second == y.second)
            return x.first > y.first;
        return x.second > y.second;
    }
};
struct cmp2 {
    bool operator()(const pl &x, const pl &y)
    {
        if (x.first == y.first)
            return x.second > y.second;
        return x.first > y.first;
    }
};

void solve()
{
    int n;
    cin >> n;
    multiset<pl, cmp1> a, c;
    multiset<pl, cmp2> b, d;
    set<pl> ans;
    ll area = 0, x, y, w, h, t1, t2;
    rep(i, 1, n)
    {
        cin >> x >> y;
        area += x * y;
        a.insert({x, y});
        b.insert({x, y});
        c.insert({x, y});
        d.insert({x, y});
    }
    y = h = a.begin()->second;
    if (area % h == 0)
    {
        w = x = area / h;
        rep(i, 0, n - 2)
        {
            if (a.begin()->second == y)
            {
                t1 = a.begin()->first, t2 = a.begin()->second;
                x -= t1;
            }
            else
            {
                t1 = b.begin()->first, t2 = b.begin()->second;
                y -= t2;
            }
            a.erase(a.find({t1, t2}));
            b.erase(b.find({t1, t2}));
        }
        if (a.begin()->first == x && a.begin()->second == y)
            ans.insert({w, h});
    }

    x = w = d.begin()->first;
    if (area % w == 0)
    {
        y = h = area / w;
        rep(i, 0, n - 2)
        {
            if (d.begin()->first == x)
            {
                t1 = d.begin()->first, t2 = d.begin()->second;
                y -= t2;
            }
            else
            {
                t1 = c.begin()->first, t2 = c.begin()->second;
                x -= t1;
            }
            c.erase(c.find({t1, t2}));
            d.erase(d.find({t1, t2}));
        }
        if (c.begin()->first == x && c.begin()->second == y)
            ans.insert({w, h});
    }

    cout << ans.size();
    for (auto &itr : ans)
        cout << "\n" << itr.first << " " << itr.second;
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
