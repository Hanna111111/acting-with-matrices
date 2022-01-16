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
void fillinMatrix (int **arr, int rows, int columns)
{

  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
	{
	  arr[i][j] = rand () % 100 + 1;
	}
    }
}


    
void frequencyOfElements(int **arr, int rows, int columns) {

for(int i = 0; i<rows; i++){//what's we are looking for
    for(int j = 0; j<columns; j++){
    int howManyTimes = 0;
    int count = arr[i][j];

        for(int m = 0; m < rows; m++){//where are we looking for
            for(int n = 0; n<columns; n++){
                if(count == arr[m][n]){
                    howManyTimes++;
                }
            }
        }
            cout<<"frequency of "<< count <<" is: "<<howManyTimes<<endl;
    }
}
}

    
//funcOutput
  void outputMatrix (int **arr, int rows, int columns)
  {

    for (int i = 0; i < rows; i++)
      {
	for (int j = 0; j < columns; j++)
	  {
	    cout << setw(4) <<arr[i][j] << " ";

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

    frequencyOfElements(arr, rows, columns);


    deleteFreeUp (arr, rows);
    return 0;
  }
