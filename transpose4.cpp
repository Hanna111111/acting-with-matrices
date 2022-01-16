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

//funcOutput
void outputMatrix(int **arr, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << setw(4)<<arr[i][j] << " ";
        }
        cout << endl;
    }
}

//transpose
void transposeMatrix(int **arr, int **arrTransp, int rows, int columns){
    for(int i = 0; i < columns;i++){
        for(int j = 0; j < rows; j++){
             arrTransp[i][j] = arr[j][i];
        }
    }
}




//freeing up memory
void deleteFreeUp(int **arr, int rows){
    for(int i = 0; i < rows; i++ ){
        delete []arr[i];
    }
    
    delete [] arr;
}



int main (){
    srand (time (NULL));
    
    int rows, columns;
    
    int **arr;
    int **trans_arr;
    
    cout << "Please, enter number of rows: " << endl;
  cin >> rows;
  
  cout << " Please, enter number of columns: " << endl;
  cin >> columns;
  
  arr = creatingMatrix(rows, columns);
  trans_arr = creatingMatrix(columns, rows);
  cout << endl;
  
  fillinMatrix(arr, rows, columns);
  
    outputMatrix(arr, rows, columns);
    
    
    cout << "-------------------------------------------" <<endl;
    
    transposeMatrix(arr,trans_arr, rows, columns);
    outputMatrix(trans_arr, columns, rows);
    
    deleteFreeUp(arr, rows);
    deleteFreeUp(trans_arr, columns);
    
  return 0;
}
