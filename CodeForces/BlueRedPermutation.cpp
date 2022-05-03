#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    std::string colors;
    std::cin>>colors;
    std::vector<int> blue;
    std::vector<int> red;
    blue.reserve(n);
    red.reserve(n);
    for(int i=0;i<n;i++){
        if(colors[i]=='B') blue.push_back(v[i]);
        else red.push_back(v[i]);
    }
    std::sort(blue.begin(),blue.end());
    std::sort(red.begin(),red.end());
    int szb=blue.size();
    int szr=red.size();
    for(int i=0;i<szb;i++){
        if(blue[i]<i+1){
            std::cout<<"NO\n";
            return;
        }
    }
    for(int i=0;i<szr;i++){
        if(red[i]>i+szb+1){
            std::cout<<"NO\n";
            return;
        }
    }
    std::cout<<"YES\n";
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
