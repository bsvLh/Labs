#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) 
{
  int max = arr[0];
  for (int i = 1; i < size; i++)
    {
      if (arr[i] > max)
      {
        max = arr[i];
      }
    }
  return max; 
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) 
{
  int temp;
  int inicio = 0;
  int final = size - 1;
  while (inicio < final)
    {
      temp = arr[inicio];
      arr[inicio] = arr[final];
      arr[final] = temp;

      inicio++;
      final--;
    }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize)
{
  int i; 
  int contador = 0;
  for (i = 0 ; i < size ; i++)
    {
      if (arr[i] % 2 == 0)
      {
        contador++;
      }
    }
  int *nuevoarr = (int *) malloc(contador * sizeof(int));
  if (nuevoarr == NULL) exit(EXIT_FAILURE);
  int ctrlpos = 0;
  for (i = 0 ; i < size ; i++)
    {
      if (arr[i] % 2 == 0)
      {
        nuevoarr[ctrlpos] = arr[i];
        ctrlpos++;
      }
    
    }
  (*newSize) = contador;
  return nuevoarr;
}


/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[])
{
  int ctra1 = 0;
  int ctra2 = 0;
  for(int i = 0; i < (size1 + size2); i++) 
  {
    if(arr1[ctra1] <= arr2[ctra2] && ctra1 < size1) 
    {
      result[i] = arr1[ctra1];
      ctra1++;
    } else 
    {
      result[i] = arr2[ctra2];
      ctra2++;
    }
  }
}


/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) 
{
  int ascen = 1;
  int descen = 1;
  int i; 
  for (i = 1 ; i < size ; i++)
    {
      if (arr[i] < arr[i-1])
      {
          ascen = 0;
        break;
      }
    }
  for (i = 1 ; i < size ; i++)
  {
    if (arr[i] > arr[i-1])
    {
        descen = 0;
      break;
    }
  }
  if (ascen == 1) {
    return 1;
  } else if (descen) {
    return -1;
  } else {
    return 0;
  }
}



/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char*nombreAutor, int anioNacimiento, int anioPublicacion) 
{
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) 
{
  Nodo *head = NULL;
  Nodo *temp = NULL;
  Nodo *actua = NULL;
  for (int i = 0; i < size; i++)
    {
      temp = (Nodo *) malloc(sizeof(Nodo));
      temp->numero = arr[i];
      temp->siguiente = NULL;

      if (head == NULL) head = temp;
      else actua->siguiente = temp;
      actua = temp;
    }
  return head;