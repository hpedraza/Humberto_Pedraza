/*
  Programmer: Humberto Pedraza
  Assignment #3: Ant Algrithms - Traveling in Romania

  Ant colony optimization algorithm to find the best path between any two nodes on the
  graph.

*/


#include "Sort.h"
/*
------ - ||

T(r, s) is the amount of pheromone currently on the path that goes directly from city r to city s
H(r, s) is the heuristic value of this link -- in the classic TSP application, this is choosen to be 1 / distance(r, s) --i.e.The shorter the distancem the higher the heuristic value.
P(r, s) is the probabilty that ant K will choose the link that goes from r to s
B is a parameter that we an call the heuristic strength
Pk(r, s) = [T(r, s) * H(r, s) ^ B] / [E(T(r, c) * H(r, c) ^ B)]; where out ant is at city r and s is a city as yet unvisted on its tour, and the summation is over all of k's unvisited cities

------ - ||
*/

void back_track(vector<agent>& Ants, int Ant_Tracker , vector<node*> Graph);
bool check_if_agent_is_stuck(vector<agent> Ants, int Ant_Tracker, vector<node*> Graph);
bool Not_In_Taboo_List(vector<agent> Ants, int Ant_Tracker , node* Node);


void get_agents_next_path(vector<agent>& Ants, int Ant_Tracker, double** Pheromone_Matrix, vector<node*> Graph){
	int random;
	int Beta = 1;
	double alpha = 3;
	
	vector<int> pos;
	vector<double> values;
	double * Prop = new double[Ants[Ant_Tracker].at->To_Size];
	int Prop_Tracker = 0;
	double total = 0;
	bool is_stuck;
	double denominator =0;
	bool checking = false;
	vector<int> list;

	// get all adjacent edgees to get denominator
	for (int n = 0; n < Ants[Ant_Tracker].at->To_Size; n++){
		for(int j =0; j < Ants[Ant_Tracker].been_at_counter; j++){
			if(Ants[Ant_Tracker].been_at[j]->location == Ants[Ant_Tracker].at->To[n]->location){
				checking = true;
		}
			else if(checking == false && j+1 == Ants[Ant_Tracker].been_at_counter){
				denominator += pow(static_cast<double>((Ants[Ant_Tracker].at->To_distance[n])),Beta) * pow(Pheromone_Matrix[Ants[Ant_Tracker].at->position_in_graph][Ants[Ant_Tracker].at->To[n]->position_in_graph],alpha); // caluclating adjacents edge distance multipled by the pheromone on that edge and adding that to denominator
			}
			
		}
		checking = false;
	}

	// Now get all adjacent's propabilty for each edge
	for (int n = 0; n < Ants[Ant_Tracker].at->To_Size; n++){
		for(int j =0; j < Ants[Ant_Tracker].been_at_counter; j++){
			if(Ants[Ant_Tracker].been_at[j]->location == Ants[Ant_Tracker].at->To[n]->location){
				checking = true;
				
		}
			else if(checking == false && j+1 == Ants[Ant_Tracker].been_at_counter){
					Prop[Prop_Tracker] = (pow(Pheromone_Matrix[Ants[Ant_Tracker].at->position_in_graph][Ants[Ant_Tracker].at->To[n]->position_in_graph] , alpha ) * pow(static_cast<double>((Ants[Ant_Tracker].at->To_distance[n])), Beta)) / denominator;
					//total += Prop[Prop_Tracker]; // adding up total for propability
					Prop_Tracker++;
					values.push_back(Prop[Prop_Tracker-1]);
					pos.push_back(n);
					//list.push_back(n);
			}
			
		}
		checking = false;

	}


	// here we will use divide edges propabily and divide that by total which is the added proabilities of each edge.  Than multiply it by .01 so we can have numbers between 0 and 1.  The reason
	// i did this is for rolling the dice.  I sort the edge taken by highest proabilt, than use rando, number generator to get a num. between 0 and 1. If random number is smaller than prop take that edge. Else check next in line of sorted list.
	// keep repeating till we reach the end.  If it reaches the end and nothing gets taken, than it will start all over at top of list until random number is smaller than a proabilty number. 

	//for (int n = 0; n < Prop_Tracker; n++){
		//Prop[n] = Prop[n] / total;
		//values.push_back(Prop[n]);
		//pos.push_back(list[n]);
	//}
		Prop_Tracker = 0;

	random = rand() % 100;
	if(values.size() > 0 ){
		sort(values, pos);
	}

	int val_track = 0;
	bool already_visited = false;
	is_stuck = check_if_agent_is_stuck(Ants, Ant_Tracker, Graph); // function will check if agent has any avaliable moves
	if (is_stuck == false){ // function is_stuck returns false that means there is at least one possible move
		while (true){
			already_visited = false;
			if (values[val_track] > random * .01 || values[val_track] == 1.0){
				
				for (int i = 0; i < Ants[Ant_Tracker].been_at_counter; i++){
					if (Ants[Ant_Tracker].been_at[i]->location == Graph[Ants[Ant_Tracker].at->To[pos[val_track]]->position_in_graph]->location){
						already_visited = true;
					}
				}

				
				if (!(already_visited) && !(Not_In_Taboo_List(Ants, Ant_Tracker, Graph[Ants[Ant_Tracker].at->To[pos[val_track]]->position_in_graph]))){
					Ants[Ant_Tracker].at = Graph[Ants[Ant_Tracker].at->To[pos[val_track]]->position_in_graph];
					Ants[Ant_Tracker].been_at.push_back(Graph[Ants[Ant_Tracker].at->position_in_graph]);
					Ants[Ant_Tracker].been_at_counter++;
					break;
				}
			}

			val_track++;
			random = rand() % 100;
			if (val_track == values.size()){
				val_track = 0;
			}
		}
	}

	else{ // if is_stuck return false than lets back track and add some nodes to taboo list
		// back track
		back_track(Ants , Ant_Tracker , Graph);
	}
}


void update_Pheromone(double **&PM , vector<node*> Graph , int Graph_Size , vector<agent> Ants , int Ant_Tracker , double rho){
/*
--------||

	Ak(r,s) is amount of pheromone added to the (r,s) link by ant k.
	m is the number of ants
	P is a parameter called the pheromone decay rate
	Lk is the length of the tour completed by ant k
	T(r,s) at the nex iteration becomes: P * T(r,s) + E (k = 1 to m) * Ak(r,s) ; where Ak(r,s) = 1/Lk

---------||
*/

	double total_pheromone;
	double total_distance = 0;
	for (int i = 0; i < Ants.size(); i++){
		for (int j = 0; j < Ants[i].been_at_counter-1; j++){
			for (int z = 0; z < Ants[i].been_at[j+1]->To_Size; z++){
				if (Ants[i].been_at[j + 1]->To[z]->location == Ants[i].been_at[j]->location){
					total_distance += Ants[i].been_at[j+1]->To_distance[z];
				}
			}
			
		}
		total_pheromone = 100 / total_distance;

		for (int j = 0; j < Ants[i].been_at_counter-1; j++){
			PM[Ants[i].been_at[j]->position_in_graph][Ants[i].been_at[j + 1]->position_in_graph] = 
				PM[Ants[i].been_at[j]->position_in_graph][Ants[i].been_at[j + 1]->position_in_graph]  + ((total_pheromone* rho));
		}


		total_distance = 0;
	}

	
}

bool check_if_agent_is_stuck(vector<agent> Ants , int Ant_Tracker , vector<node*> Graph){
	int track = 0;

	for (int i = 0; i < Ants[Ant_Tracker].been_at_counter; i++){
		for (int j = 0; j < Graph[Ants[Ant_Tracker].at->position_in_graph]->To_Size; j++){
			if (Ants[Ant_Tracker].been_at[i]->location == Graph[Ants[Ant_Tracker].at->position_in_graph]->To[j]->location){
				track++;			
			}
		}
	}

	for (int i = 0; i < Ants[Ant_Tracker].taboo_count; i++){
		for (int j = 0; j < Graph[Ants[Ant_Tracker].at->position_in_graph]->To_Size; j++){
			if (Ants[Ant_Tracker].taboo[i]->location == Graph[Ants[Ant_Tracker].at->position_in_graph]->To[j]->location){
				track++;
			}
		}
	}
	if (track >= Graph[Ants[Ant_Tracker].at->position_in_graph]->To_Size){
		return true;
	}


	return false;

}

void back_track(vector<agent>& Ants, int Ant_Tracker, vector<node*> Graph){
	
	Ants[Ant_Tracker].taboo.push_back(Ants[Ant_Tracker].been_at.back());
	Ants[Ant_Tracker].taboo_count++;
	Ants[Ant_Tracker].been_at.pop_back();
	Ants[Ant_Tracker].been_at_counter--;
	Ants[Ant_Tracker].at = Ants[Ant_Tracker].been_at.back();

	while (check_if_agent_is_stuck(Ants, Ant_Tracker, Graph)){

		Ants[Ant_Tracker].taboo.push_back(Ants[Ant_Tracker].been_at.back());
		Ants[Ant_Tracker].taboo_count++;
		Ants[Ant_Tracker].been_at.pop_back();
		Ants[Ant_Tracker].been_at_counter--;
		Ants[Ant_Tracker].at = Ants[Ant_Tracker].been_at.back();

	}


}


bool Not_In_Taboo_List(vector<agent> Ants, int Ant_Tracker , node* Node){
	for (int i = 0; i < Ants[Ant_Tracker].taboo_count; i++){
		if (Ants[Ant_Tracker].taboo[i]->location == Node->location)
			return true;
	}

	return false;
}

void evaporate(double **&PM, int Graph_Size, vector<node*> Graph , double rho ){
	for (int i = 0; i < Graph_Size; i++){
		for (int j = 0; j < Graph_Size; j++){
		
				PM[i][j] = PM[i][j] * (1 - rho) + rho;
			
		}
	}
}