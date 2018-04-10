#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct node {
	int data;
	struct node *next;
} node;

void freeList(node *list) {
	if (list == NULL) {
			return;
	}

	freeList(list->next);

	free(list);
}
int returnfirst(node *list){
    node *aux = list;
      if(list != NULL)
      return aux->data;
}
node* deletefirst(node *list){
    node *aux = list;
      if(list == NULL)
      return list;
       else  list = aux->next;

    return list;
}
node* addfirst(node *list, int i){


    node *element = (node*) malloc(sizeof(node));
	element->data = i;
    element->next = list;
    list = element;

    return list;
}
void printList(node *list) {
	printf("[ ");

	node *aux = list;
	while (aux != NULL) {
		printf("%d ", aux->data);
		aux = aux->next;
	}

	printf("]\n");
}
int isEmpty( node* list ){
   if( !list )
      return 1;
   return 0;
}
int main() {
    node *nr1 = NULL;
	int i,j;
    node *nr2 = NULL;
    node *nrfinal = NULL;
    char* numar1;
    char* numar2;
    char c;
    int shifra1,shifra2;
    printf("Number1, how many digits?");
    scanf("%d",&shifra1);
    printf("Enter number1:");
    numar1 = (char *) malloc((shifra1) * sizeof(char));
    scanf("%s",numar1);
    printf("Number2, how many digits?");
    scanf("%d",&shifra2);
    printf("Enter number2:");
    numar2 = (char *) malloc((shifra2) * sizeof(char));
    scanf("%s",numar2);

    for (j = 0; numar1[j] != '\0'; j++) {
        nr1 = addfirst(nr1,numar1[j]-'0');
    }
    for (j = 0; numar2[j] != '\0'; j++) {
        nr2 = addfirst(nr2,numar2[j]-'0');
    }
    int carry = 0;
    int s;

    while(!isEmpty(nr1) || !isEmpty(nr2)){
        s = (!isEmpty(nr1) ? returnfirst(nr1) : 0) +
            (!isEmpty(nr2) ? returnfirst(nr2) : 0 )+
            carry ;

         if( s >= 10){
            nrfinal = addfirst(nrfinal,(s % 10) );
            carry = 1;
        }else{
            nrfinal = addfirst(nrfinal,s);
        }

        if(!isEmpty(nr1))
        nr1 = deletefirst(nr1);
        if(!isEmpty(nr2))
        nr2 = deletefirst(nr2);

    }
    if(carry > 0)
        nrfinal = addfirst(nrfinal,1);

    printList(nrfinal);
    freeList(nr1);
    freeList(nr2);
    freeList(nrfinal);
	return 0;
}
