#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char caracter;
    struct no *proximo;
    
}No;


No* empilhar (No *pilha, char valor){
    No *novo = malloc(sizeof(No));
    
    if(novo){
        novo -> caracter = valor;
        novo -> proximo = pilha;
        return novo;
    }
    else
        printf("\t erro ao alocar memoria\n");
    return NULL;
}

No* desempilhar (No **pilha){
    No *remover = NULL;
    
    if(*pilha){
        remover = *pilha;
        *pilha = remover -> proximo;
    }
    else 
        printf ("\t pilha vazia");
    return remover;
}

void imprimir(No *pilha){
    printf("\t Pilha\n");
    while(pilha){
        printf("\t%c\n", pilha -> caracter);
        pilha = pilha -> proximo;
    }
        printf("\t FimPilha\n");

}

int formapar(char f, char d){
    switch(f){
    case ')': 
        if (d == '(')
            return 1;
        else 
            return 0;
        break;
    case ']':
        if (d == '[')
            return 1;
        else 
            return 0;
        break;
    case '}':
        if (d == '{')
            return 1;
        else 
            return 0;
        break;
     }
}

int identificarFormacao(char x[]){
    int i = 0;
    No *remover, *pilha = NULL;
    
    while (x[i] != '\0'){
        if (x[i] == '[' || x[i] == '(' || x[i] == '{' ){
            pilha = empilhar(pilha, x[i]);
            imprimir(pilha);
        }
        else if (x[i] == ']' || x[i] == ')' || x[i] == '}' ){
            remover = desempilhar(&pilha);
            if (formapar(x[i], remover -> caracter) == 0){
                return 1; 
            }
             free (remover);
        }
          i ++;
    }
    imprimir (pilha);
    if (pilha){
        printf("\t Expressao mal formada");
        return 1;
    }
    else {
        ("\t Expressao Correta");
        return 0;
    }
}


int main(){
    char exp[100];
    
    printf ("informe uma Expressao: ");
    scanf ("%99[^\n]", exp);
    printf ("\n Expressao: %s\nRetorno: %d\n", exp , identificarFormacao(exp));

}


   // (([({[({})}])]))
   // [({[([{}])]})]
   //([]))
   //(([])
   


