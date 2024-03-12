#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigit(string n, int b) {
    string c_d; // Combined string after concatenating n 'b' times
    int size; // Length of the c_d
    string new_n = n; // Copy of the original string n
    string first_half; // First half of the string
    string second_half; // Second half of the string
    int result; // 

    // the string 'n' 'b' times
    for (int i = 1; i < b; i++) {
        new_n += n;
    }

    // If the length of the string is 1, return the single digit
    if (new_n.length() == 1) {
        result = stoi(new_n);
    } else {
        size = new_n.length() / 2;
        first_half = new_n.substr(0, size);
        second_half = new_n.substr(size);

        // Recursive calls to first and second halves
        result = superDigit(first_half, 1) + superDigit(second_half, 1);

        // length comparison
        c_d = to_string(result);

        // If the length of the result is more than 1, compute super digit recursively
        if (c_d.length() > 1) {
            result = superDigit(c_d, 1);
        }
    }

    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    cout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}