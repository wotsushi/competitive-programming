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
#pragma region uft 1.0
struct uft
{
    vi p;
    vi s;

    uft() {}

    uft(ll n)
    {
        p.assign(n + 1, 0);
        REP1(i, n)
        {
            p[i] = i;
        }
        s.assign(n + 1, 1);
    }

    ll find(ll i)
    {
        if (p[i] == i)
        {
            return i;
        }
        p[i] = find(p[i]);
        return p[i];
    }

    void unite(ll i, ll j)
    {
        i = find(i);
        j = find(j);
        if (i == j)
        {
            return;
        }
        if (s[i] < s[j])
        {
            p[i] = j;
        }
        else
        {
            p[j] = i;
        }
        s[j] += s[i];
        s[i] = s[j];
    }

    bool same(ll i, ll j)
    {
        return find(i) == find(j);
    }

    ll size(ll i)
    {
        return s[find(i)];
    }
};
#pragma endregion uft

int main()
{
    IN(ll, N)
    IN(ll, M);
    IN(ll, S);
    graph<ll> G(N, M);
    cin >> G;
    uft uft(N);
    for (ll i = N; i > S; --i)
    {
        for (auto [j, _] : G[i])
        {
            if (i < j)
            {
                uft.unite(i, j);
            }
        }
    }
    vi ans;
    for (ll i = S; i >= 1; --i)
    {
        for (auto [j, _] : G[i])
        {
            if (i < j)
            {
                uft.unite(i, j);
            }
        }
        if (uft.same(S, i))
        {
            ans.push_back(i);
        }
    }
    reverse(ALL(ans));
    FOR(i, ans)
    {
        OUT(i);
    }
}