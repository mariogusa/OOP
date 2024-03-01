///problema #1
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
///problema #2
#include <iostream>
#include <cstring>
using namespace std;
bool compare(const void *a, const void *b) {
    const char *str1=*(const char **)a;
    const char *str2=*(const char **)b;
    int lg1=strlen(str1);
    int lg2=strlen(str2);
    if (lg1==lg2)
        return strcmp(str1,str2)>0;
    return lg1 < lg2;
int main() 
{
    char s[100];
    std::cin.getline(s,100);
    char *cuv[100];
    char *p=strtok(s," ");
    int nr=0;
    while (p!=NULL)
    {
        cuv[nr++]=p;
        p=strtok(NULL," ");
    }
    qsort(cuv,nr,sizeof(char *), compare);
    for(int i=nr-1;i>=0;i--)
        std::cout<<cuv[i]<<endl;
    return 0;
}
