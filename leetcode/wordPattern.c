

bool wordPattern(char * pattern, char * s) {
    int patternSize = strlen(pattern);
    int cnt = 0;
    char** charToWord = (char**) calloc(26, sizeof(char*));
    
    char* token = strtok(s, " ");
    
    while(cnt < patternSize && token) {
        if(!charToWord[pattern[cnt]-'a']) charToWord[pattern[cnt]-'a'] = token;
        else if(strcmp(charToWord[pattern[cnt]-'a'], token)) return false;
        
        token = strtok(NULL, " ");
        cnt++;
    }
    
    if(cnt < patternSize || token) return false;
    
    for(int i = 0; i < 26; i++) {
        if(charToWord[i]) {
            for(int j = i + 1; j < 26; j++) {
                if(charToWord[j]) {
                    if(!strcmp(charToWord[i], charToWord[j])) return false;
                }
            }
        }
    }
    
    return true;
}