#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

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
        return 0;
    }

    // Programa ---- -- --- -
    //-----------definicao de variaveis---------
    string aux;
    vector<int> winningNumbers;
    vector<int> myNumbers;
    int number;
    int numeroLinhas = countLines();
    int* quantidadeJogada= new int[numeroLinhas]; 

    for(int i = 0 ; i < numeroLinhas ; i++){
        quantidadeJogada[i] = 0;
    }

    vector<int> ResultadoCadaCarta;
    int gameNumber;
    int matchingCardNumber;


    int resultadoTotal = 0;
    int resultadoJogo = 0;



    while (input.peek() != EOF){
        //----linha X----- (loop goes here)

        resultadoJogo = 0;
        matchingCardNumber = 0;
        winningNumbers.clear();
        myNumbers.clear();

        // --- ler primeira partedo ficheiro
        getline(input, aux, ' ');
        getline(input, aux, ':');

        gameNumber = stoi(aux);
        cout << "numero do jogo " << gameNumber << endl;

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
                    matchingCardNumber ++;
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

        ResultadoCadaCarta.push_back(resultadoJogo);

        for(int i = 0 ; i < matchingCardNumber; i++){
            quantidadeJogada[gameNumber + i] += 1 + quantidadeJogada[gameNumber - 1]; 
        }
    }



    for(int i = 0 ; i < numeroLinhas ; i++){
        cout << quantidadeJogada[i] << endl;
        resultadoTotal += quantidadeJogada[i] + 1 ;

    }

    cout << resultadoTotal;

    return 0;
}