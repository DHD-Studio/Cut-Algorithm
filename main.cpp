#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const double unit_length = 5800;
const double cut_waste = 2;

bool can_cut(int remain_length,int cut_length){ // 判斷剩餘長度能不能剪
    if(remain_length - (cut_length + cut_waste) > 0)
        return 1;
    return 0;
}

double cut(int remain_length,int cut_length){ // 計算剪去以後的長度
    return remain_length - (cut_length + cut_waste);
}

int main(){
    double n,m; 
    // n = 同長度鋁料需要的數量
    // m = 鋁料長度
    vector<long double> nums;
    double waste=0;
    // nums = 每一支鋁料需要的長度
    // waste = 浪費掉的鋁料長度總和
    ifstream fin;
    ofstream fout;
    // 將 fin 和 fout 當作程式的輸入與輸出

    fin.open("input.txt");
    while(fin >> n >> m){ // 讀取檔案要求的鋁料長度資料
        for(int i=0;i<n;i++){
            nums.push_back(m);
        }
    }
    fin.close();
    // 結束讀取

    sort(nums.begin(),nums.end());

    int aluminum; // 要使用多少支料
    int remain_length=5800;
    fout.open("output.txt"); // 打開輸出用檔案
    vector<double> ans;
    int count=0,index;
    while(1){
        // 前一行 while 一圈代表使用一支 5800mm 的鋁料
        remain_length -= nums.back(); // 從剩下的最大開始找
        ans[count] = nums.back();
        nums.pop_back();

        index = nums.size();
        while(remain_length>nums[0]){
            

        }
        count++;

        cout << endl;
        ans.clear(); // 清除資料
        aluminum++; // 5800mm 鋁料使用數+1
        remain_length = 5800; //重設長度
        count=0; // 
    }

    fout << "需要使用 " << aluminum << " 支 5800mm 的鋁料" << endl;
    fout.close(); // 關閉輸出檔案
    return 0;
}