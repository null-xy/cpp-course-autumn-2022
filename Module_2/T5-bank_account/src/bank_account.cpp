
#include "bank_account.hpp"
#include <iostream>
/*
  std::string owner_;
  std::string account_number_;
  double balance_;
  */
 BankAccount::BankAccount(const std::string& owner,const std::string& account_number,
              double balance) : owner_(owner),account_number_(account_number),balance_(balance){}
 std::string BankAccount::GetOwner() const{
    return owner_;
    }
 std::string BankAccount::GetNumber() const{
    return account_number_;
  }
 double BankAccount::GetBalance() const{
    return balance_;
  }
  void BankAccount::Deposit(double amount){
    balance_=amount+balance_;
  }
  
  bool BankAccount::Withdraw(double amount){
    if(amount>balance_){
        return false;
    }else{
        balance_=balance_-amount;
        return true;
    }
  }
  void BankAccount::Print() const{
    std::cout << "Account num: " << account_number_ 
    << ", owned by: " << owner_ 
    << ", balance: " << balance_
    << " eur." << std::endl;
  }
  bool Transfer(BankAccount& source_account, BankAccount& target_account,
              double amount){
                if(amount>source_account.GetBalance()){
                    return false;
                }else{
                    source_account.Withdraw(amount);
                    target_account.Deposit(amount);
                    return true;
                }
              }