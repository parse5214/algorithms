#include<iostream>
#include<vector>
#include<algorithm>

void solve(){
    int n;
    std::cin>>n;
    std::vector<bool> v(n+1);
    std::vector<int> v1,v2;
    v1.reserve(n);
    v2.reserve(n);
    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        if(a>n||v[a]) v1.push_back(a);
        else v[a]=true;
    }
    for(int i=1;i<n+1;i++){
        if(!v[i]) v2.push_back(i);
    }
    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());
    for(int i=0;i<v1.size();i++){
        if(((v1[i]&1)&&v2[i]>v1[i]/2)||(!(v1[i]&1)&&v2[i]>v1[i]/2-1)){
            std::cout<<-1<<"\n";
            return;
        }
    }
    std::cout<<v1.size()<<"\n";
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
