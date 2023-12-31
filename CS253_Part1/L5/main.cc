#include <iostream>
#include "ll.h"

using namespace std;

int main() {
    LinkedList list;
    //list.initialize();

    for (bool done = false; !done; ) {
	unsigned int i;
	int option;

	cout << "Choose your operation:\n"
	     << "1. insert\t2. remove\t3. exit      4. display list\n";

	cin >> option;

	switch (option) {
	    case 1:
		cout << "Enter the number to insert\n";
		cin >> i;
		list.insert(i);
		break;
	    case 2:
		if (list.remove(&i))
		    cout << "removed " << i << '\n';
		else
		    cout << "No numbers in the list\n";
		break;
	    case 3:
		done = true;
		break;
        case 4:
            cout << list << '\n';
        break;
	}
    }

    return 0;
}
