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
    AIN(ll, a, N);
    vi S(2);
    REP(i, N)
    {
        S[i & 1] += max(0LL, a[i]);
    }
    if (S[0] == 0 and S[1] == 0)
    {
        ll k = max_element(ALL(a)) - a.begin();
        OUT(a[k]);
        OUT(N - 1);
        for (ll i = N - 1; i > k; --i)
        {
            OUT(i + 1);
        }
        REP(i, k)
        {
            OUT(1);
        }
        return 0;
    }
    OUT(max(S[0], S[1]));
    vi D;
    for (ll i = N - 1; i >= 0; --i)
    {
        if (a[i] <= 0 and (i & 1) == (S[0] < S[1]))
        {
            D.push_back(i);
        }
    }
    ll n = N;
    ll base = 0;
    vi ans;
    FOR(d, D)
    {
        ans.push_back(d + 1);
        if (d == n - 1)
        {
            --n;
        }
        else if (d == 0)
        {
            --n;
            base = 1;
        }
        else
        {
            n -= 2;
        }
    }
    for (ll i = n - 1; i >= 0; --i)
    {
        if (((i + base) & 1) == (S[0] >= S[1]))
        {
            ans.push_back(i + 1);
        }
    }
    OUT(ans.size());
    FOR(x, ans)
    {
        OUT(x);
    }
}