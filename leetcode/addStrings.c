
char * addStrings(char * num1, char * num2){
    int n = strlen(num1);
    int m = strlen(num2);
    int carr = 0;
    
    int p = (n > m ? n : m) + 1;
    
    char* str = (char*) malloc(sizeof(char)*(p+1));
    str[p] = '\0';
    
    while(n > 0 || m > 0 || carr > 0) {
        int a = (n < 1)? 0 : num1[n-1] - '0';
        int b = (m < 1)? 0 : num2[m-1] - '0';
        int num = a + b + carr;
        carr = num/10;
        num %= 10;
        str[p-1] = (char)(num + '0');
        n--;
        m--;
        p--;
    }
    
    return str + p;
}