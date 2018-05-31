#include <iostream>
#include <string>
#include <ctime>
#include <math.h>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> LCSArr;

class LCS
{
	public:
		string string1, string2;
		LCSArr C, m, n;
	
		/*
		** Constructor
		*/
		LCS(string a, string b, LCSArr argLCS, int argm, int argn)
		{
			string1 = a;
			string2 = b;
			C = argLCS;
		}


		void do_lcs()
		{
			int m = string1.size();
			int n = string2.size();


			for ( int i = 0; i <= m ; i ++ )
			{
				for ( int j = 0; j <= n ; j ++ )
				{
					if ( i == 0 || j == 0 )
					{
						C[i][j] = 0;
					}
					else
					if ( string1.at(i-1) == string2.at(j-1) )
					{
						C[i][j] = C[i-1][j-1] + 1;
					}
					else
					{
						if ( C[i-1][j] >= C[i][j-1] )
						{
							C[i][j] = C[i-1][j] ;
						}
						else
						{
							C[i][j] = C[i][j-1];
						}
					}

				}
			}
			display_matrix(C,"Res");
		}

		/*
		** Display lcs , result string 
		*/
		void display_lcs()
		{
			string result;
			int row = string1.size();
			int col = string2.size() ;
			
			while ( row > 0 && col > 0 )
			{
				if ( string1.at(row-1) == string2.at(col-1) )
				{
					result.insert(0,1,string1.at(row-1));
					col = col - 1;
					row = row - 1;
				}
				else if ( C[row - 1][col] > C[row][col - 1] )
				{
					row = row - 1;
				}
				else
				{
					col = col - 1;
				}
			}
			cout << "LCS : " << result << endl;
		}

                /*
                ** Display a matrix
                */
                void display_matrix(LCSArr arg_matrix, string comment)
                {
                        cout << comment << endl;
                        for (int i = 0; i < arg_matrix.size(); i++ )
                        {
                                for ( int j = 0; j < arg_matrix[0].size(); j++ )
                                {
                                        cout << arg_matrix[i][j] << " ";
                                }
                                cout << "\n";
                        }
                        cout << "\n";
                }


};

int main(int argc, char * argv[])
{
	int n;
        if ( argc != 3)
        {
                cout << "Invalid arguments, ./exec string1 string2" << endl;
                exit(0);
        }

	string input1(argv[1]);
	string input2(argv[2]);	
	LCSArr matrixC(input1.size() + 1, vector<int> (input2.size() + 1, 0));
	
	LCS l1(input1,input2,matrixC, input1.size(), input2.size());
	l1.do_lcs();
	l1.display_lcs();
}
