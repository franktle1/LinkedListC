#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct node{
        int listIndex;
        char text[255];
        struct node *next;

    } *head, *tail;
    head = tail = NULL; //sets head and tail to null

    char usrcmd[4];
    char *userin; //I've got to find a way to parse it in the scan function.
    int index;
    int counter = 0; //ill use this to keep track of the index


    userin = (char*)malloc(sizeof(char)*255);
    printf("Command: \n");
    fflush(stdout);
    scanf("%s",usrcmd);
    if(strcmp("end",usrcmd)== 0){
        free(userin);
        exit(1);
    }
    scanf("%d%s",&index,userin);





    while(strcmp("end",usrcmd)!= 0){
        //functions go here
        printf("the index: %d\nthe text: %s\n", index, userin);
        fflush(stdout);
        scanf("%s",usrcmd);
        if(strcmp("end",usrcmd)== 0){ //exits immediately after entering end by itself
            free(userin);
            exit(1);}
        scanf("%d%s",&index,userin);
    }


    free(userin);
    return 0;
}




/*

DON'T FORGET THE PROTOTYPES!


void insertAfter(int x, char *strArr){


}


void insertBefore(int x, char *strArr){

}

void delete(int x){

}

void printList(struct node *h){
    if (h==NULL)
        printf("List is empty.\n");
    else{
        printf("The list is:\n");
        while (h!= NULL){
            printf("Item %d : %s\n", h->listIndex, h->text);
            h = h->next;}
        }//else
} //end of print

struct node *search_list(struct node *h, char * strText){ //used in conjunction with delete command
    while (h != NULL){
        if(strcmp(h->text,strText) == 0){
            return h;
        }//if
        h = h->next;
    }//while

    return NULL; //if it finds nothing
}//search




*/

