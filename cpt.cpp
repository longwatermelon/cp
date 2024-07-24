#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
template <typename T> T cdiv(T a, T b) {return a/b+(sig(a)/sig(b)==1 && a%b);}
template <typename T> T fdiv(T a, T b) {return a/b-(sig(a)/sig(b)==-1 && a%b);}
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
template <typename T> T mod1(T a, T b) {return (a-1)%b+1;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
#define PTX x
#define PTY y
struct pt_t {int PTX,PTY;bool operator<(pt_t pt2)const{return PTX==pt2.PTX?PTY<pt2.PTY:PTX<pt2.PTX;}bool operator==(pt_t pt2)const{return PTX==pt2.PTX&&PTY==pt2.PTY;}bool operator>(pt_t pt2)const{return !(*this<pt2||*this==pt2);}};
template <typename T> vector<int> genord(int len, T cmp) {vector<int> ord(len+1);for(int i=1;i<=len;++i)ord[i]=i;sort(begin(ord)+1,end(ord),cmp);return ord;}
int M=1e9+7;
int modpow(int x, ll p) {assert(p>=0);return p==0 ? 1 : ((ll)modpow(((ll)x*x)%M,p/2)*(p&1?x:1))%M;}
int modinv(int x) {return modpow(x,M-2);}
template <typename T> map<T,int> primefac(T x) {map<T,int> mp;for(T i=2;i*i<=x;++i){while(x%i==0){mp[i]++;x/=i;}}if(x>1)mp[x]++;return mp;}
void sieveofe(int mx, bool *prime) {prime[1]=false;fill(prime+2,prime+1+mx,true);for(int i=2;i*i<=mx;++i){int j=i;while(i*j<mx){prime[i*j]=false;++j;}}}
// not ordered
template <typename T> vector<T> factor(T x) {vector<T>f;for(T i=1;i*i<=x;++i){if(x%i==0){f.push_back(i);if (x/i!=i)f.push_back(x/i);}}return f;}
void yn(bool ans) {puts(ans?"yes":"no");}

void solve() {
}

int main() {
}
