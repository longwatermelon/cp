#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
template <typename T> T cdiv(T a, T b) {return a/b+(sig(a)/sig(b)==1 && a%b);}
template <typename T> T fdiv(T a, T b) {return a/b-(sig(a)/sig(b)==-1 && a%b);}
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
template <typename T> T rmod(T a, T mn, T mx) {return mod((a-mn),(mx-mn+1))+mn;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
void yn(bool ans) {puts(ans?"yes":"no");}
template <typename T> using vec=vector<T>;
template <typename T> struct vec2:vector<vector<T>> {vec2()=default;vec2(int n, int m, T val=T()):vector<vector<T>>(n,vector<T>(m,val)){}};
template <typename T> struct vec3:vector<vector<vector<T>>> {vec3()=default;vec3(int n, int m, int k, T val=T()):vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T>(k,val))){}};
#define PTX x
#define PTY y
struct pt_t {int PTX,PTY;bool operator==(pt_t pt2)const{return PTX==pt2.PTX&&PTY==pt2.PTY;}};
int MD=1e9+7;
ll modpow(ll x, ll p) {assert(p>=0);return p==0?1:((ll)modpow(((ll)x*x)%MD,p/2)*(p&1?x:1))%MD;}
ll modinv(ll x) {return modpow(x,MD-2);}
ll rencr(int n,int r){if(n<r)return 0;else if(r==0||r==n) return 1;else return(rencr(n-1,r-1)+rencr(n-1,r))%MD;}
vec<int> F,IF; // fac, inv fac
void genfac(int mx) {F=vec<int>(mx+1);IF=vec<int>(mx+1);F[0]=1;IF[0]=modinv(1);for(int x=1;x<=mx;++x){F[x]=((ll)F[x-1]*x)%MD;IF[x]=modinv(F[x]);}}
ll clncr(int n,int r){if(n<r)return 0;return(((ll)F[n]*IF[r])%MD*IF[n-r])%MD;}
ll logfl(ll base, ll x) {assert(base>1);ll res=0, val=1;while (val*base<=x){val*=base;res++;}return res;}
ll logcl(ll base, ll x) {assert(base>1);ll res=0, val=1;while (val<x){val*=base;res++;}return res;}
ll sqrtfl(ll x) {ll rt=sqrtl(x);if (rt*rt>x) rt--;if ((rt+1)*(rt+1)<=x) rt++;return rt;}
ll sqrtcl(ll x) {ll rt=sqrtl(x);if (rt*rt<x) rt++;if ((rt-1)*(rt-1)>=x) rt--;return rt;}

void solve() {
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _; cin>>_;
    while (_--) {
        solve();
    }
}
