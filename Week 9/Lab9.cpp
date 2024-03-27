#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

int citySizes[100001];
int cityParents[100001];

int findParent(int city) {
    if(city == cityParents[city]) return city;
    return cityParents[city] = findParent(cityParents[city]);
}

// Group cities based on the potential roads
void groupCities(int cityA, int cityB) {
    cityA = findParent(cityA);
    cityB = findParent(cityB);
    if (cityA == cityB) return;
    if (citySizes[cityA] < citySizes[cityB]) swap(cityA, cityB);
    cityParents[cityB] = cityA;
    citySizes[cityA] += citySizes[cityB];
}

long roadsAndLibraries(int numOfCities, int libCost, int roadCost, vector<vector<int>> cities) {
    
    // if lib cost is cheaper than that of road
    if (libCost <= roadCost) 
        return numOfCities * 1LL * libCost;
    
    for (int i = 1; i <= numOfCities; i++) {
        citySizes[i] = 1;
        cityParents[i] = i;
    }
    
    for (auto cityPair: cities) {
        groupCities(cityPair[0], cityPair[1]);
    }
    
    // visited flag map
    unordered_map<int, bool> visitedMap;
    long long totalCost = 0;
    
    // check each city
    for (int i = 1; i <= numOfCities; i++) {
        int parent = findParent(i);
        if (visitedMap[parent]) continue;
        totalCost += libCost;
        totalCost += ((citySizes[parent] - 1) * roadCost);
        visitedMap[parent] = 1;
    }
    
    return totalCost;
}


int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

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
