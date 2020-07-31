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

int main()
{
    IN(ll, N);
    A2IN(ll, a, ll, b, N);

    ll T = *max_element(ALL(b));
    vector<tuple<ll, ll, ll>> p(N + 1);
    REP(i, N)
    {
        p[i] = {a[i], -b[i], i + 1};
    }
    p[N] = {0, -T, INF};
    RSORT(p);
    ll j = T - 1;
    vi dp(T + 1);
    vvi jobs(T + 1);
    for (auto [x, y, k] : p)
    {
        y = -y;
        for (; j >= x; --j)
        {
            dp[j] = dp[j + 1];
        }
        if (dp[x] < dp[y] + 1)
        {
            dp[x] = dp[y] + 1;
            jobs[x] = {k};
        }
        else if (dp[x] == dp[y] + 1)
        {
            jobs[x].push_back(k);
        }
    }
    OUT(dp[0]);
    ll t = 0;
    vi w;
    for (ll l = dp[0]; l > 0; --l)
    {
        ll opt = INF;
        while (dp[t] == l)
        {
            FOR(job, jobs[t])
            {
                CH(min, opt, job);
            }
            ++t;
        }
        w.push_back(opt);
        t = b[opt - 1];
    }
    JOUT(ALL(w)) << endl;
}