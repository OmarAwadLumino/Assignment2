#include<bits/stdc++.h>
#define Lumino iostream::\
sync_with_stdio(false);\
cin.tie(nullptr);\
cout.tie(nullptr);
#define ll long long
#define endl "\n"
#define all(v) (v.begin(),v.end())

using namespace std;

ll pow(ll n , ll i);

ll min(ll n , ll x );

ll max(ll n , ll x );

void omar(){
//#ifdef Clion
//    freopen("input.txt", "r",stdin);
//    freopen("output.txt", "w", stdout);
//#endif
}
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
        if(x[0] != '1' and x[0] != '2')return false ;
    }
    return true ;
}
string str_chk(string str){
    bool flag = false ;
    while(!flag){
        for(char i : str) {
            if (!isalpha(i) && i != ' ') {
                cout << "ENTER VALID ALPHABETIC INPUT : ";
                cin >> str;
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
            cout << "ENTER VALID INTEGER INPUT : ";
            cin >> num;
        }
    }
    int number = stoi(num);
    return number ;
}

void solve() {
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
        else{
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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ENTER YOUR TEXT : " ;
            string text , ans ; getline(cin, text);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            text = str_chk(text);
            for(char &i : text) i = toupper(i);
            string temp_a , temp_b, temp_c ;
            cout << "ENTER LETTER a IN THE FUNCTION : ";
            cin >> temp_a ;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            int a = digits_chk(temp_a) ;
            cout << "ENTER LETTER b IN THE FUNCTION : ";
            cin >> temp_b ;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            int b = digits_chk(temp_b) ;
            cout << "ENTER LETTER c IN THE FUNCTION : ";
            cin >> temp_c ;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            int c = digits_chk(temp_c) ;
            if(choice_2 == 1){
                for(char i : text){
                    ans += encrypt(i, a , b) ;
                }
                cout << "Encrypted Text --->> " << ans << "\n" ;
            }
            else if (choice_2 == 2){
                for(char i : text){
                    ans += decrypt(i, c , b) ;
                }
                cout << "Decrypted Text --->> " << ans << "\n" ;
            }
        }
    }

}

int main(){
    omar();
//    Lumino
    ll t = 1 ;
//    cin >> t ;
    while(t--)solve();
}
ll pow(ll n , ll i){
    if(i == 0)return 1 ;
    return pow(n,i-1)*n ;
}

ll min(ll n , ll x ){
    if( n >= x )return x ;
    else return n ;
}

ll max(ll n , ll x ){
    if( n <= x )return x ;
    else return n ;
}