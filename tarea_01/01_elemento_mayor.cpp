#include <iostream> // cout
#include <cstdlib>  // rand
#include <ctime>    //srand

using namespace std;



// ***************************************** //
// Imprimir el contenido de la matriz
// **mt representa la matriz
// fi número de filas de la matriz
// co número de columnas de la matriz
// ***************************************** //
void imprimir(int **mt, int fi, int co);


// ***************************************** //
// Llenar la matriz
// **mt representa la matriz
// fi número de filas de la matriz
// co número de columnas de la matriz
// ***************************************** //
void llenar(int **mt, int fi, int co);


// ***************************************** //
// Elemento máximo de una columna bajo la diagonal principal de la matriz
// **mt representa la matriz
// fi número de filas de la matriz
// co columna donde se buscará el máximo
// ***************************************** //
int maximo(int **mt, int fi, int co); 


// ***************************************** //
// **mt representa la metriz
// f1 y f2 son las filas a intercambiar
// co número de columnas de la matriz
// ***************************************** //
void intercambiar(int **mt, int f1, int f2, int co);


int main()
{
  int **m;
  int c=4,f=4;

  m = new int *[f];
  for(int i=0; i<f; i++)
    m[i] = new int[c];

  llenar(m,f,c);
  cout << endl <<  "Matriz:" << endl;
  imprimir(m,f,c);
  int ix =0;
  for(int j = 0; j<c; j++)
  {
    ix = maximo(m,f,j);
    intercambiar(m,ix,j,c);
    cout << endl << "Ciclo: " << j+1 << ", cambiar fila: " << j << " por la fila " << ix << endl;
    imprimir(m,f,c);
  }
  cout << endl << "Resultado:" << endl;
  imprimir(m,f,c);
  
  return 0;
}



void llenar(int **mt, int fi, int co)
{
  srand((int)time(0));
  for(int i=0; i<fi; i++)
    for(int j=0; j<co; j++)
      mt[i][j] = (rand() % 100) +1;
}


void imprimir(int **mt, int fi, int co)
{
  for(int i=0; i<fi; i++)
  {
    for(int j=0; j<co; j++)
      cout << mt[i][j] << "\t";
    cout << endl;
  }
}


int maximo(int **mt, int fi, int co)
{
  int mx = mt[co][co];
  int indice=co;

  for(int i = co; i<fi-1; i++)
    if(mt[i+1][co] > mx)
    {
      mx = mt[i+1][co];
      indice = i+1;
    }
  return indice;
}


void intercambiar(int **mt, int f1, int f2, int co)
{
  int tmp = 0;  
  for(int j=0; j<co; j++)
  {
    tmp = mt[f1][j];
    mt[f1][j] = mt[f2][j];
    mt[f2][j] = tmp;
  }
}


