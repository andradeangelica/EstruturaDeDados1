#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    // Recebe a mensagem
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    // Centraliza a mensagem na linha 5
    int tamanhoMensagem = mensagem.length();
    int espacosAntes = (80 - tamanhoMensagem) / 2;
    for (int i = 0; i < espacosAntes; i++) {
        cout << " ";
    }
    cout << mensagem << endl;

    // Simula a cascata da mensagem
    for (int i = 0; i < 15; i++) {
        Sleep(100); // Espera 100 milissegundos entre cada linha
        system("cls"); // Limpa a tela para desenhar a próxima linha

        for (int j = 0; j < espacosAntes; j++) {
            cout << " ";
        }
        for (int j = 0; j < tamanhoMensagem; j++) {
            if (i == j) {
                cout << mensagem[j];
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

