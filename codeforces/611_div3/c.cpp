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
    IN(ll, n);
    AIN(ll, f, n);
    vector<bool> received(n + 1);
    vector<bool> sent(n + 1);
    REP(i, n)
    {
        if (f[i] > 0)
        {
            sent[i + 1] = true;
            received[f[i]] = true;
        }
    }
    vi alone, not_send, not_received;
    REP1(i, n)
    {
        if (not received[i] and not sent[i])
        {
            alone.push_back(i);
        }
        if (not received[i] and sent[i])
        {
            not_received.push_back(i);
        }
        if (received[i] and not sent[i])
        {
            not_send.push_back(i);
        }
    }
    ll m = alone.size();
    if (m == 1)
    {
        f[alone[0] - 1] = not_received[0];
        f[not_send[0] - 1] = alone[0];
        REP1(i, not_send.size() - 1)
        {
            f[not_send[i] - 1] = not_received[i];
        }
    }
    else
    {
        REP(i, m)
        {
            f[alone[i] - 1] = alone[(i + 1) % m];
        }
        REP(i, not_send.size())
        {
            f[not_send[i] - 1] = not_received[i];
        }
    }
    JOUT(ALL(f)) << endl;
}