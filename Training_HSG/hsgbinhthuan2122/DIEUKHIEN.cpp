#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimM = 5e4+5;
const ll LimN = 20;
const ll LimS = 1e6+5;
ll m,n,s, t[LimS];
struct thongtin{
    ll xanh,tat;
};
thongtin col[LimM], row[LimN];
vector<vector<ll>> a;
//row: hang
//col: cot
ll sub1(){
    for (ll i = s;i>=1;i--){
        if (t[i] <m) break;
        ll k = t[i]-m;
        for(ll j = 1;j<=m;j++){
            a[j][k]++;
            a[j][k]%=3;
        }
    }
    for (ll i=1;i<=m;i++){
        for (ll j = 1;j<=n;j++){
            if (a[i][j]==0){
                row[i].tat++;
            }
            if (a[i][j] == 1) row[i].xanh++;
        }
    }
    ll res=0;
    for (ll i = s;i>=1;s--){
        if (t[i] > m) break;
        ll k = t[i];
        ll xanh = row[k].xanh, tat = row[k].tat;
        ll red = n - xanh - tat;
        row[k].xanh = tat;
        row[k].tat = red;
    }
    for (ll i = 1;i<=m;i++){
        res+=row[i].tat;
    }
    return res;
}

//duyet hang
ll sub2(){
    for (ll i=s;i>=1;i--){
        if (t[i] > m) break;
        ll k = t[i];
        for (ll j = 1;j<=n;j++){
            a[k][j]++;
            a[k][j]%=3;
        }
    }
    for (ll i=1;i<=m;i++){
        for (ll j = 1;j<=n;j++){
            if (a[i][j]==1){
                col[j].xanh++;
            }
            if (a[i][j]==0) col[j].tat++;
        }
    }
    for (ll i = s;i>=1;i--){
        if (t[i] <=m) break;
        ll k = t[i] - m;
        ll xanh = col[k].xanh, tat = col[k].tat;
        ll red = n - xanh - tat;
        col[k].xanh = tat;
        col[k].tat = red;    
    }
    ll res = 0;
    for (ll i=1;i<=m;i++){
        res+=col[i].tat;
    }
    return res;
}

void solve(){
    cin >> m >> n >> s;
    a.resize(m+5);
    for (ll i=1;i<=m;i++){
        a[i].resize(n+5);
        for (ll j = 1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for (ll i=1;i<=s;i++) cin >> t[i];
    if (m <=20 && n <=50000){
        cout << sub1();
    }
    else{
        cout << sub2();
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}