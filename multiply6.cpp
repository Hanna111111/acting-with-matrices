#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

//create a matrix
int **creatingMatrix(int rows, int columns){
    int **arr = new int *[rows];
    
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[columns];
    }
    return arr;
}

//fillin
void fillinMatrix(int **arr, int rows, int columns){
    
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++){
             arr[i][j] = rand() % 100 + 1;
        }
    }
}

//multiply
void multiplyMatrix(int **arr, int rows, int columns){
    double result = 1;
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++){
            if(arr[i][j] != 0){
            result *= (1.0 / arr[i][j]);
            }
        }
       
    }
     cout << "The result of multiply: " <<result << endl;
}



//funcOutput
void outputMatrix(int **arr, int rows, int columns){
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << setw(4)<<arr[i][j] << " ";
            
        }
        cout << endl;
    }
}

//freeing up memory
//сначала содержимое ссылок а потом - rows
void deleteFreeUp(int **arr, int rows){
    for(int i = 0; i < rows; i++ ){
        delete []arr[i];
    }
    
    delete [] arr;
}
    

int
main ()
{
    srand (time (NULL));
    int **arr;
    
  int rows, columns;
  cout << "Please, input size of rows:  " << endl;
  cin >> rows;

  cout << "Please, input size of columns:  " << endl;
  cin >> columns;

arr = creatingMatrix(rows, columns);

fillinMatrix(arr, rows, columns);



outputMatrix(arr, rows, columns);

cout << "-------------------------------------------" <<endl;

multiplyMatrix(arr, rows, columns);

deleteFreeUp(arr, rows);
  return 0;
}
