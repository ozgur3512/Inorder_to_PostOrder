#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

void infix_to_postfix(string,string&);
bool higher_priority(char,char);
double eval_postfix(string);
double evaluate(double,double,char);

int main(){
    string infix;
    string postfix;
    bool is_exit = false;

    while(!is_exit)
    {
        cout<<"Input the expression in infix: ";
        cin>>infix;

        if (infix == "E" || infix == "e") 
            is_exit = true;

        else
        {
            infix_to_postfix(infix, postfix);
            cout<<postfix<<endl;
            cout<<setprecision(2)<<fixed<<eval_postfix(postfix)<<endl;  
        }
        
        cin.clear();
        cin.ignore();
        infix.clear();
        postfix.clear();

    }
    return EXIT_SUCCESS;
}

void infix_to_postfix(string infix,string& postfix)
{
    stack<char> s;
    string new_string;
    int a=infix.length(); /* Finding string's length */
    
    for(int i=0;i!=a;i++){
        char j=infix[i];
        if(isdigit(j)){/* isdigit function returns true value if it's ASCII char matches int number */
           
            postfix+=j;
            
        }
        else if(!isdigit(j) && s.empty()){
            s.push(j);

        }
        else if(!isdigit(j) && !s.empty()){
            if(!higher_priority(j,s.top())){  /* If priority is higher and stack is not empty push last in */  
                s.push(j);
            }
            else{
                
                while(higher_priority(j,s.top())){/* While priority is not higher try to find a higher value*/ 
                    postfix+=s.top();
                    s.pop();
                      
                    if(s.empty()){
                        s.push(j);
                        break;

                    }

                }
                if(!higher_priority(j,s.top())){    
                s.push(j);
                }
            
            }

        } 
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();

    }
    
   
    
    
    // *********************Fill this method 
    

}





bool higher_priority(char first,char second){
    if((first=='*' || first=='/') && (second=='+' || second=='-'))
        return false;
   
   else if((first=='+' || first=='-') && (second=='+' || second=='-')){
       return true;
   }
    else if((first=='+' || first=='-') && (second=='*' || second=='/')){
       return true;
   }
  
    else return true;
}

 double eval_postfix(string expr){
    stack<double> s;
    double first, second;
    string temp=expr;
    int a=temp.length();
    
    for(int i=0;i!=a;i++){
        char j =temp[i];
        if(isdigit(j)){
            int x=j-48; /* ASCII to int */
            
            s.push(x);
        }
        else{
            second=s.top();
            s.pop();
            first=s.top();
            s.pop();
            s.push(evaluate(first,second,j));
            
        }
        
    }
    // *********************Fill this method 

    return s.top();
}  

double evaluate(double first,double second,char c){
    switch(c){
        case '*':
            return first*second;
        case '+':
            return first+second;
        case '-':
            return first-second;
        case '/':
            return first/second;
        default:
            return 0;
    }
}
/* @Author
Student Name: Özgür Seferoðlu
Student ID : 150190068
Date: 9/11/2021 */

