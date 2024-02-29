#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ln " \n"
const ll INF = 1e18;
const ll LimN = 1e3+5;
const ll MX = 1e7 + 5;
ll n,a[LimN],m, p[LimN];
bool nt[MX];

void sangnt(){
    memset(nt,true,sizeof(nt));
    nt[0] = nt[1] = 0;
    for (ll i=2;i*i<=1e7;i++){
        if (nt[i]){
            for (ll j=i*i;j<=1e7;j+=i){
                nt[j] = false;
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<=n;i++){ //ok
        p[i] = p[i-1] + a[i];
    }
    //kiem tra so nguyen to 1e7
    sangnt();
    while (m--){
        ll u,v;
        cin >> u >> v;
        ll sum = p[v] - p[u-1];
        if (sum <=0){
            cout << 0 << ln;
        }
        else if (nt[sum]) cout << 1 << ln;
        else cout << 0 << ln;
    }

    return 0;
}
