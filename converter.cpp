#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(int i=0;i<n;i++)
#define loop1(i,k,n) for(i=k;i<n;i++)
#define pb push_back
typedef long long int ll;
int order(char c){
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    return -1;
}
void infixtopostfix(string s){
    stack<char> st;
    int len=s.length();
    string ans;
    st.push('\n');
    loop(i,len){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) ans+=s[i];
        else if(s[i]=='(') st.push('(');
        else if(s[i]==')'){
            while(st.top()!='\n'&&st.top()!='('){
                char ch=st.top();
                st.pop();
                ans+=ch;
            }
            if(st.top()=='('){
                st.pop();
            }
        }
        else{
            while(st.top()!='\n'&&order(s[i])<=order(st.top())){
                char ch=st.top();
                st.pop();
                ans+=ch;
            }
            st.push(s[i]);
        }
    }
    while(st.top()!='\n'){
        char ch=st.top();
        st.pop();
        ans+=ch;
    }
    cout<<"Postfix Expression = "<<ans<<endl;
}
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
    cout<<"Enter 9 for Prefix Evalutaion\n";
    cout<<"Enter 10 for exit\n";
    cin>>i;
    switch(i){
        case 1:
        cin>>s;
        goto g;
        break;
        case 2:
        infixtopostfix(s);
        goto g;
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
        case 10:
        break;
    }
    return 0;
}