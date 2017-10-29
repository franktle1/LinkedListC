#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
        int listIndex;
        char text[255];
        struct node *next;

    };


int main()
{
    void insert_node_after(struct node**, struct node**, struct node**, int, char*);

    struct node *head, *tail, *root;

    root = head = tail = NULL; //sets head and tail to null

    char usrcmd[4];
    char *userin; //I've got to find a way to parse it in the scan function.
    int index;
    int counter = 0; //ill use this to keep track of the index


    userin = (char*)malloc(sizeof(char)*255);
    printf("Command: \n");
    fflush(stdout);
    scanf("%s",usrcmd);
    if(strcmp("end",usrcmd)== 0){
        printf("Good bye!");
        fflush(stdout);
        free(userin);
        exit(1);
    }
    scanf("%d%s",&index,userin);





    while(strcmp("end",usrcmd)!= 0){
        //functions go here
        if(strcmp("ina",usrcmd) == 0){
            insert_node_after(&root,&head,&tail,index, userin);

            printf("Insert after\n");

        }
        else if(strcmp("inb",usrcmd) == 0){
            printf("Insert before\n");
        }
        else if(strcmp("del",usrcmd) == 0){
            printf("deleted!! woo\n");
        }
        else if(strcmp("rep",usrcmd) == 0){
            printf("replaced!! woo\n");
        }
        else if(strcmp("prn",usrcmd) == 0){
            printf("printed! woo\n");
        }
        else{
            printf("Please enter an appropriate command:\nOptions:[ina] [inb] [del] [rep] [prn] [end]\n");
        }


        printf("Command: ");
        fflush(stdout);
        scanf("%s",usrcmd);
        if(strcmp("end",usrcmd)== 0){ //exits immediately after entering end by itself
            printf("Good bye!");
            fflush(stdout);
            free(userin);
            exit(1);}
        scanf("%d%s",&index,userin);
    }//end of while


    free(userin);
    printf("Good bye!");
    fflush(stdout);

    return 0;
}

void insert_node_after (struct node **root, struct node **h, struct node **t, int x, char* strArr) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    if(newNode == NULL){
        printf("Node allocation failed.\n");
        exit(1);}

    strcpy(newNode->text,strArr); //copies the entered string into newNode text member
    if(*h==NULL){ //if head points to null and list is empty
        *root = *h = *t = newNode;
        newNode->listIndex = 1; //first node has index of one
    }

    else{
        struct node *curr = NULL; //i may need to allocate memory for curr
        curr = *root; //curr will traverse the list
        while(curr != NULL){
            if(curr->listIndex == x && curr == *t){ //this should take care of sizeof 1 lists, and tail cases
                (*t)->next = newNode; //sets tail's next pointer pointing to the new Node
                (*t) = newNode; //sets tail pointing to the newNode
                newNode->listIndex = (++x);

            }
            else if(curr->listIndex == x && curr != *t){ //middle of the list
                newNode->next = curr->next;
                curr->next = newNode;
                newNode->listIndex = (++x);
                                //find a way to increment the rest of the list
                while(curr != NULL){ //traverse the rest of the list and increase the list index for each node
                    curr = curr->next;
                    ++(curr->listIndex);
                }//while
            }//elseif
            if (curr!=NULL)
                curr = curr->next;              //traverse the list

            /*else{ //end of the list
                *curr->next = newNode;
                *t = newNode;
                newNode->listIndex = (++x);
            }
 /*
        struct node **curr = NULL;
        *curr = *root; //curr will traverse the list
        while(*curr != NULL){
            if((*curr->listIndex) == x &&((*curr->listIndex) == *t->listIndex)){ //this should take care of sizeof 1 lists, and tail cases
                *t = newNode;
                *curr->next = newNode;
                newNode->listIndex = (++x);

            }
            else if((*curr->listIndex) == x && (*curr->listIndex != *t->listIndex)){ //middle of the list
                newNode->next = *curr->next;
                *curr->next = newNode;
                newNode->listIndex = (++x);


            }
            *curr = *curr->next;
*/
//
            /*else{ //end of the list
                *curr->next = newNode;
                *t = newNode;
                newNode->listIndex = (++x);
            }
            */
             //this increments the index of

                  /*
    The list exists:

    Case 1:
        When there's just one node, change pointer have pointer point to tail
    Case 2:
        When inserting into the middle of the list (more than one)
        traverse list (while *curr != NULL) {if((x) == (*curr->listIndex)) set newNode point to *curr->next, set }
    Case 3:
        else
        When inserting at the end, where x ==(*t->listIndex), set newNode->*next = NULL and *curr->next = newNode
    */
        }//WHILE



    }//ELSE





}//INSERT AFTER



//passes pointers to the head pointer, pointers to the tail pointer, the index, and the string
/*
void incrementIndex(){
    counter++;
}
*/


/*

DON'T FORGET THE PROTOTYPES!





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

