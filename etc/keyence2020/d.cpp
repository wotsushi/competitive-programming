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
    JOUT(ALL(a), cout, ", ") << "}" << endl;

template <typename T>
ostream &JOUT(T s, T e, ostream &os = cout, string sep = " ")
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
    JOUT(ALL(v), os, ", ") << ']';
    return os;
}

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#pragma endregion template

int main()
{
    IN(ll, N);
    AIN(ll, A, N);
    AIN(ll, B, N);
    ll ans = INF;
    REP(p, 1 << N)
    {
        vii x, y;
        REP(i, N)
        {
            bool odd = i & 1;
            bool rev = (p >> i) & 1;
            if (odd and rev)
            {
                x.push_back(ii(B[i], i));
            }
            else if (odd and not rev)
            {
                y.push_back(ii(A[i], i));
            }
            else if (not odd and rev)
            {
                y.push_back(ii(B[i], i));
            }
            else
            {
                x.push_back(ii(A[i], i));
            }
        }
        if (x.size() != (N + 1) / 2 or y.size() != N / 2)
        {
            continue;
        }
        SORT(x);
        SORT(y);
        bool ok = true;
        REP1(i, N - 1)
        {
            if (i & 1)
            {
                ok &= y[i / 2].first >= x[i / 2].first;
            }
            else
            {
                ok &= x[i / 2].first >= y[i / 2 - 1].first;
            }
        }
        vi z(N);
        REP(i, N)
        {
            if (i & 1)
            {
                z[i] = y[i / 2].second;
            }
            else
            {
                z[i] = x[i / 2].second;
            }
        }
        ll c = 0;
        REP(i, N)
        {
            for (ll j = N - 1; j > i; --j)
            {
                if (z[j] < z[j - 1])
                {
                    swap(z[j], z[j - 1]);
                    ++c;
                }
            }
        }
        if (ok)
        {
            CH(min, ans, c);
        }
    }
    if (ans == INF)
    {
        OUT(-1);
    }
    else
    {
        OUT(ans);
    }
}