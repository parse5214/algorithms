
#define HASHTABLE_SIZE 769

struct HashNode {
    int key;
    int val;
    struct HashNode* next;
};

typedef struct {
    
    struct HashNode ** hash_arr;
    
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*) malloc(sizeof(MyHashMap));
    
    obj->hash_arr = (struct HashNode**) malloc(sizeof(struct HashNode*) * HASHTABLE_SIZE);
    
    for(int i = 0; i < HASHTABLE_SIZE; i++) {
        obj->hash_arr[i] = NULL;
    }
    
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int bucket = key % HASHTABLE_SIZE;
    
    if(obj->hash_arr[bucket] == NULL) {
        struct HashNode* newNode = (struct HashNode*) malloc(sizeof(struct HashNode));
        newNode->key = key;
        newNode->val = value;
        newNode->next = NULL;
        obj->hash_arr[bucket] = newNode;
        return;
    }
    
    struct HashNode* prev = NULL;
    struct HashNode* tmp = obj->hash_arr[bucket];
    
    while(tmp != NULL) {
        if(tmp->key == key) {
            tmp->val = value;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    
    struct HashNode* newNode = (struct HashNode*) malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->val = value;
    newNode->next = NULL;
    prev->next = newNode;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int bucket = key % HASHTABLE_SIZE;
    
    struct HashNode* tmp = obj->hash_arr[bucket];
    while(tmp != NULL) {
        if(tmp->key == key) return tmp->val;
        tmp = tmp->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int bucket = key % HASHTABLE_SIZE;
    
    struct HashNode* prev = NULL;
    struct HashNode* tmp = obj->hash_arr[bucket];
    
    while(tmp != NULL) {
        if(tmp->key == key) {
            struct HashNode* toRemove = tmp;
            tmp = tmp->next;
            if(prev) prev->next = tmp;
            else obj->hash_arr[bucket] = tmp;
            free(toRemove);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for(int i=0; i<HASHTABLE_SIZE; i++) {
        struct HashNode* tmp = obj->hash_arr[i];
        while(tmp != NULL) {
            struct HashNode* toRemove = tmp;
            tmp = tmp->next;
            free(toRemove);
        }
    }
    free(obj->hash_arr);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/