#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define DEBUG  
  
#ifdef DEBUG  
#define debug(...) printf( __VA_ARGS__)   
#else  
#define debug(...)  
#endif

int max = 0;

struct trie_node {
    struct trie_node* child[256];
    int count;
};

struct trie_node* init_trie_node(){
    return (struct trie_node* )calloc(1, sizeof(struct trie_node));
}

void insert_trie_node(struct trie_node* root, char* line){
    struct trie_node* node = root;
    char* p;

    debug("insert line %s \n", line);
    for (p = line; *p; ++p ){
        debug("insert %c...\n", *p);
        if (node->child[*p] == 0){
            debug("create node");
            node->child[*p] =  (struct trie_node*)calloc(1, sizeof(struct trie_node));
        }else{
            debug("has node ...");
        }
        node = node->child[*p];
    }
    node->count++;
    debug("%s has %d\n", line, node->count);
}

void dfs_travel(struct trie_node* root){
    static int pos;
    static char worddump[32];
    if (root->count){
        worddump[pos] = '\0';
        if (worddump[0])
            printf("%s %.4f\n", worddump, (root->count * 100.0 )/max);
    }
    for (int i = 0; i < 256; ++i){
        struct trie_node* p;
        p = root->child[i];
        if (!p)
            continue;
        debug("word %c\n", i);
        worddump[pos++] = i;
        dfs_travel(p);
        pos--;
    }
}

int main()
{
    char line[32];
    struct trie_node* root = init_trie_node();
    while(gets(line) && strlen(line)>0){
        insert_trie_node(root, line);
        max++;
    }
    dfs_travel(root);

    return 0;
}
