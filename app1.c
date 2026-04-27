
#include <stdio.h>
#include <string.h>

// Estructura de usuario
struct Usuario {
    char username[20];
    char password[20];
    float saldo;
};

// Funciones
int login(struct Usuario usuarios[], int totalUsuarios);
void menu(struct Usuario *user);
void consultarSaldo(struct Usuario *user);
void depositar(struct Usuario *user);
void retirar(struct Usuario *user);

int main() {
    // Usuarios predefinidos
    struct Usuario usuarios[] = {
        {"admin", "1234", 1000.0},
        {"juan", "abcd", 500.0},
        {"maria", "5678", 800.0}
    };

    int totalUsuarios = 3;

    int index = login(usuarios, totalUsuarios);

    if (index != -1) {
        menu(&usuarios[index]);
    } else {
        printf("Acceso denegado.\n");
    }

    return 0;
}

// LOGIN
int login(struct Usuario usuarios[], int totalUsuarios) {
    char user[20], pass[20];

    printf("Usuario: ");
    scanf("%s", user);

    printf("Contraseña: ");
    scanf("%s", pass);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(user, usuarios[i].username) == 0 &&
            strcmp(pass, usuarios[i].password) == 0) {
            return i;
        }
    }

    return -1;
}

// MENÚ
void menu(struct Usuario *user) {
    int opcion;

    do {
        printf("\n--- CAJERO ---\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar\n");
        printf("3. Retirar\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                consultarSaldo(user);
                break;
            case 2:
                depositar(user);
                break;
            case 3:
                retirar(user);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 4);
}

// FUNCIONES
void consultarSaldo(struct Usuario *user) {
    printf("Saldo actual: %.2f\n", user->saldo);
}

void depositar(struct Usuario *user) {
    float monto;
    printf("Monto a depositar: ");
    scanf("%f", &monto);

    if (monto > 0) {
        user->saldo += monto;
        printf("Deposito exitoso.\n");
    } else {
        printf("Monto invalido.\n");
    }
}

void retirar(struct Usuario *user) {
    float monto;
    printf("Monto a retirar: ");
    scanf("%f", &monto);

    if (monto <= user->saldo && monto > 0) {
        user->saldo -= monto;
        printf("Retiro exitoso.\n");
    } else {
        printf("Fondos insuficientes o monto invalido.\n");
    }
}