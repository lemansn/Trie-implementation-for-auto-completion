#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc, char **argv) {
        (void) argc;
    char *prog_name = *argv++;
    char *config_file = *argv++;

    TrieNode *root = make_trie('\0');
    char word[50];
    FILE *name;
    char str1[] = "exit";
    char girdi[50];
    name = fopen( "/test-files/dict.txt", "r" );


    if (name == NULL) {
        fprintf(stderr, "ERROR: config file is required\n"
                        "  usage: %s \n", prog_name);
        exit(1);
    }

        while(fscanf(name, "%25s\n", word)==1){
        root = insert(root, word);
    }

    fclose(name);
    setbuf(stdout, NULL);
    printf("%s\n","Press exit to quit program:");
    scanf("%s", girdi);

    while (strcmp(str1, girdi) != 0) {
        search_prefix(root,girdi);

            scanf("%s", girdi);
    }
        return 0;

    }








