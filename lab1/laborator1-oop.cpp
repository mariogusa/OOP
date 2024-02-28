#include <iostream>
#include <fstream>
using namespace std;
istream fin("in.txt");
int transformare(const char *a) 
    {
    int rez=0,semn=1,i=0;
    while (a[i]==' ') 
        i++;
    if (a[i]=='-'||a[i]=='+') 
        semn=(a[i++]=='-') ? -1 : 1;
    while (a[i]>='0'&&a[i]<='9')
        rez=rez*10+(a[i++]-'0');
    return semn*rez;
    }
int main() 
{
    FILE *file = fopen("in.txt", "w");
    char linie[100];
    int s=0;
    while (fgets(linie, sizeof(linie), in.txt))
        {
            char *p=strtok(linie," ");
            while (p!=NULL)
            {
                suma=suma+transformare(p);
                p=strtok(NULL, " ");
            }
        }


    fclose(file);
    return 0;
}