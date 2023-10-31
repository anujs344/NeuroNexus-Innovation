#include<iostream>
using namespace std;

class SimpleCalculator{
    public: 
    int a ,b;
    SimpleCalculator(int n1, int n2){
        a = n1;
        b = n2;
    }

    void multiply(){
        cout << "Result : "<< (a*b)<<endl;
    }
    void divide(){
        cout << "Result : "<< (a/b)<<endl;
    }

    void add(){
        cout << "Result : "<< (a + b)<<endl;
    }
    
    void sub(){
        cout << "Result : "<< (a - b)<<endl;
    }
};
int main(){
    int a,b;
    cout<<"Enter First Number : ";
    cin>> a;
    cout<<endl<<"Enter Second Number : ";
    cin >> b;
    cout<<endl;

    SimpleCalculator obj(a,b);
    bool terminate = false;
    while(true){
        int choice;
        cout<< " Choose 1 -> Multiplication , 2-> Division , 3 -> Addition , 4 -> Subtraction, 5-> Termination "<<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.multiply();
            break;
        case 2:
            obj.divide();
            break;
        case 3:
            obj.add();
            break;
        case 4:
            obj.sub();
            break;
        case 5:
            terminate = true;
            break;
        default:
            cout <<" Please Enter the correct choice "<<endl;
            break;
        }

        if(terminate)
            break;

    }

}