#include <iostream>
using namespace std;

const int SIZE = 100;

class Token
{
    public:

    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
};

class Operator : public Token
{
    char oper;

    public:

    Operator(char oper){
        this->oper = oper;
    }

    char getOperator() override{
        return oper;
    }

    float getNumber() override{
        return 0;
    }
    
};

class Number : public Token
{
    float number;
    
    public:

    Number(){
        number = 0;
    }

    Number(float number){
        this->number = number;
    }

    float getNumber() override{
        return number;
    }

    char getOperator() override{
        return 0;
    } 
};

class Stack
{
    Token* arr[SIZE];
    int top;

    public:

    Stack(){
        top = 0;
    }

    void push(Token* value){
        arr[++top] = value;
    }

    
    Token* pop(){
        return arr[top--];
    }
    
    int getTop(){
        return top;
    }
};

class Express
{
    Stack data;
    char* str;
    int length;

    public:

    Express(char* str){
        this->str = str;
        length = strlen(str);
    }
    

    void parse();
    float solve();
};

void Express::parse(){
    char temp[SIZE];
    char ch;
    Number* number;
    Operator* oper;
    float lastValue;
    char lastOperator;
    Token* toDelete;

    for (int i = 0; i < length; i++){
        ch = str[i];

        if (ch >= '0' && ch <= '9'){
            int j = 0;
            while (str[i] == '.' || (str[i] >= '0' && str[i] <= '9')){
                temp[j++] = str[i++];
            }
            i--;
            number = new Number(atof(temp));
            data.push(number);
            while (j >= 0){
                temp[j--] = '0';
            }
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if (data.getTop() == 1){
                oper = new Operator(ch);
                data.push(oper);
            }
            else{
                lastValue = data.pop()->getNumber();
                lastOperator = data.pop()->getOperator();
                
                if ((ch == '*' || ch == '/') && (lastOperator ==  '+' || lastOperator == '-')){
                    data.push(oper);
                    data.push(number);
                }
                else{
                    delete number;
                    delete oper;

                    switch(lastOperator){
                        case '+':{
                            toDelete = data.pop();
                            number = new Number(lastValue + toDelete->getNumber());
                            delete toDelete;
                            data.push(number);
                            break;
                        }
                        case '-':{
                            toDelete = data.pop();
                            number = new Number(lastValue - toDelete->getNumber());
                            delete toDelete;
                            data.push(number);
                            break;
                        }
                        case '*':{
                            toDelete = data.pop();
                            number = new Number(lastValue * toDelete->getNumber());
                            delete toDelete;
                            data.push(number);
                            break;
                        }
                        case '/':{
                            toDelete = data.pop();
                            number = new Number(lastValue / toDelete->getNumber());
                            delete toDelete;
                            data.push(number);
                            break;
                        }
                        default:{
                            cout << "Invalid value" << endl;
                            exit(1);
                        }
                    }
                }
                oper = new Operator(ch);
                data.push(oper);
            }

        }
        else{
            cout << "Invalid value" << endl;
            exit(1);
        }
    }
}

float Express::solve(){
    float lastValue;
    Token* toDelete;
    Number* number;
    

    while(data.getTop() > 1){
        toDelete = data.pop();
        lastValue = toDelete->getNumber();
        delete toDelete;
        
        switch(data.pop()->getOperator()){
            case '+':{
                toDelete = data.pop();
                number = new Number(lastValue + toDelete->getNumber());
                delete toDelete;
                data.push(number);
                break;
            }
            case '-':{
                toDelete = data.pop();
                number = new Number(lastValue - toDelete->getNumber());
                delete toDelete;
                data.push(number);
                break;
            }
            case '*':{
                toDelete = data.pop();
                number = new Number(lastValue * toDelete->getNumber());
                delete toDelete;
                data.push(number);
                break;;
            }
            case '/':{
                toDelete = data.pop();
                number = new Number(lastValue / toDelete->getNumber());
                delete toDelete;
                data.push(number);
                break;
            }
            default:{
                cout << "Invalid value" << endl;
                exit(1);
            }
        }
    }

    return float(data.pop()->getNumber());
}


int main()
{
    char reply;
    char string[SIZE];


        cout << "Enter the express: ";
        cin >> string;
        Express* eptr = new Express(string);
        eptr->parse();
        cout << "The answer is " << eptr->solve() << endl;
        delete eptr;
    
}





