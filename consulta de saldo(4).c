#include <stdio.h>
#include <string.h>

float saldo = 1000;

void menu();
void consultarSaldo();

int main() {
    char user[20], pass[20];

    printf("Usuario: ");
    scanf("%s", user);

    printf("Contraseña: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        printf("Acceso correcto\n");
        menu();
    } else {
        printf("Acceso denegado\n");
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

        if (opcion == 1) {
            consultarSaldo();
        }

    } while(opcion != 4);
}

void consultarSaldo() {
    printf("Saldo: %.2f\n", saldo);
}
//Implementar consulta de saldo