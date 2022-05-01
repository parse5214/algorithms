#include<iostream>
#include<utility>
#include<cstring>
#include<vector>

const int nMax=1e6;
bool isPrime[nMax+1]={};

void prec(){
    std::memset(isPrime,true,sizeof isPrime);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i*i<=nMax;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=nMax;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

void solve(){
    int n,e;
    std::cin>>n>>e;
    std::vector<std::pair<int,bool>> a(n);
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        a[i].first=x;
        a[i].second=false;
    }
    long long sum=0;
    std::vector<int> vec;
    for(int i=0;i<n;i++){
        int mem=1;
        int cnt=0;
        int j=i;
        if(!a[j].second&&(isPrime[a[j].first]||a[j].first==1)){
            while(j<n){
                a[j].second=true;
                if(isPrime[a[j].first]){
                    vec.push_back(cnt);
                    cnt=0;
                }else if(a[j].first==1){
                    cnt++;
                }else{
                    vec.push_back(cnt);
                    mem=0;
                    break;
                }
                j+=e;
            }
            if(mem) vec.push_back(cnt);
        }else continue;
        int sz=vec.size();
        for(int k=0;k<sz-1;k++){
            sum+=static_cast<long long>(vec[k])*(vec[k+1]+1)+vec[k+1];
        }
        vec.clear();
    }
    std::cout<<sum<<"\n";
}

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
