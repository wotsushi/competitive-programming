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
    IN(ll, K);
    AIN(ll, A, N);
    SORT(A);
    vi B = A;
    RSORT(B);
    ll ok = -INF;
    ll ng = INF;
    while (ng - ok > 1)
    {
        ll mid = (ok + ng) / 2;
        ll s = 0;
        REP(i, N)
        {
            if (A[i] > 0)
            {
                ll ok2 = -1;
                ll ng2 = N;
                while (ng2 - ok2 > 1)
                {
                    ll mid2 = (ok2 + ng2) / 2;
                    if (A[i] * A[mid2] < mid)
                    {
                        ok2 = mid2;
                    }
                    else
                    {
                        ng2 = mid2;
                    }
                }
                if (ok2 < i)
                {
                    s += ok2 + 1;
                }
                else
                {
                    s += ok2;
                }
            }
            else if (A[i] == 0)
            {
                if (0 < mid)
                {
                    s += N - 1;
                }
            }
            else
            {
                ll ok2 = -1;
                ll ng2 = N;
                while (ng2 - ok2 > 1)
                {
                    ll mid2 = (ok2 + ng2) / 2;
                    if (A[i] * B[mid2] < mid)
                    {
                        ok2 = mid2;
                    }
                    else
                    {
                        ng2 = mid2;
                    }
                }
                if (ok2 < N - i - 1)
                {
                    s += ok2 + 1;
                }
                else
                {
                    s += ok2;
                }
            }
        }
        s /= 2;
        if (s < K)
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    OUT(ok);
}