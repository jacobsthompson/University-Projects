#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, const char * argv[])
{
	LinkedList* linkedList = new LinkedList(new int(47));
	linkedList->add(linkedList->head, 5);
	linkedList->add(linkedList->head->next->next, 5);
	linkedList->print();
	linkedList->cleanup();

	return 0;
}