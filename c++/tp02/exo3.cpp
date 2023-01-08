#include <iostream>
#include<vector>


using namespace std;
template <typename T>

using matrix=vector<vector<T>> ;
//this function takes input from the user and stores it in a 2D vector (matrix ) given as an  arguement , we're using templates so that that the matrix can be a mtrix of any type (matrix of int or floats)
template<typename T>
void enter_matrix (int rows , int cols  , matrix<T>& M) 
{  
 
   
   for (int i=0;i<rows;i++)
   {
     for (int j=0 ;j<cols; j++)
       {
         cin >> M[i][j];
             
        }
        
   }
   return ; 
 } 
 
 
//this function takes a matrix to be printed to te user
template<typename T>
void print_matrix (matrix<T> M )
{  
 
 // int rows = sizeof(M)/sizeof(M[0]);
  //int cols = sizeof(M)/(sizeof(int)*rows);
 
  
   cout << "{ " ;
   for (int i=0;i<M.size() ;i++)
   {
     cout<< " { " ;
     for (int j=0 ;j<M[i].size(); j++)
       {
         cout << M[i][j]<<" " ;
            
         
        }
     cout << "}"  << endl;
     
 
        
   }
     cout << " }" ;
   return ; 
 } 
 
 
template<typename T>
//this function takes row matrices and multiply them and return the reuslt matrix
matrix <T> multi_matrix(matrix<T> M , matrix<T> N)
{
   
   
   vector<vector<int>> mult;
   
   mult.resize(M.size());  //resizing (allocating memory) the matrix where we will store the reuslt of our multiplication so that it has a number of rows equal to the first matrix M and a number of columns equel to the number of the columns of the second one N
   for (int a=0;a <M.size();a++)
        { mult[a].resize(N[a].size());}
   int rows_N=N.size();
   int cols_M=M.size();
   if (cols_M!=rows_N)
      { exit(EXIT_FAILURE);}
   else 
      {
        int rows_M=M.size();
        for (int i=0;i<rows_M;i++)
            {
              int cols_N=N.size();
              for (int j=0;j<cols_N;j++)
                  {
                     int cols_M=M.size();
                     for (int k=0;k<cols_M;k++)
                      {
                        mult[i][j]+=M[i][k]*N[k][j];
                      }
                      
                      
                   }
              }
       }
       return mult;
       
}

//using the function "multi_matrix" defined above and  generlising the binary exponeniation , we can creat a recursive function that returns the power of a matrix  in a in an optimal way
template<typename T>
matrix<T> powrec(matrix<T> M,int n)
{
  
  if (n==1)
      return M;
  if (n%2==0)
    return multi_matrix(powrec(M,n/2),powrec(M,n/2));
  else
     return multi_matrix(multi_matrix(powrec(M,n/2),powrec(M,n/2)),M);
     
}
   
