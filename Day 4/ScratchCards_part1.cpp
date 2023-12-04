#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{

    ifstream input;
    input.open("input.txt");

    if (!input)
    {
        cout << "Erro ao abrir ficheiro";
        return 0;
    }

    // Programa ---- -- --- -
    //-----------definicao de variaveis---------
    string aux;
    vector<int> winningNumbers;
    vector<int> myNumbers;
    int number;

    int resultadoTotal;
    int resultadoJogo = 0;

    while (input.peek() != EOF){
        //----linha X----- (loop goes here)

        resultadoJogo = 0;
        winningNumbers.clear();
        myNumbers.clear();

        // --- ler primeira partedo ficheiro
        getline(input, aux, ':');

        getline(input, aux, '|');


        istringstream isWinningNumber(aux);

        while (isWinningNumber >> number)
        {
            winningNumbers.push_back(number);
        }

        // ---- ler segunda aparte do ficheiro
        getline(input, aux);

        istringstream isMyNumber(aux);

        while (isMyNumber >> number)
        {
            myNumbers.push_back(number);
        }


        // --- tratamento de dados
        for (int i : myNumbers)
        {
            for (int j : winningNumbers)
            {
                if (i == j)
                {
                    if (resultadoJogo == 0)
                    {
                        resultadoJogo = 1;
                    }
                    else
                    {
                        resultadoJogo *= 2;
                    }
                }
            }
        }

        resultadoTotal += resultadoJogo;
    }



   cout << resultadoTotal;

    return 0;
}