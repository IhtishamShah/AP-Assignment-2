#include <iostream>
using namespace std;

class copyStr {
	private:
		char* _strbuf;
		int _length;
	public:
		copyStr() {
			_strbuf = NULL;
			_length = 0;
		}

		copyStr(char* string, int length){
			_length = length;
			_strbuf = new char[_length];
			for (int i = 0; i < _length; i++) {
				this->_strbuf[i] = string[i];
			}
		}

		~copyStr() {
			// if (_strbuf != NULL) {
			delete[] _strbuf;
			_strbuf = NULL;
			// }
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

		char charAt(int index){
			if (index < _length) {
				return _strbuf[index];
			}
			else{
				return false;
			}
		}

		char* getString() {
			return _strbuf;
		}
};