#include <iostream>
#include "refCountStr.cpp"
using namespace std;

class refCountPtr {
	private:
		refCountStr* ptr;
	public:

		refCountPtr() {
			ptr = new refCountStr();
		}

		refCountPtr(char* string, int length) {
			ptr = new refCountStr(string, length);
		}

		refCountPtr(refCountPtr& obj) {
			ptr = obj.ptr;
			ptr->refCount++;
		}

		refCountPtr operator=(refCountPtr& obj){
			ptr = obj.ptr;
			ptr->refCount++;
		}
		
		~refCountPtr() {
			if (ptr->refCount == 1) {
				delete ptr;
			}
			ptr = NULL;
		}

		int getRefCount() {
			return ptr->refCount;
		}

		// refCountString* getPtr() {
		// 	return ptr;
		// }

		void append(char c) {
			// if (ptr->refCount == 1) {
			// 	ptr->append(c);
			// }
			// else{
			// 	ptr->refCount--;
			// 	ptr = new refCountString(ptr->getString(), ptr->length());
			// 	ptr->append(c);
			// }
			ptr->append(c);
		}

		int length() {
			return ptr->length();
		}

		char charAt(int index) {
			return ptr->charAt(index);
		}

		char* getString() {
			return ptr->getString();
		}
};