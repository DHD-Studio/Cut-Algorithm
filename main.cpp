#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const double unit_length = 5800;
const double cut_waste = 2;

double cut(double remain_length,double cut_length){ // 計算剪去以後的長度
    return remain_length - (cut_length + cut_waste);
}

int main(){
    double n,m; 
    // n = 同長度鋁料需要的數量
    // m = 鋁料長度
    vector<double> nums; // nums = 每一支鋁料需要的長度
    double waste=0; // waste = 浪費掉的鋁料長度總和
    ifstream fin;
    ofstream fout;
    // 將 fin 和 fout 當作程式的輸入與輸出

    fin.open("input.txt"); // 開啟輸入用檔案
    while(fin >> n >> m){ // 讀取檔案要求的鋁料長度資料
        for(int i=0;i<n;i++){
            nums.push_back(m);
        }
    }

    fin.close(); // 結束讀取
    sort(nums.begin(),nums.end()); // 將長度由小到大排序
    int aluminum; // 要使用多少支料
    int remain_length = unit_length; // 將剩下長度設為原長度
    fout.open("output.txt"); // 打開輸出用檔案
    vector<double> ans; // 一支鋁料切成的長度 每個空間一支
    int index;
    // index = 尋找可切割用的索引
    while(1){
        // while 一圈代表使用一支 5800mm 的鋁料
        index = nums.size();
        // 從剩下的最大開始找
        while(remain_length>nums[0/*未切割中最小的index*/]+cut_waste){ // 當剩餘長度還能再切割
            while(!remain_length<nums[index]+cut_waste){ // 取剩下能切割之中最長的
                index--;
            }
            remain_length = cut(remain_length,nums[index]);
        } // 計算所有能夠切割出來的鋁料長度並從 nums 中刪除
        waste += unit_length - remain_length; // 將單支浪費的鋁料加進浪費的總和內

        ans.clear(); // 清除資料
        aluminum++; // 5800mm 鋁料使用數+1
        remain_length = unit_length; //重設長度
        for(int i=0;i<ans.size();i++){
            fout << ans[i] << " ";
        }
        ans.clear();
        fout << endl;
    }
    
    fout << "需要使用 " << aluminum << " 支 5800mm 的鋁料" << endl;
    fout.close(); // 關閉輸出檔案
    return 0;
}