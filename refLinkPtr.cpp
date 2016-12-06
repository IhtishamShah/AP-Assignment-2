#include <iostream>
#include "refLinkStr.cpp"
using namespace std;

class refLinkPtr {
	private:
		refLinkStr* ptr;
	public:
		refLinkPtr* prev;
		refLinkPtr* next;

		refLinkPtr() {
			ptr = new refLinkStr();
			prev = this;
			next = this;
		}

		refLinkPtr(char* string, int length) {
			ptr = new refLinkStr(string, length);
			prev = this;
			next = this;
		}

		refLinkPtr(refLinkPtr& obj) {
			ptr = obj.ptr;
			next = obj.next;
			prev = &obj;
			next->prev = this;
			prev->next = this;
		}

		refLinkPtr operator=(refLinkPtr& obj){
			ptr = obj.ptr;
			next = obj.next;
			prev = &obj;
			next->prev = this;
			prev->next = this;
		}

		~refLinkPtr(){
			if (prev == this) {
				// cout << "Woah" << endl;
				delete ptr;
				ptr = NULL;
				next = NULL;
				prev = NULL;
			}
			else {
				// cout << "LOL" << endl;
				prev->next = next;
				next->prev = prev;
				next = NULL;
				prev = NULL;
			}

		}

		void append(char c) {
			ptr->append(c);
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