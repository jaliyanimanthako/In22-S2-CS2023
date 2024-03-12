#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> quick_sort(vector <int> arr );

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector <int> b = quick_sort(a);

    for (int i : b)
    {
        cout << i << " ";
    }
    
    return 0;
}

vector<int> quick_sort(vector<int> arr)
{
    // Iterate through the array and divide elements into left, equal, and right groups based on the arr[0]
    vector<int> left, equal, right;
    for (size_t k = 0; k < arr.size(); k++)
    {
        if (arr[k] < arr[0])
            left.push_back(arr[k]);
        else if (arr[k] > arr[0])
            right.push_back(arr[k]);
        else
            equal.push_back(arr[k]);
    }
    
    // Combine left, equal, and right groups to form the sorted vector
    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}





