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
 
void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+5);
    forsn(i,1,n){
        cin >> a[i];
    }
    ll res =0;
    while (true){
        ll cnt = 0;
        ll sum =0;
        forsn(i,1,n){
            if (m >= a[i]){
                cnt++;
                sum+=a[i];
                m-=a[i];
            }
        }
        if (cnt==0){
            cout << 0;
            return;
        }
        res += (cnt + 1.0 * (sum)/m);
        m%=sum;
    }
    cout << res;
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}