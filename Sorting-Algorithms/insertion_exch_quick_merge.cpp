#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class SimulationAlgos
{
	public:
		int N , random_input_array[1000], itteration_no; 
		bool gui_status ; // gui_status used to determine whether GUI (**) has to be displayed, only true when N <= 20

		/*
		** Initialize everything
		*/
		SimulationAlgos(int input_size_n)
		{
			if ( input_size_n > 20 )
			{	
				gui_status = false;
			}
			else
			{
				gui_status = true;
			}
			N = input_size_n;
			itteration_no = 0;
		}		

		/*
		** Generate an array of size N ( specified by user ), using random numbers
		*/
		void generate_random_array()
		{
			int max_random_no_limit; // create random no from 0 to max_random_no_limit variable value 

			if ( N > 20 )
			{
				max_random_no_limit = 100;
			}
			else
			{
				max_random_no_limit = 15;
			}

			srand((unsigned)time(NULL));
			for ( int i = 1; i <= N; i ++ )
			{
				random_input_array[i] = 1 + rand() % max_random_no_limit;
			}

			if ( gui_status == true )
			{
				print_gui_input_array(random_input_array, "Initial array",N);
			}
			else
			{
				cout << "Initial array" << " " ;
				cout << "[ ";
                        	for ( int i = 1; i <= N; i ++ )
                        	{
                        	        cout << random_input_array[i] << ",";
                        	}
	                        cout << " ] \n";
			}
		}

		/*
		** To print the input array in terms of * , some GUI
		*/
		void print_gui_input_array(int input[], std::string comments, int array_size)
		{
			if ( gui_status == true )
			{
				cout << comments << " " ;
                    		cout << "[ "; 
                     		for ( int i = 1; i <= array_size; i ++ )
                     		{
                       			cout << input[i] << ",";
                  		}
				cout << " ] \n"; 


				for ( int i = 1; i <= array_size; i ++ )
                        	{
					for ( int j = 1; j <= input[i]; j++)
					{
						cout << "*";
					}
					cout << "\n";
				}
			}
		}

		/*
		* print the sorted array
		*/
		void print_sorted_array(int input[], std::string comments, int array_size)
		{
                     	cout << comments << " " ;
                    	cout << "[ "; 
                    	for ( int i = 1; i <= array_size; i ++ )
                     	{
                      		cout << input[i] << ",";
                    	}
                    	cout << " ] \n";

			if ( gui_status == true )
                        {
                                for ( int i = 1; i <= array_size; i ++ )
                                {       
                                        for ( int j = 1; j <= input[i]; j++)
                                        {
                                                cout << "*";
                                        }
                                        cout << "\n";
                                }
                        }


		}

		/*
		** To swap elements in an array
		*/
		void swap_in_array(int i, int j)
		{
			int temp;
			temp = random_input_array[i];
			random_input_array[i] = random_input_array[j];
			random_input_array[j] = temp;
		}

		/*
		** ExchangeSort
		*/
		void exchangesort()
		{
			for ( int i = 1; i <= N; i++ )
			{
				for ( int j = i + 1; j <= N ; j++ )
				{
					if ( random_input_array[j] < random_input_array[i] )
					{
						swap_in_array(i,j);
					} 
				}
				// after each itteration call gui function to display
                              	std::string comment = "Itteration " + std::to_string(i);
				
				if ( gui_status == true )
				{
                               		print_gui_input_array(random_input_array, comment,N);
				}
			}
		}

		/*
		** Insertion Sort
		*/
		void insertionsort()
		{
			for ( int i = 1; i<= N ; i ++)
			{
				for ( int j = i; j > 0 && random_input_array[j] < random_input_array[j-1]; j-- )
				{
					swap_in_array(j-1,j);
				}
				// after each itteration call gui function to display
                            	std::string comment = "Itteration " + std::to_string(i);

				if ( gui_status == true )
				{
                           		print_gui_input_array(random_input_array, comment,N);
				}
			}
		}

		/*
		** Merge Sort
		*/
		void mergersort()
		{
			/*
			// Custom test cases
                        random_input_array[1] = 38;
                        random_input_array[2] = 27;
                        random_input_array[3] = 43;
                        random_input_array[4] = 3;
                        random_input_array[5] = 9;
                        random_input_array[6] = 82;
                        random_input_array[7] = 10;
			*/

			merge_break_module(1, N);
		}

                /*
                ** Merge sort, Merging and sorting module for two arrays
                */
                void merge_module_mergingarrays(int left, int right, int middle, int itteration_no)
                {
			int input_size = right-left;
                        int temp_array[right-left+1], temp_array_pointer = 0;   // to store the sorted array, temp_array_pointer as an index for temp_array
                        int i = left, j = middle + 1;

                        // Merge the two parts into temp[].
                        while (i <= middle && j <= right)
                        {
                                if (random_input_array[i] < random_input_array[j])
                                {
                                        temp_array[temp_array_pointer] = random_input_array[i];
                                        temp_array_pointer++;
                                        i++;
                                }
                                else
                                {
                                        temp_array[temp_array_pointer] = random_input_array[j];
                                        temp_array_pointer++;
                                        j++;
                                }
                        }

                        // Insert all the remaining values from i to mid into temp[].
                        while (i <= middle)
                        {
                                temp_array[temp_array_pointer] = random_input_array[i];
                                temp_array_pointer++;
                                i++;
                        }

                        // Insert all the remaining values from j to high into temp[].
                        while (j <= right)
                        {
                                temp_array[temp_array_pointer] = random_input_array[j];
                                temp_array_pointer++;
                                j++;
                        }

                        // Assign sorted data stored in temp[] to a[].
                        for (i = left; i <= right; i++)
                        {
                                random_input_array[i] = temp_array[i-left];
                        }

			// after each itteration call gui function to display
                     	std::string comment = "Itteration " + std::to_string(itteration_no);

			//cout << input_size << " call to gui";
                    	print_gui_input_array(temp_array, comment ,input_size);
                }


                /*
                ** Merge sort recursive module, split array
                */
                void merge_break_module(int left, int right)
                {
                        if ( left < right )
                        {
                                // find the middle element
                                int middle = ( left + right ) / 2;

                                // Spliting into two halves
                                merge_break_module(left, middle);
                                merge_break_module(middle+1, right);

                                // finally sort and merge the two halves of array
				itteration_no = itteration_no + 1;
                                merge_module_mergingarrays(left, right, middle, itteration_no);
                        }
                }

                /*
                ** Quick sort
                */
                void quicksort()
                {
			/*
			// Custom test cases
			random_input_array[1] = 15;
			random_input_array[2] = 22;
			random_input_array[3] = 13;
			random_input_array[4] = 27;
			random_input_array[5] = 12;
			random_input_array[6] = 10;
			random_input_array[7] = 20;
			random_input_array[8] = 25;
			*/
			quicksort_rec(1,N);
                }

		/*
		** Quick sort, recursive module
		*/
		void quicksort_rec(int left, int right)
		{
			if ( left < right )
			{
				itteration_no = itteration_no + 1;
				// partition the array into two halves
				int pivot_index = quicksort_partition(left,right,itteration_no);
				
				quicksort_rec(left, pivot_index - 1);
				quicksort_rec(pivot_index + 1 , right);
			}
		}

		/*
		** Quick sort, partitioning an array
		*/
		int quicksort_partition( int left, int right , int itteration_no)
		{
			// select first element as pivot
			int pivot = random_input_array[left];
			int j = left; // pivot item

			for ( int i = left + 1; i<= right; i ++ )
			{
				if ( random_input_array[i] < pivot )
				{
					j++;
					swap_in_array(i,j);				
				}
			}
			// put pivot item at pivot point, j is pointing to pivot item
			swap_in_array(left, j);

			// after each itteration call gui function to display
                        std::string comment = "Itteration " + std::to_string(itteration_no);
                        print_gui_input_array(random_input_array, comment,N);

			// return index
			return j;
		}
	
};

/*
** Simulate a sorting algorithm based on user input
*/
void simulate_algo ( std::string choice , int N_size)
{
	SimulationAlgos S(N_size);
	S.generate_random_array();

        if ( choice == "1" )
        {
                // Exchange Sort
		S.exchangesort();
        }
        else if ( choice == "2" )
        {
                // Insertion Sort
		S.insertionsort();
        }
        else if ( choice == "3" )
        {
                // Merge Sort
		S.mergersort();
        }
        else if ( choice == "4" )
        {
                // Randomized Quick Sort
		S.quicksort();
        }
        else
        {
                cout << "EXCEPTION ! This shouldnt have occured, simulate_algo function failed, user entered " << choice << " as his input";
        }

	// after sorting, print the result
	S.print_sorted_array(S.random_input_array, "Sorted array", S.N );
}

/*
** Validate value of N ( input parameter, if it meets requirements
** Returns 0 for valid and -1 for invalid
*/
int validate_input_data_n(int n)
{
	if ( n < 1 || n > 1000 )
	{
		// invalid value , n should be between 1 and 1000
		cout << "Invalid value for n, please enter a valid value \n";
		return -1;
	}
	else
	{
		// valid value for N
		return 0;
	}
}

int main(int argc, char * argv[])
{

	std::string userinput;
	int input_data_n ;

        cout << "1. Exchange Sort \n" ;
	cout << "2. Insertion Sort \n";
    	cout << "3. Merge Sort \n" ;
	cout << "4. Randomized Quick Sort \n";
	cout << "5. Exit : To terminate  \n \n" ;

	while ( true )
	{
   		while ( std::getline(std::cin, userinput) && userinput != "" )
		{
			if ( userinput == "1" || userinput == "2" || userinput == "3" || userinput == "4" )
			{
				cout << "Enter number of input data (n) , should be between 1 and 1000 \n" ;
				do
				{
					cin >> input_data_n;
				}
				while ( validate_input_data_n(input_data_n) == -1 );
				simulate_algo(userinput,input_data_n);
			}
			else if ( userinput == "Exit" || userinput == "exit" || userinput == "5" )
			{
				cout << "Program terminated normally \n";
				exit(0);
			}
			else
			{
				cout << "Invalid command entered \n";
			}

			cout << "1. Exchange Sort \n" ;
        		cout << "2. Insertion Sort \n";
        		cout << "3. Merge Sort \n" ;
        		cout << "4. Randomized Quick Sort \n";
	        	cout << "5. Exit : To terminate  \n \n" ;
		}        
	}
}
