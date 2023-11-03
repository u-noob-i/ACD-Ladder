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
    string s, p;
    cin >> n >> s >> p;
    vi ans;
    int op = 0, l = 0, r = n - 1;
    irep(i, n - 1, 0)
    {
        if (op % 2 && s[l] != p[i])
        {
            l++;
            continue;
        }
        if (op % 2 == 0 && s[r] == p[i])
        {
            r--;
            continue;
        }
        if (op % 2)
        {
            if (s[r] != s[l])
            {
                ans.pb(1);
                if (s[r] == '0')
                    s[r] = '1';
                else
                    s[r] = '0';
            }
            r--;
        }
        else
        {
            if (s[r] != s[l])
            {
                ans.pb(1);
                if (s[l] == '0')
                    s[l] = '1';
                else
                    s[l] = '0';
            }
            l++;
        }
        ans.pb(i + 1);
        op++;
    }
    cout << ans.size() << " ";
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

    int tt;
    cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
