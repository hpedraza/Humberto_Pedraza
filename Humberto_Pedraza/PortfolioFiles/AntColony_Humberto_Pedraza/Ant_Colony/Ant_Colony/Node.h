#include <vector>
#include <string>

using namespace std;

class node{
public:
	string location;
	vector<node*> To;
	vector<int> To_distance;
	int To_Size;
	int position_in_graph;

	node(){
		location = "NULL";
		To_Size = 0;
	
	};

	node(string loc){
		location = loc;
		To_Size = 0;
	};





};