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


	// تست ۱: دو بردار عمود بر هم (باید ۰ برگرداند)
	vector<float> v1 = {1.0f, 0.0f};
	vector<float> v2 = {0.0f, 1.0f};
	cout << "Perpendicular (90 deg): " << dif_calcul(v1, v2) << endl; 

// تست ۲: دو بردار متفاوت (باید عددی بین ۰ و ۱ برگرداند)
	vector<float> v3 = {1.0f, 2.0f};
	vector<float> v4 = {6.0f, 1.0f};
	cout << "Different angle: " << dif_calcul(v3, v4) << endl;
	/*ifstream file("query.bin",ios::binary);
	if (!file){
	
		cout<< "file not finde"<<endl;
		return 1;
	}
	
	//qvec == query file vector 
	vector <float> qvec(384,0.0f);


	file.read(reinterpret_cast<char*>(qvec.data()), qvec.size() * sizeof(float));

    	file.close();

  	  
   	//cout << "Success! First 3 elements: " << endl;
  	cout << "1: " << qvec[0] << endl;
  	cout << "2: " << qvec[1] << endl;
        cout << "3: " << qvec[2] << endl;
*/


}
