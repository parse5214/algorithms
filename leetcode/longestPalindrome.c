

int longestPalindrome(char * s){
    int n = strlen(s);
    
    int a[26] = {0};
    int b[26] = {0};
    
    for(int i = 0; i < n; i++) {
        if(islower(s[i])) a[s[i] - 'a']++;
        else b[s[i] - 'A']++;
    }
    
    int ans = 0;
    bool flag = false;
    
    for(int i = 0; i < 26; i++) {
        if(!(a[i]&1)) ans += a[i];
        else {
            ans += a[i] - 1;
            flag = true;
        }
        
        if(!(b[i]&1)) ans += b[i];
        else {
            ans += b[i] - 1;
            flag = true;
        }
    }
    
    if(flag) ans++;
    
    return ans;
}