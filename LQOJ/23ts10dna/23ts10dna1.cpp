#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
ll l,r;
ll dp[20][73][1500];
bool nto[2003];
char t[20];
void sangnt(){
    for (ll i=1;i<=2000;i++) nto[i] = true;
    nto[1] = nto[0] = false;
    for (ll i=2;i*i<=2000;i++){
        if (nto[i] == true){
            for (ll j=i*i;j<=2000;j+=i) nto[j] = false;
        }
    }
}

ll thu(ll i, bool gh, ll tong, ll tongbp){
    if (i<0){
        if (nto[tong]==1 && nto[tongbp] ==1){
            return 1;
        }
        return 0;
    }
    if (gh == false && dp[i][tong][tongbp] >=0){
        return dp[i][tong][tongbp];
    }
    ll c = (gh==1) ? t[i] : 9;
    ll ans = 0;
    bool ghm;
    for (int j = 0;j<=c;j++){
        ghm = gh && (j==c);
        ans+=thu(i-1,ghm,tong+j,tongbp + j*j);
    }
    if (gh == false) dp[i][tong][tongbp] = ans;
    return ans;
}

ll tachso(ll x){
    t[0] = 0;
    ll i = 0;
    while (x != 0){
        t[i] = x%10;
        x/=10;
        i++;
    }
    return thu(i-1,true,0,0);
}

void solve(){
    sangnt();
    cin >> l >> r;
    memset(dp,-1,sizeof(dp));
    cout << tachso(r) - tachso(l-1);
}
int main()
{
    // freopen("ANHEM.INP", "r", stdin);
    // freopen("ANHEM.OUT","w",stdout);
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}