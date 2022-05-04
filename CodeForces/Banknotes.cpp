#include<iostream>
#include<vector>

int power(int a,int b){
    int result=1;
    while(b>0){
        if(b&1) result*=a;
        a*=a;
        b/=2;
    }
    return result;
}

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n);
    for(int i=0;i<n;i++) std::cin>>a[i];
    if(n==1){
        std::cout<<static_cast<long long>(k+1)*power(10,a[0])<<"\n";
        return;
    }
    int sum=power(10,a[1]-a[0])-1;
    int m=k+1;
    long long num=0;
    for(int i=0;i<n-1;i++){
        if(m>sum){
            if(i==n-2){
                num+=power(10,a[i+1])-power(10,a[i]);
                num+=static_cast<long long>(m-sum)*power(10,a[i+1]);
                std::cout<<num<<"\n";
                return;
            }else{
                num+=power(10,a[i+1])-power(10,a[i]);
                sum+=power(10,a[i+2]-a[i+1])-1;
            }
        }else if(m==sum){
            num+=power(10,a[i+1])-power(10,a[i]);
            std::cout<<num<<"\n";
            return;
        }else{
            sum-=power(10,a[i+1]-a[i])-1;
            num+=static_cast<long long>(m-sum)*power(10,a[i]);
            std::cout<<num<<"\n";
            return;
        }
    }
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
