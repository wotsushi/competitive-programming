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
#pragma region tree 0.1
template <typename W>
struct tree
{
    using E = pair<ll, W>;
    ll n;
    ll r;
    vector<E> p;
    vector<vector<E>> c;
    vi d;

    tree() {}

    tree(graph<W> &G, ll r = 1) : n(G.n), r(r)
    {
        p.assign(G.n + 1, E(-2, 0));
        c.assign(G.n + 1, vector<E>());
        d.assign(G.n + 1, 0);
        queue<ll> q;
        p[r] = E(-1, 0);
        q.push(r);
        while (!q.empty())
        {
            ll i = q.front();
            q.pop();
            for (auto [j, w] : G[i])
            {
                if (p[j].first == -2)
                {
                    p[j] = E(i, w);
                    c[i].push_back(E(j, w));
                    d[j] = d[i] + 1;
                    q.push(j);
                }
            }
        }
    }

    E par(ll i)
    {
        return p[i];
    }

    ll depth(ll i)
    {
        return d[i];
    }

    vector<E> &operator[](int i)
    {
        return c[i];
    }
};

#pragma endregion tree
#pragma region lca 0.1
struct lca
{
    vvi p;
    vi d;
    ll m;

    lca() {}

    template <typename W>
    lca(tree<W> &T)
    {
        m = 1;
        ll n = T.n + 1;
        while (n > 1)
        {
            n >>= 1;
            ++m;
        }
        p.assign(T.n + 1, vi(m));
        REP(i, T.n + 1)
        {
            p[i][0] = T.par(i).first;
        }
        REP(j, m - 1)
        {
            REP(i, T.n + 1)
            {
                if (p[i][j] < 0)
                {
                    p[i][j + 1] = p[i][j];
                }
                else
                {
                    p[i][j + 1] = p[p[i][j]][j];
                }
            }
        }
        d.assign(T.n + 1, 0);
        REP(i, T.n + 1)
        {
            d[i] = T.depth(i);
        }
    }

    ll operator()(ll i, ll j)
    {
        if (d[i] > d[j])
        {
            swap(i, j);
        }
        REP(k, m)
        {
            if ((d[j] - d[i]) >> k & 1)
            {
                j = p[j][k];
            }
        }
        if (i == j)
        {
            return i;
        }
        for (ll k = m - 1; k >= 0; --k)
        {
            if (p[i][k] != p[j][k])
            {
                i = p[i][k];
                j = p[j][k];
            }
        }
        return p[i][0];
    }
};

#pragma endregion lca

int main()
{
    IN(ll, n);
    IN(ll, m);
    graph<ll> G(n, n - 1);
    cin >> G;
    tree<ll> T(G);
    lca lca(T);
    REP(q, m)
    {
        IN(ll, k);
        AIN(ll, v, k);
        ll i = 1;
        FOR(x, v)
        {
            if (T.depth(x) > T.depth(i))
            {
                i = x;
            }
        }
        bool ok = true;
        FOR(x, v)
        {
            ok &= x == lca(x, i) or T.par(x).first == lca(x, i);
        }
        YES(ok, "YES", "NO");
    }
}