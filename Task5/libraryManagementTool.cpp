#include <iostream>
#include <vector>
#include <string>
#include<ctime>
#include <chrono>
using namespace std;
// Define a Book class to store book information
// Define a Book class to store book information

struct date{
    int buy_month;
    int buy_year;
    int buy_date;
    int return_date;
    int return_month;
    int return_year;
    date() {
        // Get the current system time
        auto now = std::chrono::system_clock::now();
        time_t currentTime = std::chrono::system_clock::to_time_t(now);
        tm currentTM = *std::localtime(&currentTime);

        // Set buy_date, buy_month, and buy_year to the current date
        buy_date = currentTM.tm_mday;
        buy_month = currentTM.tm_mon + 1;  // Months are zero-based
        buy_year = currentTM.tm_year + 1900;  // Years since 1900

        // Calculate the return date, return month, and return year
        std::chrono::system_clock::time_point oneMonthLater = now + std::chrono::hours(24 * 30 * 60 * 60); // One month in hours
        time_t returnTime = std::chrono::system_clock::to_time_t(oneMonthLater);
        tm returnTM = *std::localtime(&returnTime);

        return_date = returnTM.tm_mday;
        return_month = returnTM.tm_mon + 1;
        return_year = returnTM.tm_year + 1900;
    }
};


void clearInput(){
    cin.clear();
    cin.ignore();
}

class Book{
    public:
    string isbn,author,title;
    
    Book(string atr, string ttl){
        author = atr;
        title = ttl;
        isbn =generateRandomISBN() ;
    }

    int getRandomInt(int min, int max) {
        return min + rand() % (max - min + 1);
    }

    
    string generateRandomISBN() {
       
        int prefix = getRandomInt(100, 999);

       
        int registration = getRandomInt(100000, 999999999);

        string isbnWithoutCheckDigit = to_string(prefix) + to_string(registration);
        int checkDigit = 0;
        int weight = 1;

        for (char digit : isbnWithoutCheckDigit) {
            checkDigit += (digit - '0') * weight;
            weight++;
        }

        checkDigit = (11 - (checkDigit % 11)) % 11;

        string checkDigitString;
        if (checkDigit == 10) {
            checkDigitString = "X";
        } else {
            checkDigitString = to_string(checkDigit);
        }

        string isbn = isbnWithoutCheckDigit + checkDigitString;

        return isbn;
    }
};
class User{
    public:
    string name;
    vector< pair<Book,date> > rented;
    User(){
        
    }
    void insert(Book obj){
        date d;
        rented.push_back({obj,d});
    }
    void showAccount(){
        for(auto i: rented){
            cout << i.first.isbn << " , ";
        }
        cout << endl;
    }
    void welcome(){
        while(true){
            cout << " Welcome to user mode \n choose the following operations \n 1. Show Accout Sections \n 2. Exit"<<endl;
            clearInput();
            int choice;
            cin >> choice;
            switch (choice)
            {
                case 1:
                    showAccount();
                    break;
                case 2:
                    return;
                    break;
                default:
                    cout << " Kindly Enter the correct choice "<<endl;
                    break;
            }
        }
        
    }

};
class Librarian{
    public:
    vector<Book> all_books;

    void addBook(){
        string auth,ttl;
        cout << " Enter the Author of the Book "<<endl;
        clearInput();
        getline(cin,auth);
        cout << " Enter the Title  of the Book " << endl;
        clearInput();
        getline(cin,ttl);
        Book obj(auth,ttl);
        all_books.push_back(obj);
        
    }

    void vieAllBook(){
        for(auto i: all_books){
            cout <<"ISBN : " << i.isbn<< " , Author : " << i.author <<" , Title : "<< i.title << endl;
        }
    }

    void rentBook(string isbn,User usr){
        
       Book obj =  find(isbn);
        if(obj.isbn == ""){
            cout << " Kindly Enter the correct ISBN number "<< endl;
            return;
        }
       usr.insert(obj);
       cout <<" You have added book to your account " << endl;
       return ;
    }
    void returnBook(string isbn,User usr){
            usr.showAccount();
        for (auto i = usr.rented.begin(); i != usr.rented.end(); ++i) {
            if(i->first.isbn == isbn){
                int fine_amount = fine(i->second);
                if(fine_amount > 0){
                    cout<< "Your Book have been return Fine of amount " << fine_amount <<" added to your account"<<endl;
                }else{
                    cout << " Your Book have been marked Returned "<<endl;

                }
                usr.rented.erase(i);
                break;
            }else{
                cout << " ISBN number not found Kindly enter the right number please" << endl;
            }
        }
    }
    int fine(date dt){
        return 1;

    }
    Book find(string isbn){
        const Book null_book = {"", "",};
        for(auto i:all_books){
            if(i.isbn == isbn)
                return i;
        }

        return null_book;
    }
    void welcome(User usr){
        while(true){
            cout << " Welcome to Librarian mode \n choose the following operations \n 1. View All Books \n 2. Add Books \n 3. Find Book \n 4. Rent Book \n 5. Return Book \n 6. Exit"<<endl;
            clearInput();
            int choice;
            string isbn;
            cin >> choice;
            switch (choice)
            {
                case 1:
                    vieAllBook();
                    break;
                case 2:
                    addBook();
                    break;
                case 3:
                    // findBook();
                    break;
                case 4:
                    
                    cout << " Enter the isbn Number "<< endl;
                    clearInput();
                    getline(cin , isbn);
                    rentBook(isbn,usr);
                    break;
                case 5:
                    cout << " Enter the isbn Number "<< endl;
                    clearInput();
                    getline(cin , isbn);
                    returnBook(isbn,usr);
                    break;
                case 6:
                    return;
                    break;
                default:
                    cout << " Kindly Enter the correct choice "<<endl;
                    break;
            }
        }
        
    }
};

int main(){
    Librarian lib;
    User usr;
    cout << "Enter Your Name " << endl;
    clearInput();
    cin >> usr.name;

    while(true){
        cout << " Welcome to Library Management System "<< endl;
        cout << " Chosse your role"  << endl;
        cout << "\n 1. Librarian \n 2. User \n 3. Exit" << endl;
        clearInput();
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                lib.welcome();
                break;
            case 2:
                usr.welcome();
                break;
            case 3:
                exit(1);
                break;
                
            default:
                cout <<" Enter the correct Option Please "<< endl;
                break;
        }

    }
  
    return 0;
}