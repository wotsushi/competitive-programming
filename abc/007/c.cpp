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

typedef pair<ll, ll> ii;

const ll DI[] = {0, 1, 0, -1};
const ll DJ[] = {1, 0, -1, 0};

ll R, C;
ll sy, sx;
ll gy, gx;
vector<string> c;

int main()
{
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    c = vector<string>(R);
    REP(i, R)
    {
        cin >> c[i];
    }

    queue<ii> q = queue<ii>();
    vector<vi> dp = vector<vi>(R, vi(C, INF));
    q.push(ii(sy - 1, sx - 1));
    dp[sy - 1][sx - 1] = 0;
    while (!q.empty())
    {
        ii p = q.front();
        q.pop();
        REP(k, 4)
        {
            ll i = p.first + DI[k];
            ll j = p.second + DJ[k];
            if (c[i][j] == '.' and dp[i][j] == INF)
            {
                dp[i][j] = dp[p.first][p.second] + 1;
                q.push(ii(i, j));
            }
        }
    }
    ll ans = dp[gy - 1][gx - 1];

    OUT(ans);
}