#include<iostream>
using namespace std;
class ATM{
    private :
        int balance;
        int password,success;
        public:
        ATM(int bal,int pin){
            balance=bal;
            password=pin;
        }
        int getBalance(){
            return balance;
        }
        int Withdraw(int amount,int pin){
            if(pin!=password){
                return false;
            }
            if(amount>balance){
                return false;
            }
            balance-=amount;
            return true;
        }
        void Deposit(int amount){
            balance+=amount;
        }
        int transfer(int amount,ATM reciever,int pin){
            if(pin!=password){
                return false;
            }
            success=Withdraw(amount,pin);
            if(success){
                reciever.Deposit(amount);
                return true;
            }
            else{
                return false;
            }
        }
};
int main(){
    ATM account(10000,123);
    int choice,success,amount,pin;
    char op;
    do{
        system("cls");
        cout<<"1.Check Balance"<<endl;
        cout<<"2.Withdraw Cash"<<endl;
        cout<<"3.Deposit Cash"<<endl;
        cout<<"4.Cash Transfer"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                    cout<<"Your Balance : "<<account.getBalance();
                    break;
            case 2:
                    cout<<"Available Balance : "<<account.getBalance()<<endl;
                    cout<<"Enter amount to withdraw : ";
                    cin>>amount;
                    cout<<"Enter Pin : ";
                    cin>>pin;
                    success=account.Withdraw(amount,pin);
                    if(success){
                        cout<<"Withdraw Succesfull..."<<endl;
                    }
                    else{
                        cout<<"Insufficient Balance or Invalid Pin !"<<endl;
                    }
                    break;
            case 3:
                    cout<<"Enter amount to deposit : ";
                    cin>>amount;
                    account.Deposit(amount);
                    cout<<"Deposit Successfull..."<<endl;
                    break;
            case 4:
                    cout<<"Available Balance : "<<account.getBalance()<<endl;
                    cout<<"Enter the amount to transfer : ";
                    cin>>amount;
                    cout<<"Enter Pin : ";
                    cin>>pin;
                    success=account.transfer(amount,account,pin);
                    if(success){
                        cout<<"Transfer Successfull..."<<endl;
                    }
                    else{
                        cout<<"Insufficient Balance or Invalid pin ! "<<endl;
                    }
                    break;
            case 5:
                    cout<<"Thanks for Visiting our ATM "<<endl;
                    exit(1);
                    break;
            default:
                    cout<<"Invalid Choice!"<<endl;

        }
        cout<<"\nDo you want to try another transaction {Yes/No} ? : ";
        cin>>op;
    }while(op=='y'||op=='Y');
    return 0;
    
}