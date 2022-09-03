class Solution {
public:
    int comb(int n,int k){
        if(n==0) return 1;
        long long ans=1;
        int m=min(k,n-k);
        for(int i=1;i<=m;i++){
            ans*=(n-i+1);
            ans/=i;
        }
        return static_cast<int>(ans);
    }
    vector<int> getRow(int idx) {
        vector<int> ans(idx+1);
        int mid=(idx+1)/2+(idx+1)%2;
        for(int j=0;j<mid;j++) ans[j]=comb(idx,j);
        for(int j=mid;j<idx+1;j++) ans[j]=ans[idx+1-j-1];
        return ans;
    }
};