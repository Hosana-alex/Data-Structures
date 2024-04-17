#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL;


void insert(int value){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node -> data = value;
    new_node -> next = NULL;
    struct Node *current = NULL;

    
    if(front == NULL){
        front = new_node;
    }else{
        current = front;
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = new_node;
    }    
}

void traverse(){
    struct Node *current = NULL;

    if(front == NULL){
        printf("Empty linked lists");
    }else{
        current = front;
        while(current != NULL){
            printf("%d, ", current -> data);
            current = current -> next;
        }
    }
    printf("\n");
} 

void search(int value){
    struct Node *current = NULL;

    if(front == NULL){
        printf("Empty linked list\n");
    }else{
        current = front;

        while(current != NULL){
            if(current -> data == value){
                printf("Value found\n");
                break;
            }
            current = current -> next;
        }
        if(current == NULL){
            printf("value not found\n");
        }
    }
}

void delete_value(int value){
    struct Node *current = NULL;
    struct Node *previous = NULL;

    if(front == NULL){
        printf("Empty list\n");
    }else if (front -> data == value){
        current = front;

        front = front -> next;
        free(current);
        printf("Node deleted\n");

    }else{
        current = front;
        previous = current;
        current = current -> next;

        while (current != NULL){
            if(current -> data == value){
                previous -> next = current -> next;
                free(current);
                printf("Node deleted\n");
                break;

            }else{
                previous = current;
                current = current -> next;
            }
        }
        if (current == NULL){
            printf("Node not deleted\n");
        }
        
    }
}

void reverse_list(){
    struct Node *previous = NULL;
    struct Node *current = front;
    struct Node *next_node = NULL;

    while (current != NULL){
        next_node = current -> next;
        current -> next = previous;
        previous = current;
        current = next_node;
    }
    front = previous;
      
}

int main(){
    insert(5);
    delete_value(5);
    traverse();
    insert(25);
    
    insert(20);
    insert(30);
    search(5);
    traverse();
    reverse_list();
    traverse();

    return 0;
}