#include "agent.h"


// a quick-easy expensize sort, but will always take in very small arrays which will not make a difference to user.
// sort will sort an array of doubles from greatest to least.
void sort(vector<double>& values , vector<int>& pos){
	int size = values.size();
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
				if (values[i] < values[j] && i < j){
					double temp = values[i];
					int temp_int = pos[i];
					values[i] = values[j];
					values[j] = temp;
					pos[i] = pos[j];
					pos[j] = temp_int;
					
				}
			}
		}
	
}

void print_welcome_message(string& starting_node, node *& start, string& goal_node, node *& goal , vector<node*> Graph , int Graph_Size ){

	bool exit = true;
	cout << "Hello, please insert starting location (make sure your insert starts with a capital character):  ";
	cin >> starting_node;
	while (exit){


		for (int z = 0; z < Graph_Size; z++){
			if (starting_node == Graph[z]->location){
				exit = false;
				start = Graph[z];
			}
		}

		if (exit){
			cout << endl;
			cout << "Sorry, but that location does not exist. Please make sure to insert one that does exist:    ";
			cin >> starting_node;
		}
	}


	exit = true;
	cout << "Please, insert goal location:    ";
	cin >> goal_node;
	while (exit){
		for (int z = 0; z < Graph_Size; z++){
			if (goal_node == Graph[z]->location){
				exit = false;
				goal = Graph[z];
			}
		}

		if (exit){
			cout << endl;
			cout << "Sorry, but that location does not exist. Please make sure to insert one that does exist:    ";
			cin >> goal_node;
		}
	}
}