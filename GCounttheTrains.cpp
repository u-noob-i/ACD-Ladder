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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    set<int> arr;
    arr.insert(0);
    int cur = a[0];
    rep(i, 1, n - 1)
    {
        if (a[i] < cur)
        {
            arr.insert(i);
            cur = a[i];
        }
    }
    rep(j, 1, m)
    {
        int i, x;
        cin >> i >> x;
        if (!x)
        {
            cout << arr.size() << " ";
            continue;
        }
        i--;
        a[i] -= x;
        auto itr = arr.upper_bound(i);
        itr--;
        if (i == *itr)
        {
            auto jtr = itr;
            itr++;
            while (itr != arr.end() && a[*itr] >= a[*jtr])
            {
                arr.erase(*itr);
                itr = jtr;
                itr++;
            }
        }
        else if (a[i] < a[*itr])
        {
            arr.insert(i);
            auto jtr = arr.find(i);
            itr = jtr;
            itr++;
            while (itr != arr.end() && a[*itr] >= a[*jtr])
            {
                arr.erase(*itr);
                itr = jtr;
                itr++;
            }
        }
        cout << arr.size() << " ";
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

    int tt = 1;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
