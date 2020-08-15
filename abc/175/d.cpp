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
    IN(ll, K);
    AIN(ll, P, N);
    AIN(ll, C, N);
    REP(i, N)
    {
        --P[i];
    }
    vi T(N);
    vi S(N);
    REP(i, N)
    {
        ll j = P[i];
        ll t = 1;
        ll s = C[j];
        while (j != i)
        {
            j = P[j];
            ++t;
            s += C[j];
        }
        T[i] = t;
        S[i] = s;
    }
    ll ans = -INF;
    REP(i, N)
    {
        if (S[i] <= 0)
        {
            ll j = P[i];
            ll k = 1;
            ll s = C[j];
            ll opt = s;
            while (j != i and k < K)
            {
                j = P[j];
                ++k;
                s += C[j];
                CH(max, opt, s);
            }
            CH(max, ans, opt);
        }
        else
        {
            ll p = max(0LL, K / T[i] - 1);
            ll s = p * S[i];
            ll opt = s;
            ll k = p * T[i];
            ll j = i;
            if (k == 0)
            {
                ++k;
                j = P[j];
                s += C[j];
                CH(max, opt, s);
            }
            while (k < K)
            {
                j = P[j];
                s += C[j];
                ++k;
                CH(max, opt, s);
            }
            CH(max, ans, opt);
        }
    }
    OUT(ans);
}