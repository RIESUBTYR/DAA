#include<studio.h>
struct Node { 
    int data; 
    struct Node* next; // Pointer to next node in DLL 
    struct Node* prev; // Pointer to previous node in DLL 
};

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
  
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
  
    (*head_ref) = new_node; 
}

void insertAfter(struct Node* prev_node, int new_data) 
{ 
    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 
  
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    new_node->data = new_data; 
  
    new_node->next = prev_node->next; 
  
   prev_node->next = new_node; 
  
    new_node->prev = prev_node; 
  
    if (new_node->next != NULL) 
        new_node->next->prev = new_node; 
} 


void append(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    struct Node* last = *head_ref;   
    
    new_node->data = new_data; 
  
    new_node->next = NULL; 
  
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
    while (last->next != NULL) 
        last = last->next; 
  	
    /* 6. Change the next of last node */
    last->next = new_node; 
  
    /* 7. Make last node as previous of new node */
    new_node->prev = last; 
  
    return; 
} 

void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data)  
{  
    if (next_node == NULL) {  
        printf("the given next node cannot be NULL");  
        return;  
    }  
  
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  
  
    new_node->data = new_data;  
  
    new_node->prev = next_node->prev;  
  
    next_node->prev = new_node;  
  
    new_node->next = next_node;  
  
    if (new_node->prev != NULL)  
        new_node->prev->next = new_node;  
    else
        (*head_ref) = new_node; 
      
}  

void main()
{



]
