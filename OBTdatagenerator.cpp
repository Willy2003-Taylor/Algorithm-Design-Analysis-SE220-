#include<bits/stdc++.h>
using namespace std;
float p[10], q[10];
int cnt, i, j;
int main(){
    srand(time(0));
    freopen("output.txt", "w", stdout);
    do{
        int randomInt = rand();
        float randomFloat = static_cast<float>(randomInt) / RAND_MAX;
        if(randomFloat >= 0.1){
            p[i++] = randomFloat;
            cnt++;
        }
    }while(cnt <= 5);
    
    cnt = 0;

    do{
        int randomInt = rand();
        float randomFloat = static_cast<float>(randomInt) / RAND_MAX;
        if(randomFloat >= 0.1){
            q[j++] = randomFloat;
            cnt++;
        }
    }while(cnt <= 6);
    //ofstream outfile;
    //outfile.open("E:\MUST\electronic book\Design & Analysis of Algorithm\output.txt");
    cout<<"Successful probability: ";
    for(int i = 1; i <= 5; i++)
        cout<<setprecision(2)<<p[i]<<" ";

    cout<<endl;

    cout<<"Failure probability: ";
    for(int i = 0; i <= 5; i++)
        cout<<setprecision(2)<<q[i]<<" ";

    fclose(stdout);   
    return 0;
}