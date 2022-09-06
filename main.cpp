#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const double num_max = 5800;
const double num_min = 300;

int main(){
    long double n;
    vector<long double> nums;
    while(cin >> n){
        nums.push_back(n);
    }
    ifstream in;
    ofstream out;
    in.open("./input.txt");
    if(in.fail()){
        cout << "input file opening failed";
        exit(1);
    }
    out.open("output.txt");
    if(out.fail()){
        cout << "output file opening failed";
        exit(1);
    }
    sort(nums.begin(),nums.end());




    in.close();
    out.close();
    return 0;
}