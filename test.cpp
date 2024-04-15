#include "header.h"
using namespace std;

coord v[10];

void citire(int &n, int &m, int **&T)
{
    ifstream f("corabii.in");
    f >> n >> m;

    T = new int *[n];
    for (int i = 0; i < n; i++)
    {
        T[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            f >> T[i][j];
        }
    }
    f.close();
}

void citireUtilizator(int &n, int &m, int **&T)
{
    ifstream f("corabii.in");
    f >> n >> m;
    f.close();
    T = new int *[n];
    for (int i = 0; i < n; i++)
    {
        T[i] = new int[m];
    }

    cout << "1 - corabie";
    cout << "\n0- spatiu";
    cout << "Dimensiunea planului [" << n << "][" << m << "]";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Introduceti pozitia [" << i << "][" << j << "]: ";
            cin >> T[i][j];
        }
    }
}

void afisare(int n, int m, int **T)
{
    cout << "Planul cu corabii: \n";
    cout << " ";
    for (int i = 0; i < (n * 2) + 1; i++)
    {
        cout << "-";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < m; j++)
        {
            cout << T[i][j] << " ";
        }
        cout << "| ";
        cout << "\n";
    }

    cout << " ";
    for (int i = 0; i < (n * 2) + 1; i++)
    {
        cout << "-";
    }
}

void afisare(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << i << ". Corabie " << name(v[i].start, v[i].end) << ", de lungimea " << v[i].counter << " cu coordonatele " << v[i].start << ", " << v[i].start1 << " -> " << v[i].end << ", " << v[i].end1;
    }
}

void exclude(int n, int m, int **&T)
{
    int a, b, a1, b1;
    cout << "Introduce coordonatele unde incepe corabia care doriti sa o stergeti: ";
    cin >> a >> b;
    cout << "Introduce coordonatele pana unde doriti sa excludeti corabia: ";
    do
    {
        cin >> a1 >> b1;
        if (a1 != a && b1 != b)
        {
            cout << "Ati introdus gresit, va rog sa repetati procedura: ";
        }
    } while (a1 != a && b1 != b);

    if (a > a1)
    {
        swap(a, a1);
    }
    if (b > b1)
    {
        swap(b, b1);
    }

    int counter = 0;
    if (a == a1)
    {
        for (int j = b; j <= b1; j++)
        {
            if (T[a][j] == 1)
            {
                counter++;
                T[a][j] = 0;
            }
        }
    }
    else if (b == b1)
    {
        for (int i = a; i <= a1; i++)
        {
            if (T[i][b] == 1)
            {
                counter++;
                T[i][b] = 0;
            }
        }
    }

    cout << "Au fost sterse " << counter << " portiuni de corabie\n";
    afisare(n, m, T);
}
void verifica(int n, int m, int **T)
{
    int a, a1;
    int b, b1;
    int counter = 0;
st:
    cout << "Introduceti coordonatele unde incepe corabia: ";
    cin >> a >> b;
    if (T[a][b] != 1)
        goto st;
en:
    cout << "Introduceti coordonatele unde se finiseaza corabia: ";
    cin >> a1 >> b1;
    if (T[a1][b1] != 1 || (a1 != a && b1 != b))
        goto en;

    if (a1 < a)
        swap(a, a1);
    else if (b1 < b)
        swap(b1, b);

    cout << "In portiune se afla: \n";
    if (b == b1)
        for (int i = a; i <= a1; i++)
        {
            if (T[a][b] == 1)
                counter++;
            if (T[a][b] == 0 || i == a1)
            {
                cout << "Corabie verticala pe " << counter << " pozitii\n";
                counter = 0;
            }
        }
    else if (a == a1)
        for (int i = b; i <= b1; i++)
        {
            if (T[a][b] == 1)
                counter++;
            if (T[a][b] == 0 || i == b1)
            {
                cout << "Corabie orizontala pe " << counter << " pozitii\n";
            }
        }
}

void count(int n, int m, int **T)
{
    int counter = 0;
    int corabii = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (T[i][j] == 1)
            {
                if (i + 1 < n)
                {
                    if (i - 1 >= 0 && T[i - 1][j] != 1)
                    {
                        if (T[i + 1][j] != 1)
                            counter++;
                    }
                    else if (i - 1 < 0)
                    {
                        if (T[i + 1][j] != 1)
                        {
                            counter++;
                        }
                    }
                }
                else if (i - 1 >= 0)
                {
                    if (i + 1 < n && T[i + 1][j] != 1)
                    {
                        if (T[i - 1][j] != 1)
                            counter++;
                    }
                    else if (i + 1 >= n)
                    {
                        if (T[i - 1][j] != 1)
                        {
                            counter++;
                        }
                    }
                }
            }
            if ((T[i][j] == 0 || j + 1 >= m) && counter > 0)
            {
                corabii++;
                counter = 0;
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (T[i][j] == 1)
            {
                if (j + 1 < m)
                {
                    if (j - 1 >= 0 && T[i][j - 1] != 1)
                    {
                        if (T[i][j + 1] != 1)
                            counter++;
                    }
                    else if (j - 1 < 0)
                    {
                        if (T[i][j + 1] != 1)
                        {
                            counter++;
                        }
                    }
                }
                else if (j - 1 >= 0)
                {
                    if (j + 1 < m && T[i][j + 1] != 1)
                    {
                        if (T[i][j - 1] != 1)
                            counter++;
                    }
                    else if (j + 1 >= m)
                    {
                        if (T[i][j - 1] != 1)
                        {
                            counter++;
                        }
                    }
                }
            }
            if (T[i][j] == 0 || i + 1 >= n)
            {
                if (counter > 1)
                    corabii++;
                counter = 0;
            }
        }
    }
    cout << "Sunt " << corabii << " corabii pe plan\n";
}

string name(int a, int b)
{
    if (a != b)
        return "verticala";
    return "orizontala";
}

void sort(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j].counter > v[j + 1].counter)
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void transfer(int n)
{
    ofstream g("orizont.txt", ios::trunc);
    for (int i = 0; i < n; i++)
        g << i << ". Corabie " << name(v[i].start, v[i].end) << ", de lungimea " << v[i].counter << " cu coordonatele " << v[i].start << ", " << v[i].start1 << " -> " << v[i].end << ", " << v[i].end1 << "\n";
    g.close();
}

void findHor(int n, int m, int **T, int &c)
{
    if (c != 0)
    {
        c = 0;
        v[c].counter = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (T[i][j] == 1)
            {
                if (v[c].counter == 0)
                {
                    v[c].start = i;
                    v[c].start1 = j;
                }
                if (i + 1 < n)
                {
                    if (i - 1 >= 0)
                    {
                        if (T[i - 1][j] != 1 && T[i + 1][j] != 1)
                            v[c].counter++;
                    }
                    else if (T[i + 1][j] != 1)
                        v[c].counter++;
                }
                else if (i - 1 >= 0)
                {
                    if (i + 1 < m)
                    {
                        if (T[i + 1][j] != 1 && T[i - 1][j] != 1)
                            v[c].counter++;
                    }
                    else if (T[i - 1][j] != 1)
                        v[c].counter++;
                }
            }
            if ((T[i][j] == 0 || j + 1 >= m) && v[c].counter > 0)
            {
                v[c].end = i;
                v[c].end1 = j;
                c += 1;
                v[c].counter = 0;
            }
        }
    }
    transfer(c);
    findVert(n, m, T, c);
}

void findVert(int n, int m, int **T, int &c)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (T[i][j] == 1)
            {
                if (v[c].counter == 0)
                {
                    v[c].start = i;
                    v[c].start1 = j;
                }
                if (j + 1 < m)
                {
                    if (j - 1 >= 0)
                    {
                        if (T[i][j - 1] != 1 && T[i][j + 1] != 1)
                        {
                            v[c].counter++;
                        }
                    }
                    else if (T[i][j + 1] != 1)
                    {
                        v[c].counter++;
                    }
                }
                else if (j - 1 >= 0)
                {
                    if (j + 1 < m)
                    {
                        if (T[i][j - 1] != 1 && T[i][j + 1] != 1)
                        {
                            v[c].counter++;
                        }
                    }
                    else if (T[i][j - 1] != 1)
                    {
                        v[c].counter++;
                    }
                }
            }
            if ((T[i][j] == 0 || i + 1 >= n) && v[c].counter > 1)
            {
                v[c].end = i;
                v[c].end1 = j;
                c = c + 1;
                v[c].counter = 0;
            }
        }
    }
    afisare(c);
}

void search(int n, int m, int **T)
{
    int n1 = n * 2;
    coord v[n1];
    coord v1[n1];
    coord final[n1];
    int c = 0, C;
    bool ver, check;
    do
    {
        cout << "Introduce numarul de corabii care doriti sa le gasiti(1<=C<=7): ";
        cin >> C;
    } while (C < 1 || C > 7);
    for (int d = 0; d < m; d++)
    {
        ver = 0;
        for (int i = d; i < n; i++)
        {
            if (ver == 1)
                break;
            for (int j = 0; j < m; j++)
            {
                if ((v[c].corabii == 0 && v1[c].corabii == 0) && (v1[c].counter == 0 && v[c].counter == 0))
                {
                    final[c].start = i;
                    final[c].start1 = 0;
                }

                if (T[i][j] == 1)
                {
                    if ((i + 1 < n && T[i + 1][j] == 1) || v1[c].counter >= 1)
                    {
                        if (d != i)
                        {
                            v1[c].counter++;
                            if (i + 2 < n && T[i + 2][j] != 1)
                            {
                                check = 1;
                            }
                            else
                                check = 0;
                        }
                        else if (d == i && i - 1 >= 0 && T[i - 1][j] != 1)
                        {
                            v1[c].counter++;
                        }
                        else if (d == i && i - 1 < 0 && T[i + 1][j] == 1)
                        {
                            v1[c].counter++;
                            check = 1;
                        }
                    }
                    else if (i - 1 >= 0 && T[i - 1][j] != 1)
                    {
                        v[c].counter++;
                    }
                }
                else if ((T[i][j] == 0 && (v1[c].counter != 0 || v[c].counter != 0)) || (j + 1 >= m && v1[c].counter == 0 && v[c].counter == 0))
                {
                    if (v1[c].counter > 1 && i + 1 < n && T[i + 1][j] != 1 && check == 1)
                    {
                        v1[c].corabii++;
                        v1[c].counter = 0;
                        v[c].counter = 0;
                    }
                    else if (v[c].counter > 0)
                    {
                        v[c].corabii++;
                        v1[c].counter = 0;
                        v[c].counter = 0;
                    }

                    if (v[c].corabii + v1[c].corabii == C)
                    {
                        final[c].end = i;
                        final[c].end1 = n - 1;
                        c++;
                        ver = 1;
                        break;
                    }
                }
            }
        }
    }
    int minDistanceIndex = 0;
    int currentDistance;
    int minDistance;

    for (int i = 1; i < c; i++)
    {
        currentDistance = (final[i].end1 + final[i].end) - final[i].start + final[i].start1;
        minDistance = (final[minDistanceIndex].end1 + final[minDistanceIndex].end) - final[minDistanceIndex].start + final[minDistanceIndex].start1;
        if (currentDistance < minDistance)
        {
            minDistanceIndex = i;
        }
    }
    cout << "Cele " << C << " corabii au fost gasite in zona [" << final[minDistanceIndex].start << "][" << final[minDistanceIndex].start1 << "] -> [" << final[minDistanceIndex].end << "][" << final[minDistanceIndex].end1 << "]";
}

void way(int n, int m, int **T)
{
    ofstream e("way.txt", ios::trunc);
    int start, start1;
    int end, end1;

st:
    cout << "Introduceti coordonatele de unde va incepe ([start][start1] == 1): ";
    cin >> start >> start1;
    if (T[start][start1] == 1)
    {
        if (start - 1 >= 0 && T[start - 1][start1] == 1)
            goto st;
        else if (start + 1 < n && T[start][start1 + 1] == 1)
            goto st;
        else if (start1 - 1 >= 0 && T[start][start1] == 1)
            goto st;
        else if (start1 + 1 < m && T[start][start1 + 1] == 1)
            goto st;
    }

    int progress = start, progress1 = start1;

    do
    {
        cout << "Introduceti coordonatele unde va ajunge([end][end1] == 0): ";
        cin >> end >> end1;
    } while (T[end][end1] != 0);

    while (progress != end || progress1 != end1)
    {
        e << progress << " " << progress1;
        e << "\n";

        if (end > progress && T[progress + 1][progress1] != 1 && progress + 1 < n)
            progress += 1;
        else if (end1 > progress1 && T[progress][progress1 + 1] != 1 && progress1 + 1 < m)
            progress1 += 1;
        else if (end < progress && T[progress - 1][progress1] != 1 && progress - 1 >= 0)
            progress -= 1;
        else if (end1 < progress1 && T[progress][progress1 - 1] != 1 && progress1 - 1 >= 0)
            progress1 -= 1;
        else
            break;
    }
    e.close();
}