#include <iostream>

using namespace std;

void afisareTabla(char *tabla)
{
    int i;

    for(i=0; i<9; i+=3)
    {
        cout<<"   |   |"<<endl;
        cout<<" "<<tabla[i]<<" | "<<tabla[i+1]<<" | "<<tabla[i+2]<<endl;
        cout<<"   |   |"<<endl;
        if(i!=6)
            cout<<"-----------"<<endl;
    }

    cout<<endl<<endl;
}

int victorie(char *tabla)
{
    char castigator;

    if (tabla[0] == tabla[1] && tabla[1] == tabla[2] && tabla[0] != ' ') // linie 1
        castigator = tabla[0];
    
    if (tabla[3] == tabla[4] && tabla[4] == tabla[5] && tabla[3] != ' ') // linie 2
        castigator = tabla[3];

    if (tabla[6] == tabla[7] && tabla[7] == tabla[8] && tabla[6] != ' ') // linie 3
        castigator = tabla[6];

    if (tabla[0] == tabla[3] && tabla[3] == tabla[6] && tabla[0] != ' ') // coloana 1
        castigator = tabla[0];

    if (tabla[1] == tabla[4] && tabla[4] == tabla[7] && tabla[1] != ' ') // coloana 2
        castigator = tabla[1];

    if (tabla[2] == tabla[5] && tabla[5] == tabla[8] && tabla[2] != ' ') // coloana 3
        castigator = tabla[2];

    if (tabla[0] == tabla[4] && tabla[4] == tabla[8] && tabla[0] != ' ') // diagonala principală
        castigator = tabla[0];

    if (tabla[2] == tabla[4] && tabla[4] == tabla[6] && tabla[2] != ' ') // diagonala secundară
        castigator = tabla[2];

    if (castigator == 'X')
        return 1;

    if (castigator == '0')
        return 2;

    return 0;
}

int tablaPlina(char *tabla)
{
    int i;

    for (i = 0; i < 9; i++)
        if (tabla[i] == ' ')
            return 0;
    
    return 1;
}

void mutareX(char *tabla)
{
    int pozitie = 0;

    while (1)
    {
        a:
        cout<<"Introduceți poziția dorită: ";
        cin>>pozitie;

        if (pozitie < 1 || pozitie > 9)
        {
            cout<<"Pozitia trebuie sa fie intre 1 si 9"<<endl;
            goto a;
        }
            
        if (tabla[pozitie - 1] != ' ')
        {
            cout<<"Poziția este deja ocupată"<<endl;
            goto a;
        }

    	tabla[pozitie - 1] = 'X';
    	cout<<endl;
    	break;
    }
}

void mutare0(char *tabla)
{
    int i, a = 0;

    // Verificare dacă 0 poate câștiga pentru a pune 0 în acea poziție

    for (i = 0; i < 9 && a == 0; i++)
	{
		if (tabla[i] == ' ')
		{
			tabla[i] = '0';

			if (victorie(tabla) == 2)
                a = 1;
			else
				tabla[i]=' ';
		}
	}

    // Verificare dacă X poate câștiga pentru a pune 0 în acea poziție pentru a-l bloca

	for (i = 0; i < 9 && a == 0; i++)
	{
		if (tabla[i] == ' ')
		{
			tabla[i] = 'X';

			if (victorie(tabla) == 1)
			{
				tabla[i] = '0';
				a = 1;
			}
			else
				tabla[i]=' ';
		}
	}

    // Primul 0 se punde random

	while (a == 0) 
	{
		i = rand()%9;
		if (tabla[i] == ' ') 
		{
            tabla[i] = '0';
            break;
        }
    }
}

int main()
{
    int i;
    char tabla[9];

    while(1)
    {
        cout<<endl<<endl<<"Bun venit!"<<endl;
        cout<<"Tu vei muta primul - esti cu X."<<endl;
	    cout<<"Tabla de joc are pozitiile numerotate de la 1 la 9."<<endl<<endl;
	    
        for(i=0; i<9; i++)
            tabla[i]=' ';

        afisareTabla(tabla);

        while(1)
        {
            mutareX(tabla);

            afisareTabla(tabla);

            if (victorie(tabla) == 1)
            {
                cout<<"Ai castiagat! Felicitari!";
                break;
            }

            if(!tablaPlina(tabla))
            {
                mutare0(tabla);
                afisareTabla(tabla);
            }
            else
            {
                cout<<"Remiza!";
                break;
            }
            
            if(victorie(tabla) == 2)
                {
                    cout<<"Ai pierdut! Mai incearca.";
                    break;
                }
        }
    }

    return 0;
}
