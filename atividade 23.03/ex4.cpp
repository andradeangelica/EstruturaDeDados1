#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Função para transformar uma string em citação bibliográfica
std::string transforma_nome(std::string nome) {
    std::vector<std::string> partes;
    std::string parte;
    std::istringstream stream(nome);
    
    // Separa o nome em partes usando espaços como delimitador
    while (std::getline(stream, parte, ' ')) {
        partes.push_back(parte);
    }
    
    // Transforma a última parte do nome em maiúscula
    partes.back() = partes.back().substr(0, 1) + partes.back().substr(1, partes.back().length()-1);
    
    // Abrevia as partes do meio do nome
    std::string nome_abreviado;
    for (auto i = partes.begin(); i != partes.end(); i++) {
        if (i == partes.begin()) {
            // Sobrenome em maiúscula
            nome_abreviado += (*i).substr(0, 1) + (*i).substr(1, (*i).length()-1);
        } else if (i == partes.end() - 1) {
            // Última parte do nome sem abreviação
            nome_abreviado += " " + *i;
        } else {
            // Abrevia as partes do meio do nome
            nome_abreviado += " " + (*i).substr(0, 1) + ".";
        }
    }
    
    // Coloca o sobrenome em maiúscula, seguido da abreviação do nome
    std::string sobrenome = partes[partes.size() - 1];
    nome_abreviado = sobrenome + ", " + nome_abreviado;
    
    return nome_abreviado;
}

int main() {
    std::ifstream arquivo("nomes.txt");
    std::ofstream saida("nomes_formatados.txt");
    std::string nome;
    
    if (!arquivo.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo" << std::endl;
        return 1;
    }
    
    // Lê cada nome do arquivo, formata e escreve no arquivo de saída
    while (std::getline(arquivo, nome)) {
        std::string nome_formatado = transforma_nome(nome);
        saida << nome_formatado << std::endl;
    }
    
    arquivo.close();
    saida.close();
    
    return 0;
}
