#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a, n) \
    REP(i, n) { cout << (a[i]) << (i == n - 1 ? "\n" : " "); }
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

vector<vi> b(2, vi(3)), c(3, vi(2));

map<string, ll> dp, dp2;

void dfs(string s, char t)
{
    if (dp.find(s) != dp.end())
    {
        return;
    }
    bool is_finish = true;
    REP(i, 9)
    {
        is_finish &= s[i] != '2';
    }
    if (is_finish)
    {
        ll x, y;
        x = y = 0;
        REP(i, 2)
        {
            REP(j, 3)
            {
                if (s[3 * i + j] == s[3 * (i + 1) + j])
                {
                    x += b[i][j];
                }
                else
                {
                    y += b[i][j];
                }
            }
        }
        REP(i, 3)
        {
            REP(j, 2)
            {
                if (s[3 * i + j] == s[3 * i + j + 1])
                {
                    x += c[i][j];
                }
                else
                {
                    y += c[i][j];
                }
            }
        }
        dp[s] = x;
        dp2[s] = y;
    }
    else
    {
        ll opt, opt2;
        opt = opt2 = -1;
        REP(i, 9)
        {
            if (s[i] == '2')
            {
                s[i] = t;
                dfs(s, '1' - t + '0');
                if (t == '0' and dp[s] > opt)
                {
                    opt = max(opt, dp[s]);
                    opt2 = dp2[s];
                }
                if (t == '1' and dp2[s] > opt2)
                {
                    opt = dp[s];
                    opt2 = max(opt2, dp2[s]);
                }
                s[i] = '2';
            }
        }
        dp[s] = opt;
        dp2[s] = opt2;
    }
}

int main()
{
    REP(i, 2)
    {
        REP(j, 3)
        {
            cin >> b[i][j];
        }
    }
    REP(i, 3)
    {
        REP(j, 2)
        {
            cin >> c[i][j];
        }
    }

    dfs("222222222", '0');
    OUT(dp["222222222"]);
    OUT(dp2["222222222"]);
}