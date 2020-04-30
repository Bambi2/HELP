#include <iostream>
using namespace std;


class String
{
    protected:

    enum{SZ = 80};
    char str[SZ];

    public:

    String(){
        str[0] = '\0';
    }

    String(char s[]){
        strcpy(str, s);
    }

    void display() const{
        cout << str << endl; 
    }

    operator char*(){
        return str;
    }

};

class Pstring : public String
{
    public:

    Pstring() : String(){
    };

    Pstring(char s[]);
};

Pstring::Pstring(char s[]){
    if (strlen(s) > SZ - 1){
        for (int i = 0; i < SZ - 1; i++){
            str[i] = s[i];
        }
        str[SZ - 1] = '\0';
    }
    else{
        strcpy(str, s);
    }
}


class Pstring2 : public Pstring
{
    public:
    Pstring2() : Pstring(){
    };
    Pstring2(char s[]) : Pstring(s){
    };

    Pstring2 left(int number) const;

    Pstring2 right(int number) const;

    Pstring2 mid(int number, int indexToStart) const;

    Pstring2& operator=(const Pstring2& other){
        for(int i = 0; i < strlen(other.str); i++){
            str[i] = other.str[i];
        }
        return *this;
    }

    
};

Pstring2 Pstring2::left(int number) const{
    Pstring2 temp;

    for (int i = 0; i < number; i++){
        temp.str[i] = str[i];
    }

    return temp;
}

Pstring2 Pstring2::right(int number) const{
    Pstring2 temp;

    for (int i = strlen(str) - number; i < strlen(str); i++){
        temp.str[i] = str[i];
    }

    return temp;
}

Pstring2 Pstring2::mid(int number, int indexToStart) const{
    Pstring2 temp;

    for (int i = indexToStart - 1; i < indexToStart + number - 1; i++){
        temp.str[i] = str[i];
    }

    return temp;
}


int main()
{
    Pstring2 s1 = "Hello";

    Pstring2 s2, s3, s4;

    s1.display();
    s2 = s1.left(2);
    s3 = s1.right(2);
    s4 = s1.mid(2, 2);

    s1.display();
    cout << "S2 = "; s2.display();
    cout << "S3 = "; s3.display();
    cout << "S4 = "; s4.display();

}
