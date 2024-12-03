#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string filename = "input/input1a.txt";
    ifstream file(filename);


    vector<int> col1, col2;
    string line;

    while(getline(file, line)) {
        istringstream stream(line);

        int num1, num2;

        stream >> num1 >> num2;

        col1.push_back(num1);
        col2.push_back(num2);
    }
    file.close();

    sort(col1.begin(), col1.end());
    sort(col2.begin(), col2.end());

    int distance = 0;
    for(int i = 0; i < col1.size(); i++) {
        distance += abs(col1[i]-col2[i]);
        cout << col1[i] << "; " << col2[i] << ": " << distance << "\n";
    }

    cout << distance;
    return 0;
}
