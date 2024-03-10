#include <bits/stdc++.h>
using namespace std;

// function gets the order of the letter from 0 ~ 25
int int_ord(char chr){
    return int(chr-'A');
}
// function gets the letter which represent the number from 0 ~ 25
char char_ord(int num){
    return char(num+'A');
}
// encryption function
char encrypt(char chr, int a, int b){
    if(chr == ' ')return ' ';
    return char_ord((a*(int_ord(chr))+b)%26);
}
// decryption function
char decrypt(char chr, int c, int b){
    if(chr == ' ')return ' ';
    return char_ord(((c*(int_ord(chr)-b))+(8*26))%26);
}
// function to check if  the integer input is valid or not
bool int_chk(string x ){
    if(x.length()>1)return false ;
    else{
        if(x[0] != '1'  and x[0] != '2')return false ;
    }
    return true ;
}
// function to check if  the string input is valid or not
string str_chk(string str){
    bool flag = false ;
    while(!flag){
        for(char i : str) {
            if (!isalpha(i) && i != ' ') {
                cout << "ENTER VALID ALPHABETIC INPUT : ";
                getline(cin,str);
                flag = false;
                break;
            } else {
                flag = true;
            }
        }
    }
    return str ;
}
// function to check if the string has only digits or not
int digits_chk(string num){
    bool flag = false ;
    while(!flag){
        for (char i: num) {
            if (!isdigit(i)) {
                flag = false;
                break;
            }
            flag = true ;
        }
        if (!flag) {
            cout << "ENTER VALID INPUT : ";
            cin >> num;
        }
    }
    int number = stoi(num);
    return number ;
}


int main()
{
    // The Main Menu
    while(true){
        cout << "================== AFFINE CIPHER ==================\n" ;
        cout << "1 - START THE PROGRAM .\n"; // start
        cout << "2 - EXIT THE PROGRAM .\n"; // exit
        cout << "ENTER YOUR CHOICE : ";
        string temp_choice_1;
        cin >> temp_choice_1;// input which will be checked
        while(!int_chk(temp_choice_1)){ // checking
            cout << "ENTER VALID INPUT : " ;
            cin >> temp_choice_1 ;
        }
        int choice_1 = stoi(temp_choice_1); // the final choice which is  equal to (1) or (2)
        if(choice_1 == 2)break ; // exit the program
        else // start the program
        {
            // Program Start Menu
            cout << "================== AFFINE CIPHER ==================\n" ;
            cout << "1 - ENCRYPT TEXT .\n"; // Encryption
            cout << "2 - DECRYPT TEXT .\n"; // Decryption
            cout << "3 - BACK TO THE MAIN MENU .\n";
            cout << "ENTER YOUR CHOICE : ";
            string temp_choice_2 ; cin >> temp_choice_2 ; // input which will be checked
            while(!int_chk(temp_choice_2) and !(temp_choice_2.size() == 1 and temp_choice_2[0] == '3')){ // checking
                cout << "ENTER VALID INPUT : " ;
                cin >> temp_choice_2 ;
            }
            int choice_2 = stoi(temp_choice_2); // the final choice which is  equal to (1) or (2)
            if (choice_2 == 3) continue ; // Back To The Main Menu
            cout << "ENTER YOUR TEXT : " ;
            string text , ans ;
            cin.ignore() ;
            getline(cin, text); // Text which will be encrypted or decrypted
            text = str_chk(text); // Text Checking
            bool flag = true ; // this boolean for determination if the input is small or capital
            // to make the output like the input as its size
            for(char &i : text) { // Capitalize The Text
                if (islower(i))flag = false ;
                i = toupper(i);
            }
            int a , b , c ; // The three integers which required for the two equations
            while(true)
            {
                string temp_a , temp_b, temp_c ;
                cout << "ENTER THE NUMBER THAT PRESENTS LETTER (a) IN THE FUNCTION : ";
                cin >> temp_a ; // The input which will be checked
                a = digits_chk(temp_a) ; // checking
                cout << "ENTER THE NUMBER THAT PRESENTS LETTER (b) IN THE FUNCTION : ";
                cin >> temp_b ;// The input which will be checked
                b = digits_chk(temp_b) ; // checking
                cout << "ENTER THE NUMBER THAT PRESENTS LETTER (c) IN THE FUNCTION : ";
                cin >> temp_c ;// The input which will be checked
                c = digits_chk(temp_c) ; // checking
                if((a*c)%26 == 1 and !(a < 0 || b < 0 || c < 0)){ // checking if three integers satisfies the conditions
                    break ;
                }
                else{// if three integers does not satisfy the conditions
                    cout << "YOUR INPUT DOES NOT SATISFY THE CONDITION.....!\n";
                    cout << "you should input three positive integer a , b , c and ((a*c)mod 26) should be equal to 1\n";
                    cout << "============================================================================================\n";
                    cout << "Please Enter them again according to the conditions \n" ;
                    cout << "============================================================================================\n";
                }
            }
            // Encryption
            if(choice_2 == 1)
            {
                for(char i : text) ans += encrypt(i, a , b) ;
                if(!flag) for(auto &i : ans) i = tolower(i);
                cout << "Your Encrypted Text --->> " << ans << "\n" ;
            }
            // Decryption
            else if (choice_2 == 2)
            {
                for(char i : text) ans += decrypt(i, c , b) ;
                if(!flag) for(auto &i : ans) i = tolower(i);
                cout << "Your Decrypted Text --->> " << ans << "\n" ;
            }
        }
    }

}

