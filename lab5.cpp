#include <iostream>
#include <string>
#include <fstream>

using namespace std;
bool IsNullOrEmpty(string& str){
    if(str.empty())
        return true;
    if(str[0] == ' '){
        for(char s : str){
            if(s != ' ')
                return false;
        }
        return true;
    }
    return false;
}
void FindEmptyLinesInFile(ifstream& inpfile, ofstream& outfile){
    if (!inpfile || !outfile) {
        cout << "Error!";
        return;
    }
    int line_number = 1, empty_line_number;
    int count_empty_lines = 0;
    while (inpfile) {
        string line;
        getline(inpfile, line);
        if (IsNullOrEmpty(line)) {
            count_empty_lines++;
            if (count_empty_lines == 1)
                empty_line_number = line_number;
        } else {
            if (count_empty_lines != 0) {
                outfile << "First line: " << empty_line_number << "; Amount of empty lines: " << count_empty_lines << "\n";
                count_empty_lines = 0;
            }
        }
        line_number++;
    }
}

int main() {

    ifstream inpfile("input.txt");
    ofstream outfile("output.txt");
    FindEmptyLinesInFile(inpfile, outfile);
    return 0;
}
