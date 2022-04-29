#include<iostream>
#include<string>

void solve(){
    std::string str1,str2;
    std::cin>>str1>>str2;
    int sz1=str1.size();
    int sz2=str2.size();
    std::string str3="";
    int j=sz1-1;
    for(int i=sz2-1;i>=0;i--){
        char nums;
        if(j>=0) nums=str1[j];
        else nums='0';
        if(str2[i]>=nums){
            str3=std::to_string(str2[i]-nums)+str3;
            j--;
        }else if(i!=0){
            int num1=str2[i]-'0';
            int num2=str2[i-1]-'0';
            int num3=num2*10+num1;
            int num4=nums-'0';
            int num5=num3-num4;
            if(num5>9||num5<0){
                std::cout<<-1<<"\n";
                return;
            }
            str3=std::to_string(num5)+str3;
            i--;
            j--;
        }else{
            std::cout<<-1<<"\n";
            return;
        }
    }
    if(j>-1){
        std::cout<<-1<<"\n";
        return;
    }else{
        int cnt=0;
        for(char c:str3){
            if(c=='0') cnt++;
            else break;
        }
        str3=str3.substr(cnt);
        std::cout<<str3<<"\n";
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
