#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const double unit_length = 5800;
const double cut_waste = 2;

int main(){
    long double n,m;
    vector<long double> nums;
    ifstream fin;
    ofstream fout;

    fin.open("input.txt");
    while(fin >> n >> m){
        for(int i=0;i<n;i++){
            nums.push_back(m);
        }
    }
    fin.close();

    sort(nums.begin(),nums.end());

    

    fout.open("output.txt");
    for(int i=0;i<nums.size();i++){
        fout << nums[i] << " ";
    }
    fout.close();

    return 0;
}