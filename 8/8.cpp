#include <iostream>
using namespace std;

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

string rev(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        char t=s[i]; s[i]=s[j]; s[j]=t;
        i++; j--;
    }
    return s;
}

string inf_to_post(string s){
    char st[100]; int top=-1;
    string r="";
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c>='0'&&c<='9' || c>='a'&&c<='z' || c>='A'&&c<='Z') r+=c;
        else if(c=='(') st[++top]=c;
        else if(c==')'){
            while(top!=-1 && st[top]!='(') r+=st[top--];
            top--;
        } else {
            while(top!=-1 && prec(st[top])>=prec(c)) r+=st[top--];
            st[++top]=c;
        }
    }
    while(top!=-1) r+=st[top--];
    return r;
}

string inf_to_pre(string s){
    s = rev(s);
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    string r = inf_to_post(s);
    r = rev(r);
    return r;
}

string pre_to_inf(string s){
    string st[100]; int top=-1;
    for(int i=s.size()-1;i>=0;i--){
        char c=s[i];
        if(c>='0'&&c<='9' || c>='a'&&c<='z' || c>='A'&&c<='Z'){
            string t=""; t+=c;
            st[++top]=t;
        } else {
            string a=st[top--];
            string b=st[top--];
            string t="("+a+c+b+")";
            st[++top]=t;
        }
    }
    return st[top];
}

string post_to_inf(string s){
    string st[100]; int top=-1;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c>='0'&&c<='9' || c>='a'&&c<='z' || c>='A'&&c<='Z'){
            string t=""; t+=c;
            st[++top]=t;
        } else {
            string b=st[top--];
            string a=st[top--];
            string t="("+a+c+b+")";
            st[++top]=t;
        }
    }
    return st[top];
}

int main(){
    string s;

    cin>>s;
    cout<<inf_to_pre(s)<<endl;

    cout<<inf_to_post(s)<<endl;

    cin>>s;
    cout<<pre_to_inf(s)<<endl;

    cin>>s;
    cout<<post_to_inf(s)<<endl;
}
