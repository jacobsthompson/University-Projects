#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Hash{
	int size;
	list<int> *table;
	public:
	Hash (int V);
	void insert(int x);
	void search(int x);
	void del(int x);
	int mod(int x){
		return (x % size);
	}
	void display();
};

Hash::Hash(int s){
	this->size = s;
	table = new list<int>[size];
}

void Hash::insert(int key){
	int place = mod(key);
	table[place].push_front(key);

}
void Hash::del(int key){
	int place = mod(key);
	list<int>::iterator i;
	for(i = table[place].begin(); i != table[place].end(); i++){
		if(*i == key){
			break;
		}
	}

	if(i != table[place].end()){
		table[place].erase(i);
		std::cout << key << ":" << "DELETED" << ';' << std::endl;
	} else {
		std::cout << key << ":" << "DELETE_FAILED" << ';' << std::endl;
	}
}
void Hash::search(int key){
	list<int>:: iterator i;
	int count = 0;
	int place = mod(key);
	for(i = table[place].begin(); i != table[place].end();i++){
		if(*i == key){
			break;
		}
		count++;
	}

	if(i != table[place].end()){
		std::cout << key << ":" << "FOUND_AT" << place << ',' << count << ';' << std::endl;
	} else {
		std::cout << key << ":" << "NOT_FOUND" << ';' << std::endl;
	}
}
void Hash::display(){
	for(int i = 0; i < size; i++){
		cout << i << ":";
		for(int x : table[i]){
			cout << x << "->";
		}
		cout << ";" << endl;
	}
}

int main(int argc, char const *argv[]) {

  int number =  0;
  int hashSize = 0;
  bool repeat = true;

  string input = "";

  cin >> hashSize;
  Hash HT(hashSize);

  //

  do{
      number = 0;
      cin >> input;
      //Create integer if required by function
      if (input[0] != 'o' || input[0] != 'e'){
        for (int i = 1; i < input.size(); i++){
          int digit = input[i] - '0';
          number = 10 * number + digit;
        }
      }

      if(input[0] == 'i'){
       HT.insert(number);
      }else if(input[0] == 'd'){
       HT.del(number);
      }else if(input[0] == 's'){
       HT.search(number);
      }else if(input[0] == 'o'){
       HT.display();
      }else if(input[0] == 'e'){
        repeat = false;
      }else{
        cout << "Wrong input" << endl;
      }
  }while(repeat);

  return 0;
}