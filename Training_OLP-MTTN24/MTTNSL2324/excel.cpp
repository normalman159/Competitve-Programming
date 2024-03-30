#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
ll m,n;
string s;
ll giai(ll l, ll r,vector<vector<ll>> &v){
    if (r-l+1==2){
        return v[s[r]-'0'][s[l] -'A' + 1];
    }
    ll cnt =0,pos=0;
    forsn(i,l+4,r-1){
        if (s[i]=='(') cnt++;
        if (s[i]==')') cnt--;
        if (cnt==0 && s[i]==','){
            pos = i;
            break;
        }
    }
    if (s[l]=='M') return max(giai(l+4,pos-1,v) ,giai(pos+1,r-1,v) );
    else return giai(l+4,pos-1,v) + giai(pos+1,r-1,v);
}

void solve(){
    cin >> m >> n;
    vector<vector<ll>> v(m+5,vector<ll>(n+5));
    for (ll i=1;i<=m;i++){
        for (ll j = 1;j<=n;j++){
            cin >> v[i][j];
        }
    }
    ll q; cin >> q;
    while (q--){
        cin >> s;
        cout << giai(0,s.size()-1,v) << ln;
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}