#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int>test {100,232,435,5346};
vector<int>test1;
vector<int>::iterator it;
for(int val:test1){
    cout<<val<<endl;
}
return 0;
}