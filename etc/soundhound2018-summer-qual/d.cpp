#pragma region template
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a) \
    REP(i, (a).size()) { cout << (a[i]) << (i == (a).size() - 1 ? "\n" : " "); }
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

typedef tuple<ll, ll, ll> e;

int main()
{
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    vi u(m), v(m), a(m), b(m);
    REP(i, m)
    {
        cin >> u[i] >> v[i] >> a[i] >> b[i];
    }

    vector<vector<e>> G(n + 1);
    REP(i, m)
    {
        G[u[i]].push_back(e(v[i], a[i], b[i]));
        G[v[i]].push_back(e(u[i], a[i], b[i]));
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    vi dp(n + 1, INF);
    q.push(ii(0, s));
    dp[s] = 0;
    while (!q.empty())
    {
        ii x = q.top();
        q.pop();
        ll c = x.first;
        ll i = x.second;

        REP(k, G[i].size())
        {
            ll j = get<0>(G[i][k]);
            ll w = c + get<1>(G[i][k]);
            if (w < dp[j])
            {
                dp[j] = w;
                q.push(ii(w, j));
            }
        }
    }
    priority_queue<ii, vector<ii>, greater<ii>> q2;
    vi dp2(n + 1, INF);
    q2.push(ii(0, t));
    dp2[t] = 0;
    while (!q2.empty())
    {
        ii x = q2.top();
        q2.pop();
        ll c = x.first;
        ll i = x.second;

        REP(k, G[i].size())
        {
            ll j = get<0>(G[i][k]);
            ll w = c + get<2>(G[i][k]);
            if (w < dp2[j])
            {
                dp2[j] = w;
                q2.push(ii(w, j));
            }
        }
    }
    priority_queue<ii, vector<ii>, greater<ii>> r;
    REP1(i, n)
    {
        r.push(ii(dp[i] + dp2[i], i));
    }
    REP(i, n)
    {
        while (r.top().second <= i)
        {
            r.pop();
        }
        ll ans = 1e15 - r.top().first;
        OUT(ans);
    }
}
#pragma endregion template