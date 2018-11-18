/*
 * Filename: main.cpp
 * Author: SeekingMini
 * Version: 1.1
 * Time: 2018-11-13
 */
#include <iostream>
#include <map>
using namespace std;

const int MAX=20;  // 一个车厢20排
const int NUM=5;  // 每一排5个座位

int main() {
    map<int,int>s;
    map<int,int>::iterator itr;
    int time;  // 购票指令的数量
    int n;  // 每次购票的数量
    int start,end;

    for(int i=1;i<=MAX;i++){  // 初始化车厢
        s[i]=NUM;
    }

    cin>>time;
    for(int i=1;i<=time;i++){
        bool flag=false;

        cin>>n;
        for(itr=s.begin();itr!=s.end();itr++) {
            if (n <= itr->second) {  // 购票数量刚好够全部买在同一排上
                start=(itr->first-1)*NUM+1+(NUM-itr->second);
                end=start+n-1;
                for(int j=start;j<=end;j++){
                    if(j!=start)cout<<" ";
                    cout<<j;
                }
                cout<<endl;
                if(itr->second==n)s.erase(itr);
                else itr->second-=n;
                n=0;
                break;
            }

            // 否则，进入下一排寻找是否符合要求
        }

        // 分配车票（多排分配）并且输出结果
        bool nofirstflag = false;
        while(n > 0) {
            for(itr=s.begin();itr!=s.end();itr++) {
                if(itr->second >= n) {
                    // 输出结果
                    start = (itr->first - 1) * NUM + 1 + (NUM - itr->second);
                    end = start + n - 1;
                    for(int j=start; j<=end; j++) {
                        if(nofirstflag)
                            cout << " ";
                        cout << j;
                        nofirstflag = true;
                    }

                    // 对于票数已经分配完毕的排，删除
                    if(itr->second == n)
                        s.erase(itr);
                    else
                        itr->second = itr->second - n;

                    n = 0;
                    break;
                } else {
                    // 输出结果
                    start = (itr->first - 1) * NUM + 1 + (NUM - itr->second);
                    end = start + itr->second - 1;
                    for(int j=start; j<=end; j++) {
                        if(nofirstflag)
                            cout << " ";
                        cout << j;
                        nofirstflag = true;
                    }

                    n = n - itr->second;

                    // 对于票数已经分配完毕的排，删除
                    s.erase(itr);
                }
            }
            cout << endl;
        }
    }

    return 0;
}
