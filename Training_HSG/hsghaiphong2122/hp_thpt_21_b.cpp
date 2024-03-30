#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define ln "\n"
const ll INF = 1e18;

void fast_cin(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

const ll LimN = 1e5+5;
const ll LimA = 1e7 +5;
ll n,t,a[LimN], p[LimN];
bool nt[LimA],cnt[LimA];
map<ll,bool> mp;
vector<ll> snt;
void sangnt(){
    memset(nt,true,sizeof(nt));
    nt[0] = nt[1] = 0;
    for (ll i=2;i*i<=1e7;i++){
        if (nt[i]==true){
            for (ll j=i*i;j<=1e7;j+=i){
                nt[j] = false;
            }
        }
    }
}

bool checksieunt(ll x){
    string s = to_string(x);
    if (nt[x] == false) return false;
    bool flag2 = false;
    for (char z='0';z<='9';z++){
        string tmp = s;
        tmp+=z;
        ll tmp1 = stoll(tmp);
        if (nt[tmp1] == true){
            flag2 = true;
            break;
        }
    }
    if (flag2 == false) return false;
    x/=10;
    while (x>0){
        if (nt[x] == false) return false;
        x/=10;
    }
    return true;
}

bool checknt(ll n){
    for (ll i=2;i*i<=n;i++){
        if (n%i==0) return false;
    }
    return true;
}

int main(){
    fast_cin();
    freopen("input.INP","r",stdin);
    freopen("output.OUT","w",stdout);

    cin >> n;
    ll MA = -INF;
    for (ll i=1;i<=n;i++){ //ok
        cin >> a[i];
        MA = max(MA,a[i]);
    }
    sangnt(); //ok
//    queue<ll> dq;
//    dq.push(2); dq.push(3); dq.push(5); dq.push(7);
//    cnt[2] = cnt[3] = cnt[5] = cnt[7] = true;
//
//    while (true){
//        ll z = dq.front();
//        dq.pop();
//        bool flag = false;
//        for (ll z1 = z*10;z1<=z*10+9;z1++){
//            if (z1 <=1e7 && nt[z1]== true){
////                cout << z << " " << z1 << ln;
//                flag = true;
//                dq.push(z1);
//                //cnt[z1] = 1;
//                mp[z1] = true;
//            }
//        }
//        if (flag == false){
////            cout << z << ln;
//            mp[z] = false;
//        }
//        if (!(dq.back() <= 1e6)) break;
//    }

    for (ll i=1;i<=n;i++){ //ok
        p[i] = p[i-1];
        if (checksieunt(a[i]) == true) p[i]++;
    }

//    for (ll i =1;i<=n;i++){
//        cout << i << " " << p[i] << ln;
//    }
    cin >> t;
    while(t--){
        ll u,v; cin >> u >> v;
        cout << p[v] - p[u-1] << ln;
    }


    return 0;
}
