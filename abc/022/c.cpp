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

ll N, M;
vi u, v, l;

int main()
{
    cin >> N >> M;
    u = v = l = vi(M);
    REP(i, M)
    {
        cin >> u[i] >> v[i] >> l[i];
    }

    auto G = vector<vi>(N + 1, vi(N + 1, INF));
    REP(i, M)
    {
        G[u[i]][v[i]] = l[i];
        G[v[i]][u[i]] = l[i];
    }
    ll opt = INF;
    for (ll k = 2; k <= N; ++k)
    {
        ll tmp = G[1][k];
        G[1][k] = INF;
        priority_queue<ii, vector<ii>, greater<ii>> q;
        vi dp = vi(N + 1, INF);
        dp[1] = 0;
        q.push(ii(0, 1));
        while (!q.empty())
        {
            ii t = q.top();
            ll w = t.first;
            ll i = t.second;
            q.pop();
            REP(j, N + 1)
            {
                ll d = w + G[i][j];
                if (d < dp[j])
                {
                    dp[j] = d;
                    q.push(ii(d, j));
                }
            }
        }
        opt = min(opt, dp[k] + tmp);
        G[1][k] = tmp;
    }
    ll ans = opt < INF ? opt : -1;

    OUT(ans);
}