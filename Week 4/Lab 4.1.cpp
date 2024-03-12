#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> numbers)
{
    // Create two pairs of vectors to store numbers and their indices
    vector<pair<int, int>> parr1;
    vector<pair<int, int>> parr2;
    
    // Populate parr1 and parr2 with numbers and their indices
    for (size_t i = 0; i < numbers.size(); i++)
        parr1.push_back({numbers[i], i});
    for (size_t i = 0; i < numbers.size(); i++)
        parr2.push_back({numbers[i], i});
    
    // Sort parr1 in ascending order based on the integers and parr2 in descending order
    sort(parr1.begin(), parr1.end());
    sort(parr2.rbegin(), parr2.rend());
    int countAsc = 0;
    int countDesc = 0;
    
    // Iterate through parr2 and swap elements until they are in their sorted positions
    for (size_t i = 0; i < parr1.size(); i++)
    {
        while ((long)i != parr1[i].second)
        {
            swap(parr1[i], parr1[parr1[i].second]);
            countAsc++;
        }
    }
    for (size_t i = 0; i < parr2.size(); i++)
    {
        while ((long)i != parr2[i].second)
        {
            swap(parr2[i], parr2[parr2[i].second]);
            countDesc++;
        }
    }
    
    // Determine the minimum count of swaps required between the ascending and descending order
    int result = 0;
    if (countAsc < countDesc)
    {
        result = countAsc;
    }
    else
    {
        result = countDesc;
    }
    return result;
}



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    cout << result << "\n";

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
