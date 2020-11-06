#include <iostream>
using namespace std;

/*
///////////////
DATE STRUCT
//////////////
*/
struct Date
{
    int day;
    int month;
    int year;

    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void print_date();
    int get_date_in_days();
    void ask_for_date();
};

void Date::print_date()
{
    cout << day << "." << month << "." << year;
}

int Date::get_date_in_days()
{
    int answer;

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        answer += 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        answer += 30;
    }

    else
    {
        answer += 28;
    }

    answer += year * 365;
    answer += day;

    return answer;
}

void Date::ask_for_date()
{
    cout << "Enter Date" << endl;
    cin >> day >> month >> year;
}
/*
//////////////////
END OF DATE STRUCT
//////////////////
*/

/*
///////////////
STUDENT STRUCT
//////////////
*/
struct Student
{
    string first_name;
    string last_name;
    string patronymic;
    Date admission;
    Date exit;

    Student();
    Student(string first_name, string last_name, string patronymic, Date admission, Date exit);
    void print_student();
    Student ask_for_data();
};

Student::Student()
{
    first_name = "unknown";
    last_name = "unknown";
    patronymic = "unknown";
}
Student::Student(string first_name, string last_name, string patronymic, Date admission, Date exit)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->patronymic = patronymic;
    this->admission.day = admission.day;
    this->admission.month = admission.month;
    this->admission.year = admission.year;
    this->exit.day = exit.day;
    this->exit.month = exit.month;
    this->exit.year = exit.year;
}

void Student::print_student()
{
    cout << last_name << " " << first_name << " " << patronymic << " Admission: ";
    admission.print_date();
    cout << " Exit: ";
    exit.print_date();
    cout << endl;
}

Student Student::ask_for_data()
{
    cout << "Enter First Name: ";
    cin >> first_name;
    cout << "Enter Last Name: ";
    cin >> last_name;
    cout << "Enter Patronymic: ";
    cin >> patronymic;
    cout << "Enter Admission Date: ";
    cin >> admission.day >> admission.month >> admission.year;
    cout << "Enter Exit Date: ";
    cin >> exit.day >> exit.month >> exit.year;

    return *this;
}
/*
/////////////////////
END OF STUDENT STRUCT
/////////////////////
*/

/*
////
LIST1
////
*/

class List
{
public:
    List();
    ~List();
    void search(int reply);
    void insert(Student data, int index); //вставка элемента
    void push_front(Student data);        //добавить в начало
    void pop_front();                     //удалить в начале
    void push_back(Student data);         //добавить в конце
    void pop_back();                      //удалить в конце
    int get_size() { return size; };      //получить размер
    void removeAt(int index);             //удалить выбранный элемент
    void clear();                         //очистить весь список
    Student &operator[](const int index); //перегрузка оператора []

private:
    class Node
    {
    public:
        Node *pNext;
        Student data;

        Node(Student data = Student(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int size;
    Node *head;
};

List::List()
{
    size = 0;
    head = nullptr;
}

List::~List()
{
    clear();
}

//POP FRONT

void List::pop_front()
{
    Node *temp = head;
    head = head->pNext;

    delete temp;

    size--;
}

//PUSH BACK

void List::push_back(Student data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node *current = head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }

        current->pNext = new Node(data);
    }

    size++;
}

//POP BACK

void List::pop_back()
{
    removeAt(size - 1);
}

//CLEAR

void List::clear()
{
    while (size)
    {
        pop_front();
    }
}

//OPERATOR[]

Student &List::operator[](const int index)
{
    int counter = 0;
    Node *current = head;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }

        current = current->pNext;
        counter++;
    }
}

//PUSH FRONT

void List::push_front(Student data)
{
    head = new Node(data, head);
    size++;
}

//INSERT

void List::insert(Student data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node *previous = head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node *newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;

        size++;
    }
}

// REMOVE AT

void List::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node *previous = head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;

        size--;
    }
}

// SEARCH
void List::search(int reply)
{
    if (reply == 0)
    {
        string temp_string;
        Node *temp_data = head;
        int max_pairs = 0;

        cout << "Enter First Name" << endl;
        cin >> temp_string;

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.first_name[j])
            {
                j++;
            }

            if (j > max_pairs)
            {
                max_pairs = j;
            }

            temp_data = temp_data->pNext;
        }

        temp_data = head;

        if (max_pairs == 0)
        {
            cout << "There's no student who you're looking for" << endl;
        }

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.first_name[j])
            {
                j++;
            }

            if (j == max_pairs)
            {
                temp_data->data.print_student();
            }

            temp_data = temp_data->pNext;
        }
    }
    else if (reply == 1)
    {
        string temp_string;
        Node *temp_data = head;
        int max_pairs = 0;

        cout << "Enter Last Name" << endl;
        cin >> temp_string;

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.last_name[j])
            {
                j++;
            }

            if (j > max_pairs)
            {
                max_pairs = j;
            }

            temp_data = temp_data->pNext;
        }

        temp_data = head;

        if (max_pairs == 0)
        {
            cout << "There's no student who you're looking for" << endl;
        }

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.last_name[j])
            {
                j++;
            }

            if (j == max_pairs)
            {
                temp_data->data.print_student();
            }

            temp_data = temp_data->pNext;
        }
    }

    else if (reply == 2)
    {
        string temp_string;
        Node *temp_data = head;
        int max_pairs = 0;

        cout << "Enter Patronymic" << endl;
        cin >> temp_string;

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.patronymic[j])
            {
                j++;
            }

            if (j > max_pairs)
            {
                max_pairs = j;
            }

            temp_data = temp_data->pNext;
        }

        temp_data = head;

        if (max_pairs == 0)
        {
            cout << "There's no student who you're looking for" << endl;
        }

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.patronymic[j])
            {
                j++;
            }

            if (j == max_pairs)
            {
                temp_data->data.print_student();
            }

            temp_data = temp_data->pNext;
        }
    }
    else if (reply == 3)
    {
        Date users_admission_date;
        Node *temp = head;

        users_admission_date.ask_for_date();

        int difference = abs(head->data.admission.get_date_in_days() - head->pNext->data.admission.get_date_in_days());

        for (int i = 0; i < size; i++)
        {
            if (abs(users_admission_date.get_date_in_days() - temp->data.admission.get_date_in_days()) < difference)
            {
                difference = abs(users_admission_date.get_date_in_days() - temp->data.admission.get_date_in_days());
            }

            temp = temp->pNext;
        }

        temp = head;

        for (int i = 0; i < size; i++)
        {
            if (abs(users_admission_date.get_date_in_days() - temp->data.admission.get_date_in_days()) == difference)
            {
                temp->data.print_student();
            }

            temp = temp->pNext;
        }
    }

    else if (reply == 4)
    {
        Date users_exit_date;
        Node *temp = head;

        users_exit_date.ask_for_date();

        int difference = abs(head->data.exit.get_date_in_days() - head->pNext->data.exit.get_date_in_days());

        for (int i = 0; i < size; i++)
        {
            if (abs(users_exit_date.get_date_in_days() - temp->data.exit.get_date_in_days()) < difference)
            {
                difference = abs(users_exit_date.get_date_in_days() - temp->data.exit.get_date_in_days());
            }

            temp = temp->pNext;
        }

        temp = head;

        for (int i = 0; i < size; i++)
        {
            if (abs(users_exit_date.get_date_in_days() - temp->data.exit.get_date_in_days()) == difference)
            {
                temp->data.print_student();
            }

            temp = temp->pNext;
        }
    }
}
/*
///////////
END OF LIST1
///////////
*/

/*
/////
LIST2
/////
*/
class List2
{
public:
    List2();
    ~List2();
    void push_back(Student data);         //добавление элемента в конце
    void push_front(Student data);        //добавление элемента в начале
    void pop_back();                      //удаление последнего элемента
    void pop_front();                     //удаление первого элемента
    void clear();                         //очистка списка
    void removeAt(int index);             //удаление выбранного элемента
    void insert(Student data, int index); //вставить элемент по выбранному индексу
    void search(int reply);               //поиск по значению
    void print_all();                     //вывести весь список

private:
    class Node
    {
    public:
        Student data;
        Node *pNext;
        Node *pPrev;

        Node(Student data = Student(), Node *pNext = nullptr, Node *pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };

    int size;
    Node *head;
    Node *tail;
};

List2::List2()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

List2::~List2()
{
    clear();
}

/*
/////////
PUSH BACK
/////////
*/
void List2::push_back(Student data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        tail = new Node(data, nullptr, tail);
    }

    size++;
}

/*
/////////
PUSH FRONT
/////////
*/

void List2::push_front(Student data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        head = new Node(data, head);
    }

    size++;
}

/*
/////////
POP BACK
/////////
*/

void List2::pop_back()
{
    Node *temp = tail;
    tail = tail->pPrev;
    tail->pNext = nullptr;

    delete temp;

    size--;
}

/*
/////////
PUSH FRONT
/////////
*/

void List2::pop_front()
{
    Node *temp = head;
    head = head->pNext;
    head->pPrev = nullptr;

    delete temp;

    size--;
}

/*
/////////
CLEAR
/////////
*/

void List2::clear()
{
    while (size)
    {
        pop_front();
    }
}

/*
/////////
REMOVE AT
/////////
*/

void List2::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else if (index == size - 1)
    {
        pop_back();
    }
    else if (size - index < size / 2)
    {
        Node *toDelete = tail;
        for (int i = size - 1; i > index; i--)
        {
            toDelete = toDelete->pPrev;
        }

        toDelete->pPrev->pNext = toDelete->pNext;
        toDelete->pNext->pPrev = toDelete->pPrev;
        delete toDelete;
    }
    else
    {
        Node *toDelete = head;
        for (int i = 0; i < index; i--)
        {
            toDelete = toDelete->pNext;
        }

        toDelete->pPrev->pNext = toDelete->pNext;
        toDelete->pNext->pPrev = toDelete->pPrev;
        delete toDelete;
    }

    size--;
}

/*
////////
INSERT
////////
*/

void List2::insert(Student data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else if (index == size - 1)
    {
        push_back(data);
    }
    else if (size - index < size / 2)
    {
        Node *current = tail;
        for (int i = size - 1; i > index; i--)
        {
            current = current->pPrev;
        }

        Node *newNode = new Node(data, current, current->pPrev);
        current->pPrev->pNext = newNode;
        current->pPrev = newNode;
    }
    else
    {
        Node *current = tail;
        for (int i = 0; i < index; i--)
        {
            current = current->pNext;
        }

        Node *newNode = new Node(data, current, current->pPrev);
        current->pPrev->pNext = newNode;
        current->pPrev = newNode;
    }

    size++;
}

/*
////////
SEARCH
////////
*/

void List2::search(int reply)
{
    if (reply == 0)
    {
        string temp_string;
        Node *temp_data = head;
        int max_pairs = 0;

        cout << "Enter First Name" << endl;
        cin >> temp_string;
        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.first_name[j])
            {
                j++;
            }

            if (j > max_pairs)
            {
                max_pairs = j;
            }

            temp_data = temp_data->pNext;
        }

        temp_data = head;

        if (max_pairs == 0)
        {
            cout << "There's no student who you're looking for" << endl;
        }

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.first_name[j])
            {
                j++;
            }

            if (j == max_pairs)
            {
                temp_data->data.print_student();
            }

            temp_data = temp_data->pNext;
        }
    }
    else if (reply == 1)
    {
        string temp_string;
        Node *temp_data = head;
        int max_pairs = 0;

        cout << "Enter Last Name" << endl;
        cin >> temp_string;

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.last_name[j])
            {
                j++;
            }

            if (j > max_pairs)
            {
                max_pairs = j;
            }

            temp_data = temp_data->pNext;
        }

        temp_data = head;

        if (max_pairs == 0)
        {
            cout << "There's no student who you're looking for" << endl;
        }

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.last_name[j])
            {
                j++;
            }

            if (j == max_pairs)
            {
                temp_data->data.print_student();
            }

            temp_data = temp_data->pNext;
        }
    }

    else if (reply == 2)
    {
        string temp_string;
        Node *temp_data = head;
        int max_pairs = 0;

        cout << "Enter Patronymic" << endl;
        cin >> temp_string;

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.patronymic[j])
            {
                j++;
            }

            if (j > max_pairs)
            {
                max_pairs = j;
            }

            temp_data = temp_data->pNext;
        }

        temp_data = head;

        if (max_pairs == 0)
        {
            cout << "There's no student who you're looking for" << endl;
        }

        for (int i = 0; i < size; i++)
        {
            int j = 0;

            while (temp_string[j] == temp_data->data.patronymic[j])
            {
                j++;
            }

            if (j == max_pairs)
            {
                temp_data->data.print_student();
            }

            temp_data = temp_data->pNext;
        }
    }
    else if (reply == 3)
    {
        Date users_admission_date;
        Node *temp = head;

        users_admission_date.ask_for_date();

        int difference = abs(head->data.admission.get_date_in_days() - head->pNext->data.admission.get_date_in_days());

        for (int i = 0; i < size; i++)
        {
            if (abs(users_admission_date.get_date_in_days() - temp->data.admission.get_date_in_days()) < difference)
            {
                difference = abs(users_admission_date.get_date_in_days() - temp->data.admission.get_date_in_days());
            }

            temp = temp->pNext;
        }

        temp = head;

        for (int i = 0; i < size; i++)
        {
            if (abs(users_admission_date.get_date_in_days() - temp->data.admission.get_date_in_days()) == difference)
            {
                temp->data.print_student();
            }

            temp = temp->pNext;
        }
    }

    else if (reply == 4)
    {
        Date users_exit_date;
        Node *temp = head;

        users_exit_date.ask_for_date();

        int difference = abs(head->data.exit.get_date_in_days() - head->pNext->data.exit.get_date_in_days());

        for (int i = 0; i < size; i++)
        {
            if (abs(users_exit_date.get_date_in_days() - temp->data.exit.get_date_in_days()) < difference)
            {
                difference = abs(users_exit_date.get_date_in_days() - temp->data.exit.get_date_in_days());
            }

            temp = temp->pNext;
        }

        temp = head;

        for (int i = 0; i < size; i++)
        {
            if (abs(users_exit_date.get_date_in_days() - temp->data.exit.get_date_in_days()) == difference)
            {
                temp->data.print_student();
            }

            temp = temp->pNext;
        }
    }
}

/*
/////////
PRINT ALL
/////////
*/

void List2::print_all()
{
    Node *current = head;
    while (current != nullptr)
    {
        current->data.print_student();
        current = current->pNext;
    }
}
/*
///////////
END OF LIST2
///////////
*/

int main()
{
    List2 lst;
    Student current;

    int reply;

    do
    {
        cout << "What do you want to do? (0 - push_back, 1 - push_front, 2 - pop_back, 3 - pop_front, 4 - search, 5 - insert, 6 - delete, 7 - print all, 8 - exit)" << endl;
        cin >> reply;

        if (reply == 0)
        {
            lst.push_back(current.ask_for_data());
        }
        else if (reply == 1)
        {
            lst.push_front(current.ask_for_data());
        }
        else if (reply == 2)
        {
            lst.pop_back();
        }
        else if (reply == 3)
        {
            lst.pop_front();
        }
        else if (reply == 4)
        {
            cout << "What do you want to search for? (0 - first name, 1 - last name, 2 - patronymic, 3 - admission date, 4 - exit date)" << endl;
            int answer;
            cin >> answer;
            lst.search(answer);
        }
        else if (reply == 5)
        {
            int index;
            cout << "What index do you want to insert after?" << endl;
            cin >> index;
            lst.insert(current.ask_for_data(), index - 1);
        }
        else if (reply == 6)
        {
            cout << "What index do you want to delete?" << endl;
            int indexToDelete;
            cin >> indexToDelete;
            lst.removeAt(indexToDelete);
        }
        else if (reply == 7)
        {
            lst.print_all();
        }
        else if (reply == 8)
        {
            break;
        }
        else
        {
            cout << "Invalid data, try again" << endl;
        }
    } while (true);
}
