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
ll M = 998244353;

void solve()
{
    int n, q, x;
    string s;
    cin >> n >> q >> s;
    set<int> op, cl;
    rep(i, 0, n - 2)
    {
        if (s[i] == s[i + 1])
        {
            if (s[i] == '(')
                op.insert(i);
            else
                cl.insert(i);
        }
    }
    rep(i, 1, q)
    {
        cin >> x;
        x--;
        if (x < n - 1)
        {
            if (s[x] == '(' && s[x + 1] == '(')
                op.erase(x);
            else if (s[x] == ')' && s[x + 1] == ')')
                cl.erase(x);
            else if (s[x] == '(' && s[x + 1] == ')')
                cl.insert(x);
            else if (s[x] == ')' && s[x + 1] == '(')
                op.insert(x);
        }
        if (x > 0)
        {
            if (s[x] == '(' && s[x - 1] == '(')
                op.erase(x - 1);
            else if (s[x] == ')' && s[x - 1] == ')')
                cl.erase(x - 1);
            else if (s[x] == '(' && s[x - 1] == ')')
                cl.insert(x - 1);
            else if (s[x] == ')' && s[x - 1] == '(')
                op.insert(x - 1);
        }
        if (s[x] == '(')
            s[x] = ')';
        else
            s[x] = '(';
        // cout << s << " ";
        if (n % 2 || s[0] == ')' || s[n - 1] == '(')
            cout << "NO\n";
        else if ((op.size() && !cl.size()) || (!op.size() && cl.size()))
            cout << "NO\n";
        else if (op.size() && cl.size())
        {
            int x = *op.begin(), y = *cl.begin();
            int w = *op.rbegin(), z = *cl.rbegin();
            // cout << x << " " << y << " " << w << " " << z << " ";
            if (y < x || z < w)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else
            cout << "YES\n";
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
    // cin >> tt;
    for (int TT = 1; TT <= tt; TT++)
    {
        solve();
        cout << "\n";
    }
}
