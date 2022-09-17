
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

char * gcdOfStrings(char * str1, char * str2){
    
    int m = strlen(str1);
    int n = strlen(str2);
    
    char* str3 = (char*) malloc(sizeof(char)*(m + n + 1));
    char* str4 = (char*) malloc(sizeof(char)*(m + n + 1));
    
    sprintf(str3, "%s%s", str1, str2);
    sprintf(str4, "%s%s", str2, str1);
    
    if(!(strcmp(str3, str4) == 0)) {
        char* ans = (char*) malloc(sizeof(char));
        ans[0] = '\0';
        return ans;
    }else {
        int val = gcd(m, n);
        char* ans = (char*) malloc(sizeof(char)*(val + 1));
        ans[val] = '\0';
        for(int i = 0; i < val; i++) ans[i] = str1[i];
        return ans;
    }
}