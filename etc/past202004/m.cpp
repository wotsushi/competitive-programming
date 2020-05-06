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
    IN(ll, D);
    IN(ll, L);
    IN(ll, N);
    AIN(ll, C, D);
    vi K(N), F(N), T(N);
    REP(i, N)
    {
        cin >> K[i] >> F[i] >> T[i];
    }
    map<ll, vi> X;
    map<ll, vi> Y;
    REP(i, D)
    {
        if (X[C[i]].empty())
        {
            Y[C[i]].push_back(0);
        }
        else
        {
            Y[C[i]].push_back(Y[C[i]].back() + (i - X[C[i]].back() + L - 1) / L);
        }
        X[C[i]].push_back(i);
    }
    for (auto [c, x] : X)
    {
        Y[c].push_back(Y[c].back() + (x[0] + D - x.back() + L - 1) / L);
        X[c].push_back(x[0] + D);
    }
    REP(j, N)
    {
        if (X.find(K[j]) == X.end())
        {
            OUT(0);
            continue;
        }
        ll i = lower_bound(ALL(X[K[j]]), F[j] - 1) - X[K[j]].begin();
        T[j] -= (X[K[j]][i] - (F[j] - 1) + L - 1) / L;
        if (T[j] <= 0)
        {
            OUT(0);
            continue;
        }
        ll m = X[K[j]].size() - 1;
        ll ans = m * (T[j] / Y[K[j]].back());
        T[j] %= Y[K[j]].back();
        ll ok = i;
        ll ng = i + m;
        while (ng - ok > 1)
        {
            ll mid = (ok + ng) / 2;
            if ((Y[K[j]][mid % m] - Y[K[j]][i] + Y[K[j]].back()) % Y[K[j]].back() <= T[j])
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        ans += ok - i;
        T[j] -= (Y[K[j]][ok % m] - Y[K[j]][i] + Y[K[j]].back()) % Y[K[j]].back();
        ans += T[j] > 0;
        OUT(ans);
    }
}