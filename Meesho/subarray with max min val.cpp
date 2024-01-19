#include <bits/stdc++.h>

using namespace std;

int sol2(int n, vector<int>&price, int max_price){
    int cnt = 0;
    int maxi = 0;
    
    for(int i=0;i<n;i++){
        if(price[i]==max_price)
            cnt++;
        if(i+1==n or price[i]!=max_price){
            maxi = max(maxi,cnt);
            cnt = 0;
        }
    }
    
    cnt = 0;
    
    for(int i=1;i<=maxi;i++){
        cnt+=i;
    }
    
    return cnt;
}

int sol(int n, vector<int>&price, int max_price, int min_price){
    if(max_price==min_price)
        return sol2(n,price,max_price);
    int maxVal = -1;
    int minVal = -1;
    int start = 0;
    int maxi = 0;
    int cnt = 0;
    int p = 0;
    
    for(int i=0;i<n;i++){
        int t;
        if(price[i]>min_price && price[i]<max_price && maxVal!=-1 && minVal!=-1){
            cnt+=p;
        }
        else if(price[i]<min_price or price[i]>max_price){
            maxi = max(maxi,cnt);
            cnt = 0;
            start = i+1;
            maxVal = -1;
            minVal = -1;
            p=0;
        }
        else{
            if(price[i]==min_price){
                if(minVal==-1){
                    if(maxVal!=-1){
                        t = maxVal - start + 1;
                        p=t;
                        cnt = t;
                    }
                }
                else if(minVal>maxVal && maxVal!=-1){
                    cnt+=p;
                }
                else if(maxVal>minVal){
                    cnt+=p;
                    t = maxVal - minVal;
                    cnt+=t;
                    p+=t;
                }
                minVal = i;
            }
            else if(price[i]==max_price){
                if(maxVal==-1){
                    if(minVal!=-1){
                        t = minVal - start + 1;
                        p = t;
                        cnt = t;
                    }
                }
                else if(maxVal>minVal && minVal!=-1){
                    cnt+=p;
                }
                else if(minVal>maxVal){
                    cnt+=p;
                    t = minVal - maxVal;
                    cnt+=t;
                    p+=t;
                }
                maxVal = i;
            }
        }
        
        cout<<i<<" "<<cnt<<endl;
    }
    
    maxi = max(maxi,cnt);
    
    return maxi;
}


int main()
{
    int n;
    cin>>n;
    vector<int>price;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        price.push_back(t);
    }
    
    int max_price;
    int min_price;
    
    cin>>max_price;
    cin>>min_price;
    
    int t = sol(n,price,max_price,min_price);
    
    cout<<"Ans is "<<t<<endl;

    return 0;
}
