//
//  main.cpp
//  Class
//
//  Created by Nicholas Brown on 2/14/25.
//

#include <iostream>
#include <string>
#include <iomanip>
using std::endl, std::cout, std:: cin, std:: string;

class MyClass {
public:
    int getChoice( string drink [], int size,int machineNum[]);
    void transaction(string drink [], int size , int machineNum[], double &money, double prices []);
    void currency(string drink [],double prices[], double &money, int size, int selection);

};


int  MyClass ::getChoice( string drink [], int size, int machineNum[]){
    
    
    
    string choice;
    cout << "Please pick a drink: ";
    getline(cin, choice);
    
    cout << "You picked: " << choice << endl;
    
    
    // call the currency function here when you are finished with it.
    for (int i = 0; i < size; i++) {
        
        // work on this part and make sure the number in machine doesnt pass 0 (2/14/2025)
        if (drink[i] == choice) {
            if (machineNum[i] <= 0) {
                cout << "Sorry!! There is no more." << '\n';
                machineNum[i] = 0;
            }
            return i;
        }
        
        
    }
    cout << "Invalid choice! Please try again." << endl;
    return getChoice(drink, size,  machineNum);
}



void MyClass::transaction(string drink [], int size , int machineNum[], double &money, double prices []){
    
    char answer;
    
    cout << std::setw(2)  << "Drink Name" << std::setw(40) << "Cost" << std::setw(30) << "Number in Machine" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    
    for (int i = 0; i < size; ++i) {
        // Fixes my indentation problem I had initially due to the fact that Cola and Root Beer were less words than the other drink options.
        if (i == 0) {
            cout << std::setw(2)  << drink[i] << std::setw(46) << std::fixed << std::setprecision(2) << prices[i] << std::setw(30) << machineNum[i] << endl;
            
            
        }else if (i == 1){
            
            cout << std::setw(2)  << drink[i] << std::setw(41) << std::fixed << std::setprecision(2) << prices[i] << std::setw(30) << machineNum[i] << endl;
            
        }else
            cout << std::setw(2)  << drink[i] << std::setw(40) << std::fixed << std::setprecision(2) << prices[i] << std::setw(30) << machineNum[i] << endl;
        
    }
    
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    
    int selection = getChoice(drink, size,  machineNum);
    this->currency(drink, prices, money, size, selection); // Calling using the 'this' pointer
    for (int i = 0; i < size; i++) {
        
       // this->currency(prices, money, size); // Calling using the 'this' pointer

        //if user's drink selection is equivalent to the string in any of the drink[]'s array then my machineNum will go down.
        if (drink[selection] == drink[i] && money <= 1.0) {
            machineNum[i]--;
        }
        
        if (machineNum[i] == 0 && drink[selection] == drink[i]) {
            cout  << "Uh oh..thats the last one-" << endl;
        }
    }
    

    
    cout << "Want another? Y or N: ";
    cin >> answer;

    
    if (answer) {
        toupper(answer);
        cin.ignore();
    }
    
    
    
    if (answer == 'Y') {
        // calls the function again for replayability until you
        this->transaction(drink, size, machineNum, money, prices);
        
    }else{
        cout << "Thank you!!" << endl;
    }
    
}


void MyClass:: currency(string drink [],double prices[], double &money, int size, int selection){
   
    // Print money amount to get the
    cout << "Please enter the money amount: $";
    cin >> money;

    //Here you want to do the calculation between the prices and the money you give the machine.
        if (money >= prices[selection && money <= 1.00]) {
            money -= prices[selection];
            cout << "Here is your change: $" << money << endl;
            //size = 0;

        }else
            cout << "Sorry, thats a really high bill!" << endl;
            //size = 0;
        
    
    
    // If you have more than 1 dollar I will not accept your money
    
    // If you do have less than or equal to 1 dollar I will give you back your change.
    
    // Print change given back.
    

}




int main() {
    MyClass vendingMachine;
    
    string drink[5] = {"Cola", "Root Beer", "Lemon-Lime", "Grape Soda", "Cream Soda"};
    double prices[5] = {0.75, 0.75, 0.75, 0.80, 0.80};
    int machineNum[5] = {20, 20, 20, 20, 20};
    double money = 0.0;
    int size = sizeof(drink) / sizeof(drink[0]);
    
    vendingMachine.transaction(drink, size, machineNum, money, prices);
    
    return 0;
}
