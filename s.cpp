#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include <bits/stdc++.h> 
using namespace std;

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << " ";
    }
}

void countsort(vector<int> &arr, int d){
    vector<int> farr(10);
    vector<int> ans(arr.size());
    for(int i=0;i<arr.size();i++){
        int o = arr[i]/pow(10,d-1);
        farr[o%10]++;
    }
    for(int i =1;i<10;i++){
        farr[i]+=farr[i-1];
    }
    for(int i=arr.size()-1;i>=0;i--){
        int o = arr[i]/pow(10,d-1);
        int value=o%10;
        int pos=farr[value];
        ans[pos-1]=arr[i];
        farr[value]--; 
 

    }
    for(int i=0;i<arr.size();i++){
        arr[i]=ans[i];
    }

    cout<< "After sorting on " << d << " place -> ";
    Display(arr);
    cout << endl;
}

void radixSort(vector<int> &arr){
    int max=arr[0];
    for(int ele :arr){

        if(ele>max){
            max=ele;
        }
    }
    int count = 0;
    while(max>0){
        max/10;
        count++;
    }

    for(int d=1;d<=count;d++){
        countsort(arr,d);

    }

}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    
    for(int i = 0; i < n; i++){    
        cin >> arr[i];
    }
    
    radixSort(arr);
    Display(arr);
    return 0;
}