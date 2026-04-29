#include <stdio.h>
#include <string.h>

int main() {
    char user[20], pass[20];

    printf("Usuario: ");
    scanf("%s", user);

    printf("Contraseña: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        printf("Acceso correcto\n");
    } else {
        printf("Acceso denegado\n");
    }

    return 0;
}
//Agregar sistema de login basico