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

vector<vector<char>> c(4, vector<char>(4));

int main()
{
    REP(i, 4)
    {
        REP(j, 4)
        {
            cin >> c[i][j];
        }
    }

    REP(i, 4)
    {
        vector<char> ans(4);
        REP(j, 4)
        {
            ans[j] = c[3 - i][3 - j];
        }
        OUTA(ans, 4);
    }
}