#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;
#define forn(i, e) for (ll i = 1; i <= e; i++)
#define forsn(i, s, e) for (ll i = s; i <= e; i++)
#define rforn(i, s) for (ll i = s; i >= 1; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout << #x << " = " << x << ln
#define pb push_back
#define fi first
#define se second
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

// Modulo Calculation
ll add(ll x, ll y)
{
    return (x + y) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)x * y % MOD;
}

const ll SIZE = 1e5 + 5;

ll m, n, A[20][20];

bool ch(){
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            if (A[i][j] == 1) return false;
        }
    }
    return true;
}

bool quaylui(){
    if (ch()){
        return true;
    }

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m;j++){
            if (i + 1 == n || j + 1 == m) continue;
            if (A[i][j] == 1 && A[i+1][j] == 1 &&  A[i+1][j+1] == 1){
                
                A[i][j] = A[i+1][j] = A[i+1][j+1] = 0;
                if(quaylui()) return true;
                A[i][j] = A[i+1][j] = A[i+1][j+1] = 1;
            }
            if (j - 1 < 0) continue;
            if (A[i][j] == 1 && A[i+1][j] == 1 &&  A[i+1][j-1] == 1){
                
                A[i][j] = A[i+1][j] = A[i+1][j-1] = 0;
                if(quaylui()) return true;
                A[i][j] = A[i+1][j] = A[i+1][j-1] = 1;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            char t; cin >> t;
            A[i][j] = 1;
            if (t == '#') A[i][j] = 0;
        }
    }

    if (quaylui()) cout << "YES";
    else cout << "NO";
}

int main()
{
    
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}


