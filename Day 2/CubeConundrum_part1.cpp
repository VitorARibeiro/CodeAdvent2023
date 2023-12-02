//only 12 red cubes, 13 green cubes, and 14 blue cubes

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main (){
    
    ifstream input;
    input.open("input.txt");

    //logica de abertura de ficheiro
    if(!input){
        cout << "Erro ao abrir ficheiro" << endl;
    }

    //-------------
    //variaveis globais

    int soma = 0;
    string stringRGB[3] = {"red","green","blue"};
    int numeroRGB[3] = {12,13,14};


    // leitura do ficheiro

    //possivelmente while aqui
    string auxStr="",gameStr = "" ,colorStr ="", numberStr="";
    getline(input,gameStr, ':');
    getline(input,auxStr);


    gameStr = gameStr.substr(5); // numero do jogo em string

    
    bool valido = true;
    bool Num = false, inicioSet ;

    for(int i = 0 ; i< auxStr.length() ; i++){
        //leitura das informacoes 
        inicioSet = false;

        if (Num == false && auxStr[i] == ' '){
            Num = true;
        }
        else if (Num && auxStr[i] != ' ' && auxStr[i] != ',' && auxStr[i] != ';'){
            numberStr.append(1,auxStr[i]);
        }
        else if (Num && auxStr[i] == ' '){
            Num = false;
        }
        else if(Num == false && auxStr[i] != ' ' && auxStr[i] != ',' && auxStr[i] != ';'){
            colorStr.append(1,auxStr[i]);
        }
        else if (Num == false && (auxStr[i] == ';' || auxStr[i] == ',')){
            inicioSet = true;
        } //fim do set

        //tratamento de dados

        if(inicioSet){

            for(int j = 0; j < 3 ; j++){
                
        
                if(stringRGB[j] == colorStr && stoi(numberStr) > numeroRGB[j]){
                    valido = false;
                }

            }
            cout << gameStr <<":"<< numberStr <<":"<< colorStr << endl;

            numberStr = "";
            colorStr = "";

        }
        
    }

    if (valido){
        soma += stoi(gameStr);
    }
    return 0;
}