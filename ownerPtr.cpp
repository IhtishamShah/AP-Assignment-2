#include <iostream>
#include "ownerStr.cpp"
using namespace std;

class ownerTransferPtr {
	private:
		ownerTransferStr* ptr;
	public:
		bool owner;

		ownerTransferPtr() {
			ptr = new ownerTransferStr();
			owner = true;
		}

		ownerTransferPtr(char* string, int length) {
			ptr = new ownerTransferStr(string, length);
			owner = true;
		}

		ownerTransferPtr(ownerTransferPtr& obj) {
			// if (owner) {
			// 	delete ptr;
			// 	ptr = NULL;
			// }
			ptr = obj.ptr;
			owner = true;
			obj.owner = false;
		}

		ownerTransferPtr operator=(ownerTransferPtr& obj) {
			if (owner) {
				delete ptr;
				ptr = NULL;
			}
			ptr = obj.ptr;
			owner = true;
			obj.owner = false;
		}

		~ownerTransferPtr() {
			if (owner){
				delete ptr;
				ptr = NULL;
			}
		}

		void append(char c) {
			if (owner) {
				ptr->append(c);
			}
		}

		int length() {
			return ptr->length();
		}

		char charAt(int index) {
			if(!ptr->charAt(index)){
				cout << "Invalid Index";
			}
			else{
				cout << ptr->charAt(index);
			}
		}

		char* getString() {
			return ptr->getString();
		}
};