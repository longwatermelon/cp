#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
template <typename T> T cdiv(T a, T b) {return a/b+(a/b>=0 && a%b!=0);}
template <typename T> T fdiv(T a, T b) {return a/b-(a/b<0 && a%b!=0);}
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
#define PTX x
#define PTY y
struct pt_t {int PTX,PTY;bool operator<(pt_t b)const{return PTX==b.PTX?PTY<b.PTY:PTX<b.PTX;}bool operator==(pt_t b)const{return PTX==b.PTX&&PTY==b.PTY;}};
vector<int> genord(int len) {vector<int> ord(len+1);for(int i=1;i<=len;++i)ord[i]=i;return ord;}

void solve() {
}

int main() {
    int _; cin>>_;
    while (_--) {
        solve();
    }
}
