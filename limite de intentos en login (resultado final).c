#include <stdio.h>
#include <string.h>

float saldo = 1000;

void menu();
void consultarSaldo();
void depositar();
void retirar();

int main() {
    char user[20], pass[20];
    int intentos = 3;
    int acceso = 0;

    while (intentos > 0) {
        printf("Usuario: ");
        scanf("%s", user);

        printf("Contraseña: ");
        scanf("%s", pass);

        if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
            printf("Acceso correcto\n");
            acceso = 1;
            break;
        } else {
            intentos--;
            printf("Error. Intentos restantes: %d\n", intentos);
        }
    }

    if (acceso == 1) {
        menu();
    } else {
        printf("Acceso bloqueado.\n");
    }

    return 0;
}

void menu() {
    int opcion;

    do {
        printf("\n1. Consultar saldo\n");
        printf("2. Depositar\n");
        printf("3. Retirar\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: consultarSaldo(); break;
            case 2: depositar(); break;
            case 3: retirar(); break;
            case 4: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida\n");
        }

    } while(opcion != 4);
}

void consultarSaldo() {
    printf("Saldo: %.2f\n", saldo);
}

void depositar() {
    float monto;
    printf("Monto a depositar: ");
    scanf("%f", &monto);

    if (monto > 0) {
        saldo += monto;
        printf("Deposito exitoso\n");
    } else {
        printf("Monto invalido\n");
    }
}

void retirar() {
    float monto;
    printf("Monto a retirar: ");
    scanf("%f", &monto);

    if (monto > 0 && monto <= saldo) {
        saldo -= monto;
        printf("Retiro exitoso\n");
    } else {
        printf("Operacion invalida\n");
    }
}
//Agregar limite de intentos en login