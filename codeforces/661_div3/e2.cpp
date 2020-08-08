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

vii E;
tree<ll> T;
vi w, c;

ll f(ll i)
{
    if (T[i].empty())
    {
        return 1;
    }
    ll res = 0;
    for (auto [j, k] : T[i])
    {
        ll cnt = f(j);
        E.push_back({k, cnt});
        res += cnt;
    }
    return res;
}

void solve()
{
    IN(ll, n);
    IN(ll, S);
    graph<ll> G(n, 0, true);
    w.resize(n - 1);
    c.resize(n - 1);
    REP(i, n - 1)
    {
        ll u, v;
        cin >> u >> v >> w[i] >> c[i];
        G.add(u, v, i);
    }
    T = tree<ll>(G);
    E.clear();
    f(1);
    vector<priority_queue<tuple<ll, ll, ll>>> q(2);
    ll s = 0;
    for (auto [k, cnt] : E)
    {
        q[c[k] - 1].push({w[k] * cnt - (w[k] / 2) * cnt, w[k] / 2, cnt});
        s += w[k] * cnt;
    }
    ll ans = 0;
    while (s > S)
    {
        vi dw(2), weight(2), cnt(2);
        ll dw2 = 0;
        ll weight2 = 0;
        ll cnt2 = 0;
        if (not q[0].empty())
        {
            auto t = q[0].top();
            dw[0] = get<0>(t);
            weight[0] = get<1>(t);
            cnt[0] = get<2>(t);
            q[0].pop();
            if (not q[0].empty())
            {
                auto t2 = q[0].top();
                dw[1] = get<0>(t2);
                weight[1] = get<1>(t2);
                cnt[1] = get<2>(t2);
            }
        }
        if (not q[1].empty())
        {
            auto t = q[1].top();
            dw2 = get<0>(t);
            weight2 = get<1>(t);
            cnt2 = get<2>(t);
        }
        ll ndw = weight[0] * cnt[0] - (weight[0] / 2) * cnt[0];
        if (s - dw[0] <= S or dw[0] + dw[1] >= dw2 or dw[0] + ndw >= dw2)
        {
            s -= dw[0];
            q[0].push({ndw, weight[0] / 2, cnt[0]});
            ++ans;
        }
        else
        {
            s -= dw2;
            q[0].push({dw[0], weight[0], cnt[0]});
            q[1].pop();
            q[1].push({weight2 * cnt2 - (weight2 / 2) * cnt2, weight2 / 2, cnt2});
            ans += 2;
        }
    }
    OUT(ans);
}

int main()
{
    IN(ll, t);
    REP(_, t)
    {
        solve();
    }
}