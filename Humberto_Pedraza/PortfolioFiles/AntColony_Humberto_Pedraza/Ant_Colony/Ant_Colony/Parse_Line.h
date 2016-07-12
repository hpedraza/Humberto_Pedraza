#include "Node.h"


void Parse_Line( vector<node*>& Graph , string temp , int& Graph_Size){
	int first = 1;

	vector<char> location(16);
	string loc = "";
	int l = 0;

	vector<char> To(16);
	string to = "";
	int T = 0;

	vector<char> distance(7);
	string dist;
	int D = 0;
	
 	for (int z = 0; z < temp.size(); z++){
		if (first == 1){
			if (temp[z] != ','){
				location[l] = temp[z];
				l++; // int keping track so I can resize vchar vector with approriate length

			}
			else{
				location[l] = '!'; // this char is used to let program know when it has reached the end of the string; since I was having trouble
				// parsing I had to include a char to indicate when the end of the string was.  
				first = 0;
				loc.resize(l);
				l = 0; // reset l for next string
			}

		}

		else if (first == 0){ // first = 0, therefore program is reading in the estimated distance
			if (temp[z] != ','){
				To[T] = (temp[z]);
				T++; // same as purpose as int l; to keep track of vector<char> size
			}
			else{
				To[T] = '!';
				first = 2;
				to.resize(T);
				T = 0;
		}
		}

		else{
			distance[D] = temp[z];
			D++;
		}





	} // END OF FOR-LOOP
	distance[D] = '!';
	dist.resize(D);

	for (int x = 0; x < location.size(); x++){
		if (location[x] == '!') { break; }
		loc[x] = location[x];
	}

	for (int x = 0; x < To.size(); x++){
		if (To[x] == '!') { break; }
		to[x] = To[x];
	}

	for (int x = 0; x < distance.size(); x++){
		if (distance[x] == '!') { break; }
		dist[x] = distance[x];
	}




	// Now add to graph after parsing in read in line
	for (int i = 0; i < Graph_Size; i++){
		if (Graph[i]->location == loc){

			for (int j = 0; j < Graph_Size; j++){
				if (Graph[j]->location == to){
					Graph[i]->To.push_back(Graph[j]);
					Graph[i]->To_distance.push_back(atoi(dist.c_str()));
					Graph[i]->To_Size++;
					return;
				}
			}

			node * temp_node = new node;
			temp_node->location = to;
			temp_node->position_in_graph = Graph_Size;
			Graph[Graph_Size] = temp_node;
			Graph_Size++;
			Graph[i]->To.push_back(Graph[Graph_Size - 1]);
			Graph[i]->To_distance.push_back(atoi(dist.c_str()));
			Graph[i]->To_Size++;
			return;
		}
	}
	node *temp_node = new node;
	node * temp_node_2 = new node;

	temp_node->location = loc;
	temp_node->position_in_graph = Graph_Size;
	temp_node->To.push_back(temp_node_2);
	temp_node->To_distance.push_back(atoi(dist.c_str()));
	temp_node->To_Size++;
	temp_node_2->location = to;
	temp_node_2->position_in_graph = Graph_Size + 1;

	//Graph[Graph_Size] = new node(location);
	Graph[Graph_Size] = temp_node;
	Graph[Graph_Size + 1] = temp_node_2;

	//Graph[Graph_Size]->To.push_back(Graph[Graph_Size + 1]);
	//Graph[Graph_Size]->To_distance.push_back(atoi(dist.c_str()));
	//Graph[Graph_Size]->To_Size++;
	Graph_Size = Graph_Size + 2;
}

