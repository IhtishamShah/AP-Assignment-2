#include <iostream>
using namespace std;

class refCountStr {
	private:
		char* _strbuf;
		int _length;
	public:
		int refCount;

		refCountStr() {
			_strbuf = NULL;
			_length = 0;
			refCount = 1;
		}

		refCountStr(char* string, int length) {
			_strbuf = new char[length];
			_length = length;
			for (int i = 0; i < _length; i++) {
				_strbuf[i] = string[i];
			}
			refCount = 1;
		}

		~refCountStr() {
			delete[] _strbuf;
			_strbuf = NULL;
		}

		void append(char c) {
			int length = _length +1;
			char* _strbufTemp = new char[length];
			for (int i = 0; i < length; i++) {
				_strbufTemp[i] = _strbuf[i];
			}
			delete[] _strbuf;
			_strbuf = NULL;
			_strbuf = new char[length];
			_strbufTemp[_length] = c;
			_length+=1;
			for(int i=0;i<_length;i++){
				_strbuf[i] = _strbufTemp[i];
			}
			delete[] _strbufTemp;
			_strbufTemp = NULL;
		}

		int length() {
			return _length;
		}

		char charAt(int index) {
			if (index < _length) {
				return _strbuf[index];
			}
			else{
				return false;
			}
		}

		char* getString() {
			// char* new_str = new char[_length];
			// for (int i = 0; i < _length; i++) {
			// 	new_str[i] = _strbuf[i];
			// }
			return _strbuf;
		}
};