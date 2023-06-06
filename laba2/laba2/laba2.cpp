#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct Unemployed
{
    string surname, gender, education, profession, position, registrationDate, desiredPosition;
    int age, workExperience, totalExperience;
    double desiredSalary;
    Unemployed* next, *previous;
}*t;

typedef Unemployed* PNode;

struct Group {
    PNode une;
    string name;
    Group* next;
};

typedef Group* PGroup;

void seeFromStart(PNode& start);
void seeFromEnd(PNode& end);
void add(PNode& start, PNode& end, int);
void del(PNode& start, PNode& end, int);
void addInGroup(PGroup& group, PNode un);
void seeGroup(PGroup group);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PNode steckUnemployedStart = NULL, steckUnemployedEnd = NULL;
    PGroup group = NULL;
    while (true)
    {
        cout << "Операции: " << endl;
        cout << "1.Добавить в начало очереди" << endl;
        cout << "2.Добавить в конец очереди" << endl;
        cout << "3.Удалить начало очереди" << endl;
        cout << "4.Удалить конец очереди" << endl;
        cout << "5.Просмотреть с начала до конца" << endl;
        cout << "6.Просмотреть с конца до начала" << endl;
        cout << "7.Создать новую группу" << endl;
        cout << "8.Увидеть все группы" << endl;
        cout << "0.Завершить" << endl;
        switch (_getch())
        {
        case '1':
            add(steckUnemployedStart, steckUnemployedEnd, 0);
            break;
        case '2':
            add(steckUnemployedStart, steckUnemployedEnd, 1);
            break;
        case '3':
            del(steckUnemployedStart, steckUnemployedEnd, 0);
            break;
        case '4':
            del(steckUnemployedStart, steckUnemployedEnd, 1);
            break;
        case '5':
            seeFromStart(steckUnemployedStart);
            break;
        case '6':
            seeFromEnd(steckUnemployedEnd);
            break;
        case '7':
            addInGroup(group, steckUnemployedStart);
            break;
        case '8':
            seeGroup(group);
            break;
        case '0':
            return 0;
            break;

        default:
            break;
        }
    }
}

void  seeFromStart(PNode& start) {
    system("cls");
    PNode steckSee = start;

    if (steckSee == NULL) {

        cout << "Очередь не создана" << endl;
        return;

    }
    int i = 1;
    do {
        cout << "Безработный №" << i << endl;
        cout << "   Фамилия: " << steckSee->surname << endl;
        cout << "   Возраст: " << steckSee->age << endl;
        cout << "   Пол: " << steckSee->gender << endl;
        cout << "   Образование: " << steckSee->education << endl;
        cout << "   Профессия: " << steckSee->profession << endl;
        cout << "   Должность: " << steckSee->position << endl;
        cout << "   Стаж работы в последней должности: " << steckSee->workExperience << endl;
        cout << "   Общий стаж: " << steckSee->totalExperience << endl;
        cout << "   Желаемая заработная плата: " << steckSee->desiredSalary << endl;
        cout << "   Желаемая должность: " << steckSee->desiredPosition << endl;
        steckSee = steckSee->next;
        i++;
    } while (steckSee != NULL);

}

void  seeFromEnd(PNode& end) {
    system("cls");
    PNode steckSeeEnd = end;
    if (steckSeeEnd == NULL) {

        cout << "Очередь не создана" << endl;
        return;

    }
    int i = 1;
    do {
        cout << "Безработный №" << i << endl;
        cout << "   Фамилия: " << steckSeeEnd->surname << endl;
        cout << "   Возраст: " << steckSeeEnd->age << endl;
        cout << "   Пол: " << steckSeeEnd->gender << endl;
        cout << "   Образование: " << steckSeeEnd->education << endl;
        cout << "   Профессия: " << steckSeeEnd->profession << endl;
        cout << "   Должность: " << steckSeeEnd->position << endl;
        cout << "   Стаж работы в последней должности: " << steckSeeEnd->workExperience << endl;
        cout << "   Общий стаж: " << steckSeeEnd->totalExperience << endl;
        cout << "   Желаемая заработная плата: " << steckSeeEnd->desiredSalary << endl;
        cout << "   Желаемая должность: " << steckSeeEnd->desiredPosition << endl;
        steckSeeEnd = steckSeeEnd->previous;
        i++;
    } while (steckSeeEnd != NULL);

}

void  add(PNode& start, PNode& end, int se) {
    system("cls");
    PNode steckAdd = new Unemployed;
    if (!steckAdd) {
        cout << "Нет свободной памяти" << endl;
    }
    steckAdd->next = 0;
    cout << "Фамилия" << endl;
    cin >> steckAdd->surname;
    cout << "Возраст" << endl;
    cin >> steckAdd->age;
    cout << "Пол" << endl;
    cin >> steckAdd->gender;
    cout << "Образование" << endl;
    cin >> steckAdd->education;
    cout << "Профессия" << endl;
    cin >> steckAdd->profession;
    cout << "Должность" << endl;
    cin >> steckAdd->position;
    cout << "Стаж работы в последней должности" << endl;
    cin >> steckAdd->workExperience;
    cout << "Общий стаж" << endl;
    cin >> steckAdd->totalExperience;
    cout << "Желаемая заработная плата" << endl;
    cin >> steckAdd->desiredSalary;
    cout << "Желаемая должность" << endl;
    cin >> steckAdd->desiredPosition;

    t = new Unemployed;
    t = steckAdd;
    if (!start) {

        t->next = t->previous = NULL;
        start = end = t;
    }
    else {
        if (se == 0) {
            t->previous = NULL;
            t->next = start;
            start->previous = t;
            start = t;
        }
        else {
            t->next = NULL;
            t->previous = end;
            end->next = t;
            end = t;
        }
    }
}

void  del(PNode& start, PNode& end, int se) {
    system("cls");
    if (start == NULL) {
        start = end = NULL;
        cout << "Очередь пуста" << endl;
        return;
    }

    if (se == 0) {

        start = start->next;
        start->previous = NULL;
    }
    else {
        end = end->previous;
        end->next = NULL;
    }

}

void addInGroup(PGroup& g, PNode un){
    system("cls");
    PGroup save = g;
    PNode see = un;
    int par;
    g = new Group;
    cout << "Введите название группы: ";
    cin >> g->name;
    while (true)
    {
        cout << "По какому параметру сделать группу?(1-возраст 2-опыт работы 3-зарплата)";
        system("cls");
        switch (_getch())
        {
        case '1':
            cout << "Введите возраст: "; cin >> par;
            while (see!=NULL) {
                if (see->age <= par) {
                    t = new Unemployed;
                    t = see;
                    if (!g->une) {

                        t->next = t->previous = NULL;
                        g->une = t;
                    }
                    else {
                        
                         t->next = NULL;
                         t->previous = g->une->previous;
                         g->une->next = t;
                         g->une = t;
                       
                    }
                }
                see = see->next;
            }
            return;
            break;
        case '2':
            cout << "Введите опыт работы: "; cin >> par;
            while (see != NULL) {
                if (see->age >= par) {
                    t = new Unemployed;
                    t = see;
                    if (!g->une) {

                        t->next = t->previous = NULL;
                        g->une = t;
                    }
                    else {

                        t->next = NULL;
                        t->previous = g->une->previous;
                        g->une->next = t;
                        g->une = t;

                    }
                }
                see = see->next;
            }
            return;
            break;
        case '3':
            cout << "Введите зарплату: "; cin >> par;
            while (see!=NULL) {
                if (see->age <= par) {
                    t = new Unemployed;
                    t = see;
                    if (!g->une) {

                        t->next = t->previous = NULL;
                        g->une = t;
                    }
                    else {
                        
                         t->next = NULL;
                         t->previous = g->une->previous;
                         g->une->next = t;
                         g->une = t;
                       
                    }
                }
                see = see->next;
            }
            return;
            break;
        default:
            cout << "Ошибка" << endl;
            break;
        }
    }
    return ;
}

void seeGroup(PGroup group) {
    system("cls");
    PGroup seeG = group;
    int i = 1;
    while (seeG != NULL) {
        cout << "Группа №" << i << " (" << seeG->name << ") " << endl << endl;
        seeFromStart(seeG->une);
        seeG = seeG->next;
        cout << endl;
    }
    return;
}