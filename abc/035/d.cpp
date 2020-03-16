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

int main()
{
    ll N, M, T;
    cin >> N >> M >> T;
    vi A(N);
    REP(i, N)
    cin >> A[i];
    vi a(M), b(M), c(M);
    REP(i, M)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<ii>> G(N + 1);
    vector<vector<ii>> G2(N + 1);
    REP(i, M)
    {
        G[a[i]].push_back(ii(b[i], c[i]));
        G2[b[i]].push_back(ii(a[i], c[i]));
    }
    vi dp(N + 1, INF), dp2(N + 1, INF);
    priority_queue<ii, vector<ii>, greater<ii>> q, q2;
    dp[1] = 0;
    q.push(ii(0, 1));
    while (!q.empty())
    {
        ii t = q.top();
        q.pop();
        ll wi = t.first;
        ll i = t.second;
        REP(k, G[i].size())
        {
            ll j = G[i][k].first;
            ll w = wi + G[i][k].second;
            if (w < dp[j])
            {
                dp[j] = w;
                q.push(ii(w, j));
            }
        }
    }
    dp2[1] = 0;
    q2.push(ii(0, 1));
    while (!q2.empty())
    {
        ii t = q2.top();
        q2.pop();
        ll wi = t.first;
        ll i = t.second;
        REP(k, G2[i].size())
        {
            ll j = G2[i][k].first;
            ll w = wi + G2[i][k].second;
            if (w < dp2[j])
            {
                dp2[j] = w;
                q2.push(ii(w, j));
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= N; ++i)
    {
        ans = max(ans, max(0LL, T - dp[i] - dp2[i]) * A[i - 1]);
    }

    OUT(ans);
}