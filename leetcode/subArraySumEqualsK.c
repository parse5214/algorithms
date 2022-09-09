#define HASHTABLE_SIZE 769

struct HashNode {
    
    int key;
    int val;
    struct HashNode* next;
    
};

typedef struct HashMap {
    
    struct HashNode** hash_arr;
    
} MyHashMap;

MyHashMap* myHashMapCreate() {
    
    MyHashMap* obj = (MyHashMap*) malloc(sizeof(MyHashMap));
    
    obj->hash_arr = (struct HashNode**) malloc(sizeof(struct HashNode*)*HASHTABLE_SIZE);
    
    for(int i = 0; i < HASHTABLE_SIZE; i++) {
        obj->hash_arr[i] = NULL;
    }
    
    return obj;
    
}

void myHashMapPut(MyHashMap* obj, int key, int val) {
    int bucket = ((key % HASHTABLE_SIZE) + HASHTABLE_SIZE) % HASHTABLE_SIZE;
    
    if(obj->hash_arr[bucket] == NULL) {
        struct HashNode* tmp = (struct HashNode*) malloc(sizeof(struct HashNode));
        tmp->key = key;
        tmp->val = val;
        tmp->next = NULL;
        obj->hash_arr[bucket] = tmp;    
        return;
    }
    
    struct HashNode* prev = NULL;
    struct HashNode* tmp = obj->hash_arr[bucket];
    
    
    while(tmp != NULL) {
        if(tmp->key == key) {
            tmp->val = val;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    
    struct HashNode* newNode = (struct HashNode*) malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->val = val;
    newNode->next = NULL;
    prev->next = newNode;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int bucket = ((key % HASHTABLE_SIZE) + HASHTABLE_SIZE) % HASHTABLE_SIZE;
    
    struct HashNode* tmp = obj->hash_arr[bucket];

    while(tmp != NULL) {
        if(tmp->key == key) return tmp->val;
        tmp = tmp->next;
    }
    
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int bucket = ((key % HASHTABLE_SIZE) + HASHTABLE_SIZE) % HASHTABLE_SIZE;
    
    struct HashNode* prev = NULL;
    struct HashNode* tmp = obj->hash_arr[bucket];
    
    while(tmp != NULL) {
        if(tmp->key == key) {
            struct HashNode* to_remove = tmp;
            tmp = tmp->next;
            if(prev) prev->next = tmp;
            else obj->hash_arr[bucket] = tmp;
            free(to_remove);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for(int i = 0; i < HASHTABLE_SIZE; i++) {
        struct HashNode* tmp = obj->hash_arr[i];
        while(tmp != NULL) {
            struct HashNode* to_remove = tmp;
            tmp = tmp->next;
            free(to_remove);
        }
    }
    free(obj->hash_arr);
    free(obj);
}

int subarraySum(int* nums, int numsSize, int k){
    
    MyHashMap* myMap = myHashMapCreate();
    
    int ans = 0;
    int sum = 0;
    
    myHashMapPut(myMap, sum, 1);
    
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int find = sum - k;
        if(myHashMapGet(myMap, find) != -1) ans += myHashMapGet(myMap, find);

        if(myHashMapGet(myMap, sum) == -1) myHashMapPut(myMap, sum, 1);
        else myHashMapPut(myMap, sum, myHashMapGet(myMap, sum) + 1);
    }
    
    myHashMapFree(myMap);
    
    return ans;
}