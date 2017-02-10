#include <iostream> // para usar cout
#include <cstdlib>  // para usar rand
#include <ctime>    // para usar srand
#include <sstream>  // para usar stringstream

using namespace std;

//****************************************************//
//                CREAR  LA  MATRIZ                   //
// Parametros:                                        //
// t => tamaño de la matriz                           //
//                                                    //
//****************************************************//
float** crear_matriz(int t);


//****************************************************//
//                NUMERO ALEATORIO                    // 
// Parametros:                                        //
// a => Valor mínimo                                  //
// t => Valor máximo                                  //
//                                                    //
//****************************************************//
float random_float(float a, float b); 


//****************************************************//
//               LLENAR  MATRIZ                       // 
// Parametros:                                        //
// **m  => la matriz                                  //
// t    => tamaño de la matriz                        //
//                                                    //
//****************************************************//
void llenar_matriz(float **m, int t); 




//****************************************************//
//                IMPRIMIR   MATRIZ                   // 
// Parametros:                                        //
// **m  => la matriz                                  //
// t    => tamaño de la matriz                        //
//                                                    //
//****************************************************//
void imprimir_matriz(float **m, int t);



//****************************************************//
//                 AJUSTAR NÚMERO                     // 
// Parametros:                                        //
// x          =>  Número                              //
// decDigits  =>  Cantidad de digitos decimales.      //
// width      =>  Ancho que ocupara el número. Se     //
//                rellena con espacios en blanco      //
//                el faltante.                        //
//                                                    //
//****************************************************//
std::string prd(const float x, const int decDigits, const int width);




//****************************************************//
//               FORWARD ELIMINATION                  // 
// Parametros:                                        //
// m => La matriz                                     //
// t => Tamaño de la matriz                           //
//                                                    //
//****************************************************//
void forward_elimination(float **m, int t);



//****************************************************//
//                 CONVERTIR A UNO                    // 
// Parametros:                                        //
// m    => La matriz                                  //
// size => Tamaño de la matriz                        //
// row  => fila donde se encuetra elemento a          //
//         convertir en 1.                            //
//                                                    //
//****************************************************//
void to_one(float **m, int row, int size);



//****************************************************//
//                 CONVERTIR A CERO                   // 
// Parametros:                                        //
// m    => La matriz                                  //
// size => Tamaño de la matriz                        //
// col  => columna donde se encuentra elemento a      //
//         convertir en 0.                            //
//                                                    //
//****************************************************//
void to_zero( float **m, int col, int size );



int main() 
{ 
  float **mtr;  // Matriz 
  int e;        // Número de ecuaciones

  e = 6; // Tamaño de la matriz,

  mtr = crear_matriz(e);
  llenar_matriz(mtr, e); // Llenar la matriz
  imprimir_matriz(mtr, e);
  forward_elimination(mtr, e); // Hallar una solución para la matriz

  // Borrar matriz
  delete[] *mtr;
  delete[] mtr;
}

float** crear_matriz(int t)
{
  float **m;
  m = new float *[t];
  for(int i=0; i<t; i++)
    m[i] = new float[t*2]; // t*2 es para agregar la matriz identidad
  return m;
}



void llenar_matriz(float **m, int t)
{
    srand((int)time(0));
    srand (static_cast <unsigned> (time(0)));
    for(int i = 0; i<t; i++)
    {
        for(int j=0; j<t; j++)
            m[i][j] = random_float(-5.0, 5.0); // Llenar matriz A
        m[i][t+i] = 1; // Llenar matriz identidad
    }
// 2 ecuaciones 2 incognitas
//m[0][0] = 3;
//m[0][1] = 4;
//m[0][2] = 2;
//m[1][0] = 8;
//m[1][1] = 7;
//m[1][2] = 5;


// 4 ecuaciones 4 incognitas
//m[0][0] = 16  /*1   2*/;
//m[0][1] = -6  /*-1  2*/;
//m[0][2] = 4   /*0   -4*/;
//m[0][3] = 1   /*0   5*/;
//m[0][4] = -36 /*-6  0*/;

//m[1][0] = 1   /*0   3*/;
//m[1][1] = -8  /*1   2*/;
//m[1][2] = 1   /*1   -3*/;
//m[1][3] = 1   /*0   -2*/;
//m[1][4] = -64 /*3   14*/;

//m[2][0] = 16  /*0   5*/;
//m[2][1] = 2   /*0   -2*/;
//m[2][2] = -4  /*1   4*/;
//m[2][3] = 1   /*2   -1*/;
//m[2][4] = -4  /*4   -1*/;

//m[3][0] = 9   /*2   4*/;
//m[3][1] = 8   /*0   3*/;
//m[3][2] = -3  /*0   -1*/;
//m[3][3] = 1   /*-3  -1*/;
//m[3][4] = -64 /*5   13*/;
}





void imprimir_matriz(float **m, int t)
{
  cout << "Matriz" << endl;
  std::cout << std::string(6*(t*2)+t, '-') << "\n";
  for(int i=0; i<t; i++)
  {
    std::cout << "|";
    for(int j=0; j<t*2; j++)
    {
      std::cout << prd(m[i][j],2,6); //  << " | ";
      if(j==t-1) cout << "  |";
    }
    cout << " | " << endl;
  }
  std::cout << std::string(6*(t*2) + t, '-') << endl;

}



std::string prd(const float x, const int decDigits, const int width)
{
  stringstream ss;
  ss << fixed << right;
  ss.fill(' ');
  ss.width(width);
  ss.precision(decDigits);
  ss << x;
  return ss.str();
}



float random_float(float a, float b) 
{
  float random = ((float) rand()) / (float) RAND_MAX;
  float diff = b - a;
  float r = random * diff;
  return a + r;
}



void forward_elimination( float **m, int size)
{
  for(int i=0; i<size; i++)
  {
    to_one(m, i, size);
    to_zero(m, i, size);
    cout << "\n\n\n\n";
    imprimir_matriz(m, size);

  }
}



void to_one(float **m, int row, int size)
{
    float value = m[row][row];
    float tmp;
    if(value == 0)
    // intercambiar con otra fila que no tenga cero en la misma posición.
    for(int i=row; i<size; i++)
        if(m[i][row]!=0)
        {
            cout << "Intercambiar fila " << row << " con la fila" << i << endl;
            for(int j=0; j< size*2; j++)
            {
                tmp = m[row][j];
                m[row][j] = m[i][j];
                m[i][j] = tmp;
            }
            break;
        }
  
    value = m[row][row];
    for(int i=0; i<size*2; i++)
        if(m[row][i]!=0)
            m[row][i]=m[row][i]/value;
    cout << "Dividir por: " << value << " la fila " << row << endl;
}



void to_zero( float **m, int col, int size )
{
  float value;

  for( int x=0; x<size; x++ )  // Recorrer la columna
  {
    value=m[x][col];
    if( x != col )
    {
      // Recorrer la fila
      cout << "Fila " << x << " - fila " << col << " * " << value << endl;
      for( int y=0; y<size*2; y++ )
      {
            m[x][y] =  m[x][y] -  m[col][y] * value;
      }
    }
  }
}
