#include <iostream>
#include "copiedStr.cpp"
using namespace std;

class copyPtr {
	private:
		copyStr* ptr;
	public:
		copyPtr() {
			ptr = new copyStr();
		}

		copyPtr(char* string, int length) {
			ptr = new copyStr(string, length);
		}

		copyPtr(copyPtr& obj){
			ptr = new copyStr(obj.getString(), obj.length());
		}

		copyPtr operator=(copyPtr &obj){
			ptr = new copyStr(obj.getString(), obj.length());

		}

		~copyPtr() {
			delete ptr;
			ptr = NULL;
		}

		void append(char c) {
			ptr->append(c);
		}

		int length() {
			return ptr->length();
		}

		void charAt(int index) {
			if(!ptr->charAt(index)){
				cout << "Invalid Index";
			}
			else{
				cout << ptr->charAt(index) << endl;
			}
		}

		char* getString() {
			return ptr->getString();
		}
};