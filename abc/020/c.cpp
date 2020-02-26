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
typedef pair<ll, ii> iii;

ll H, W, T;
vector<string> s;

int main()
{
    cin >> H >> W >> T;
    s = vector<string>(H);
    REP(i, H)
    {
        cin >> s[i];
    }

    ii start, goal;
    REP(i, H)
    {
        REP(j, W)
        {
            if (s[i][j] == 'S')
            {
                start = ii(i, j);
            }
            if (s[i][j] == 'G')
            {
                goal = ii(i, j);
            }
        }
    }
    ll ok = 1;
    ll ng = T;
    while (abs(ng - ok) > 1)
    {
        ll mid = (ok + ng) / 2;
        priority_queue<iii> q;
        auto dp = vector<vi>(H, vi(W, INF));
        dp[start.first][start.second] = 0;
        q.push(iii(0, start));
        while (!q.empty())
        {
            iii r = q.top();
            ll t = r.first;
            ii y = r.second;
            q.pop();
            for (auto d : {ii(1, 0), ii(0, 1), ii(-1, 0), ii(0, -1)})
            {
                ii z = ii(y.first + d.first, y.second + d.second);
                if (z.first < 0 or z.first >= H or z.second < 0 or z.second >= W)
                {
                    continue;
                }
                ll c = t + (s[z.first][z.second] == '#' ? mid : 1);
                if (c < dp[z.first][z.second])
                {
                    dp[z.first][z.second] = c;
                    q.push(iii(c, z));
                }
            }
        }
        if (dp[goal.first][goal.second] <= T)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    ll ans = ok;

    OUT(ans);
}