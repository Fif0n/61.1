#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class file{
	public:
		ifstream fIn;
		ofstream fOut;

		file();
		~file();
};

file::file(){
	fIn.open("C:\\ciagi.txt");
	fOut.open("C:\\wynik1.txt");
}

file::~file(){
	fIn.close();
	fOut.close();
}


class ciag{
	private:
		vector <int> ciag;
		int lenght, diff, counter = 0, max = 0, num;
		bool isAritmetic;
		file f;
		public:
			void checkAritmetic();
		
};

void ciag::checkAritmetic(){
	while(!f.fIn.eof()){
		f.fIn>>lenght;
		for(int i = 0; i<lenght;i++){
			f.fIn>>num;
			ciag.push_back(num);
		}
		diff = ciag[1] - ciag[0];
		isAritmetic = true;
		for(int i = 0; i+1<lenght;i++){
			if(ciag[i+1] - ciag[i] != diff){
				isAritmetic = false;
			}
		}
		
		if(isAritmetic){
			counter++;
			if(max<diff){
				max = diff;
			}	
		}
		ciag.clear();
		
	}
	fOut<<counter<<endl<<max;
}

int main(int argc, char** argv) {
	ciag c1;
	c1.checkAritmetic();
	return 0;
}
