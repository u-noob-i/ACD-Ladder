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
    int n, x, y, z, a = 1, b = 2, c = 3;
    cin >> n >> x >> y >> z;
    if (x == y && y == z && x % 2)
    {
        cout << "NO";
        return;
    }
    if (y >= x && y >= z)
    {
        swap(y, x);
        swap(b, a);
        swap(z, y);
        swap(c, b);
    }
    else if (z >= x && z >= y)
    {
        swap(x, z);
        swap(a, c);
        swap(y, z);
        swap(b, c);
    }
    vb v(3 * n + 1, 0);
    v[a] = 1;
    vvi edge;
    vi d(3 * n + 1, -1);
    d[a] = 0;
    if (x == y && y == z)
    {
        int last = a, i = 1, j = 4, mid;
        while (i < x)
        {
            v[j] = 1;
            d[j] = i;
            if (i == x / 2)
                mid = j;
            edge.pb({last, j});
            last = j;
            i++, j++;
        }
        v[b] = 1;
        d[b] = i;
        edge.pb({last, b});
        last = mid;
        i = d[last] + 1;
        while (i < x)
        {
            v[j] = 1;
            d[j] = i;
            edge.pb({last, j});
            last = j;
            i++, j++;
        }
        v[c] = 1;
        d[c] = i;
        edge.pb({last, c});
    }
    else if (x == y + z)
    {
        int last = a, i = 1, j = 4;
        while (i < z)
        {
            v[j] = 1;
            d[j] = i;
            edge.pb({last, j});
            last = j;
            i++, j++;
        }
        v[c] = 1;
        d[c] = i;
        edge.pb({last, c});
        last = c;
        i++;
        while (i < x)
        {
            v[j] = 1;
            d[j] = i;
            edge.pb({last, j});
            last = j;
            i++, j++;
        }
        v[b] = 1;
        d[b] = i;
        edge.pb({last, b});
    }
    else if ((x + z - y) % 2 == 0)
    {
        int p = (x + z - y) / 2, q = x - p, r = y - q, last = a, i = 1, j = 4;
        while (i <= p)
        {
            v[j] = 1;
            d[j] = i;
            edge.pb({last, j});
            last = j;
            i++, j++;
        }
        int mid = last;
        while (i < x)
        {
            v[j] = 1;
            d[j] = 1;
            edge.pb({last, j});
            last = j;
            i++, j++;
        }
        v[b] = 1;
        d[b] = i;
        edge.pb({last, b});
        last = mid;
        i = d[last] + 1;
        while (i < z)
        {
            v[j] = 1;
            d[j] = 1;
            edge.pb({last, j});
            last = j;
            j++, i++;
        }
        v[c] = 1;
        d[c] = i;
        edge.pb({last, c});
    }
    int ct = v[1] + v[2] + v[3];
    rep(i, 4, n)
    {
        if (!v[i])
            edge.pb({1, i});
        ct++;
    }
    if (ct < n || v[n + 1] || d[b] != x || d[c] != z)
    {
        cout << "NO";
        return;
    }
    cout << "YES";
    for (auto &x : edge)
        cout << "\n" << x[0] << " " << x[1];
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
