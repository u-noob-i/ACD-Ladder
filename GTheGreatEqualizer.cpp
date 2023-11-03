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
    int n, q;
    cin >> n;
    vi a(n);
    map<int, int> arr;
    multiset<int> dif;
    for (auto &x : a)
    {
        cin >> x;
        arr[x]++;
    }
    auto itr = arr.begin();
    int prev = itr->first;
    itr++;
    while (itr != arr.end())
    {
        dif.insert(itr->first - prev);
        prev = itr->first;
        itr++;
    }
    cin >> q;
    while (q--)
    {
        int i, x;
        cin >> i >> x;
        i--;
        arr[a[i]]--;
        if (!arr[a[i]])
        {
            auto itr = arr.find(a[i]), prv = itr, nxt = itr;
            if (itr != arr.begin())
            {
                prv--;
                dif.erase(dif.find(a[i] - prv->first));
            }
            nxt++;
            if (nxt != arr.end())
                dif.erase(dif.find(nxt->first - a[i]));
            arr.erase(a[i]);
            itr = arr.upper_bound(a[i]);
            if (itr != arr.end() && itr != arr.begin())
            {
                prv = nxt = itr;
                prv--;
                dif.insert(nxt->first - prv->first);
            }
        }
        if (arr.find(x) == arr.end())
        {
            auto itr = arr.upper_bound(x);
            if (itr != arr.end() && itr != arr.begin())
            {
                auto jtr = itr;
                jtr--;
                dif.erase(dif.find(itr->first - jtr->first));
            }
        }
        arr[x]++;
        a[i] = x;
        if (arr[x] == 1)
        {
            auto itr = arr.find(a[i]), prv = itr, nxt = itr;
            if (itr != arr.begin())
            {
                prv--;
                dif.insert(a[i] - prv->first);
            }
            nxt++;
            if (nxt != arr.end())
                dif.insert(nxt->first - a[i]);
        }
        cout << arr.rbegin()->first + (!dif.size() ? 0 : *dif.rbegin()) << " ";
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
