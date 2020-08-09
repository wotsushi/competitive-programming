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
    AIN(string, A, N);
    vi D = {2, 5};
    vvi f(2, vi(N));
    vvi g(20, vi(20));
    REP(i, N)
    {
        string x;
        string y;
        ll j;
        for (j = 0; j < A[i].size() and A[i][j] != '.'; ++j)
        {
            x.push_back(A[i][j]);
        }
        ++j;
        for (; j < A[i].size(); ++j)
        {
            y.push_back(A[i][j]);
        }
        while (y.size() < 9)
        {
            y.push_back('0');
        }
        ll p = stoll(x + y);
        REP(k, 2)
        {
            f[k][i] = -9;
            while (p % D[k] == 0)
            {
                ++f[k][i];
                p /= D[k];
            }
            CH(min, f[k][i], 9LL);
        }
        ++g[f[0][i] + 9][f[1][i] + 9];
    }
    ll ans = 0;
    REP(i, N)
    {
        for (ll j = -f[0][i]; j <= 9; ++j)
        {
            for (ll k = -f[1][i]; k <= 9; ++k)
            {
                ans += g[j + 9][k + 9];
            }
        }
        ans -= f[0][i] >= 0 and f[1][i] >= 0;
    }
    ans /= 2;
    OUT(ans);
}