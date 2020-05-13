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
#pragma region grid 0.1
void way4(ll i, ll j, ll H, ll W, function<void(ll, ll)> f)
{
    for (auto [di, dj] : {ii(1, 0), ii(0, 1), ii(-1, 0), ii(0, -1)})
    {
        ll u = i + di;
        ll v = j + dj;
        if (0 <= u and u < H and 0 <= v and v < W)
        {
            f(u, v);
        }
    }
}

void way8(ll i, ll j, ll H, ll W, function<void(ll, ll)> f)
{
    for (ll u = i - 1; u <= i + 1; ++u)
    {
        for (ll v = j - 1; v <= j + 1; ++v)
        {
            if (0 <= u and u < H and 0 <= v and v < W and u != i or v != j)
            {
                f(u, v);
            }
        }
    }
}
#pragma endregion grid

int main()
{
    IN(ll, n);
    IN(ll, m);
    IN(ll, t);
    AIN(string, c, n);
    vvi dp(n, vi(m, INF));
    queue<ii> q;
    REP(i, n)
    {
        REP(j, m)
        {
            bool ok = false;
            way4(i, j, n, m, [&](ll u, ll v) {
                ok |= c[u][v] == c[i][j];
            });
            if (ok)
            {
                dp[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (not q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        way4(i, j, n, m, [&](ll u, ll v) {
            if (dp[u][v] == INF)
            {
                dp[u][v] = dp[i][j] + 1;
                q.push({u, v});
            }
        });
    }
    REP(q, t)
    {
        IN(ll, i);
        IN(ll, j);
        IN(ll, p);
        YES((c[i - 1][j - 1] + max(0LL, p - dp[i - 1][j - 1])) & 1, "1", "0");
    }
}