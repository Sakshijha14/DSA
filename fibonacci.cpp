#include<bits/stdc++.h>
using namespace std;


int fibonacci(int n,map<int, int>&store) {
    
    if (store.find(n) != store.end()) {
        return store[n];
    }
    
    
    if (n <= 1) {
        return n;
    }
    
    
    int result = fibonacci(n - 1,store) + fibonacci(n - 2,store);
    
    
    store[n] = result;
    
    return result;
}

int main() {
    map<int, int>store;
    
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    int sum=0;
    
    cout << "Fibonacci series up to " << n << " terms: ";
    for (int i = 0; i < n; ++i) {
        int result=fibonacci(i,store);
        cout<<result<< " ";
        sum+=result;
    }
    
    cout << std::endl;
    cout<<"Sum of the series "<<n<<"terms: "<<sum<<endl;
    return 0;
}
