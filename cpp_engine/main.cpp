#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){

	ifstream file(
        "mini_vector_search_engine/vector.bin",
        ios::binary
    );

    if (!file) {
        cerr << "Error: cannot find file\n";
        return 1;
    }

    int num = 0;
    int dim = 0;

    
    file.read(reinterpret_cast<char*>(&num), sizeof(int));
    file.read(reinterpret_cast<char*>(&dim), sizeof(int));

    cout << "num = " << num << ", dim = " << dim << endl;

    if (num <= 0 || dim <= 0) {
        cerr << "Invalid header\n";
        return 1;
    }

    size_t total = static_cast<size_t>(num) * dim;
    cout << "total floats = " << total << endl;

    vector<float> vec(total);

    file.read(reinterpret_cast<char*>(vec.data()),
              total * sizeof(float));

    file.close();

    cout << "Read " << vec.size() << " floats successfully!\n";
    cout << "First 5 elements: ";

    for (int i = 0; i < 5 && i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << std::endl;

}
