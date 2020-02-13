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

ll N;
vi x, y;
ll Q;
vi a, b;

vector<vi> G;
vector<vi> parent;
vi depth;

void dfs(ll i, ll p, ll d)
{
    parent[0][i] = p;
    depth[i] = d;
    REP(j, G[i].size())
    {
        if (G[i][j] != p)
        {
            dfs(G[i][j], i, d + 1);
        }
    }
}

void answer(ll u, ll v, ll c)
{
    ll ans = depth[u] + depth[v] - 2 * depth[c] + 1;
    OUT(ans);
}

int main()
{
    cin >> N;
    x = vi(N);
    y = vi(N);
    REP(i, N - 1)
    {
        cin >> x[i] >> y[i];
    }
    cin >> Q;
    a = vi(Q);
    b = vi(Q);
    REP(i, Q)
    {
        cin >> a[i] >> b[i];
    }

    G = vector<vi>(N + 1);
    REP(i, N - 1)
    {
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
    }
    parent = vector<vi>(20, vi(N + 1));
    depth = vi(N + 1);
    dfs(1, 0, 0);
    REP(k, 19)
    {
        for (ll i = 1; i <= N; ++i)
        {
            parent[k + 1][i] = parent[k][parent[k][i]];
        }
    }
    REP(i, Q)
    {
        ll u = a[i];
        ll v = b[i];
        if (depth[u] > depth[v])
        {
            swap(u, v);
        }
        REP(k, 20)
        {
            if ((depth[v] - depth[u]) >> k & 1)
            {
                v = parent[k][v];
            }
        }
        if (u == v)
        {
            answer(a[i], b[i], u);
        }
        else
        {
            for (ll k = 19; k >= 0; --k)
            {
                if (parent[k][u] != parent[k][v])
                {
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            answer(a[i], b[i], parent[0][u]);
        }
    }
}