#include <iostream>
#include "copiedPtr.cpp"
#include "ownerPtr.cpp"
#include "refCountPtr.cpp"
#include "refLinkPtr.cpp"
using namespace std;



int main() {
	char x = 'a';
	cout << "Copy pointer:" << endl;
	copyPtr cpy1;
	copyPtr cpy2("Darts", 5);
	cpy2.append(x);
	cout << cpy2.getString() << endl;
	copyPtr cpy3 = cpy2;
	cout << cpy3.getString() << endl;

	cout << &cpy1 << endl;
	cout << &cpy2 << endl;
	cout << &cpy3 << endl;
	cout << endl;


	cout << "Owned pointers:" << endl;

	ownerTransferPtr owner1("Darts",5);
	ownerTransferPtr owner2=owner1;
	owner2.append(x);
	cout << owner2.getString() << endl;
	cout << &owner1 << endl;
	cout << &owner2 << endl;

	cout << endl;

	cout << "COW with reference linking:" << endl;

	refLinkPtr refLink1("Darts",5);
	refLinkPtr refLink2 = refLink1;
	refLink2.append(x);
	cout << refLink2.getString() << endl;

	cout << &refLink1 << endl;
	cout << &refLink2 << endl;
 	
	cout << endl;

	cout << "COW with reference counting: "<< endl;
	refCountPtr refCount1("Darts",5);
	refCountPtr refCount2 = refCount1;
	refCount2.append(x);
	cout << refCount2.getString() << endl;
	cout << &refCount1 << endl;
	cout << &refCount2 << endl;
	return 0;
}