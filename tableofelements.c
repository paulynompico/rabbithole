/*
Prints a table of elements
Week 3 assignment - Option 2
April 15, 2022
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct element {char *name; char *symbol; double AW;} element;
typedef struct list {element em; struct list *next;} list;

list* create_list(element e)
{
    list* head = malloc(sizeof(list));
    head->em = e;
    head->next = NULL;
    return head;
}

list* add_front(element e, list* h) 
{
    list* head = create_list(e);
    head->next = h;
    return head;
}

list* array_list(element e[], int size) //make array a linked list
{
    int i;
    list* head = NULL;
    for (i=size-1; i>=0; --i){ //parse the list backwards
        head = add_front(e[i], head);
    }
    return head;
}

void print_element(element* e)
{
    printf("%-15s%-10s%lf\n", e->name, e->symbol, e->AW);
}

void print_list(list *h, char *title)
{
    printf("%s\n", title);
    printf("---------------------------------------\n");
    while (h != NULL){
        print_element(&h->em);
        h = h->next;
    }
}


int main()
{
    list* head = NULL;
    
    element e1 = {"Hydrogen", "H", 1.008};
    element e2 = {"Helium", "He", 4.003};
    element e3 = {"Lithium", "Li", 6.941};
    element e4 = {"Beryllium", "Be", 9.012};
    element e5 = {"Boron", "B", 10.811};
    element e6 = {"Carbon", "C", 12.011};
    element e7 = {"Nitrogen", "N", 14.007};
    element e8 = {"Oxygen", "O", 15.999};
    element e9 = {"Fluorine", "F", 	18.998};
    element e10 = {"Neon", "Ne", 20.180};

    element el[10] = {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10}; //turn struct to array
    head = array_list(el, 10);
    
    printf("\n");
    print_list(head, "NAME           SYMBOL    ATOMIC WEIGHT");
    printf("\n");
    return 0;
}
