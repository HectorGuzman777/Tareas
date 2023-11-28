#ifndef FUNCIONES_H
#define FUNCIONES_H

class Funciones {
public:
    int sumaIterativa(int n) {
        int suma = 0;
        for (int i = 1; i <= n; i++) {
            suma += i;
        }
        return suma;
    }

    int sumaRecursiva(int n) {
        if (n == 0) {
            return 0;
        } else {
            return n + sumaRecursiva(n - 1);
        }
    }

    int sumaDirecta(int n) {
        return (n * (n + 1)) / 2;
    }
};

#endif



