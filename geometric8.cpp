#include <iostream>
#include <iomanip>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

//create a matrix
int **creatingMatrix (int rows, int columns)
{
  int **arr = new int *[rows];

  for (int i = 0; i < rows; i++)
    {
      arr[i] = new int[columns];
    }
  return arr;
}

//fillin
void
fillinMatrix (int **arr, int rows, int columns)
{

  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
	{
	  arr[i][j] = rand () % 100 + 1;
	}
    }
}

void geometricMean(int **arr, int rows, int columns)
{
    
    float product = 1;
    int n = rows * columns;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++) {
            product *= abs(arr[i][j]);
        }
    }
   
    float gm = pow(product, (float)1 / n);
    //return gm;
    cout << "The geometric mean: " << gm << endl;
}

//funcOutput
  void outputMatrix (int **arr, int rows, int columns)
  {

    for (int i = 0; i < rows; i++)
      {
	for (int j = 0; j < columns; j++)
	  {
	    cout << setw(4)<<arr[i][j] << " ";

	  }
	cout << endl;
      }
  }
  
  
  //freeing up memory
  void deleteFreeUp (int **arr, int rows)
  {
    for (int i = 0; i < rows; i++)
      {
	delete[]arr[i];
      }

    delete[]arr;
  }
  

  int main ()
  {
    srand (time (NULL));
    
    
    int **arr;
    

    int rows, columns;
    cout << "Please, input size of rows:  " << endl;
    cin >> rows;

    cout << "Please, input size of columns:  " << endl;
    cin >> columns;

    arr = creatingMatrix (rows, columns);

    fillinMatrix (arr, rows, columns);

    outputMatrix (arr, rows, columns);
    cout << "-------------------------------------------" << endl;
    
    geometricMean(arr, rows, columns);

    deleteFreeUp (arr, rows);
    return 0;
  }
