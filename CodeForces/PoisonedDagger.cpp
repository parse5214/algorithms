#include<iostream>
#include<vector>

// Operator overloads

template<typename T>
std::istream& operator>>(std::istream& istream,std::vector<T>& v){
    for(auto& it:v) std::cin>>it;
    return istream;
}

long long binarySearch(std::vector<long long>& diff,long long h){
    long long low=0;
    long long high=h;
    long long mid=(low+high)/2;
    int sz=diff.size();
    while(high>low){
        long long sum=0;
        for(int i=0;i<sz;i++){
            if(mid<diff[i]) sum+=mid;
            else sum+=diff[i];
        }
        if(sum>=h) high=mid;
        else low=mid+1;
        mid=(low+high)/2;
    }
    return mid;
}

void solve(){
    int n;
    long long h;
    std::cin>>n>>h;
    std::vector<int> a(n);
    std::cin>>a;
    std::vector<long long> diff(n);
    for(int i=0;i<n;i++){
        if(i==n-1) diff[i]=h;
        else diff[i]=a[i+1]-a[i];
    }
    long long k=binarySearch(diff,h);
    std::cout<<k<<"\n";
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
