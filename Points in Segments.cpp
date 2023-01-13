#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int Case;
void ac(){
    int n,q;    scanf("%lld%lld", &n, &q);
    int a[n+2],i;
    for(i=0; i<n; i++)  scanf("%lld", &a[i]);
    printf("Case %lld:\n",++Case);
    while(q--){
        int l,r;    scanf("%lld%lld", &l, &r);
        int lb,ub;
        ub=upper_bound(a, a+n, r)-a;
        lb=lower_bound(a, a+n, l)-a;
        printf("%lld\n",ub-lb);

    }
}
signed main(){
    int tc;     scanf("%lld", &tc);
    while(tc--){
        ac();
    }
    return 0;
}
