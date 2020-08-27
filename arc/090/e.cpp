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
    using E = pair<W, ll>;
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
#pragma region mint 1.1
struct mint
{
    ll a;

    mint(ll a = 0) : a((a % MOD + MOD) % MOD) {}
    mint pow(ll y)
    {
        ll exp = y;
        mint res = 1;
        mint p = a;
        while (exp)
        {
            if (exp & 1)
            {
                res *= p;
            }
            exp >>= 1;
            p *= p;
        }
        return res;
    }
    mint pow(mint y)
    {
        return pow(y.a);
    }
    mint &operator+=(ll y)
    {
        *this = a + y;
        return *this;
    }
    mint &operator+=(mint y)
    {
        *this += y.a;
        return *this;
    }
    mint &operator-=(ll y)
    {
        *this = a - y;
        return *this;
    }
    mint &operator-=(mint y)
    {
        *this -= y.a;
        return *this;
    }
    mint &operator*=(ll y)
    {
        *this = a * y;
        return *this;
    }
    mint &operator*=(mint y)
    {
        *this *= y.a;
        return *this;
    }
    mint &operator/=(ll y)
    {
        *this *= mint(y).pow(MOD - 2);
        return *this;
    }
    mint &operator/=(const mint y)
    {
        *this /= y.a;
        return *this;
    }
    mint &operator++()
    {
        *this += 1;
        return *this;
    }
    mint &operator++(int)
    {
        *this += 1;
        return *this;
    }
    mint &operator--()
    {
        *this -= 1;
        return *this;
    }
    mint &operator--(int)
    {
        *this -= 1;
        return *this;
    }
};

mint operator+(const mint &x, const mint &y)
{
    return mint(x.a) += y;
}
mint operator+(const mint &x, const ll &y)
{
    return mint(x.a) += y;
}
mint operator+(const ll &x, mint &y)
{
    return mint(x) += y;
}
mint operator-(const mint &x, const mint &y)
{
    return mint(x.a) -= y;
}
mint operator-(const mint &x, const ll &y)
{
    return mint(x.a) -= y;
}
mint operator-(const ll &x, const mint &y)
{
    return mint(x) -= y;
}
mint operator*(const mint &x, const mint &y)
{
    return mint(x.a) *= y;
}
mint operator*(const mint &x, const ll &y)
{
    return mint(x.a) *= y;
}
mint operator*(const ll &x, const mint &y)
{
    return mint(x) *= y;
}
mint operator/(const mint &x, const mint &y)
{
    return mint(x.a) /= y;
}
mint operator/(const mint &x, const ll &y)
{
    return mint(x.a) /= y;
}
mint operator/(const ll &x, const mint &y)
{
    return mint(x) /= y;
}
bool operator==(const mint &x, const mint &y)
{
    return x.a == y.a;
}
bool operator==(const mint &x, const ll &y)
{
    return x.a == y;
}
bool operator==(const ll &x, mint &y)
{
    return x == y.a;
}
bool operator!=(const mint &x, const mint &y)
{
    return !(x == y);
}
bool operator!=(const mint &x, const ll &y)
{
    return !(x == y);
}
bool operator!=(const ll &x, mint &y)
{
    return !(x == y);
}
istream &operator>>(istream &is, mint &i)
{
    is >> i.a;
    return is;
}
ostream &operator<<(ostream &os, const mint &i)
{
    os << i.a;
    return os;
}

typedef vector<mint> vm;
#pragma endregion mint

int main()
{
    IN(ll, N);
    IN(ll, M);
    IN(ll, S);
    IN(ll, T);
    graph<ll> G(N, M, true);
    cin >> G;

    vi dps = dijkstra(G, S);
    vi dpt = dijkstra(G, T);
    auto f = [&](ll i) {
        return dps[i] + dpt[i] == dps[T];
    };

    vm cs(N + 1);
    vector<bool> used(N + 1);
    used[S] = true;
    cs[S] = 1;
    pq_asc<ii> q;
    q.push({0LL, S});
    while (not q.empty())
    {
        auto [t, i] = q.top();
        q.pop();
        for (auto [j, w] : G[i])
        {
            if (t + w == dps[j] and f(j))
            {
                cs[j] += cs[i];
                if (not used[j])
                {
                    q.push({dps[j], j});
                    used[j] = true;
                }
            }
        }
    }
    vm ct(N + 1);
    ct[T] = 1;
    used = vector<bool>(N + 1);
    used[T] = true;
    q = pq_asc<ii>();
    q.push({0, T});
    while (not q.empty())
    {
        auto [t, i] = q.top();
        q.pop();
        for (auto [j, w] : G[i])
        {
            if (t + w == dpt[j] and f(j))
            {
                ct[j] += ct[i];
                if (not used[j])
                {
                    q.push({dpt[j], j});
                    used[j] = true;
                }
            }
        }
    }

    mint ans = cs[T] * cs[T];
    REP1(i, N)
    {
        for (auto [j, w] : G[i])
        {
            if (f(j) and dps[i] + w == dps[j] and 2 * dps[i] < dps[T])
            {
                if (2 * dps[j] > dps[T])
                {
                    ans -= (cs[i] * ct[j]).pow(2);
                }
                if (2 * dps[j] == dps[T])
                {
                    ans -= (cs[i] * ct[j]) * (ct[j] * cs[j]);
                }
            }
        }
    }
    OUT(ans);
}