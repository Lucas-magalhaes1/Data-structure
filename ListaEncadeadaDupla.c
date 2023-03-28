#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo
{
  int dado;
  struct sNodo *next;
  struct sNodo *previous;	
} Nodo;

typedef struct sLista
{
  struct sNodo *head;
  struct sNodo *tail;
  int size;
} Lista;

Nodo *alocamemoriaNodo ();
Lista *alocamemoriaLista ();
Nodo *criaNodo (int);
Lista *criaLista ();
int insereElementoLista (Lista *, Nodo *, int);
void percorrelistaHeadTail (Lista *);
int removeElementoLista (Lista *, int);

int
main ()
{
  Lista *lista1;
  lista1 = alocamemoriaLista ();
  insereElementoLista (lista1, NULL, 10);
  insereElementoLista (lista1, lista1->head, 5);
  insereElementoLista (lista1, lista1->tail, 7);
  insereElementoLista (lista1, NULL, 9);
  insereElementoLista (lista1, NULL, 15);
  insereElementoLista (lista1, NULL, 25);
  insereElementoLista (lista1, NULL, 30);
  removeElementoLista (lista1, 9);
  removeElementoLista (lista1, 30);
  removeElementoLista (lista1, 7);
  removeElementoLista (lista1, 5);
  percorrelistaHeadTail (lista1);
}

Nodo *
alocamemoriaNodo ()
{
  return (Nodo *) malloc (sizeof (Nodo));
}

Lista *
alocamemoriaLista ()
{
  return (Lista *) malloc (sizeof (Lista));
}

Nodo *
criaNodo (int dado)
{
  Nodo *nodo = alocamemoriaNodo ();
  if (nodo != NULL)
    {
      nodo->dado = dado;
      nodo->next = NULL;
      nodo->previous = NULL;	
    }
  return nodo;
}

Lista *
criaLista ()
{
  Lista *lista = alocamemoriaLista ();
  if (lista != NULL)
    {
      lista->head = NULL;
      lista->tail = NULL;
      lista->size = 0;
    }
  return lista;
}

int
insereElementoLista (Lista * lista, Nodo * pivo, int dado)
{
  Nodo *novo = criaNodo (dado);
  if (novo == NULL)
    return -1;

  if (pivo == NULL)
    {
      if (lista->size == 0)
	lista->tail = novo;
      novo->next = lista->head;
      if (lista->head != NULL)	
	lista->head->previous = novo;
      lista->head = novo;
    }
  else
    {
      novo->next = pivo->next;
      if (novo->next != NULL)	
	novo->next->previous = novo; 
      pivo->next = novo;
      novo->previous = pivo;	
      if (pivo == lista->tail)	
	lista->tail = novo;
    }
  lista->size++;
  return 0;
}

int
removeElementoLista (Lista * lista, int dado)
{
  Nodo *atual = lista->head;
  while (atual != NULL)
    {
      if (atual->dado == dado)
	{
	  if (atual == lista->head)
	    {
	      lista->head = atual->next;
	      if (lista->head != NULL)	
		lista->head->previous = NULL;
	      if (atual == lista->tail)	
		lista->tail = NULL;
	    }
	  else if (atual == lista->tail)
	    {
	      lista->tail = atual->previous;
	      lista->tail->next = NULL;
	    }
	  else
	    {
	      atual->previous->next = atual->next;
	      atual->next->previous = atual->previous;
	    }
	  free (atual);
	  lista->size--;
	  return 1;
	}
      atual = atual->next;
    }
  return 0;
}

void
percorrelistaHeadTail (Lista * lista)
{
  Nodo *atual = lista->head;
  while (atual != NULL)
    {
      printf ("%d ", atual->dado);
      atual = atual->next;
    }
  printf ("\n");
  atual = lista->tail;
  while (atual != NULL)
    {
      printf ("%d ", atual->dado);
      atual = atual->previous;
    }
}



