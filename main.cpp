#include "header.h"
#include "test.cpp"
using namespace std;

int main()
{
    int n, m;
    int **T;
    citire(n, m, T);
    coord v[n];
    int c = 0;

    int choice;
    do
    {
        cout << "\n";
        cout << "\n1. Afisarea planului cu corabii";
        cout << "\n2. Verifica toipul de corabie";
        cout << "\n3. Excluderea unei corabii";
        cout << "\n4. Numarul de corabii prezente";
        cout << "\n5. Gaseste corabiile care se afla pe orizontala si verticala(Transmiterea datelor in fisier)";
        cout << "\n6. Afiseaza toate corabiile din plan in forma sortata";
        cout << "\n7. Cauta cea mai zona unde se afla corabia de dimensiunea C";
        cout << "\n8. Cea mai scurta cale de deplasare pana in alt punct";
        cout << "\n0. Iesire";
        cout << "\nAlegerea: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            afisare(n, m, T);
            break;
        case 2:
            verifica(n, m, T);
            break;
        case 3:
            exclude(n, m, T);
            break;
        case 4:
            count(n, m, T);
            break;
        case 5:
            findHor(n, m, T, c);
            break;
        case 6:
            sort(c);
            afisare(c);
            break;
        case 7:
            search(n, m, T);
            break;
        case 8:
            way(n, m, T);
            break;
        case 0:
            cout << "iesire din program";
            break;
        default:
            cout << "A fost introdusa gresit varianta";
        }
        cout << "\n";
    } while (choice != 0);

    return 0;
}