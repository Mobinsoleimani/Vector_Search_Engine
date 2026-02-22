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
 
	ifstream file("vector.bin", ios::binary);
        //read query bin file

        ifstream file_q("query.bin",ios::binary);


        if (!file && !file_q){


                cerr << "CRITICAL ERROR: Could not find or open the file!" << endl;

                return 1;

        }


        vector <float> qvec(384,0.0f);

	file_q.read(reinterpret_cast<char*>(qvec.data()), qvec.size() * sizeof(float));



        // read vector or database file


        float max_score = 0.0;

        int num_vector {0};

        int dim {0};


        file.read(reinterpret_cast<char*>(&num_vector),sizeof(int));

        file.read(reinterpret_cast<char*>(&dim),sizeof(int));



        vector <float> buffer(dim) ;

        int count =0 ;


        int best_index = -1;

        while(file.read(reinterpret_cast<char*>(buffer.data()),dim * sizeof(float))){


                float cal = dif_calcul(qvec,buffer );


                if (cal > max_score ){


                        max_score = cal ;

                        best_index = count;

                }


                count++;




        }


        file.close();



        string result ;


        ifstream text_file("vector.txt"); 

	if (text_file.is_open() && best_index != -1){
    		for(int j = 0 ; j <= best_index ; j++ ){
    		    getline(text_file, result);
    		}
   
    	cout << "Best Match: " << result << endl; 
    	cout << "Confidence Score: " << max_score << endl;
    	text_file.close();
	} else {

        	cout << "No match found or file error." << endl;

        }

 
 

}
