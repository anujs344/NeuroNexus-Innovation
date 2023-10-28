#include<iostream>
using namespace std;

int guessTheNumber(int currentNumber){
    while(true){
        int newNumber;
        cout <<" Please guess the Number : ";
        cin >> newNumber;
        // cout<<endl;
        if(currentNumber == newNumber){
            cout<< " Hurray ! You have Entered the Correct Number "<<endl;
            break;
        }else if(newNumber > currentNumber){
            cout<< "You have entered number higher than the correct Number"<<endl;
        }else{
            cout<< "You have entered number lower than the correct Number"<<endl;
        }
    }
}
int main(){
    int currentNumber = rand()%100;
    guessTheNumber(currentNumber);
    return 0;

}