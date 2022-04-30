#include<iostream>
#include<algorithm>

const int nMax=2e5;
int dp[nMax+1][18]={};
void prec();
void solve();

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    prec();
    int t;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

void prec(){
    for(int i=0;i<18;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<nMax+1;i++){
        int j=17;
        int x=i;
        while(x>0){
            dp[i][j]=x%2+dp[i-1][j];
            x/=2;
            j--;
        }
    }
}

void solve(){
    int l,r;
    std::cin>>l>>r;
    int m=0;
    for(int i=0;i<18;i++){
        m=std::max(m,dp[r][i]-dp[l-1][i]);
    }
    std::cout<<r-l+1-m<<"\n";
}
