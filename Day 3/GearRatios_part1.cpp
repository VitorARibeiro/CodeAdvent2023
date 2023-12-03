#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool validar(string *stringArray, int posFim, int numero)
{
    bool valido = false;

    // tamanho do numero
    string numString = to_string(numero);
    int sizeNum = numString.length();

    // set borders
    int inicio;

    if (posFim - sizeNum - 1 > 0)
    {
        inicio = posFim - sizeNum - 1;
    }
    else
    {
        inicio = 0;
    }

    // checkar lados
    if ((stringArray[1][posFim] != '.' && !isdigit(stringArray[1][posFim])) || (stringArray[1][inicio] != '.' && !isdigit(stringArray[1][inicio])))
    {
        return true;
    }

    // checkar adjacentes de cima
    for (int i = inicio; i < posFim + 1; i++)
    {
        if (stringArray[0][i] != '.' && !isdigit(stringArray[0][i]))
        {
            return true;
        }
    }
    // checkar adjacentes de baixo
    for (int i = inicio; i < posFim + 1; i++)
    {
        if (stringArray[2][i] != '.' && !isdigit(stringArray[2][i]))
        {
            return true;
        }
    }

    return valido;
}

int countLineChar()
{

    string aux;
    ifstream input;

    input.open("input.txt");
    if (!input)
    {
        cout << "Erro ao abrir ficheiro";
    }

    getline(input, aux);

    input.close();

    return aux.length();
}

int countLines()
{
    int lines = 0;
    string aux;
    ifstream input;

    input.open("input.txt");
    if (!input)
    {
        cout << "Erro ao abrir ficheiro";
    }

    while (getline(input, aux))
    {
        lines++;
    }

    input.close();

    return lines;
}

int main()
{

    ifstream input;
    input.open("input.txt");
    if (!input)
    {
        cout << "Erro ao abrir ficheiro";
    }

    string stringArray[3];
    int result = 0;

    vector<char> numStr;
    int numInt;
    int lines, tamanhoLinhas;

    lines = countLines();

    cout << "lines: " << lines << endl;

    tamanhoLinhas = countLineChar();

    string linhasDefault(tamanhoLinhas, '.');

    //...logica do programa...

    for (int k = 0; k < lines; k++)
    {
        // possivelmente aqui while loop

        bool numBool = false;

        // leitura das 3 primeiras linhas
        // 0 * *

        if (k == 0)
        { // primeira linha
            stringArray[0] = linhasDefault;
            getline(input, stringArray[1]);
            getline(input, stringArray[2]);
        }
        else if (k > 0 && k < lines - 1)
        {
            stringArray[0] = stringArray[1];
            stringArray[1] = stringArray[2];
            getline(input, stringArray[2]);
        }
        else if (k == lines - 1)
        { // ultima linha
            stringArray[0] = stringArray[1];
            stringArray[1] = stringArray[2];
            stringArray[2] = linhasDefault;
        }

        for (int i = 0; i < tamanhoLinhas; i++)
        { // 10 é tamanho da linha

            if (isdigit(stringArray[1][i]))
            {
                if (!numBool)
                {
                    numBool = true;
                    numStr.push_back(stringArray[1][i]);

                    if (i == tamanhoLinhas - 1)
                    {
                        string numString(numStr.begin(), numStr.end());
                        numInt = stoi(numString);
                        numStr.clear(); // apaga vertor para o proximo numero

                        // checkar se numero tem simbolos a adjacentes para validar o mesmo
                        if (validar(stringArray, i, numInt))
                        {
                            cout << "valido: " << numInt << endl;
                            result += numInt;
                        }
                    }
                }
                else
                {

                    numStr.push_back(stringArray[1][i]);
                    if (i == tamanhoLinhas - 1)
                    {
                        string numString(numStr.begin(), numStr.end());

                        numInt = stoi(numString);
                        numStr.clear(); // apaga vertor para o proximo numero
                        // checkar se numero tem simbolos a adjacentes para validar o mesmo
                        if (validar(stringArray, i, numInt))
                        {
                            cout << "valido: " << numInt << endl;
                            result += numInt;
                        }
                    }
                }
            }
            else if (numBool)
            { // se nao for um digito 345* <- estamos no asterisco

                string numString(numStr.begin(), numStr.end());
                numInt = stoi(numString);
                numStr.clear(); // apaga vertor para o proximo numero
                // checkar se numero tem simbolos a adjacentes para validar o mesmo
                if (validar(stringArray, i, numInt))
                {
                    cout << "valido: " << numInt << endl;
                    result += numInt;
                }

                numBool = false;
            }
        }
    }
    cout << result;

    return 0;
}