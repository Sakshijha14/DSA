#include<bits/stdc++.h>
using namespace std;

int mod=100000007;

int evaluateExpressionhelper(int i,int j,int isTrue,string &expression){

    if(i>j){
        return 0;
    }

    if(i==j){
        if(isTrue==1){
            return expression[i]=='T'?1:0;
        }
        else{
            return expression[i]=='F'?1:0;
        }
    }
    long ways=0;

    for(int index=i+1;index<=j-1;index+=2){
        long lefttrue=evaluateExpressionhelper(i,index-1,1,expression);
        long leftfalse=evaluateExpressionhelper(i,index-1,0,expression);
        long righttrue=evaluateExpressionhelper(index+1,j,1,expression);
        long rightfalse=evaluateExpressionhelper(index+1,j,0,expression);


        if(expression[index]=='&'){
            if(isTrue){
                ways=(ways+(righttrue*lefttrue)%mod)%mod;
            }
            else{
                ways=(ways+(righttrue*leftfalse)%mod+(rightfalse*lefttrue)%mod+(leftfalse*rightfalse)%mod)%mod;
            }

        }
        else if(expression[index]=='|'){
            if(isTrue){
                ways=(ways+(lefttrue*rightfalse)%mod+(leftfalse*righttrue)%mod+(righttrue*lefttrue)%mod)%mod;
            }
            else{
                ways=(ways+(leftfalse*rightfalse)%mod)%mod;
            }

        }
        else{
            if(isTrue){
               ways=(ways+(leftfalse*righttrue)%mod+(lefttrue*rightfalse)%mod)%mod;
            }
            else{
                ways=(ways+(lefttrue*righttrue)%mod+(leftfalse*rightfalse)%mod)%mod;
            }
        }

    }
    return ways;
}

int evaluateExpression(string &expression){
    int n=expression.size();

    return evaluateExpressionhelper(0,n-1,1,expression);
}

int main(){

    string expression="F|T^F";
    int ways=evaluateExpression(expression);
    cout<<"the total number of ways "<<ways<<endl;


    return 0;
}