#include <iostream>
#include <string>
#include <ctime>
#include <climits>
#include <math.h>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


struct ITEM
{
        int label;
        int profit;
        int weight;
};

typedef vector<ITEM> ITEM_SET;


class Knapsack
{
        public:
		ITEM_SET knapsack ;
		double knapsack_capacity = 0;
		int N;

                /*
                ** Constructor , initialize rows and columns of all matrices
                */
                Knapsack( int n )
                {
                        N = n;
                }

                /*
                ** Returns a randomly generated number between 1 and 10
                */
                int generate_random_no(int from, int to)
                {
                        int random = rand() % to + from;
                        return random;
                }

                /*
                ** Populates node matrix with randomly generated numbers
                */
                void input_matrix()
                {
                        for (int i = 0; i < N; i++ )
                        {
                              	ITEM obj ;
                            	obj.label = i;
                             	obj.profit = generate_random_no(10,30);
                           	obj.weight = generate_random_no(5,20);
                      		knapsack.push_back(obj);
                        }
			// find knapsack capacity
			int sum_w = 0;
			for ( int i = 0; i < N; i++ )
			{
				sum_w = sum_w + knapsack[i].weight;
			}
			knapsack_capacity = floor(0.6 * sum_w) ;
		}

		/*
                ** Display a matrix
                */
                void display_matrix_1d( ITEM_SET arg_matrix, string comment)
                {
                        cout << comment << endl;
                        for (int i = 0; i < arg_matrix.size(); i++ )
                        {
                      		printf ("%d	Profit : %d	Weight : %d", arg_matrix[i].label, arg_matrix[i].profit, arg_matrix[i].weight );
                          	cout << "\n";
                        }
                        cout << "\n";
                }

};

/*
** Simulate a Knapsack algorithm based on user input
*/
void simulate_algo ( std::string choice )
{
	int n;
        srand ( (unsigned) time(NULL) );
        n = rand() % 8 + 4;    // generates random number between 4 and 8

        cout << "Selected value of n ( Radmoly generated ) " << n << endl;

	if ( choice == "1" )
        {
		// Brute Force
        }
        else if ( choice == "2" )
        {
		// Dynamic
        }
	else if ( choice == "3" )
	{
		// Backtracking
	}
        else
        {
                cout << "EXCEPTION ! This shouldnt have occured, simulate_algo function failed, user entered " << choice << " as his input";
        }
}


int main()
{
        std::string userinput;
        int input_data_n ;

        while ( true )
        {
                cout << "1. Brute Force Knapsack \n" ;
                cout << "2. Dynamic Programming Knapsack \n";
                cout << "3. Backtracking Knapsack  \n" ;
		cout << "4. Exit \n \n";

                while ( std::getline(std::cin, userinput) && userinput != "" )
                {
                        if ( userinput == "1" || userinput == "2" || userinput == "3")
                        {
                                simulate_algo(userinput);
                        }
                        else if ( userinput == "Exit" || userinput == "exit" || userinput == "4" )
                        {
                                cout << "Program terminated normally \n";
                                exit(0);
                        }
                        else
                        {
				cout << "1. Brute Force Knapsack \n" ;
                		cout << "2. Dynamic Programming Knapsack \n";
                		cout << "3. Backtracking Knapsack  \n" ;
                		cout << "4. Exit \n \n";
                        }
                }
        }
}

