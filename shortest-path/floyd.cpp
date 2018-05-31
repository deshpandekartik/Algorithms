#include <iostream>
#include <string>
#include <ctime>
#include <climits>
#include <math.h>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> VERTICES;

class Floyds
{
        public:
		VERTICES D,P;	// d matrix and p matrix
		int N;		// no of vertices
		int Negate = -999;

                /*
                ** Constructor , initialize rows and columns of all matrices
                */
		Floyds( VERTICES arg1, int n )
		{
			N = n;
			D = arg1;
			P = arg1;
		}

                /*
                ** Returns a randomly generated number between 1 and 10
                */
                int generate_random_no()
                {
                        int random = rand() % 10 + 1;
                        return random;
                }

                /*
                ** Populates node matrix with randomly generated numbers
                */
                void input_matrix()
                {
                        // first matrix
                        for (int i = 0; i < N; i++ )
                        {
                                for ( int j = 0; j < N; j++ )
                                {
					if ( i == j ) 
					{
						D[i][j] = 0;
					}
					else
					{
						int number = generate_random_no();
                                        	D[i][j] = number;		// no between 1 and 10
						D[j][i] = number;
						
					}
					P[i][j] = Negate;	// initialize P matrix to 0
                                }
                        }
			/*
			D = { {0,   4,  3, 3 },
                        { 4, 0, 10 ,8},
                        { 3, 10, 0 ,1},
                        { 3, 8, 1, 0}
                      };
			*/
                      	display_matrix(D,"Randomly generated Matrix ");
                        //display_matrix(P,"P0 ");
                }

                /*
                ** Display a matrix
                */
                void display_matrix(VERTICES arg_matrix, string comment)
                {
                        cout << comment << endl;
                        for (int i = 0; i < arg_matrix.size(); i++ )
                        {
                                for ( int j = 0; j < arg_matrix.size(); j++ )
                                {
                                        //cout << arg_matrix[i][j] << " ";
					printf ("%7d", arg_matrix[i][j]);
                                }
                                cout << "\n";
                        }
                        cout << "\n";
                }


		void floyd_algo()
		{
			for ( int k = 0 ; k < N ; k ++ )
			{
				for ( int i = 0 ; i < N; i ++ )
				{
					for ( int j = 0 ; j < N; j ++ )
				 	{
						if ( D[i][k] + D[k][j] < D[i][j] )
						{
							D[i][j] = D[i][k] + D[k][j] ;
							P[i][j] = k ;
						}
					}
				}
				//display_matrix(D,"D " + std::to_string(k + 1));
				//display_matrix(P,"P " + std::to_string(k + 1));
			}
			find_all_paths();
		}

		void find_all_paths()
		{
			for ( int i = 0; i < N; i ++ )
			{
				for ( int j = 0; j < N; j ++ )
				{
					if ( i != j )
					{
						string result = to_string(i) + " -> ";
						int total_cost = 0;
						shortest_path(i , j , &result , &total_cost);
						if ( total_cost != 0 )
						{
							result = result + to_string(j);
						}
						else
						{
							total_cost = D[i][j];
							result = result + to_string(j);
						}
						result = result + " Length = " + to_string(total_cost);
						cout << result << endl;
					}
				}
			} 
		}

		void shortest_path(int q, int r, string *result, int *cost )
		{
			if ( P[q][r] != Negate )
			{
				if ( P[q][r] != r )
				{
					shortest_path(q,P[q][r], result, cost);
				}
				*cost = *cost + D[q][r];
				result->append(to_string(P[q][r]));
				result->append(" -> ");
				if ( P[q][r] != q ) 
				{
					shortest_path(P[q][r], r,result, cost);
				}
				return ;
			}
			else
			{
				return;
			}
		}
		
};


int main()
{
	int n;
	srand ( (unsigned) time(NULL) );
	n = rand() % 10 + 5;    // generates random number between 5 and 10
     	cout << "Selected value of n ( Radmoly generated ) " << n << endl;

	VERTICES input_mat(n, vector<int> (n, 0));
	Floyds f1(input_mat,n);
	f1.input_matrix();
	f1.floyd_algo();
}
