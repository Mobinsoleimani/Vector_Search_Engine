#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;


float dif_calcul(const vector <float> &A,const vector <float> &B){

        float vec_dot = 0 ;
        float vec_a_power = 0;
        float vec_b_power =0 ;  

        for (int i = 0;i <A.size(); i++){

                vec_dot += A[i] * B[i];

                vec_a_power += A[i] * A[i];

                vec_b_power += B[i] * B[i];     

        }

        return vec_dot / (sqrt(vec_a_power) * sqrt(vec_b_power));
}
int main(){

	//read bin file 
	
	ifstream file(
        "mini_vector_search_engine/vector.bin",
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
