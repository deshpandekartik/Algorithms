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

typedef vector<vector<int>> EDGES;
typedef vector<int> COST;

struct QueeStruct
{
	int vertex;
	int value;
};



/*
	Kruskal's
*/
struct EDGE1
{
        int source;
        int dest;
        int cost;
};

typedef vector<EDGE1> EDGES_K;
typedef vector<int> SUBSET;

class Prims
{
        public:
		EDGES D;	// d matrix and p matrix
		COST cost,parent;
		int N;		// no of vertices
		int INF = 999, NILL = 0;

                /*
                ** Constructor , initialize rows and columns of all matrices
                */
		Prims( EDGES arg1, COST arg2, int n )
		{
			N = n;
			D = arg1;
			cost = arg2;
			parent = arg2;
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
					cost[i] = INF;	// initialize Cost matrix to Infinity
					parent[i] = NILL;	// Init parent matrix to 0 
                                }
                        }
			/*
			D = { {0,   4,  3, 3 },
                        { 4, 0, 10 ,8},
                        { 3, 10, 0 ,1},
                        { 3, 8, 1, 0}
                      };
			D = {{0, 2, 999, 6, 999},
                      {2, 0, 3, 8, 5},
                      {999, 3, 0, 999, 7},
                      {6, 8, 999, 0, 9},
                      {999, 5, 7, 9, 0},
                     };
			*/
                      	display_matrix_2d(D,"Randomly generated Matrix ");
                }

                /*
                ** Display a 2d matrix
                */
                void display_matrix_2d(EDGES arg_matrix, string comment)
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

		/*
                ** Display a matrix
                */
                void display_matrix_1d(COST arg_matrix, string comment)
                {
                        cout << comment << endl;
                        for (int i = 0; i < arg_matrix.size(); i++ )
                        {
                            	//cout << arg_matrix[i][j] << " ";
                              	printf ("%7d - %d", arg_matrix[i], i );
                                cout << "\n";
                        }
                        cout << "\n";
                }

		/*
		** Prims algo
		*/
		void prims()
		{
			// initially pick any node, ( lets say node 0 )
                        int root_node = 0;

			std::map<int, int> pq;
			std::map<int,int>::iterator it;

			for ( int i = 0; i < N; i++ )
			{
				cost[i] = INF;
				parent[i] = NILL;
				if ( i == 0 )
				{
					// add root node to quee
        		                pq[i] = 0;
				}
				else
				{
                                        pq[i] = INF;
				}
			}

			cost[root_node] = 0;
		

			string result = "";
			while ( pq.size() > 0 )
			{
	                        int min = 1000;
        	                int vertex;
                	        for (it = pq.begin(); it != pq.end(); it++)
                        	{
                        	        if ( (*it).second < min )
                        	        {
                        	                min = (*it).second;
                        	                vertex = (*it).first;
	                                }
					cout << "content " << (*it).first << " " << (*it).second << endl;
	                        }

				// remove top vertex 
				it = pq.find(vertex) ;
	                        pq.erase(it);
				cout << "selected " << vertex << endl ;	
				// all adjacent edges
				for ( int z = 0; z < N ; z++ )
                                {
					//cout << "cost " << z << " " << cost[z] << endl; 
                                        if ( pq.count(z) > 0 and D[vertex][z] < cost[z] )
                                        {
                                                cost[z] = D[vertex][z];
                                                parent[z] = vertex;
						result = result + " " + to_string(vertex) + " - > " + to_string(z) ;	

                                                pq[z] = cost[z];
                                        }
                                }
			}
			cout << result;
			display_matrix_1d(parent,"Final");
		}
};


class Kruskals
{
        public:
                EDGES D;        // d matrix and p matrix
		EDGES_K edge_arr;
                int N;          // no of vertices
                int INF = 999, NILL = 0;
		SUBSET SET, HEIGHT;

                /*
                ** Constructor , initialize rows and columns of all matrices
                */
                Kruskals( EDGES_K arg1,  int n )
                {
                        N = n;
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
                                                //D[i][j] = 0;
                                        }
                                        else
                                        {
                                                int number = generate_random_no();
                                                //D[i][j] = number;               // no between 1 and 10
                                                //D[j][i] = number;

						bool insert_flag = true;
						for ( int v = 0; v < edge_arr.size(); v ++ )
						{
							if ( ( edge_arr[v].source == i && edge_arr[v].dest== j ) || ( edge_arr[v].source == j && edge_arr[v].dest== i ))
							{
								insert_flag = false;	
								break;
							}
						}

						if ( insert_flag == true )
						{
							EDGE1 obj ;
							obj.source = i;	
							obj.dest = j;
							obj.cost = number;
							edge_arr.push_back(obj);
						}
                                        }
                                }
                        }

			/*
				// Custom test case

				EDGE1 obj ;

			    	// add edge 0-1
    				obj.source = 0;
    				obj.dest = 1;
    				obj.cost = 9;
				edge_arr.push_back(obj);

    				// add edge 0-2
    				obj.source = 0;
    				obj.dest = 2;
    				obj.cost = 1;
				edge_arr.push_back(obj);
 
    				// add edge 0-3
    				obj.source = 0;
    				obj.dest = 3;
    				obj.cost = 5;
				edge_arr.push_back(obj);

    				// add edge 1-2
    				obj.source = 1;
    				obj.dest = 2;
    				obj.cost = 9; 
				edge_arr.push_back(obj);
 
    				// add edge 1-3
    				obj.source = 1;
    				obj.dest = 3;
    				obj.cost = 5;
				edge_arr.push_back(obj);
 
    				// add edge 2-3
    				obj.source = 2;
    				obj.dest = 3;
    				obj.cost = 6;
				edge_arr.push_back(obj);
			
			*/

                       	//display_matrix_2d(D,"Randomly generated Matrix ");
                }

                /*
                ** Display a 2d matrix
                */
                void display_matrix_2d(EDGES arg_matrix, string comment)
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

                /*
                ** Display a matrix
                */
                void display_matrix_1d(EDGES_K arg_matrix, string comment)
                {
                        cout << comment << endl;
                        for (int i = 0; i < arg_matrix.size(); i++ )
                        {
                                //cout << arg_matrix[i][j] << " ";
                                printf ("%7d - %d 	Cost %d", arg_matrix[i].source, arg_matrix[i].dest, arg_matrix[i].cost );
                                cout << "\n";
                        }
                        cout << "\n";
                }


		void non_decreasingsort()
		{
			for ( int i = 0; i < edge_arr.size(); i++ )
			{
				for ( int j = i + 1; j < edge_arr.size(); j ++ )
				{
					if ( edge_arr[i].cost > edge_arr[j].cost )
					{
						// swap
						EDGE1 temp;
						temp = edge_arr[i];
						edge_arr[i] = edge_arr[j];
						edge_arr[j] = temp;
					}
				}
			} 
		}

		int find3 (int x)
		{
			// find root of tree with x
			int root = x;
			
			while ( root != SET[root] )
			{
				root = SET[root];
			}

			int node = x;

			while ( node != root )
			{
				int parent = SET[node];
				SET[node] = root;
				node = parent;
			}

			return node;
		}


		void union3 ( int repx, int repy )
		{
			if ( HEIGHT[repx] == HEIGHT[repy] )
			{
				// y’s tree points to x’s tree
				HEIGHT[repx] ++;
				SET[repy] = repx;
			}
			else
			{		
				if ( HEIGHT[repx] > HEIGHT[repy] )
				{
					// y’s tree points to x’s tree	
					SET[repy] = repx;
				}
				else
				{
					// x’s tree points y’s tree
					SET[repx] = repy;
				}
			}

		}

		/*
		** Kruskal's
		*/
		void kruskals()
		{
			// sort edges in non decreasing cost order
			display_matrix_1d(edge_arr, "Before");	
			non_decreasingsort();
			display_matrix_1d(edge_arr, "After");

			// T -> NuLL
			EDGES_K T;

			// For each vertex create subset 
			for ( int i = 0; i < N; i++ )
			{
				SET.push_back(i);
				HEIGHT.push_back(0);
			}

			// repeat untill T does not contaain | V | - 1 edges
			do
			{ 
				for ( int i = 0; i < edge_arr.size(); i ++ )
				{
					int ucomp = find3 (edge_arr[i].source);
					int vcomp = find3 (edge_arr[i].dest);

					if ( ucomp != vcomp )
					{
						// add edge to T
						T.push_back(edge_arr[i]);
						
						union3 (ucomp, vcomp);
					}
				}
			} while ( T.size() != N - 1 );

			display_matrix_1d(T, "After");
		}
};


int main()
{
	int n;
	srand ( (unsigned) time(NULL) );
	//n = rand() % 10 + 5;    // generates random number between 5 and 10

	n = 5;
     	cout << "Selected value of n ( Radmoly generated ) " << n << endl;

	COST cost_mat(n,0);
	EDGES input_mat(n, vector<int> (n, 0));
	Prims f1(input_mat,cost_mat,n);
	f1.input_matrix();
	f1.prims();


	/*
        n = 4;
        cout << "Selected value of n ( Radmoly generated ) " << n << endl;
	
	EDGES_K edges;
        Kruskals f1(edges,n);
        f1.input_matrix();
        f1.kruskals();
	
	*/
}
