#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    string filename = "input/input1a.txt";
    ifstream file(filename);

    vector<int> col1;
    unordered_map<int, int> col2_map;
    string line;

    while(getline(file, line)) {
        istringstream stream(line);

        int num1, num2;

        stream >> num1 >> num2;

        col1.push_back(num1);
        col2_map[num2]++;
    }
    file.close();

    int score = 0;
    for(auto num : col1) {
        if (col2_map.find(num) != col2_map.end()) {
            score += num * col2_map[num];
        }
    }

    cout << score;
    return 0;
}
