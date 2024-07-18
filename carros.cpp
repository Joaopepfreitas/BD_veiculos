#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TAM = 100;
//Declarando cada variável do struct "CARRO".

typedef struct {
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potencia_do_motor;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    string portas;
    string placa;
    float valor;
    bool valido;
} Carro;

int main(int argc, char** argv) {
    int op, qtde = 0, i = 0;//variáveis auxiliares para contagem 
    int conthatch = 0, contsedan = 0, contsuv = 0, contpickup = 0, contvan =0 , contflex =0, carroVelho = 0, mediakm = 0;
    float contdiesel = 0, contgasolina = 0, carroBarato = 99999999.00;//variáveis necessárias para a contagem no relatório. 
    float valorMax, valorMin, maisCaro = 1.00;//variáveis auxiliares para busca.
    string placaMaiscaro, placaMaisbarato;
    bool encontrado;
    Carro carro[TAM];

    ifstream arquivo("BD_veiculos.txt");

    if (!arquivo.is_open()) {
        cout << "Erro: arquivo não existe" << endl;
        return 1;
    }

    if (arquivo.is_open()) {
        string aux;
        arquivo >> aux;
        while (aux != "fim") {
            carro[i].modelo = aux;
            arquivo >> carro[i].marca
                    >> carro[i].tipo
                    >> carro[i].ano
                    >> carro[i].km
                    >> carro[i].potencia_do_motor
                    >> carro[i].combustivel
                    >> carro[i].cambio
                    >> carro[i].direcao
                    >> carro[i].cor
                    >> carro[i].portas
                    >> carro[i].placa
                    >> carro[i].valor;
            carro[i].valido = true;
            i++;
            arquivo >> aux;
        }
        qtde = i; // Set qtde to the number of cars read
        arquivo.close();
    } else {
        cout << "Erro ao abrir o Banco de Dados." << endl;
        return 1;
    }

    //Menu de opções
    do {
        cout << "Digite 1 para incluir um novo veículo na base de dados" << endl;
        cout << "Digite 2 para buscar um veículo pelo tipo" << endl;
        cout << "Digite 3 para buscar um veículo pelo câmbio" << endl;
        cout << "Digite 4 para buscar um veículo pela placa" << endl;
        cout << "Digite 5 para filtrar os valores dos veículos" << endl;
        cout << "Digite 6 para ver um relatório do banco de dados" << endl;
        cout << "Digite 7 para sair" << endl;

        cin >> op;

        switch (op) { // O carro a ser adicionado no banco de dados é informado aqui mas é adicionado apenas quando o usuário fechar o programa.
            case 1: {
                if (qtde < TAM) {
                    cout << "Digite o modelo: ";
                    cin >> carro[qtde].modelo;
                    cout << "Digite a marca: ";
                    cin >> carro[qtde].marca;
                    cout << "Digite o tipo: ";
                    cin >> carro[qtde].tipo;
                    cout << "Digite o ano: ";
                    cin >> carro[qtde].ano;
                    cout << "Digite a quilometragem rodada: ";
                    cin >> carro[qtde].km;
                    cout << "Digite a potência do motor: ";
                    cin >> carro[qtde].potencia_do_motor;
                    cout << "Digite o tipo de combustível: ";
                    cin >> carro[qtde].combustivel;
                    cout << "Digite o tipo de câmbio: ";
                    cin >> carro[qtde].cambio;
                    cout << "Digite o tipo de direção: ";
                    cin >> carro[qtde].direcao;
                    cout << "Digite a cor: ";
                    cin >> carro[qtde].cor;
                    cout << "Digite o número de portas: ";
                    cin >> carro[qtde].portas;
                    cout << "Digite a placa: ";
                    cin >> carro[qtde].placa;
                    cout << "Digite o valor: ";
                    cin >> carro[qtde].valor;

                    carro[qtde].valido = true;
                    qtde++;
                } else {
                    cout << "Limite de veículos alcançado." << endl;
                }
                break;
            }
            case 2: {
                cout << "Digite o tipo de veículo que você deseja buscar: ";
                string tipoProcurado;
                cin >> tipoProcurado;
                encontrado = false;
                for (int i = 0; i < qtde; i++) {
                    if (carro[i].valido && carro[i].tipo == tipoProcurado) { // Informações dos veículos que satisfazem as condições procuradas.
                        cout << "Veículo encontrado:" << endl;
                        cout << "Modelo: " << carro[i].modelo << endl;
                        cout << "Marca: " << carro[i].marca << endl;
                        cout << "Ano: " << carro[i].ano << endl;
                        cout << "Quilometragem: " << carro[i].km << endl;
                        cout << "Potência do motor: " << carro[i].potencia_do_motor << endl;
                        cout << "Combustível: " << carro[i].combustivel << endl;
                        cout << "Câmbio: " << carro[i].cambio << endl;
                        cout << "Direção: " << carro[i].direcao << endl;
                        cout << "Cor: " << carro[i].cor << endl;
                        cout << "Portas: " << carro[i].portas << endl;
                        cout << "Placa: " << carro[i].placa << endl;
                        cout << "Valor: " << carro[i].valor << endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "Tipo não encontrado na base de dados." << endl;
                }
                break;
            }
            case 3: {
                cout << "Digite o tipo de câmbio do veículo que você deseja buscar: ";// Informações dos veículos que satisfazem as condições procuradas.
                string cambioProcurado;
                cin >> cambioProcurado;
                encontrado = false;
                for (int i = 0; i < qtde; i++) {
                    if (carro[i].valido && carro[i].cambio == cambioProcurado) {
                        cout << "Veículo encontrado:" << endl;
                        cout << "Modelo: " << carro[i].modelo << endl;
                        cout << "Marca: " << carro[i].marca << endl;
                        cout << "Ano: " << carro[i].ano << endl;
                        cout << "Quilometragem: " << carro[i].km << endl;
                        cout << "Potência do motor: " << carro[i].potencia_do_motor << endl;
                        cout << "Combustível: " << carro[i].combustivel << endl;
                        cout << "Câmbio: " << carro[i].cambio << endl;
                        cout << "Direção: " << carro[i].direcao << endl;
                        cout << "Cor: " << carro[i].cor << endl;
                        cout << "Portas: " << carro[i].portas << endl;
                        cout << "Placa: " << carro[i].placa << endl;
                        cout << "Valor: " << carro[i].valor << endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "Câmbio não encontrado na base de dados." << endl;
                }
                break;
            }
            case 4: {
                cout << "Digite a placa do veículo que você deseja buscar: ";// Informações dos veículos que satisfazem as condições procuradas.
                string placaProcurada;
                cin >> placaProcurada;
                encontrado = false;
                for (int i = 0; i < qtde; i++) {
                    if (carro[i].valido && carro[i].placa == placaProcurada) {
                        cout << "Veículo encontrado:" << endl;
                        cout << "Modelo: " << carro[i].modelo << endl;
                        cout << "Marca: " << carro[i].marca << endl;
                        cout << "Ano: " << carro[i].ano << endl;
                        cout << "Quilometragem: " << carro[i].km << endl;
                        cout << "Potência do motor: " << carro[i].potencia_do_motor << endl;
                        cout << "Combustível: " << carro[i].combustivel << endl;
                        cout << "Câmbio: " << carro[i].cambio << endl;
                        cout << "Direção: " << carro[i].direcao << endl;
                        cout << "Cor: " << carro[i].cor << endl;
                        cout << "Portas: " << carro[i].portas << endl;
                        cout << "Placa: " << carro[i].placa << endl;
                        cout << "Valor: " << carro[i].valor << endl;

                        cout << "Você deseja exclui-la do banco de dados? (sim/não): "; //Caso o usuário decida excluir o  
                        string placaExcluir;                                            //veículo do banco de dados é 
                        cin >> placaExcluir;                                            //atribuído falso ao carro, e o bancode dados
                        if (placaExcluir == "sim") {                                    // é atualizado quando o programa é fechado.   
                            carro[i].valido = false;
                            cout << "Carro excluído com sucesso." << endl;
                        }
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Placa não encontrada na base de dados." << endl;
                }
                break;
            }
            case 5: {
                cout << "Digite o valor mínimo: ";
                cin >> valorMin;
                cout << "Digite o valor máximo: ";
                cin >> valorMax;

                encontrado = false;
                for (int i = 0; i < qtde; i++) {
                    if (carro[i].valor >= valorMin && carro[i].valor <= valorMax) {
                        cout << "Veículo encontrado na faixa de valores de R$ " << valorMin << " a R$ " << valorMax << endl;
                        cout << "Modelo: " << carro[i].modelo << endl;
                        cout << "Marca: " << carro[i].marca << endl;
                        cout << "Ano: " << carro[i].ano << endl;
                        cout << "Quilometragem: " << carro[i].km << endl;
                        cout << "Potência do motor: " << carro[i].potencia_do_motor << endl;
                        cout << "Combustível: " << carro[i].combustivel << endl;
                        cout << "Câmbio: " << carro[i].cambio << endl;
                        cout << "Direção: " << carro[i].direcao << endl;
                        cout << "Cor: " << carro[i].cor << endl;
                        cout << "Portas: " << carro[i].portas << endl;
                        cout << "Placa: " << carro[i].placa << endl;
                        cout << "Valor: " << carro[i].valor << endl;
                        cout << endl;
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "Nenhum veículo encontrado na faixa de valores de R$ " << valorMin << " a R$ " << valorMax << endl;
                }
                break;
            }
            case 6: {
                //Loop que percorre todo o vetor e já armazena informações que será preciso para o relatório.
                for (int i = 0; i < qtde; i++) {
                    if (carro[i].tipo == "Hatch")
                    conthatch++;
                    if (carro[i].tipo == "SUV")
                    contsuv++;
                    if (carro[i].tipo == "Sedan")
                    contsedan++;
                    if (carro[i].tipo == "Van")
                    contvan++;
                    if (carro[i].tipo == "Pick-up")
                    contpickup++;
                    if (carro[i].combustivel == "Gasolina")
                    contgasolina++;
                    if (carro[i].combustivel == "Flex")
                    contflex++;
                    if (carro[i].combustivel == "Diesel")
                    contdiesel++;
                    if(carro[i].direcao == "Hidráulica" && carro[i].cambio == "Automático" && carro[i].valor > maisCaro){
                        maisCaro = carro[i].valor;
                        placaMaiscaro = carro[i].placa;
                    }   
                    if (carro[i].ano <= 2019){
                        carroVelho++;
                        mediakm = mediakm + carro[i].km;
                    }    
                   if (carro[i].potencia_do_motor == 1.0 && carro[i].valor < carroBarato) 
                    carroBarato = carro[i].valor;
                    placaMaisbarato = carro[i].placa;
                    }

                    cout <<"Porcentagem de carros do tipo Hatch: "<<(conthatch*100.00) / qtde <<"%"<<endl;   //divide apenas pela quantidade de veículos válidos
                    cout <<"Porcentagem de carros do tipo SUV: "<<(contsuv*100.00) / qtde <<"%"<<endl;
                    cout <<"Porcentagem de carros do tipo Pick up: "<<(contpickup*100.00) / qtde <<"%"<<endl;
                    cout <<"Porcentagem de carros do tipo Sedã: "<<(contsedan*100.00) / qtde <<"%"<<endl;
                    cout <<"Porcentagem de carros do tipo Van: "<<(contvan*100.00) / qtde <<"%"<<endl;
                    cout <<"Porcentagem de carros a diesel: "<<(contdiesel*100.00) / qtde <<"%"<<endl;
                    cout <<"Porcentagem de carros a gasolina: "<<(contgasolina*100.00) / qtde <<"%"<<endl;
                    cout <<"Porcentagem de carros flex: "<<(contflex*100.00) / qtde <<"%"<<endl;
                    cout <<"Há "<<carroVelho<<" carros com 5 anos ou mais e com uma média de "<<mediakm / carroVelho <<" kms rodados"<<endl;
                    cout <<"O valor do veículo mais caro com direção hidráulica e câmbio automático é: R$"
                    <<maisCaro<< " e sua placa é: " << placaMaiscaro<< " e o valor do seguro estimado é: "<<(maisCaro / 100)*5.00<<endl; // Valor do seguro estimado com base no cálculo de 5% do valor do veículo.
                    cout <<"O valor do carro mais barato com potência do motor 1.0 é R$"<<carroBarato<<" e sua placa é: "<<placaMaisbarato
                    <<" e o valor de cada prestação de um financiamento em 60 meses é: R$"<<((carroBarato / 100)*140) / 60<< endl; // Valor do financiamento calculado com base na taxa de 28% ao ano
                
                break;
            }
            case 7: {
                ofstream arquivo_saida("BD_veiculos.txt"); // Salva e sai
            // Abrindo o arquivo para salvar as informações antes do programa fechar.
                if (arquivo_saida.is_open()) {
                    for (int i = 0; i < qtde; ++i) {
                        if (carro[i].valido) {
                            arquivo_saida << carro[i].modelo << " "
                                          << carro[i].marca << " "
                                          << carro[i].tipo << " "
                                          << carro[i].ano << " "
                                          << carro[i].km << " "
                                          << carro[i].potencia_do_motor << " "
                                          << carro[i].combustivel << " "
                                          << carro[i].cambio << " "
                                          << carro[i].direcao << " "
                                          << carro[i].cor << " "
                                          << carro[i].portas << " "
                                          << carro[i].placa << " "
                                          << carro[i].valor << endl;
                        }
                    }
                    arquivo_saida << "fim";
                    arquivo_saida.close();
                    cout << "Alterações salvas com sucesso." << endl;
                } else {
                    cout << "Erro ao abrir o arquivo para salvar as alterações." << endl;
                }

                cout << "Saindo do Banco de Dados..." << endl;
                break;
            }
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (op != 7);

    return 0;
}
