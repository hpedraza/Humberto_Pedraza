/*
  Programmer: Humberto Pedraza
  Assignment #3: Ant Algrithms - Traveling in Romania

  Ant colony optimization algorithm to find the best path between any two nodes on the
  graph.

  Program will produce a .txt file called PathTracker.  It will display all the cycles, with ant number and its path. 

  Program always find optimal path (in my testing).
*/


#include <iostream>
#include<fstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "get_agents_next_path.h"


/*
	Population Size = 10
	Max. Cycles = 50
	Amount of Pheromone per ant,per cycle = 100
*/

int main(){

	srand(time(NULL));

	// Read in graph
	ifstream graph;
	ofstream Path_Tracker;
	Path_Tracker.open("Path_Tracker.txt");
	string temp;
	vector<node*> Graph(25);
	vector<agent> Ants;
	double rho = 0.65;

	int Graph_Size = 0;
	graph.open("graph.txt");

	// Make graph
	while (!(graph.eof())){
		getline(graph , temp);
		Parse_Line(Graph , temp , Graph_Size);
	}

	graph.close();
	// Ask user for start Node and End node
	string starting_node; 
	node * start = NULL;
	string goal_node;
	node * goal = NULL;
	int Ant_Tracker = 0;

	print_welcome_message(starting_node, start, goal_node, goal , Graph , Graph_Size); // Function is found in sort.h


	// Step 1: Intialization
		// -- Randolmy place K agents on the graph.  
	for (int i = 0; i < 10; i++){

		agent temp_ant(start);
		Ants.push_back(temp_ant);
	}
		// -- Pheromone matric T(i,j) are intialized with a random value.  The major challenge in the intializaion process is determining the heuristic matrix.
	double **Pheromone_Matrix = new double*[Graph_Size];

	set_PM_Values(Pheromone_Matrix , Graph , Graph_Size); // intialize Pheromones
	//evaporate(Pheromone_Matrix, Graph_Size, Graph, rho); // evaporate pheromones
	for (int cycle = 0; cycle < 200; cycle++){
		while (Ants[Ant_Tracker].at->location != goal_node){
			// Step 2: Contruction Process
			// -- The Probability with which the agent moves is given by the probabilty equation Pxy				
			get_agents_next_path(Ants, Ant_Tracker, Pheromone_Matrix,Graph); // get agents next path and keep executing until agent arrives at goal

			// Step 3 (and 5): Update Process
			// -- The pheromone matrix is updated twice. In step 3 the trail of the ant (given by T(x,y)) is updated where as in step 5 the evaporation rate of the trail is updated which is given by the below equation.  Tnew = (1 - Pheromone decay)Told + Pheromone decay coeficient 0 < t < 1
			
			// Step 7: Decision Process:
			// -- Once the K ants have moved a fixed distance L for N iteration, the decision whether it is an edge or not s based n the threshold T on the pheromone matrix.  Thereshold for the below example is calculated based on Otsu's method.
		}

		
		Ant_Tracker++;
		cycle--;
		if (Ant_Tracker == 10){
			// decay pheromones
			Ant_Tracker = 0;
			cycle++;
			// Now update pheromones edges
			update_Pheromone(Pheromone_Matrix, Graph, Graph_Size, Ants, Ant_Tracker , rho); // update new path
			evaporate(Pheromone_Matrix, Graph_Size, Graph, rho); // evaporate pheromones
			Erase_Agents_Path_Memory(Ants , start , Path_Tracker , cycle); // erase agents memory because they will all start over at start node
			
			
		}
		
	} // END OF FOR LOOP CYCLE

	
	delete[] Pheromone_Matrix;
	Path_Tracker.close();
	system("pause");
	return 0;
}
