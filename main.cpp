#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const double unit_length = 5800;
const double cut_waste = 2;

bool can_cut(int unit_length,int cut_length){
    if(unit_length - (cut_length + cut_waste) > 0)
        return 1;
    return 0;
}

double cut(int unit_length,int cut_length){
    return unit_length - (cut_length + cut_waste);
}

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

    int aluminum; // 要使用多少支料
    int reg=5800;
    fout.open("output.txt");
    vector<double> ans;
    int count=0,index;
    while(1){
        reg -= nums.back(); // 從剩下的最大開始找
        ans[count] = nums.back();
        nums.pop_back();

        index = nums.size();
        while(reg>nums[0]){
            

        }
        count++;

        cout << endl;
        ans.clear(); // 清除資料
        aluminum++;
        reg = 5800;
        count=0;
    }

    fout << "需要使用 " << aluminum << " 支 5800mm 的鋁料" << endl;

    for(int i=0;i<nums.size();i++){
        fout << nums[i] << " ";
    }
    fout.close();
    return 0;
}