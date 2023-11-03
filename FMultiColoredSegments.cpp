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
    int n;
    cin >> n;
    vi ans(n, INF);
    vvi a(n, vi(4));
    rep(i, 0, n - 1)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][3] = i;
    }
    sort(a.begin(), a.end(), [&](const vi & x, const vi & y) {
        if (x[0] == y[0])
            return x[1] > y[1];
        return x[0] < y[0];
    });
    int c1 = -1, m1 = -1, c2 = -1, m2 = -1;
    map<int, vvi> m;
    rep(i, 0, n - 1)
    {
        int l = a[i][0], r = a[i][1], c = a[i][2], ind = a[i][3];
        // cout << c1 << " " << m1 << ", " << c2 << " " << m2 << " : ";
        // cout << l << " " << r << "\n";
        if (c1 != -1 && c1 != c)
            ans[ind] = min(ans[ind], max(0, l - m1));
        else if (c2 != -1 && c2 != c)
            ans[ind] = min(ans[ind], max(0, l - m2));
        m[c].pb({l, r, ind});
        auto itr = m.begin();
        while (itr != m.end())
        {
            if (itr->first == c)
            {
                itr++;
                continue;
            }
            vvi t = itr->second;
            for (auto &x : t)
                ans[x[2]] = min(ans[x[2]], max(0, l - x[1]));
            auto jtr = itr;
            itr++;
            m.erase(jtr->first);
        }
        if (c1 == -1)
        {
            c1 = c;
            m1 = r;
        }
        else if (c1 == c)
        {
            m1 = max(m1, r);
        }
        else if (c2 == -1)
        {
            c2 = c;
            m2 = r;
        }
        else if (c2 == c)
        {
            m2 = max(m2, r);
        }
        else if (r > m2)
        {
            c2 = c;
            m2 = r;
        }
        if (m2 > m1)
        {
            swap(c1, c2);
            swap(m1, m2);
        }
    }
    m.clear();
    sort(a.begin(), a.end(), [&](const vi & x, const vi & y) {
        if (x[1] == y[1])
            return x[0] < y[0];
        return x[1] > y[1];
    });
    c1 = c2 = m1 = m2 = -1;
    rep(i, 0, n - 1)
    {
        int l = a[i][0], r = a[i][1], c = a[i][2], ind = a[i][3];
        if (c1 != -1 && c != c1)
            ans[ind] = min(ans[ind], max(0, m1 - r));
        else if (c2 != -1 && c != c2)
            ans[ind] = min(ans[ind], max(0, m2 - r));
        m[c].pb({l, r, ind});
        auto itr = m.begin();
        while (itr != m.end())
        {
            if (itr->first == c)
            {
                itr++;
                continue;
            }
            vvi t = itr->second;
            for (auto &x : t)
                ans[x[2]] = min(ans[x[2]], max(0, x[0] - r));
            auto jtr = itr;
            itr++;
            m.erase(jtr->first);
        }
        if (c1 == -1)
        {
            c1 = c;
            m1 = l;
        }
        else if (c1 == c)
        {
            m1 = min(m1, l);
        }
        else if (c2 == -1)
        {
            c2 = c;
            m2 = l;
        }
        else if (c2 == c)
        {
            m2 = min(m2, l);
        }
        else if (l < m2)
        {
            c2 = c;
            m2 = l;
        }
        if (m2 < m1)
        {
            swap(c1, c2);
            swap(m1, m2);
        }
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
