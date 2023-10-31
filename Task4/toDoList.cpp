#include<iostream>
#include<string>
#include<map>
using namespace std;

class task{
    public:

    map<int,pair<int,string>> mp;
    int count ;
    task(){
        count = 0;
    }
    void add(){
        string str;
        cout<< "----------------------------------------------- \n Kindly Enter Your Task \n-----------------------------------------------"<<endl;
        cin.clear();
        cin.ignore();
        getline(cin,str);
        cout<< "----------------------------------------------- \n "<<endl;
        mp[++count] = {0,str};
        return;
    }

    void changeStatus(){
        if(mp.empty()){ 
            cout <<"----------------------------------------------- \n Kindly add a todo to use this Section \n-----------------------------------------------"<<endl;
            return;
        }
        int id;
        cout << "----------------------------------------------- \n Kinldy Enter the id of the task \n-----------------------------------------------"<<endl;
        cin >> id;
        cout<< "----------------------------------------------- \n "<<endl;
        if(mp.find(id) == mp.end()){
            cout<<"----------------------------------------------- \n Kindly Enter correct id  \n-----------------------------------------------"<<endl;
            changeStatus();
        }else{
            string status = mp[id].first == 0? "Completed":"Incompleted";
            cout<<"----------------------------------------------- \n Your status have been change to "<< status<<"\n-----------------------------------------------"<<endl;
            mp[id].first = !mp[id].first;
        }
    }

    void viewTask(){
        if(mp.empty()){ 
            cout <<"----------------------------------------------- \n Kindly add a todo to use this Section \n-----------------------------------------------"<<endl;
            return;
        }
        cout<< "----------------------------------------------- \n "<<endl;
        for(auto i:mp){
            string status = i.second.first == 0? "Incompleted":"Completed";
            cout << i.first<<"  |  "<<status<<"   |  "<<i.second.second << endl;
            
        }
        cout<< "\n -----------------------------------------------"<<endl;
    }

    void removeTask(){
        if(mp.empty()){ 
            cout <<"----------------------------------------------- \n Kindly add a todo to use this Section \n-----------------------------------------------"<<endl;
            return;
        }
        int id;
        cout << "----------------------------------------------- \n  Enter the id of the task you wanted to delete\n-----------------------------------------------"<<endl;
        cin >> id;
        cout<< "----------------------------------------------- \n "<<endl;
        if(mp.find(id) == mp.end()){
            cout<<"----------------------------------------------- \n Please Enter the correct id 's\n-----------------------------------------------"<<endl;
            removeTask();
        }else{
            cout<<"----------------------------------------------- \n Succesfully Deleted\n-----------------------------------------------";
            mp.erase(id);
        }
    }
};

int main(){
    task t;
    start:
        bool stop = false;
        int choice;
        cout<< "----------------------------------------------- \n "<<endl;
        cout<<"Enter the choices for "<<endl;
        cout << " 1: View Todo's \n 2: Remove Todo \n 3: Add Todo \n 4: Change Status \n 5: Exit"<<endl;
        cout<< "\n----------------------------------------------- "<<endl;
        cin  >> choice;
        cout<< "----------------------------------------------- \n "<<endl;
        switch (choice)
        {
        case 1:
            t.viewTask();
            break;
        case 2:
            t.removeTask();
            break;    
        case 3:
            t.add();
            break;
        case 4:
            t.changeStatus();
            break;
        case 5:
            cout<<"----------------------------------------------- \n  Thank You! Have a Nice Day \n-----------------------------------------------"<<endl;
            stop = true;
            break;            
        default:
            cout<<"----------------------------------------------- \n  Kindly Enter From the given Choices \n-----------------------------------------------"<<endl;
            break;
        }
        if(!stop) goto start;
    return 0;
}