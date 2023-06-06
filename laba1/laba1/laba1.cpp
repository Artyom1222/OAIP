#include <iostream>
#include <windows.h>

using namespace std;

struct Stack {
    int a;
    Stack* next;
};

typedef Stack* PStack;

PStack addData(PStack s);
void seeStack(PStack s);
void makeStacks(PStack &chet, PStack& neChet, PStack s);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PStack userStack = NULL, chetStack = NULL, neChetStack = NULL;
    int colvo;
    while (true) {
        colvo = 100 + rand() % (100000 - 100);
        for (int i = 0; i < colvo;i++) {
            userStack = addData(userStack);
        }
        cout << "Созданный список: " << endl;
        seeStack(userStack);
        makeStacks(chetStack, neChetStack, userStack);
        cout << "Четные числа: " << endl;
        seeStack(chetStack);
        cout << "Нечетные числа: " << endl;
        seeStack(neChetStack);
        system("pause");
        system("cls");
        userStack = NULL, chetStack = NULL, neChetStack = NULL;
    }
}

PStack addData(PStack s) {
    PStack save = s;
    s = new Stack;
    s->a = 1 + rand() % (1000-1);
    s->next = save;
    return s;
}

void seeStack(PStack s) {
    PStack see = s;
    int i = 0;
    while (see != NULL)
    {
        cout << see->a << ' ';
        see = see->next;
        i++;
        if (i == 20) {
            cout << endl;
            i = 0;
        }
    }
    cout << endl;
}

void makeStacks(PStack& chet, PStack& neChet, PStack s) {
    PStack see = s, save = NULL;
    while (see!=NULL) {
        if(see->a%2==0) {
            save = chet;
            chet = new Stack;
            chet->a = see->a;
            chet->next = save;
        }
        else {
            save = neChet;
            neChet = new Stack;
            neChet->a = see->a;
            neChet->next = save;
        }
        see = see->next;
    }
}