#include<iostream>

long long binarySearch(long long k,long long x){
    long long low=0;
    long long high=2*k;
    long long mid=(low+high)/2;
    long long sum=0;
    while(high>low){
        if(mid>k) sum=k*k-((2*k-mid-1)*(2*k-mid))/2;
        else sum=(mid*(mid+1))/2;
        if(sum>=x) high=mid;
        else low=mid+1;
        mid=(low+high)/2;
    }
    if(mid==2*k) return mid-1;
    return mid;
}

void solve(){
    long long k;long long x;
    std::cin>>k>>x;
    long long result=binarySearch(k,x);
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
