#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class task{
    public:

    unordered_map<int,pair<int,string>> mp;
    int count ;
    task(){
        count = 0;
    }
    void add(){
        string str;
        cout<< "Kindly Enter Your Task"<<endl;
        getline(cin,str);
        
        cin >> str;

        mp.insert({++count,{0,str}});
        return;
    }

    void changeStatus(){
        int id;
        cout << "Kinldy Enter the id of the task"<<endl;
        cin >> id;
        if(mp.find(id) == mp.end()){
            cout<<"Kindly Enter correct id"<<endl;
            changeStatus();
        }else{
            string status = mp[id].first == 0? "Completed":"Incompleted";
            cout<<"Your status have been change to "<< status<<endl;
            mp[id].first = !mp[id].first;
        }
    }

    void vewTask(){
        for(auto i:mp){
            string status = i.second.first == 0? "Incompleted":"Completed";
            cout << i.first<<"   "<<status<<"   "<<i.second.second;
            
        }
    }

    void removeTask(){
        int id;
        cout << " Enter the id of the task you wanted to delete"<<endl;
        cin >> id;
        if(mp.find(id) == mp.end()){
            cout<<"Please Enter the correct id 's"<<endl;
            removeTask();
        }else{
            cout<<"Succesfully Deleted";
            mp.erase(id);
        }
    }
};

int main(){
    task t;
    start:
        bool stop = false;
        int choice;
        cout<<"Enter the choices for"<<endl;
        cout << "1 : View Todo's \n 2: Remove Todo \n 3: Add Todo \n 4: Change Staus \n 5: Exit"<<endl;
        cin  >> choice;
        switch (choice)
        {
        case 1:
            t.vewTask();
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
            stop = true;
            break;            
        default:
            cout<<" Kindly Enter From the given Choices"<<endl;
            break;
        }
        if(!stop) goto start;
    return 0;
}