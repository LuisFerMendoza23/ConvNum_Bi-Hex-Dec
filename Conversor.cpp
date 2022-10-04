#include <iostream>
#include <stdlib.h>

using namespace std;

class Conversor{
        private:
            int decimal, decimal_2; 
            int binario[12]; //BiDecHex y DecBiHex

            int resultado_DEC, resultado_HEX; //BiDecHex
            int IN_binario; //BiDecHex
            int resto = 0; //BiDecHex

            int residuo; //DecBiHex
            int digitoHex[20]; //DecBiHex
            int i=0;

            int hexa_1[4], hexa_2[4];
            int Rhexa_1, Rhexa_2;
        public: 
            /*Conversor(int _decimal){
                decimal = _decimal;
            }*/
            void conversionDecBiHex(){
                //--------------------------CONVERSION DECIMAL BINARIO
                cout<<"\nIngrese el valor en decimal: ";
                cin>>decimal;
                //Div entre 2 y asignacio           
                for(int i=0; i<12; i++){
                    binario[i] = decimal%2;
                    decimal/=2;
                }
                //Juntamos el binario
                cout<<"El numero binario es: ";
                for(int i=11; i>=0; i--){
                    cout<<binario[i];
                }
                //-------------------------CONVERSION BINARIO HEXADECIMAL
                //Dividir en grupos de 4 
            }

            void conversionBiDecHex(){
                resto =0;
                residuo = 0;
                digitoHex[20] = { };
                cout<<"Ingrese el numero Binario: ";
                cin>>IN_binario;

                //dividimos el numero binario
                for(int i=0; i<12; i++){
                    binario[i] = IN_binario%10; 
                    IN_binario/=10;
                }
                //Convertimos de binario a decimal
                for(int i=11; i>=0; i--){
                    resultado_DEC = (resto * 2) + binario[i];
                    resto=resultado_DEC;
                }

                cout<<"El numero decimal es: "<<resultado_DEC<<endl;
                //-------------------------CONVERSION DECIMAL HEXADECIMAL    
                do{
                    residuo = resultado_DEC%16;
                    resultado_HEX = resultado_DEC/16;
                    digitoHex[i] = residuo;
                    resultado_DEC = resultado_HEX;
                    i++;
                }while(resultado_HEX > 15);

                digitoHex[i] = resultado_HEX;

                cout<<"\nEl valor Hexadecimal: ";

                for(int j=i; j>=0; j--){
                    if(digitoHex[j] == 10){
                        cout<<"A";
                    }
                    else if(digitoHex[j] == 11){
                        cout<<"B";
                    }
                    else if(digitoHex[j] == 12){
                        cout<<"C";
                    }
                    else if(digitoHex[j] == 13){
                        cout<<"D";
                    }
                    else if(digitoHex[j] == 14){
                        cout<<"E";
                    }
                    else if(digitoHex[j] == 15){
                        cout<<"F";
                    }
                    else{
                        cout<<digitoHex[j];
                    }
                }
                cout << endl;
            }
            
    };

int main(){
    int menu, opc, decimal;

    Conversor result;
    do{
        system("cls");
        //MENU:
        cout<<"--------CONVERSOR DE VALORES BIN-DEC-HEX--------"<<endl;
        cout<<"(Binario maximo 12 Digitos: 000000000000=4095)"<<endl;
        cout<<"Seleccione una operacion: "<<endl;
        cout<<"1) Dec - Bin y Hex"<<endl;
        cout<<"2) Bin - Dec y Hex"<<endl;
        cin>>menu;
        cout<<endl;

        switch(menu)
        {
            case 1:
                result.conversionDecBiHex();
            break;
            case 2:
                result.conversionBiDecHex();
            break;
        }

        cout<<"\n\nQuiere repetir el programa?\n1)Si\n2)No "<<endl;
        cin>>opc;        
    }while(opc==1);
    cout<<"\nTerminando programa..."<<endl;
    return 0;
}