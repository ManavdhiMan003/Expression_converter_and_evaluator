#include<bits/stdc++.h>
#include<string>
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
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^') return true;
    return false;
}
bool operand(char c){
    if(c>='a'&&c<='z'||c>='A'&&c<='Z') return true;
    return false;
}
int expr(int val,int val2,char c){
    if(c=='+') return val+val2;
    if(c=='-') return val2-val;
    if(c=='*') return val*val2;
    if(c=='/') return val2/val;
    if(c=='^') return val2^val;
    return 0;
}
string infixtopostfix(string s){
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
    return ans;
}
void postfixtoinfix(string s){
    stack<string> st;
    int len = s.length();
    loop(i,len){
        if(operand(s[i])){
            string t(1,s[i]);
            st.push(t);
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            st.push("("+t2+s[i]+t1+")");
        }
    }
    cout<<"\nPostfix to Infix Expression = "<<st.top()<<endl<<endl;
}
void infixtoprefix(string s){
    int len = s.length();
    reverse(s.begin(),s.end());
    loop(i,len){
        if(s[i]==')') s[i++]='(';
        else if(s[i]=='(') s[i++]=')';
    }
    string ans = infixtopostfix(s);
    reverse(ans.begin(),ans.end());
    cout<<"Infix to Prefix Expression = "<<ans<<endl<<endl;
}
void prefixtoinfix(string s){
    stack<string> st;
    for(int i=s.length()-1;i>=0;i--){
        if(isOperator(s[i])){
            string t=st.top();
            st.pop();
            string t2= st.top();
            st.pop();
            st.push('('+t+s[i]+t2+')');
        }
        else{
            string t(1,s[i]);
            st.push(t);
        }
    }
    cout<<"Prefix to Infix Expression = "<<st.top()<<endl<<endl;
}
void prefixtopostfix(string s){
    stack<string> st;
    for(int i=s.length()-1;i>=0;i--){
        if(isOperator(s[i])){
            string t=st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(t+t2+s[i]);
        }
        else    st.push(string(1,s[i]));
    }
    cout<<"Prefix to Postfix Expression = "<<st.top()<<endl<<endl;
}
void postfixtoprefix(string s){
    stack<string> st;
    loop(i,s.length()){
        if(isOperator(s[i])){
            string t = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(s[i]+t2+t);
        }
        else    st.push(string(1,s[i]));
    }
    string ans;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<"Postfix to Prefix Expression = "<<ans<<endl<<endl;
}
void postfix_eval(string s){
    stack<int> st;
    loop(i,s.length()){
        if(s[i]==' ') continue;
        else if(isdigit(s[i])){
            int no=0;
            while(isdigit(s[i])){
                no=no*10+int(s[i]-'0');
                i++;
            }
            i--;
            st.push(no);
        }
        else{
            int val=st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            st.push(expr(val,val2,s[i]));
        }
    }
    cout<<"\nPostfix Evaluation = "<<st.top()<<endl<<endl;
}
void prefix_eval(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==' ') continue;
        if(isdigit(s[i])){
            int no=0;
            while(isdigit(s[i])){
                no=no*10+int(s[i]-'0');
                i--;
            }
            i++;
            st.push(no);
        }
        else{
            int t=st.top();
            st.pop();
            int t2=st.top();
            st.pop();
            st.push(expr(t2,t,s[i]));
        }
    }
    cout<<"\nPrefix Expression = "<<st.top()<<endl<<endl;
}
void infix_eval(string s){
    stack<int> st;
    stack<char> opd;
    loop(i,s.length()){
        if(s[i]==' ') continue;
        else if(s[i]=='(') opd.push(s[i]);
        else if(isdigit(s[i])){
            int no=0;
            while(isdigit(s[i])&&i<s.length()){
                no=no*10+int(s[i++]-'0');
            }
            i--;
            st.push(no);
        }
        else if(s[i]==')'){
            while(!opd.empty()&&opd.top()!='('){
                int t=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                char c = opd.top();
                opd.pop();
                st.push(expr(t,t2,c));
            }
            if(!opd.empty()) opd.pop();
        }
        else{
            while(!opd.empty()&&order(s[i])<=order(opd.top())){
                int t=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                char c = opd.top();
                opd.pop();
                st.push(expr(t,t2,c));
            }
            opd.push(s[i]);
        }
    }
    while(!opd.empty()){
        int t=st.top();
        st.pop();
        int t2=st.top();
        st.pop();
        char c = opd.top();
        opd.pop();
        st.push(expr(t,t2,c));
    }
    cout<<"\nInfix Evaluation = "<<st.top()<<endl<<endl;
}
void intro(){
    cout<<"Welcome TO Expression Evalutaor\n\t\tBy: Manav Dhiman\n\t\tRoll NO. 19103063\n\n";
}
int main(){
    intro();
    string s;
    int i;
    g:cout<<"Enter 1 for input Expression\n";
    cout<<"Enter 2 for Infix to Postfix\n";
    cout<<"Enter 3 for Postfix to Infix\n";
    cout<<"Enter 4 for Infix to Prefix\n";
    cout<<"Enter 5 for Prefix to Infix\n";
    cout<<"Enter 6 for Prefix to Postfix\n";
    cout<<"Enter 7 for Postfix to Prefix\n";
    cout<<"Enter 8 for Infix Evalutaion\n";
    cout<<"Enter 9 for Postfix Evalutaion\n";
    cout<<"Enter 10 for Prefix Evalutaion\n";
    cout<<"Enter 11 for exit\n";
    cin>>i;
    switch(i){
        case 1:
        cout<<"\n\nEnter your string = ";
        cin.ignore();
        getline(cin,s);
        cout<<endl;
        goto g;
        case 2:
        cout<<"\nInfix to Postfix Expression = "<<infixtopostfix(s)<<endl<<endl;
        goto g;
        case 3:
        postfixtoinfix(s);
        goto g;
        case 4:
        infixtoprefix(s);
        goto g;
        case 5:
        prefixtoinfix(s);
        goto g;
        case 6:
        prefixtopostfix(s);
        goto g;
        case 7:
        postfixtoprefix(s); 
        goto g;
        case 8:
        infix_eval(s);
        goto g;
        case 9:
        postfix_eval(s);
        goto g;
        case 10:
        prefix_eval(s);
        goto g;
        case 11:
        break;
    }
    return 0;
}