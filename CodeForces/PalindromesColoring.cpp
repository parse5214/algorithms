#include<iostream>
#include<vector>
#include<utility>
#include<string>

void solve(){
    int n,k;
    std::string str;
    std::cin>>n>>k;
    std::cin>>str;
    int fq[26]={};
    for(int i=0;i<n;i++){
        fq[str[i]-'a']++;
    }
    int nOdds=0;
    for(int i=0;i<26;i++){
        if(fq[i]&1) nOdds++;
    }
    int nAv=n-nOdds;
    nAv/=2;
    int result=0;
    if(nAv>=k){
        int res=nAv%k;
        int quot=nAv/k;
        if(nOdds+res*2>=k){
            result=2*quot+1;
        }else{
            result=2*quot;
        }
    }else{
        result=1;
    }
    std::cout<<result<<"\n";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
