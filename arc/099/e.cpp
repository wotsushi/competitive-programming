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

ll N;
vector<vector<bool>> H;
vi C;
vii A;

ii f(ll i, ll c)
{
    C[i] = c;
    ii res;
    if (c == 1)
    {
        res = {1, 0};
    }
    else
    {
        res = {0, 1};
    }
    REP1(j, N)
    {
        if (H[i][j])
        {
            if (C[j] == c)
            {
                return {0, 0};
            }
            if (C[j] == 0)
            {
                ii p = f(j, -c);
                if (p == ii{0, 0})
                {
                    return {0, 0};
                }
                res.first += p.first;
                res.second += p.second;
            }
        }
    }
    return res;
}

int main()
{
    cin >> N;
    IN(ll, M);
    graph<ll> G(N, M);
    cin >> G;
    H = vector<vector<bool>>(N + 1, vector<bool>(N + 1, true));
    REP1(i, N)
    {
        H[i][i] = false;
        for (auto [j, _] : G[i])
        {
            H[i][j] = false;
            H[j][i] = false;
        }
    }
    C.resize(N + 1);
    REP1(i, N)
    {
        if (C[i] == 0)
        {
            ii res = f(i, 1);
            if (res == ii{0, 0})
            {
                OUT(-1);
                return 0;
            }
            A.push_back(res);
        }
    }
    ll K = A.size();
    vector<vector<bool>> dp(K + 1, vector<bool>(N + 1));
    dp[0][0] = true;

    REP(i, K)
    {
        auto [x, y] = A[i];
        REP(j, N)
        {
            if (dp[i][j] and j + x <= N)
            {
                dp[i + 1][j + x] = true;
            }
            if (dp[i][j] and j + y <= N)
            {
                dp[i + 1][j + y] = true;
            }
        }
    }
    ll ans = INF;
    REP1(i, N)
    {
        if (dp[K][i])
        {
            CH(min, ans, i * (i - 1) / 2 + (N - i) * (N - i - 1) / 2);
        }
    }
    OUT(ans);
}
