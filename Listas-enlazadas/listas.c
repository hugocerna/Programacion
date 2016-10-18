#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElementoLista
{
  char *dato;
  struct ElementoLista *siguiente;
} Elemento;

typedef struct ListaIdentificar
{
  Elemento *inicio;
  Elemento *fin;
  int tamanno;
} Lista;

void
inicialisacion (Lista * lista)
{
  lista ->inicio = NULL;
  lista ->fin = NULL;
  lista ->tamanno = 0;
}

/* insercion en une lista vacia */
int ins_enlista_vacia (Lista *lista, char *dato){
  Elemento *nuevo_elemento;
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nuevo_elemento->dato, dato);

  nuevo_elemento->siguiente = NULL;
  lista ->inicio = nuevo_elemento;
  lista ->fin = nuevo_elemento;
  lista ->tamanno++;
  return 0;
}

/* inserción al inicio de la lista */
int ins_inicio_lista (Lista * lista, char *dato){
  Elemento *nuevo_elemento;
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nuevo_elemento->dato, dato);

  nuevo_elemento->siguiente = lista->inicio;
  lista ->inicio = nuevo_elemento;
  lista ->tamanno++;
  return 0;
}

/*insercion al final de la lista */
int ins_fin_lista (Lista * lista, Elemento * actual, char *dato){
  Elemento *nuevo_elemento;
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nuevo_elemento->dato, dato);

  actual->siguiente = nuevo_elemento;
  nuevo_elemento->siguiente = NULL;

  lista ->fin = nuevo_elemento;

  lista ->tamanno++;
  return 0;
}

/* insercion en la posicion solicitada */
int ins_lista (Lista * lista, char *dato, int pos){
  if (lista ->tamanno < 2)
    return -1;
  if (pos < 1 || pos >= lista ->tamanno)
    return -1;

  Elemento *actual;
  Elemento *nuevo_elemento;

  int i;

  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;

  actual = lista ->inicio;
  for (i = 1; i < pos; ++i)
    actual = actual->siguiente;
  if (actual->siguiente == NULL)
    return -1;
  strcpy (nuevo_elemento->dato, dato);

  nuevo_elemento->siguiente = actual->siguiente;
  actual->siguiente = nuevo_elemento;
  lista ->tamanno++;
  return 0;
}

/* supresión al inicio de la lista */
int sup_inicio (Lista * lista){
  if (lista ->tamanno == 0)
    return -1;
  Elemento *sup_elemento;
  sup_elemento = lista ->inicio;
  lista ->inicio = lista ->inicio->siguiente;
  if (lista ->tamanno == 1)
    lista ->fin = NULL;
  free (sup_elemento->dato);
  free (sup_elemento);
  lista ->tamanno--;
  return 0;
}

/* suprimir un elemento después de la posición solicitada */
int sup_en_lista (Lista * lista, int pos){
  if (lista ->tamanno <= 1 || pos < 1 || pos >= lista ->tamanno)
    return -1;
  int i;
  Elemento *actual;
  Elemento *sup_elemento;
  actual = lista ->inicio;

  for (i = 1; i < pos; ++i)
    actual = actual->siguiente;

  sup_elemento = actual->siguiente;
  actual->siguiente = actual->siguiente->siguiente;
  if(actual->siguiente == NULL)
          lista ->fin = actual;
  free (sup_elemento->dato);
  free (sup_elemento);
  lista ->tamanno--;
  return 0;
}

/* visualización de la Lista */
void muestra (Lista * lista){
  Elemento *actual;
  actual = lista ->inicio;
  while (actual != NULL){
      printf ("%p - %s\n", actual, actual->dato);
      actual = actual->siguiente;
  }
}

/* destruir la Lista */
void destruir (Lista *lista){
  while (lista->tamanno > 0)
    sup_inicio (lista);
}

int menu (Lista *lista,int *k){
  int eleccion;
  printf("********** MENU **********\n");
  if (lista ->tamanno == 0){
    printf ("1. Adición del1er elemento\n");
    printf ("2. Quitar\n");
  }else if(lista ->tamanno == 1 || *k == 1){
    printf ("1. Adición al inicio de la lista\n");
    printf ("2. Adición al final de la lista\n");
    printf ("4. Supresión al inicio de la lista\n");
    printf ("6. Destruir la lista\n");
    printf ("7. Quitar\n");
  }else {
    printf ("1. Adición al inicio de la lista\n");
    printf ("2. Adición al final de la lista\n");
    printf ("3. Adición después de la posición indicada\n");
    printf ("4. Supresión al inicio de la lista\n");
    printf ("5. Supresión después de la posición indicada\n");
    printf ("6. Destruir la lista\n");
    printf ("7. Quitar\n");
  }
  printf ("\n\nElegir: ");
  scanf ("%d", &eleccion);
  getchar();
  if(lista->tamanno == 0 && eleccion == 2)
    eleccion = 7;
  return eleccion;
}



int main (void)
{
  char eleccion;
  char *nom;
  Lista *lista;
  Elemento *actual;
  int aux;

  if ((lista = (Lista *) malloc (sizeof (Lista))) == NULL)
    return -1;
  if ((nom = (char *) malloc (50)) == NULL)
    return -1;
  actual = NULL;
  eleccion = 'o';

  inicialisacion (lista);
  int pos, k;

  while (eleccion!= 7){
      eleccion = menu (lista, &k);
      switch (eleccion){
        case 1:
          printf ("Ingrese un elemento : ");
          scanf ("%s", nom);
          getchar ();
          if (lista->tamanno == 0)
            aux=ins_enlista_vacia (lista, nom);
          else
            aux=ins_inicio_lista (lista, nom);
          printf ("%d elementos:ini=%s,fin=%s\n", lista->tamanno,
                  lista->inicio->dato, lista->fin->dato);
          muestra (lista);
          break;
        case 2:
          printf ("Ingrese un elemento: ");
          scanf ("%s", nom);
          getchar ();
          aux=ins_fin_lista (lista, lista->fin, nom);
          printf ("%d elementos:ini=%s,fin=%s\n", lista->tamanno,
                  lista->inicio->dato, lista->fin->dato);
          muestra (lista);
          break;
        case 3:
          printf ("Ingrese un elemento: ");
          scanf ("%s", nom);
          getchar ();
          do{
              printf ("Ingrese la posicion: ");
              scanf ("%d", &pos);
	    }
          while (pos < 1 || pos > lista->tamanno);
          getchar ();
          if (lista->tamanno == 1 || pos == lista->tamanno){
              k = 1;
              printf("-----------------------------------------------\n");
              printf("/!\\Fracaso la insercion.Utilice el menu {1|2} /!\\\n");
              printf("-----------------------------------------------\n");
              break;
	    }
          ins_lista (lista, nom, pos);
          printf ("%d elementos:ini=%s,fin=%s\n", lista->tamanno,
                  lista->inicio->dato, lista->fin->dato);
          muestra (lista);
          break;
        case 4:
          aux=sup_inicio (lista);
          if (lista->tamanno != 0)
            printf ("%d elementos:ini=%s,fin=%s\n", lista->tamanno,
                    lista->inicio->dato, lista->fin->dato);
          else
            printf ("lista vacia\n");
          muestra (lista);
          break;
        case 5:
          do{
              printf ("Ingrese la posicion : ");
              scanf ("%d", &pos);
	    }
          while (pos < 1 || pos > lista->tamanno);
          getchar ();
          aux=sup_en_lista (lista, pos);
          if (lista->tamanno != 0)
            printf ("%d elementos:ini=%s,fin=%s\n", lista->tamanno,
                    lista->inicio->dato, lista->fin->dato);
          else
            printf ("lista vacia\n");
          muestra (lista);
          break;
        case 6:
          destruir (lista);
          printf ("la lista ha sido destruida: %d elementos\n", lista->tamanno);
          break;
      }
  }
  return 0;
}


