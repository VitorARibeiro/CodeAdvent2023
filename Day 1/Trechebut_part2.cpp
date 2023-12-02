#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream input;
    input.open("input_trechebut.txt");

    if (!input){
        cout<<"Impossivel abrir ficheiro"<<endl;
    }
    else{
        cout << "Ficheiro lido com sucesso"<<endl;
    }

    //loop
    string stringAux;
    char finalchar[3];
    int soma = 0;
    string numeros_string[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int numeros_int[10] = {0,1,2,3,4,5,6,7,8,9};
    
    while(getline(input,stringAux)){

        
        int firstPos = stringAux.length(); //fim da linha
        firstPos = stringAux.find_first_of("0123456789");
        int lastPos = 0; // inicio da linha
        lastPos =  stringAux.find_last_of("0123456789");


        finalchar[0] = stringAux[firstPos];
        finalchar[1] = stringAux[lastPos];
        finalchar[2] = '\0';

        //main logic

        for(int i = 0 ; i < firstPos ; i++){ // procurar um numer menor que o primeiro numero ja encontrado

            for (int j = 0; j < 10; j++) //compara cada letra com o inicio de cada char
            {
                if (stringAux[i] == numeros_string[j][0]){ //checka se o inicio é igual
                    bool igual = true;

                    for (int k = 0 ; k < numeros_string[j].length(); k++){

                        if(stringAux[i+k] != numeros_string[j][k] ){
                            igual = false;
                            //break;
                        }
                    }

                    if (igual){
                        firstPos = i;
                        finalchar[0] = numeros_int[j] + '0';
                    }
                } 
            }
        }

        for(int i = lastPos ; i < stringAux.length() ; i++){ // procurar um numero maiors que o ultimo numero ja encontrado

            for (int j = 0; j < 10; j++) //compara cada letra com o inicio de cada char
            {
                if (stringAux[i] == numeros_string[j][0]){ //checka se o inicio é igual
                    bool igual = true;

                    for (int k = 0 ; k < numeros_string[j].length(); k++){

                        if(stringAux[i+k] != numeros_string[j][k] ){
                            igual = false;
                            //break;
                        }
                    }

                    if (igual){
                        lastPos = i;
                        finalchar[1] = numeros_int[j] + '0';
                        
                    }
                } 
            }
        }

        soma += atoi(finalchar);


    }

    cout << soma;


    return 0;
}


