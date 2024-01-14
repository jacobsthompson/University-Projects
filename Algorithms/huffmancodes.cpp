#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
char abcdef[6] = {'A','B','C','D','E','F'};								//array storing the hardcoded 6 letters

struct Node{															//struct that builts the Nodes		
	char letter;														//stores the letter of node
	int freq;															//stores frequency of letter of node
	struct Node* left;													//stores pointer to left child
	struct Node* right;													//stores pointer to right child
	Node(char letter, int freq){										//builds node
		this->letter = letter;
		this->freq = freq;
		this->left = NULL;
		this->right = NULL;
	}
};

class NodeList{															//builds a Binary tree using a vector list of nodes
	public:
	vector<Node*> arr;													//our array of all our nodes
	NodeList(){}

	void makelist(char letter[], int freq[]){							//makes the original list containing all 6 letters nodes
		for(int i = 0; i < 6; i++){
			arr.push_back(new Node(letter[i],freq[i]));
		}
	}

	Node* extractMin(){													//finds the minimum frequency in our arr vector list
		int size = arr.size();											//sets size for loops equal to vector size, because the size will be changing
		Node* smallest = arr[0];										//set smallest element to first element
		for(int i = 1; i < size; i++){									//classic loop through to find smallest element
			if(arr[i]->freq < smallest->freq ){
				smallest = arr[i];
			}
		}

		for(int i = 0; i < size; i++){									//once smallest is found, we loop through arr to find its position
			if(arr[i] == smallest){
				arr.erase(arr.begin()+i);								//remove the smallest element from the list
			}
		}
		return smallest;												//return the smallest node
	}
																		//this is how we print our tree with its new coded form.
	void travel(Node* temp, int path[], int counter, int cletter){		//temp is our current node, path is our 0's and 1's, counter is the number of 0's and 1's and cletter is what letter the travel should search for
		if(temp->left != NULL){											//check if current node has a left child
			path[counter] = 0;											//if so, add a 0 (left) to our path
			travel(temp->left,path,counter+1,cletter);					//recursive travel to left node, increasing counter position
		}
		if(temp->right != NULL){										//check if current node has a right child
			path[counter] = 1;											//if so add a 1 (right) to our path
			travel(temp->right,path,counter+1,cletter);					//recursive travel to right node, increasing counter position
		}
		if(temp->left == NULL && temp->right == NULL){					//if we have reached a bottom node with no children, we found a letter
			if(temp->letter == abcdef[cletter]){						//if the letter in node is in alphabetical order, print
				cout << temp->letter << ":";							//print out letter :
				for(int i = 0; i < counter; i++){						//loop through our path array
					cout << path[i];									//print all 0's and 1's
				}
				cout << endl;
			}
		}
	}

	void print(Node* temp){												//this function prints out binary tree in its original form (unused)												
		if(temp != NULL){												//checks if node is not bottom node
			cout << temp->letter << ":" << temp->freq << endl;			//print out letter and frequency
			print(temp->left);											//recursive down left path
			print(temp->right);											//recursive down right path
		}
	}

	void huffman(){														//the huffman algorithm pseudocode
		for(int i = 0; i < 5; i++){										//loop through list n-1 times
			Node* z = new Node('\0',0);									//create a new empty parent node 
			z->left = extractMin();										//set minimum from list to left child
			z->right = extractMin();									//set second minimum from list to right child
			z->freq = z->left->freq + z->right->freq;					//set frequency to the childrens frequency's sum
			arr.push_back(z);											//put new parent node back into array
		}
		int path[6];													//create a path array that keeps the 0's and 1's (6 max because only 6 elements)
		for(int i = 0; i < 6; i++){										//print out each letters code code (travel finds the ith letter in our global abcdef[])
			travel(extractMin(),path,0,i);
		}												
	}
};

int main() {
	int freq[6];														//create array of frequencies
	for(int i = 0; i < 6; i++){	cin >> freq[i]; }						//fills array with frequencies alpabetically 

	NodeList list;														//create nodelist
	list.makelist(abcdef,freq);											//make original list
	list.huffman();														//huffman encode it
  	return 0;
}