#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	fstream file("test.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            int i = line.size() - 1;
            cout << line[i] << endl;
        }

        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}