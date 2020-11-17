#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
void 
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
        infixtopostfix(s);
        break;
        case 3:
        infixtoprefix(s);
        break;
        case 4:
        prefixtoinfix(s);
        break;
        case 5:
        prefixtopostfix(s);
        break;
        case 6:
        postfixtoprefix(s);
        break;
        case 7:
        infix_eval(s);
        break;
        case 8:
        postfix_eval(s);
        break;
        case 9:
        prefix_eval(s);
        break;
    }
    return 0;
}