#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

// Operator overloads
template<typename T> // cin>>vector<T>
std::istream& operator>>(std::istream& istream,std::vector<T>& v){
    for(auto& it:v) std::cin>>it;
    return istream;
}

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n);
    std::cin>>a;
    std::sort(a.begin(),a.end());
    std::unordered_map<int,int> fq;
    for(int i=n-1;i>=n-2*k;i--)fq[a[i]]++;
    int maxfq=0;
    for(auto& it:fq){
        if(maxfq<it.second) maxfq=it.second;
    }
    int num=maxfq-k;
    int sum=0;
    if(num>0) sum+=num;
    for(int i=0;i<n-2*k;i++){
        sum+=a[i];
    }
    std::cout<<sum<<"\n";
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
