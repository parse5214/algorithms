#include<iostream>
#include<cstdlib>

void solve(){
    int n,a,b;
    std::cin>>n>>a>>b;
    if(a+b>n-2||abs(a-b)>1){
        std::cout<<-1<<"\n";
        return;
    }
    int odd=1;
    int even=2;
    int cnt=0;
    int mem=1;
    if(a==b){
        int nn=n;
        if(nn&1) nn--;
        int m=nn;
        while(m--){
            if(!(cnt&1)&&odd<=nn){
                std::cout<<odd<<" ";
                odd+=2;
            }else{
                std::cout<<even<<" ";
                even+=2;
            }
            cnt++;
            if(cnt==nn-1-a-b&&mem){
                cnt--;
                mem=0;
            }
        }
        if(n&1) std::cout<<n;
    }else if(a==b+1){
        int m=n;
        while(m--){
            if(cnt&1){
                std::cout<<even<<" ";
                even+=2;
            }else{
                std::cout<<odd<<" ";
                odd+=2;
            }
            cnt++;
            if(cnt==n-1-a-b&&mem){
                cnt--;
                mem=0;
            }
        }
    }else if(b==a+1){
        int m=n;
        while(m--){
            if(cnt&1){
                std::cout<<odd<<" ";
                odd+=2;
            }else{
                std::cout<<even<<" ";
                even+=2;
            }
            cnt++;
            if(cnt==a+b+1&&mem){
                cnt--;
                mem=0;
            }
        }
    }
    std::cout<<"\n";
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
