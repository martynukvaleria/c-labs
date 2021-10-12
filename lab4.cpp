#include <iostream>
#include <vector>

#define MAX 301
using namespace std;

bool sumbolinString(const char value, const char *place) {
    for (int i = 0; ((place[i] != '\n') && (place[i] != '\0')); i++) {
        if (value == place[i])
            return true;
    }
    return false;
}

int _strspn(const char *string, const char *strCharSet) {
    bool state = false;
    int counter = 0;
    for (int i = 0; string[i] != '\n'; ++i) {
        bool permit = sumbolinString(string[i], strCharSet);
        if (permit) {
            state = true;
            counter++;
        } else if ((!permit) && (state == true)) {
            return counter;
        }
    }
    return counter;
}

bool is_digit(vector<char> str) {
    for (int i = 0; i < str.size(); i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}

vector<char> getString(const char *str, const int start, const int end) {
    vector<char> answer;
    for (int i = start; i <= end; i++) {
        answer.push_back(str[i]);
    }
    return answer;
}

int searchNulls(const vector<char> word) {
    int nulls = 0;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == '0')
            nulls++;
    }
    return nulls;
}

int getSize(const char *str) {
    int answer = 0;
    for (int i = 0; str[i] != '\0'; i++)
        answer = i;
    return answer;
}
//part B
vector<char> SearchStringWithMaxNulls(const char *string) {
    bool state = false;
    vector<char> buffer;
    int start = 0;
    int end = 0;
    int currentNulls = 0;
    vector<char> last;
    vector<char> penult;
    int limit = getSize(string) + 2;
    for (int i = 0; i < limit; ++i) {
        if (string[i] != ' ' && state == false) {
            state = true;
            start = i;
        } else if (((string[i] == ' ') || (string[i] == '\0')) && state == true) {
            state = false;
            end = i - 1;
            buffer = getString(string, start, end);
            if (is_digit(buffer)) {
                if (currentNulls == searchNulls(buffer)) {
                    penult = last;
                    last = buffer;
                } else if (currentNulls < searchNulls(buffer)) {
                    last = buffer;
                    penult = buffer;
                    currentNulls = searchNulls(buffer);
                }
            }
        }
    }
    return penult;
}

void PrintString(const vector<char> &string) {
    for (auto i: string)
        cout << i;
    cout << '\n';
}

int main() {
/*  part A using
    char *str = new char[MAX];
    cin.getline(str, MAX, '\n');
    char *strCharSet = new char[MAX];
    cin.getline(strCharSet, MAX, '\n');
    cout << _strspn(str, strCharSet) << "\n";
    cin.getline(str, MAX, '\n');
    cout << searchNulls(str) << "\n"<<"\n";
*/
    char *string = new char[MAX];
    cout << "Enter string:\n";
    cin.getline(string, MAX, '\n');

    vector<char> penult = SearchStringWithMaxNulls(string);

    PrintString(penult);
}
