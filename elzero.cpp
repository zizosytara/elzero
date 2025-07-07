#include<iostream>
using namespace std;
//method1
void voidRepeat( int times,string temp){
   if(times==0)
    return;

   else
   cout<<temp;

   voidRepeat(times-1,temp);
}
//method 2
string stringRepeat(int times,string temp,string sep){
    if(times==0)
    return "";

    else 
    return temp+sep+stringRepeat(times-1,temp,sep);
}
string cond(int times,string temp ,string sep){
    
}
//mathod 3
string elzero(int times, string temp, string sep){

}
int main (){

cout<<stringRepeat(3,"ziad","#") ;   
    return 0;
}