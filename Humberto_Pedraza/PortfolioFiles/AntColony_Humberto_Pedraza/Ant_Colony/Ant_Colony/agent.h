/*
  Programmer: Humberto Pedraza
  Assignment #3: Ant Algrithms - Traveling in Romania

  Ant colony optimization algorithm to find the best path between any two nodes on the
  graph.

*/


#include "Parse_Line.h"

class agent{
public:
	node * at;
	vector<node*> been_at;
	vector<node*> taboo;
	int been_at_counter;
	int taboo_count;

	agent(){
		at = NULL;
		been_at_counter = 0;


	};

	agent(node * a){
		at = a;
		been_at_counter = 1;
		taboo_count = 0;
		been_at.push_back(a);
	};

	void clear_been_at(node * start){
		been_at.clear();
		taboo.clear();
		taboo_count = 0;
		at = start;
		been_at_counter = 1;
		been_at.push_back(start);

	}



};

void Erase_Agents_Path_Memory(vector<agent>& Ants, node * start , ofstream& Path_Tracker , int cycle){
	for (int i = 0; i < 10; i++){
		Path_Tracker << "Ant" << " " << i << ":Cycle "  << cycle << " = ";
		for (int j = 0; j < Ants[i].been_at_counter; j++){
			Path_Tracker << Ants[i].been_at[j]->location <<  " , ";
		}
		Path_Tracker << "\n";
		Ants[i].clear_been_at(start);
	}
}

void set_PM_Values(double ** &PM, vector<node*> Graph, int Graph_Size){
	for (int i = 0; i < Graph_Size; i++){
		bool set = false;
		for (int j = 0; j < Graph_Size; j++){
			if (!set){
				PM[i] = new double[Graph_Size];
				set = true;
			}

			PM[i][j] = .01;
		}

	}
}