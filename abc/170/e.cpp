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
    IN(ll, Q);
    A2IN(ll, A, ll, B, N);
    ll M = 2e5;
    vector<multiset<ll>> S(M + 1);
    multiset<ll> R;
    vi z(N + 1);
    REP(i, N)
    {
        S[B[i]].insert(A[i]);
        z[i + 1] = B[i];
    }
    REP1(i, M)
    {
        if (not S[i].empty())
        {
            R.insert(*(S[i].rbegin()));
        }
    }
    REP(i, Q)
    {
        IN(ll, C);
        IN(ll, D);
        ll a = A[C - 1];
        bool flag = (*S[z[C]].rbegin()) == a;
        S[z[C]].erase(S[z[C]].find(a));
        if (S[z[C]].empty())
        {
            R.erase(R.find(a));
        }
        else if (flag and *S[z[C]].rbegin() != a)
        {
            R.erase(R.find(a));
            R.insert(*S[z[C]].rbegin());
        }

        if (S[D].empty())
        {
            R.insert(a);
        }
        else if (*S[D].rbegin() < a)
        {
            R.erase(R.find(*S[D].rbegin()));
            R.insert(a);
        }
        S[D].insert(a);
        z[C] = D;
        OUT(*R.begin());
    }
}