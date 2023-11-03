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
    int n, x;
    cin >> n;
    cout << "+ " << n << "\n";
    cout.flush();
    cin >> x;
    if (x == -2)
        exit(0);
    cout << "+ " << n + 1 << "\n";
    cout.flush();
    cin >> x;
    if (x == -2)
        exit(0);
    int md = -1, ind = -1;
    rep(i, 2, n)
    {
        cout << "? 1 " << i << "\n";
        cout.flush();
        cin >> x;
        if (x == -2)
            exit(0);
        if (x > md)
        {
            md = x;
            ind = i;
        }
    }
    vi a(n + 1), b(n + 1), c(n + 1);
    int p = n, q = 1;
    rep(i, 1, n)
    {
        if (i % 2)
            c[i] = p--;
        else
            c[i] = q++;
    }
    a[ind] = c[1];
    b[ind] = c[n];
    rep(i, 1, n)
    {
        if (ind == i)
            continue;
        cout << "? " << ind << " " << i << "\n";
        cout.flush();
        cin >> x;
        if (x == -2)
            exit(0);
        a[i] = c[x + 1];
        b[i] = c[n - x];
    }
    cout << "!";
    rep(i, 1, n) cout << " " << a[i];
    rep(i, 1, n) cout << " " << b[i];
    cout << "\n";
    cout.flush();
    cin >> x;
    if (x == -2)
        exit(0);
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
