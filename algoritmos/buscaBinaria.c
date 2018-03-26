//
// Created by timoteo on 26/03/18.
//

static int _buscaBinaria(int *A, int inicio, int final, int valor) {
    int meio = (inicio + final) / 2;

    if (inicio > final) return -1;

    if(A[meio] == valor)
        return meio;
    else if (A[meio] < valor)
        return _buscaBinaria(A, meio + 1, final, valor);
    else
        return _buscaBinaria(A, inicio, meio - 1, valor);
}

/// Função para busca binária em um vetor ORDENADO
/// \param A - O vetor a ser buscado
/// \param tamanho - O tamanho do vetor
/// \param valor - O valor a ser buscado
/// \return - A posição no vetor se for encontrado;
int buscaBinaria(int *A, int tamanho, int valor) {
    return _buscaBinaria(A, 0, tamanho - 1, valor);
}

static int _contaOcorrenciasDireita(int *A, int inicio, int final, int valor) {
    int meio = (inicio + final) / 2;

    if (inicio > final) return inicio;

    if (A[meio] > valor)
        return _contaOcorrenciasDireita(A, inicio, meio - 1, valor);
    else
        return _contaOcorrenciasDireita(A, meio + 1, final, valor);

}

static int _contaOcorrenciasEsquerda(int *A, int inicio, int final, int valor) {
    int meio = (inicio + final) / 2;

    if (inicio > final) return inicio;

    if (A[meio] < valor)
        return _contaOcorrenciasEsquerda(A, meio + 1, final, valor);
    else
        return _contaOcorrenciasEsquerda(A, inicio, meio - 1, valor);

}

/// Conta quantas vezes o valor se repete no vetor
/// \param A - O vetor a ser buscado
/// \param tamanho - O tamanho do vetor
/// \param valor - O valor a ser buscado
/// \return - Quantas vezes o valor aparece na lista
int contaOcorrencias(int *A, int tamanho, int valor) {
    int pelaDireita = _contaOcorrenciasDireita(A, 0, tamanho - 1, valor);
    int pelaEsquerda = _contaOcorrenciasEsquerda(A, 0, tamanho - 1, valor);

    return pelaDireita - pelaEsquerda;
}