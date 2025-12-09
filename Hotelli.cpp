
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void uusihuone();

// Miska Kuusikko

// Lopputyö

// Aliohjelma, joka tarkistaa, että ei voi varata samaa huonetta kahdesti päällekkäin
int vapaaHuone(const vector<bool> &varattu)
{
    vector<int> vapaat;

    for (int i = 1; i < varattu.size(); i++)
    {
        if (!varattu[i])

            vapaat.push_back(i);
    }
    if (vapaat.empty())
        return -1;

    int numero = rand() % vapaat.size();
    return vapaat[numero];
}
// varauksen aliohjelma
void Yhdenhengenhuone()
{

    int raha = rand() % 21 + 80;
    int oidenMaara;

    string varaaja;
    int huoneNumero = rand() % 41 + 30;

    // tarkistaa, että huoneita vapaana
    vector<bool> varattu(huoneNumero + 1, false);
    int huone = vapaaHuone(varattu);

    if (huone == -1)
    {
        cout << "huoneita ei ole vapaana";
        return;
    }

    varattu[huone] = true;

    // kysyy varaajalta varauksen tiedot
    cout << "Varaajan nimi: ";
    cin.ignore();
    getline(cin, varaaja);

    // ohjelma tarkistaa, että öidenmääräksi annetan numero ja kysyy sen niin monta kertaa, että käyttäjä antaa numeron
    bool suoritettu = false;
    while (!suoritettu)
    {
        cout << "Montako yota: ";
        cin >> oidenMaara;
        if (cin.fail())
        {
            cout << "syote ei ole numero" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (oidenMaara >= 0 && oidenMaara <= 1000000)
        {

            cout << endl
                 << "Huoneen numero: " << huoneNumero << "\n"
                 << "Varaajan nimi: " << varaaja << "\n"
                 << "Montako yota: " << oidenMaara << "\n " << "Hinta: " << oidenMaara * raha << endl;

            suoritettu = true;
        }
        else
        {
            cout << "virheellinen syote yrita uudelleen: ";
        }
        uusihuone();
    }
}
// aliohjema, joka kysyy haluaako käyttäjä varata toisen huoneen ja jos syöttää väärin alkaa varaus alusta
void uusihuone()
{

    string vastaus;
    cout << "haluatko varata uuden huoneen k/e: ";
    cin >> vastaus;

    if (vastaus == "k")
    {
        Yhdenhengenhuone();
    }
    if (vastaus == "e")
    {
        cout << "varaus lopetetaan";
        return;
    }
    if (vastaus != "k" || vastaus != "e")
    {
        cout << "varaus lopetetaan" << endl;
        return;
    }
}
// pääohjelmassa kysyy syötteen ja runaa tarvittavat aliohjelmat
int main()
{
    cout << "syota 1, jos haluat varata yhden hengenhuoneen" << endl;

    cout << "syota jokin muu jos haluat lopettaa" << endl;
    int syote;

    cout << "syota luku: ";
    cin >> syote;
    if (syote != 1)
    {
        cout << "varaus lopetetaan" << endl;
        return 0;
    }

    if (syote == 1)
    {
        Yhdenhengenhuone();
    }

    srand(time(0));

    return 0;
}