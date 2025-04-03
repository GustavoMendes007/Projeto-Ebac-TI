#include <iostream> //realizar operações de entrada e saida de dados no seu programa
#include <fstream> //serve para criar, manipular ficheiros (arquivos) e escrever, não serve para ler).
#include <string> //Biblioteca para manipulação de strings em C++, facilitando operações como concatenação e modificação de textos.
#include <cstdlib> // Biblioteca que fornece funções para alocação de memória, controle de processos e conversões numéricas, como system() e rand().
#include <locale.h> //Biblioteca que permite configurar a localização do programa, facilitando a exibição de caracteres acentuados e formatação regional.  

using namespace std;

void registro() {
    setlocale(LC_ALL, "Portuguese");
    
    string cpf, nome, sobrenome, cargo;
    cout << "Digite o CPF a ser cadastrado: ";
    cin >> cpf;
    
    ofstream file(cpf.c_str());
    if (!file) {
        cerr << "Erro ao criar o arquivo!" << endl;
        return;
    }
    file << cpf << ",";
    
    cout << "Digite um nome a ser cadastrado: ";
    cin >> nome;
    file << nome << " ";
    
    cout << "Digite o sobrenome a ser cadastrado: ";
    cin >> sobrenome;
    file << sobrenome << ",";
    
    cout << "Digite o cargo a ser cadastrado: ";
    cin >> cargo;
    file << cargo;
    
    file.close();
    cout << "Registro concluido com sucesso!" << endl;
    system("pause");
}

void consulta() {
    setlocale(LC_ALL, "Portuguese");
    
    string cpf, conteudo;
    cout << "Digite o CPF a ser consultado: ";
    cin >> cpf;
    
    ifstream file(cpf.c_str());
    if (!file) {
        cerr << "CPF não encontrado no sistema!" << endl;
        return;
    }
    
    cout << "\nEssas são as informações do usuário:\n";
    while (getline(file, conteudo)) {
        cout << conteudo << endl;
    }
    file.close();
    system("pause");
}

void deletar() {
    string cpf, nome, sobrenome, cargo, conteudo;
    cout << "Digite o CPF que deseja deletar: ";
    cin >> cpf;
    
    ifstream file(cpf.c_str());
    if (!file) {
        cerr << "Usuário não encontrado." << endl;
        return;
    }
    
    getline(file, conteudo);
    file.close();
    
    string storedCpf, storedNome, storedSobrenome, storedCargo;
    size_t pos1 = conteudo.find(",");
    size_t pos2 = conteudo.find(" ", pos1 + 1);
    size_t pos3 = conteudo.find(",", pos2 + 1);
    
    storedCpf = conteudo.substr(0, pos1);
    storedNome = conteudo.substr(pos1 + 1, pos2 - pos1 - 1);
    storedSobrenome = conteudo.substr(pos2 + 1, pos3 - pos2 - 1);
    storedCargo = conteudo.substr(pos3 + 1);
    
    cout << "Digite o nome do usuário: ";
    cin >> nome;
    cout << "Digite o sobrenome do usuário: ";
    cin >> sobrenome;
    cout << "Digite o cargo do usuário: ";
    cin >> cargo;
    
    if (cpf == storedCpf && nome == storedNome && sobrenome == storedSobrenome && cargo == storedCargo) {
        char confirmacao;
        cout << "Tem certeza que deseja deletar este usu�rio? (S/N): ";
        cin >> confirmacao;
        
        if (confirmacao == 'S' || confirmacao == 's') {
            if (remove(cpf.c_str()) == 0) {
                cout << "Usuário deletado com sucesso!" << endl;
            } else {
                cerr << "Erro ao deletar o usu�rio." << endl;
            }
        } else {
            cout << "Operação de exclusão cancelada." << endl;
        }
    } else {
        cout << "As informações fornecidas não coincidem com os dados do usuário." << endl;
    }
    system("pause");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    
    while (true) {
        system("cls");
        cout << "### Cartório da EBAC ###\n\n";
        cout << "Escolha a Opção desejada do Menu: \n\n";
        cout << "\t1 - Registrar nomes\n";
        cout << "\t2 - Consultar nomes\n";
        cout << "\t3 - Deletar nomes\n";
        cout << "\t4 - Sair\n\n";
        cout << "Opção: ";
        cin >> opcao;

        system("cls");
        
        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                cout << "Encerrando o programa..." << endl;
                return 0;
            default:
                cout << "Opção inv�lida!" << endl;
                system("pause");
                break;
        }
    }
    return 0;
}

