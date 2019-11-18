#include <string>
#include <iostream>
using namespace std;

int length(string);
int find(string, char);
int findAll(string, char);
string substr(string, int, int);
void erase(string&, int, int);
void insert(string&, int, string);

int main()
{
    string sTexto = "Hola mundo";
    // cout << sTexto.length() << endl;
    // cout << length(sTexto) << endl;
    // cout << sTexto.find('o') << endl;
    // cout << find(sTexto, 'o') << endl;
    // cout << findAll(sTexto, 'o') << endl;
    // cout << sTexto.substr(5, 5) << endl;
    // cout << substr(sTexto, 5, 5) << endl;
    // sTexto.erase(5, 5);
    // cout << sTexto << endl;
    // erase(sTexto, 5, 5);
    // cout << sTexto << endl;
    // sTexto.insert(sTexto, 5, "gran");
    insert(sTexto, 5, "gran ");
    cout << sTexto << endl;
    return 0;
}

int length(string sTexto)
{
    int iCont, iX;
    iCont = 0;
    for (iX = 0; sTexto[iX] != '\0'; iX++)
    {
        iCont++;
    }
    return iCont;
}

int find(string sTexto, char cChar)
{
    for (int iX = 0; sTexto[iX] != '\0'; iX++)
    {
        if (sTexto[iX] == cChar)
        {
            return iX;
        }
    }
    return -1;
}

int findAll(string sTexto, char cChar)
{
    int iCont, iX;
    iCont = 0;
    for (iX = 0; iX < length(sTexto); iX++)
    {
        if (sTexto[iX] == cChar)
        {
            iCont++;
            cout << "Indice " << iX << endl;
        }
    }
    return iCont;
}


string substr(string sTexto, int iIndice, int iCuantos)
{
    string sRes = "";
    int iX;
    if ((0 <= iIndice) && (iIndice < length(sTexto)) && ((iIndice + iCuantos) <= length(sTexto)))
    {
        for (iX = iIndice; iX < (iIndice + iCuantos); iX++)
        {
            sRes += sTexto[iX];
        }
        return sRes;
    }
    else
    {
        return "";
    }
}

void erase(string &sTexto, int iIndice, int iCuantos)
{
    string sFinal;
    int iX;
    if ((iIndice + iCuantos) <= length(sTexto))
    {
        sFinal = "";
        for (iX = 0; iX < length(sTexto); iX++)
        {
            if ((iX < iIndice) || (iX > (iIndice + iCuantos - 1)))
            {
                sFinal += sTexto[iX];
            }
        }
        sTexto = sFinal;
    }
}

void insert(string &sTexto, int iIndice, string sAgregar)
{
    string sFinal = "";
    int iX;
    if (iIndice < length(sTexto))
    {
        for (iX = 0; iX < length(sTexto); iX++)
        {
            if (iX == iIndice)
            {
                sFinal += sAgregar;
            }
            sFinal += sTexto[iX];
        }
        sTexto = sFinal;
    }
}