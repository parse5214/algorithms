typedef struct word {
  char sorted[256];
  char s[256];
  UT_hash_handle hh;
} hEl;

int cmp(const void* aa, const void* bb) {
  char a, b;
  a = *(char*) aa;
  b = *(char*) bb;

  if(a < b) return -1;
  else if(a > b) return 1;
  else return 0;
}

char* sortString(char *s) {
  char* rs = (char*) malloc(sizeof(char)*(strlen(s) + 1));
  assert(rs);
  strcpy(rs, s);
  qsort(rs, strlen(rs), sizeof(rs[0]), cmp);
  return rs;
}

int wordSort(hEl* a, hEl* b) {
  return strcmp(a->sorted, b->sorted);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
  hEl *w, *tmp;
  hEl *words = NULL;

  for(int i = 0; i < strsSize; i++) {
    char* sorted = sortString(strs[i]);
    w = (hEl*) malloc(sizeof *w);
    strncpy(w->sorted, sorted, 256);
    strncpy(w->s, strs[i], 256);
    HASH_ADD_STR(words, sorted, w);
    free(sorted);
  }

  char*** ans = (char***) malloc(strsSize * sizeof(char**));
  *returnColumnSizes = (int*) malloc(strsSize * sizeof(int));
  assert(*returnColumnSizes);
  assert(ans);

  *returnSize = -1;
  char* sortedWord = NULL;
  HASH_SORT(words, wordSort);
  HASH_ITER(hh, words, w, tmp) {
    if(sortedWord != NULL && strcmp(w->sorted, sortedWord) == 0) {
      ans[*returnSize][(*returnColumnSizes)[*returnSize]] = w->s;
      ((*returnColumnSizes)[*returnSize])++;
    } else {
      (*returnSize)++;
      ans[*returnSize] = (char**) malloc(strsSize * sizeof(char*));
      assert(ans[*returnSize]);
      (*returnColumnSizes)[*returnSize] = 0;
      ans[*returnSize][(*returnColumnSizes)[*returnSize]] = w->s;
      ((*returnColumnSizes)[*returnSize])++;
      sortedWord = w->sorted;
    }
  }

  (*returnSize)++;
  return ans;
}
