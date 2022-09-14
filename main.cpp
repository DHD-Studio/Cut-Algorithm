#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin;
ofstream fout;
// 將 fin 和 fout 當作程式的輸入與輸出

const double unit_length = 5800;
const double cut_waste = 2;

double cut(double remain_length,double cut_length){ // 計算剪去以後的長度
    return remain_length - (cut_length + cut_waste);
}

void print_v(vector<double> nums){
    for(auto i : nums)
        fout << i << " ";
    fout << endl;
}

void solve(){
    vector<double> nums; // nums = 每一支鋁料需要的長度
    fin.open("input.txt"); // 開啟輸入用檔案
    double n,m; // n = 同長度鋁料需要的數量 m = 鋁料長度

    while(fin >> n >> m){ // 讀取檔案要求的鋁料長度資料
        for(int i=0;i<n;i++){
            nums.push_back(m);
        }
    }

    fin.close(); // 結束讀取
    sort(nums.begin(),nums.end()); // 將長度由小到大排序
    fout.open("output.txt"); // 打開輸出用檔案
    fout << "There are " << nums.size() << " datas." << endl << endl;
    fout << "There are all of the data index: " << endl;
    print_v(nums);
    fout << endl;
    int aluminum=0; // 要使用多少支料
    double remain_length = unit_length; // 剩下的長度 初始值為 unit_length
    vector<double> ans; // 一支鋁料切成的長度 每個空間一支
    size_t index; // index = 尋找可切割用的索引
    double waste=0; // waste = 浪費掉的鋁料長度總和
    index = nums.size()-1;

    while(1){ // while 一圈代表使用一支 5800mm 的鋁料
        remain_length = unit_length; //重設長度
        ans.clear(); // 清除已計算的內容給下一支鋁料紀錄使用

        while(remain_length>*min_element(nums.begin(),nums.end())+cut_waste){ // 當剩餘長度還能再切割
            index = nums.size()-1; // 從剩下的最大開始找
            while(remain_length<nums[index]+cut_waste && index>0/*index*/){ // 取剩下能切割之中最長的
                index--;
            }
            if(index>0)
                remain_length = cut(remain_length,nums[index]); // 計算切割後長度
            else
                break;
            ans.push_back(nums[index]); // 計算好的放入答案欄中
            nums.erase(nums.begin() + index); // 移除已切好的鋁料資料
        } // 計算所有能夠切割出來的鋁料長度並從 nums 中刪除
        
        fout << "This time waste " << remain_length << " mm of aluninum." << endl;
        waste += remain_length; // 將單支浪費的鋁料加進浪費的總和內
        aluminum++; // 5800mm 鋁料使用數+1
        // cout << "nums =";
        // print_nums(nums);
        fout << "ans = ";
        print_v(ans); // 列出單支鋁料能夠切割出的長度
        fout << endl;
        if(!index)
            break;
    }

    fout << "Need to use " << aluminum << "*5800mm aluminum materials." << endl;
    fout << "Wasted " << waste << " mm of aluminum.";
    fout.close(); // 關閉輸出檔案
    return;
}

int main(){
    solve();
    return 0;
}