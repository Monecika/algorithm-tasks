#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string.h>
#include <fstream>

struct coord
{
    int start = 0, start1 = 0;
    int end = 0, end1 = 0;
    int counter = 0, corabii = 0;
};

int main();
void citire(int &n, int &m, int **&T);
void citireUtilazotor(int &n, int &m, int **&T);
void afisare(int n, int m, int **T);
void afisare(int n);
void exclude(int n, int m, int **&T);
void verifica(int n, int m, int **T);
void count(int n, int m, int **T);
std::string name(int a, int b);
void transfer(int n);
void findHor(int n, int m, int **T, int &c);
void findVert(int n, int m, int **T, int &c);
void sort(int n);
void search(int n, int m, int **T);
void way(int n, int m, int **T);

#endif
