#include <iostream>
#include <fstream>

#include <string>
using namespace std;

class Date
{
    int day;
    int month;
    int hours;
    int minutes;

public:
    Date()
    {
        day = 0;
        month = 0;
        hours = 0;
        minutes = 0;
    }

    Date(int day, int month, int hours, int minutes)
    {
        this->day = day;
        this->month = month;
        this->hours = hours;
        this->minutes = minutes;
    }

    void setDate(int day, int month, int hours, int minutes)
    {
        this->day = day;
        this->month = month;
        this->hours = hours;
        this->minutes = minutes;
    }
    void printDate()
    {
        cout << day << "/" << month << " " << hours << ":" << minutes;
    }

    int get_day()
    {
        return day;
    }

    int get_month()
    {
        return month;
    }

    int get_hours()
    {
        return hours;
    }

    int get_minutes()
    {
        return minutes;
    }

    bool operator>(const Date &other)
    {
        if (month > other.month)
        {
            return true;
        }

        else if (month < other.month)
        {
            return false;
        }

        else if (day > other.day)
        {
            return true;
        }

        else if (day < other.day)
        {
            return false;
        }

        else if (hours > other.hours)
        {
            return true;
        }

        else if (hours < other.hours)
        {
            return false;
        }

        else if (minutes > other.minutes)
        {
            return true;
        }

        else if (minutes < other.minutes)
        {
            return false;
        }

        else
        {
            return false;
        }
    }

    bool operator<(const Date &other)
    {
        if (month < other.month)
        {
            return true;
        }

        else if (month > other.month)
        {
            return false;
        }

        else if (day < other.day)
        {
            return true;
        }

        else if (day > other.day)
        {
            return false;
        }

        else if (hours < other.hours)
        {
            return true;
        }

        else if (hours > other.hours)
        {
            return false;
        }

        else if (minutes < other.minutes)
        {
            return true;
        }

        else if (minutes > other.minutes)
        {
            return false;
        }

        else
        {
            return false;
        }
    }

    bool operator==(const Date &other)
    {
        if (month == other.month && day == other.day && hours == other.hours && minutes == other.minutes)
        {
            return true;
        }

        return false;
    }
};

// ///////////////////
// START OF MOVIE CLASS
// ///////////////////
class Movie
{
    char title[200];
    Date date;
    int price;
    int viewers;
    bool is_active;

public:
    Movie();

    Movie(char *title, int day, int month, int hours, int minutes, int price, int viewers);

    void set_movie(char *title, int day, int month, int hours, int minutes, int price, int viewers);

    void print_movie();

    void set_condition(bool condition);

    bool get_condition();

    char get_first_letter();

    Date get_date();

    int get_price();

    int get_viewers();

    char *get_title();
};

Movie::Movie()
{
    is_active = false;
    strcpy(title, "unknown");
    price = 0;
    viewers = 0;
}

Movie::Movie(char *title, int day, int month, int hours, int minutes, int price, int viewers)
{
    is_active = true;
    strcpy(this->title, title);
    date.setDate(day, month, hours, minutes);
    this->price = price;
    this->viewers = viewers;
}

void Movie::set_movie(char *title, int day, int month, int hours, int minutes, int price, int viewers)
{
    is_active = true;
    strcpy(this->title, title);
    date.setDate(day, month, hours, minutes);
    this->price = price;
    this->viewers = viewers;
}

void Movie::print_movie()
{
    cout << title << " ";
    date.printDate();
    cout << " " << price << "rub " << viewers << " viewers";
    if (is_active)
    {
        cout << " (Active)" << endl;
    }
    else
    {
        cout << " (Not active)" << endl;
    }
}

void Movie::set_condition(bool condition)
{
    is_active = condition;
}

bool Movie::get_condition()
{
    if (is_active)
    {
        return true;
    }

    return false;
}

char Movie::get_first_letter()
{
    return title[0];
};

Date Movie::get_date()
{
    Date return_date(date.get_day(), date.get_month(), date.get_hours(), date.get_minutes());
    return return_date;
}

int Movie::get_price()
{
    return price;
}

int Movie::get_viewers()
{
    return viewers;
}

char *Movie::get_title()
{
    return title;
}

// ///////////////////
// END OF MOVIE CLASS
// ///////////////////

void clear_data(int index, Movie *database) //очищаем выбранный элемент
{
    database[index].set_condition(false);
}

int free_database_index(int &size, Movie *&database) //ищем свободную ячейку в массиве
{
    for (int i = 0; i < size; i++)
    {
        if (!database[i].get_condition())
        {
            return i;
        }
    }

    Movie *newDatabase = new Movie[size + 1];

    for (int i = 0; i < size; i++)
    {
        newDatabase[i] = database[i];
    }

    size++;

    delete[] database;

    database = newDatabase;

    return size - 1;
}

int get_first_active_data(Movie *database, int size) // Ищем индекс первого активного элемента
{
    for (int i = 0; i < size; i++)
    {
        if (database[i].get_condition())
        {
            return i;
        }
    }

    return 0;
}

void put_new_data(int index, Movie *database) //добавляем новый элемент в массив
{
    char title[200];
    int day;
    int month;
    int hours;
    int minutes;
    int price;
    int viewers;

    cout << "Enter the title of the movie: ";
    cin >> title;
    cout << "Enter the day, the month, the hours and the minutes: ";
    cin >> day >> month >> hours >> minutes;
    cout << "Enter the price: ";
    cin >> price;
    cout << "Enter the number of viewers: ";
    cin >> viewers;
    database[index].set_movie(title, day, month, hours, minutes, price, viewers);
}

void print_data(int index, Movie *database) //выводим в консоль выбранный элемент
{
    database[index].print_movie();
}

void print_all_data(Movie *database, int size) //выводи в консоль все активыные элементы
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (database[i].get_condition())
        {
            database[i].print_movie();
        }
    }
}

void search_data(int size, Movie *database, char *title)
{
    int max_pairs = 0;
    int index;

    for (int i = 0; i < size; i++)
    {
        if (database[i].get_condition())
        {
            int j = 0;
            while (database[j].get_title()[j] == title[j])
            {
                j++;
            }
            if (j > max_pairs)
            {
                max_pairs = j;
                index = i;
            }
        }
    }

    database[index].print_movie();
}

void search_min_data(Movie *database, int number, int size) //ищем минимальные значения по выбору (1 - название, 2 - сеанс, 3 - цена, 4 - зрители)
{
    if (number == 1)
    {
        char min_char = database[get_first_active_data(database, size)].get_first_letter();

        for (int i = 0; i < size; i++)
        {
            if (database[i].get_condition())
            {
                if (database[i].get_first_letter() < min_char)
                {
                    min_char = database[i].get_first_letter();
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (database[i].get_condition())
            {
                if (database[i].get_first_letter() == min_char)
                {
                    database[i].print_movie();
                }
            }
        }
    }
    else if (number == 2)
    {
        Date min_date = database[get_first_active_data(database, size)].get_date();

        for (int i = 0; i < size; i++)
        {
            if (database[i].get_condition())
            {
                if (database[i].get_date() < min_date)
                {
                    min_date = database[i].get_date();
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (database[i].get_condition())
            {
                if (database[i].get_date() == min_date)
                {
                    database[i].print_movie();
                }
            }
        }
    }

    else if (number == 3)
    {
        int min_price = database[get_first_active_data(database, size)].get_price();

        for (int i = 0; i < size; i++)
        {
            if (database[i].get_condition())
            {
                if (database[i].get_price() < min_price)
                {
                    min_price = database[i].get_price();
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (database[i].get_condition())
            {
                if (database[i].get_price() == min_price)
                {
                    database[i].print_movie();
                }
            }
        }
    }

    else if (number == 4)
    {
        int min_viewers = database[get_first_active_data(database, size)].get_viewers();

        for (int i = 0; i < size; i++)
        {
            if (database[i].get_condition())
            {
                if (database[i].get_viewers() < min_viewers)
                {
                    min_viewers = database[i].get_viewers();
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (database[i].get_condition())
            {
                if (database[i].get_viewers() == min_viewers)
                {
                    database[i].print_movie();
                }
            }
        }
    }

    else
    {
        cout << "Wrong value was sent" << endl;
    }
}

int main()
{
    int size = 1;
    Movie *database = new Movie[size];
    Movie spiderman("Spiderman", 21, 12, 9, 24, 700, 23200);

    database[0] = spiderman;

    put_new_data(free_database_index(size, database), database);
    put_new_data(free_database_index(size, database), database);
    put_new_data(free_database_index(size, database), database);
    put_new_data(free_database_index(size, database), database);

    print_all_data(database, size);

    print_data(3, database);

    clear_data(2, database);

    print_all_data(database, size);

    cout << "Minimum value of price" << endl;
    search_min_data(database, 3, size);

    cout << "Search by 'Aveg'" << endl;
    search_data(size, database, "Aven");

    delete[] database;
}
