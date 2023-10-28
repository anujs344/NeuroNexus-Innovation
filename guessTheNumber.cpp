#include<iostream>
using namespace std;

int guessTheNumber(int currentNumber){
    while(true){
        int newNumber;
        cout <<" Please guess the Number : ";
        cin >> newNumber;
        cout<<endl;
        if(currentNumber == newNumber){
            cout<< " Hurray ! You have Entered the Correct Number "<<endl;
        }else if(newNumber > currentNumber){
            cout<< " Hurray ! You have Entered the Correct Number "<<endl;
        }else{
            cout<< " Hurray ! You have Entered the Correct Number "<<endl;
        }
    }
}
int main(){

}