#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n)
{
  int numeros_usados[10]; //para no repetir numeros
  //validamso las filas
  for (int fila = 0 ; fila < 9 ; fila++)
  {
    for (int i = 0 ; i < 10 ; i++)
    {
      numeros_usados[i] = 0;
    }

    for (int columna = 0 ; columna < 9 ; columna++)
    {
      int num = n->sudo[fila][columna];
      if (num != 0)
      {
        if (numeros_usados[num])
        {
          return 0;
        }
        numeros_usados[num] = 1;
      }
    }
  }

  //validamos las columnas

  for (int columna = 0 ; columna < 9 ; columna++)
  {
    for (int i = 0 ; i < 10 ; i++)
    {
      numeros_usados[i] = 0;
    }

    for (int fila = 0 ; fila < 9 ; fila++)
    {
      int num = n->sudo[fila][columna];
      if (num != 0)
      {
        if (numeros_usados[num])
        {
          return 0;
        }
        numeros_usados[num] = 1;
      }
    }
  }

  //validar matrices 3x3

  for (int matriz = 0 ; matriz < 9 ; matriz++)
  {
    for (int i = 0 ; i < 10 ; i++)
    {
      numeros_usados[i] = 0;
    }

  for (int celda = 0 ; celda < 9 ; celda++)
  {
    int fila = 3 * (matriz / 3) + (celda / 3);
    int columna = 3 * (matriz % 3) + (celda % 3);
    int num = n->sudo[fila][columna];
    if (num != 0)
    {
      if (numeros_usados[num])
      {
        return 0;
      }
      numeros_usados[num] = 1;
    }
  }
  }
    return 1;
}


List* get_adj_nodes(Node* n)
{
    List* list=createList();
    
    for (int fila = 0 ; fila < 9 ; fila++)
    {
      for (int columna = 0 ; columna < 9 ; columna++)
      {
        if (n->sudo[fila][columna] == 0)
        {
          for (int num = 1; num <= 9; num++)
          {
            Node * nuevoNodo = copy(n);
            nuevoNodo->sudo[fila][columna] = num;
            pushBack(list, nuevoNodo);
          }
          return list;
        }
      }
    }
    return list;
}

int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/