#include <iostream>
using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

int altura(NoArvore* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int alturaEsquerda = altura(raiz->esquerda);
        int alturaDireita = altura(raiz->direita);

        if (alturaEsquerda > alturaDireita) {
            return (alturaEsquerda + 1);
        } else {
            return (alturaDireita + 1);
        }
    }
}

bool verificarBalanceamento(NoArvore* raiz) {
    if (raiz == NULL) {
        return true;  
    }

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    int diferencaAlturas = (alturaEsquerda - alturaDireita);

    if (diferencaAlturas <= 1 && verificarBalanceamento(raiz->esquerda) && verificarBalanceamento(raiz->direita)) {
        return true;
    } else {
        return false;  
    }
}

void percorrerPreOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        cout << raiz->data << " ";
        percorrerPreOrdem(raiz->esquerda);
        percorrerPreOrdem(raiz->direita);
    }
}

int main() {

    NoArvore* raiz = new NoArvore;
    raiz->data = 1;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore* elementoEsquerda = new NoArvore;
    elementoEsquerda->data = 2;
    elementoEsquerda->esquerda = NULL;
    elementoEsquerda->direita = NULL;

    raiz->esquerda = elementoEsquerda;

    NoArvore* elementoDireita = new NoArvore;
    elementoDireita->data = 5;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;

    elementoEsquerda->direita = elementoDireita;

    NoArvore* elementoDireita2 = new NoArvore;
    elementoDireita2->data = 3;
    elementoDireita2->esquerda = NULL;
    elementoDireita2->direita = NULL;

    raiz->direita = elementoDireita2;

    cout << "Arvore em pre-ordem: ";
    percorrerPreOrdem(raiz);
    cout << endl;

    int alturaArvore = altura(raiz);
    cout << "Altura da arvore: " << alturaArvore << endl;
    cout << endl;
    
    bool balanceada = verificarBalanceamento(raiz);

    if (balanceada) {
        cout << "A arvore esta balanceada." << endl;
    } else {
        cout << "A arvore nao esta balanceada." << endl;
    }

    return 0;
}

