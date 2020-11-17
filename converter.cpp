#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
void intro(){
    cout<<"Welcome TO Expression Evalutaor\n\t\tBy: Manav Dhiman\n\n";
}
int main(){
    intro();
    string s;
    int i;
    g:cout<<"Enter 1 for input Expression\n";
    cout<<"Enter 2 for Infix to Postfix\n";
    cout<<"Enter 3 for Infix to Prefix\n";
    cout<<"Enter 4 for Prefix to Infix\n";
    cout<<"Enter 5 for Prefix to Postfix\n";
    cout<<"Enter 6 for Postfix to Prefix\n";
    cout<<"Enter 7 for Infix Evalutaion\n";
    cout<<"Enter 8 for Postfix Evalutaion\n";
    cout<<"Enter 7 for Prefix Evalutaion\n";
    cin>>i;
    switch(i){
        case 1:
        cin>>s;
        break;
        case 2:
        infixtopostfix();
        break;
        case 3:
        infixtoprefix();
        break;
        case 4:
        prefixtoinfix();
        break;
        case 5:
        prefixtopostfix();
        break;
        case 6:
        postfixtoprefix();
        break;
        case 7:
        infixeval();
        break;
        case 8:
        postfixeval();
        break;
        case 9:
        prefixeval();
        break;
    }
    return 0;
}