#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);

    // Remove os espaços da mensagem
    mensagem.erase(remove(mensagem.begin(), mensagem.end(), ' '), mensagem.end());

    // Verifica se a mensagem invertida é igual à original
    string mensagemInvertida = mensagem;
    reverse(mensagemInvertida.begin(), mensagemInvertida.end());
    if (mensagem == mensagemInvertida) {
        cout << "A mensagem é um palíndromo!" << endl;
    } else {
        cout << "A mensagem não é um palíndromo." << endl;
    }

    return 0;
}
