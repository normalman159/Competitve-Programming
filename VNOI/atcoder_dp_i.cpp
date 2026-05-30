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

const ll SIZE = 3e3 + 5;

ll n;
double dp[SIZE][SIZE], a[SIZE];

void solve()
{
    cin >> n;
    for (ll i =1; i <= n;i++){
        cin >> a[i];
    }

    dp[0][0] = 0;
    dp[1][1] = a[1];
    dp[0][1] = 1 - a[1];


    //ngua = a[i]
    //dp[i][j] : Xac suat co duoc i mat ngua xet den ptu j
    //dp[i][j] = dp[i-1][j-1]*a[j] + dp[i][j-1]*(1-a[j])
    for (ll i = 0; i <= n; i++){
        for (ll j = 2; j <= n; j++){
            if (i > j) continue;
            dp[i][j] = dp[i][j-1]*(1-a[j]);
            if (i != 0){
                dp[i][j] +=dp[i-1][j-1]*a[j];
            }
        }
    }
    double ans = 0.0;
    
    for (ll i = n/2 + 1; i <=n; i++){
        ans += dp[i][n];
    }

    cout << fixed << setprecision(9) << ans;
}

int main()
{
    
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}
