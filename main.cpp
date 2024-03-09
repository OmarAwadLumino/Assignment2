#include <bits/stdc++.h>
using namespace std;

int int_ord(char chr){
    return int(chr-'A');
}
char char_ord(int num){
    return char(num+'A');
}
char encrypt(char chr, int a, int b){
    if(chr == ' ')return ' ';
    return char_ord((a*(int_ord(chr))+b)%26);
}
char decrypt(char chr, int c, int b){
    if(chr == ' ')return ' ';
    return char_ord(((c*(int_ord(chr)-b))+(8*26))%26);
}
bool int_chk(string x ){
    if(x.length()>1)return false ;
    else{
        if(x[0] != '1'  and x[0] != '2')return false ;
    }
    return true ;
}
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
    while(true){
        cout << "================== AFFINE CIPHER ==================\n" ;
        cout << "1 - START THE PROGRAM .\n";
        cout << "2 - EXIT THE PROGRAM .\n";
        cout << "ENTER YOUR CHOICE : ";
        string temp_choice_1;
        cin >> temp_choice_1;
        while(!int_chk(temp_choice_1)){
            cout << "ENTER VALID INPUT : " ;
            cin >> temp_choice_1 ;
        }
        int choice_1 = stoi(temp_choice_1);
        if(choice_1 == 2)break ;
        else
        {
            cout << "================== AFFINE CIPHER ==================\n" ;
            cout << "1 - ENCRYPT TEXT .\n";
            cout << "2 - DECRYPT TEXT .\n";
            cout << "3 - BACK TO THE MAIN MENU .\n";
            cout << "ENTER YOUR CHOICE : ";
            string temp_choice_2 ; cin >> temp_choice_2 ;
            while(!int_chk(temp_choice_2) and !(temp_choice_2.size() == 1 and temp_choice_2[0] == '3')){
                cout << "ENTER VALID INPUT : " ;
                cin >> temp_choice_2 ;
            }
            int choice_2 = stoi(temp_choice_2);
            if (choice_2 == 3) continue ;
            cout << "ENTER YOUR TEXT : " ;
            string text , ans ;
            cin.ignore() ;
            getline(cin, text);
            text = str_chk(text);
            bool flag = true ;
            for(char &i : text) {
                if (islower(i))flag = false ;
                i = toupper(i);
            }
            int a , b , c ;
            while(true)
            {
                string temp_a , temp_b, temp_c ;
                cout << "ENTER THE NUMBER THAT PRESENTS LETTER (a) IN THE FUNCTION : ";
                cin >> temp_a ;
                a = digits_chk(temp_a) ;
                cout << "ENTER THE NUMBER THAT PRESENTS LETTER (b) IN THE FUNCTION : ";
                cin >> temp_b ;
                b = digits_chk(temp_b) ;
                cout << "ENTER THE NUMBER THAT PRESENTS LETTER (c) IN THE FUNCTION : ";
                cin >> temp_c ;
                c = digits_chk(temp_c) ;
                if((a*c)%26 == 1 and !(a < 0 || b < 0 || c < 0 )){
                    break ;
                }
                else{
                    cout << "YOUR INPUT DOES NOT SATISFY THE CONDITION.....!\n";
                    cout << "you should input three positive integer a , b , c and ((a*c)mod 26) should be equal to 1\n";
                    cout << "============================================================================================\n";
                    cout << "Please Enter them again according to the conditions \n" ;
                    cout << "============================================================================================\n";
                }
            }
            if(choice_2 == 1)
            {
                for(char i : text) ans += encrypt(i, a , b) ;
                if(!flag) for(auto &i : ans) i = tolower(i);
                cout << "Your Encrypted Text --->> " << ans << "\n" ;
            }
            else if (choice_2 == 2)
            {
                for(char i : text) ans += decrypt(i, c , b) ;
                if(!flag) for(auto &i : ans) i = tolower(i);
                cout << "Your Decrypted Text --->> " << ans << "\n" ;
            }
        }
    }

}

