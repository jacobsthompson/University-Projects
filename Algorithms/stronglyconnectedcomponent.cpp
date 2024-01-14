#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
public:
	vector<int> V;
	void addedge(int u, int v);
	void printGraph();
};

void Graph::addedge(int u, int v){
	V.push_back(u);
	V.push_back(v);
}

void Graph::printGraph(){
	for(int i = 0; i < V.size();i++){
		cout << V[i] << " ";
	}
	cout << endl;
}

void DFS(Graph G, int start){
	stack<int> S;
	bool *visited = new bool[G.V.size()];
	for(int i = 0; i < G.V.size(); i++){
		visited[i] = false;
	}

	S.push(start);

	while(S.empty() == false){
		int temp = S.top();
		S.pop();
		if(visited[temp] == false){
			cout << temp << " ";
			visited[temp] = true;

			vector<int> adjacent = G.adj[temp];
			for(int i = 0; i < adjacent.size(); i++){
				if(visited[adjacent[i]] == false){
					S.push(adjacent[i]);
				}
			}
		}
	}
}

vector<vector<int>> SCC(Graph G){
	
}

// struct Vertex{
// 	int num;
// 	int color;
// 	int d;
// 	int f;
// 	struct Vertex* pi;
// 	struct Vertex* next;
// };

// void append(Vertex** head, int headindex, int newnum){
// 	Vertex* temp = new Vertex();
// 	Vertex* last = *(head+headindex);
// 	temp->num = newnum;
// 	temp->next = NULL;
// 	if(*(head+headindex) == NULL){
// 		*(head+headindex) = temp;
// 		return;
// 	}

// 	while(last->next != NULL){
// 		last = last->next;
// 	}
// 	last->next = temp;
// }

// int listlen(Vertex* head){
// 	int count = 0;
// 	Vertex* current = head;
// 	while(current != NULL){
// 		count++;
// 		current = current->next
// 	}
// 	return count;
// }

// void printList(Vertex** head, int count){
// 	for(int i = 0; i < count; i++){
// 		Vertex* current = *(head+i);
// 		cout << i << ": ";
// 		while(current != NULL){
// 			cout << current->num << " ";
// 			current = current->next;
// 		}
// 		cout << endl;
// 	}
// }

// void DFSVisit(Vertex** head, Vertex* u, int time){
// 	time++;
// 	u->d = time;
// 	u->color = 1;
// 	Vertex* v = u;
// 	while(v != NULL){
// 		if(v->color == 0){
// 			v->pi = u;
// 			DFSVisit(head,v,time);
// 		}
// 		v = v->next;
// 	}
// 	u->color = 2;
// 	time++;
// 	u->f = time;
// }

// void DFS(Vertex** head, int count){
// 	for(int i = 0; i < count; i++){
// 		Vertex* u = *(head+i);
// 		u->color = 0;
// 		u->pi = NULL;
// 	}
// 	int time = 0;
// 	for(int i = 0; i < count; i++){
// 		Vertex* u = *(head+i);
// 		if(u->color == 0){
// 			DFSVisit(head, u, time);
// 		}
// 	}
// }

// void printDFS(Vertex** head, int count){
// 	for(int i = 0; i < count; i++){
// 		Vertex* current = *(head+i);
// 		cout << head+i << " color: " << current->color << " start: " << current->d << " end: " << current->f << " pi: " << current->pi << endl;
// 	}
// }


int main(){
	int verticies = 0;
	cin >> verticies;
	int edges = 0;
	cin >> edges;
	Graph G;
	// Vertex** head;
	// head = new Vertex*[verticies];
	// for(int i = 0; i < verticies; i++){
	// 	*(head+i) = NULL;
	// }

    for(int i = 0; i < edges; i++){
    	int u;
    	int v;
    	cin >> u >> v;
    	G.addedge(u,v);
    }

    G.printGraph();
    cout << endl;
    DFS(G,0);
    //printDFS(head,verticies-1);
 
    return 0;
}