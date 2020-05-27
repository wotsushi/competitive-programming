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
    IN(ll, N);
    AIN(ll, P, N * N);
    vvi dp(N, vi(N));
    vector<vector<bool>> exist(N, vector<bool>(N, true));
    REP(i, N)
    {
        REP(j, N)
        {
            dp[i][j] = min({i, j, N - 1 - i, N - 1 - j});
        }
    }
    ll ans = 0;
    FOR(p, P)
    {
        ll y = (p - 1) / N;
        ll x = (p - 1) % N;
        ans += dp[y][x];
        exist[y][x] = false;
        queue<ii> q;
        q.push({y, x});
        while (not q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            way4(i, j, N, N, [&](ll u, ll v) {
                if (dp[u][v] > dp[i][j] + exist[i][j])
                {
                    dp[u][v] = dp[i][j] + exist[i][j];
                    q.push({u, v});
                }
            });
        }
    }
    OUT(ans);
}