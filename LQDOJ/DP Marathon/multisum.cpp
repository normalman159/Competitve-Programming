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
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

//DP Digit
ll d,ch=0;
char t[10005];
string k;
ll f[10005][105];
ll thu(ll i, bool gh, ll sum){
    if (i < 0){
        if (sum ==0){
            return 1;
        }
        else return 0;
    }
    if (gh == false && f[i][sum] >=0){
        return f[i][sum];
    }
    ll maxc = (gh) ? t[i] : 9;
    bool ghm;
    ll ans = 0;
    for (ll c = 0; c<=maxc;c++){
        ghm = gh && (c==maxc);
        ans+=thu(i-1,ghm,(sum+c)%d);
    }
    ans%=MOD;
    if (gh== false){
        f[i][sum] = ans;
    } 
    return ans;
}

ll tach(string s){
    ll n = s.size();
    ll sum=0;
    for (ll i = 0;i<n;i++){
        t[n-i-1] = s[i] - '0';
    }    
    for (ll i=0;i<n;i++){
        sum+=t[i];
    }
    if (sum%d==0) {
        ch = 1;
    }
    return thu(n-1,true,0);
}

void solve(){
    cin >> k >> d;
    string u = "1";
    memset(f,-1,sizeof(f));
    cout << tach(k) - ch - tach(u);
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}