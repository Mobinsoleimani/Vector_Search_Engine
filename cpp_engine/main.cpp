#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){

	//read bin file 
	
	ifstream file(
        "/home/hello-world/mini_vector_search_engine/vector.bin",
        ios::binary
    );
	if (!file){

		cerr << "CRITICAL ERROR: Could not find or open the file!" << endl;
		return 1;
	}

	int num_vector {0};
	int dim {0};

	file.read(reinterpret_cast<char*>(&num_vector),sizeof(int));
	file.read(reinterpret_cast<char*>(&dim),sizeof(int));


	vector <float> buffer(dim) ;
       	int count =0 ; 

	while(file.read(reinterpret_cast<char*>(buffer.data()),dim * sizeof(float))){
	
		cout <<"read_vector"<<count<<"first element"<<buffer[0];

		count++;

		
	
	}

	file.close();

	cout<< "read file succes";	

}
