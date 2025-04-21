// Fractional Knapsack (without STL)
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Item{
public:
    int weight;
    int profit;
    float perUnit;
    Item(){} // Default constructor
    Item(int weight, int profit){ // Parameterized constructor
        this->weight=weight;
        this->profit=profit;
        perUnit=(float)profit/weight; // Calculate profit per unit weight
    }
};

int main(){
    // n=number of items, k=capacity of knapsack
    // w[i]=weight of ith item, p[i]=profit of ith item
    ll n,k; 
    cout<<"Enter number of items"<<endl;
    cin>>n;
    cout<<"Enter capacity of knapsack"<<endl;
    cin>>k;
    Item items[n];
    for(int i=0;i<n;i++){
        int w,p;
        cout<<"Enter weight and profit of item "<<i+1<<endl;
        cin>>w>>p;
        items[i]=Item(w,p); // 
    }
    
    // Sorting items based on per unit profit in descending order
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(items[i].perUnit<items[j].perUnit){
                swap(items[i],items[j]);
            }
        }
    }

    float total=0.0;
    for(int i=0;i<n;i++){
        if(k>=items[i].weight){ // If the knapsack can hold the entire item
            total+=items[i].profit;
            k-=items[i].weight;
        }
        else{ // If the knapsack can only hold a fraction of the item
            total+=(items[i].profit*(float)k/items[i].weight);
            k=0;
        }
    }
    cout<<"Maximum profit: "<<total<<endl;
}