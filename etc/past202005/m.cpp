#pragma region template 2.4
#include <bits/stdc++.h>
using namespace std;
template <typename T>
using pq_asc = priority_queue<T, vector<T>, greater<T>>;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define FOR(i, a) for (auto &i : a)
#define CH(f, x, y) x = f(x, y)
#define IN(T, x) \
    T x;         \
    cin >> x;
#define AIN(T, a, n) \
    vector<T> a(n);  \
    FOR(i, a)        \
    cin >> i;
#define A2IN(T1, a, T2, b, n) \
    vector<T1> a(n);          \
    vector<T2> b(n);          \
    REP(i, n)                 \
    cin >> a[i] >> b[i];
#define OUT(x) cout << (x) << endl;
#define FOUT(x) cout << fixed << setprecision(15) << (x) << endl;
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define DUMPA(a)          \
    cout << #a << " = {"; \
    JOUT(ALL(a), ", ", cout) << "}" << endl;

template <typename T>
ostream &JOUT(T s, T e, string sep = " ", ostream &os = cout)
{
    if (s != e)
    {
        os << *s;
        ++s;
    }
    while (s != e)
    {
        os << sep << *s;
        ++s;
    }
    return os;
}

ostream &YES(bool cond, string yes = "Yes", string no = "No", ostream &os = cout)
{
    if (cond)
    {
        os << yes << endl;
    }
    else
    {
        os << no << endl;
    }
    return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '[';
    JOUT(ALL(v), ", ", os) << ']';
    return os;
}

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#pragma endregion template
#pragma region graph 0.2
template <typename W>
struct graph
{
    using E = pair<ll, W>;
    ll n;
    ll m;
    bool weighted;
    bool directed;
    vector<vector<E>> e;

    graph() {}

    graph(ll n, ll m = 0, bool weighted = false, bool directed = false) : n(n), m(m), directed(directed), weighted(weighted)
    {
        e.assign(n + 1, vector<E>());
    }

    void add(ll i, ll j, W w = 1)
    {
        e[i].push_back(E(j, w));
        if (not directed)
        {
            e[j].push_back(E(i, w));
        }
        ++m;
    }

    vector<E> &operator[](int i)

    {
        return e[i];
    }
};

template <typename W>
istream &operator>>(istream &is, graph<W> &G)
{
    REP(i, G.m)
    {
        ll from, to, w;
        is >> from >> to;
        if (G.weighted)
        {
            is >> w;
            G.add(from, to, w);
        }
        else
        {
            G.add(from, to);
        }
        --G.m;
    }
    return is;
}

#pragma endregion graph
#pragma region dijkstra 1.0
template <typename W>
vi dijkstra(graph<W> &G, ll s)
{
    using E = pair<ll, W>;
    vi dp(G.n + 1, INF);
    pq_asc<E> q;
    q.push({0, s});
    dp[s] = 0;
    while (!q.empty())
    {
        auto [c, i] = q.top();
        q.pop();
        for (auto [j, w] : G[i])
        {
            if (c + w < dp[j])
            {
                dp[j] = c + w;
                q.push({dp[j], j});
            }
        }
    }
    return dp;
}

#pragma endregion dijkstra

int main()
{
    IN(ll, N);
    IN(ll, M);
    graph<ll> G(N, M);
    cin >> G;
    IN(ll, s);
    IN(ll, K);
    AIN(ll, t, K);
    t.insert(t.begin(), s);
    ll m = t.size();
    ll S = 1 << m;
    graph<ll> G2(m * S, 0, true, true);
    REP(i, m)
    {
        vi dp = dijkstra(G, t[i]);
        REP(j, m)
        {
            if (i == j)
            {
                continue;
            }
            REP(k, S)
            {
                G2.add(i * S + k, (j * S + k) | (1 << j), dp[t[j]]);
            }
        }
    }
    vi dp = dijkstra(G2, 1);
    ll ans = INF;
    REP(i, m)
    {
        CH(min, ans, dp[i * S + S - 1]);
    }
    OUT(ans);
}