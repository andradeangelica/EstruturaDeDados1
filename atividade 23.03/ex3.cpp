#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // Abre o arquivo com a lista de nomes
    ifstream infile("nomes.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (!infile.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return 1;
    }

    // Abre o arquivo para escrita dos novos nomes
    ofstream outfile("nomes_formatados.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (!outfile.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return 1;
    }

    // Lê cada linha do arquivo com os nomes
    string line;
    while (getline(infile, line)) {

        // Divide o nome em partes, utilizando o espaço em branco como separador
        vector<string> parts;
        string part;
        for (char c : line) {
            if (c == ' ') {
                parts.push_back(part);
                part.clear();
            }
            else {
                part += c;
            }
        }
        parts.push_back(part);

        // Organiza as partes do nome no formato desejado
        reverse(parts.begin(), parts.end());
        string formatted_name = parts[0] + ", ";
        for (int i = 1; i < parts.size() - 1; i++) {
            formatted_name += parts[i] + " ";
        }
        formatted_name += parts[parts.size() - 1];

        // Escreve o novo nome no arquivo
        outfile << formatted_name << endl;
    }

    // Fecha os arquivos
    infile.close();
    outfile.close();

    return 0;
}
