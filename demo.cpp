#include <iostream>
#include <cstring>
#include <unistd.h>

using namespace std;

/* Estructura para almacenar el nombre, la contrasena y el saldo de cada usuario */
struct Usuario
{
    char nombre[50];
    char contrasena[50];
    float saldo;
};

const int MAX_USUARIOS = 10; // Constante para limitar el número maximo de usuarios
const int DELAY = 5000000;
Usuario usuarios[MAX_USUARIOS]; // Arreglo de usuarios
int totalUsuarios = 0;
Usuario *usuarioActual = nullptr;

/* Procedimiento que limpia el terminal */
void limpiarTerminal()
{
    system("cls||clear") ;
    fflush(stdout) ;
    fflush(stdin) ;
}

/* Procedimiento para crear un nuevo usuario */
void crearUsuario()
{
    if (totalUsuarios >= MAX_USUARIOS)
    {
        cout << "Se ha alcanzado el limite maximo de usuarios." << endl;
        return;
    }

    Usuario nuevoUsuario;
    cout << "CREACION DE USUARIO" << endl << endl;
    cout << "Ingrese el nombre: ";
    cin >> nuevoUsuario.nombre;
    cout << "Ingrese la contrasena: ";
    cin >> nuevoUsuario.contrasena;
    nuevoUsuario.saldo = 0.0;

    usuarios[totalUsuarios++] = nuevoUsuario;

    cout << "Usuario creado exitosamente." << endl;
}

/* Funcion booleana para logeo */
bool logearse()
{
    char nombre[50];
    char contrasena[50];
    usleep(DELAY);
    limpiarTerminal();
    cout << "INICIO DE SESION" << endl << endl;
    cout << "Nombre de usuario: ";
    cin >> nombre;
    cout << "Contrasena: ";
    cin >> contrasena;

    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(usuarios[i].nombre, nombre) == 0 && strcmp(usuarios[i].contrasena, contrasena) == 0)
        {
            usuarioActual = &usuarios[i];
            return true;
        }
    }

    cout << "Nombre de usuario o contrasena incorrectos." << endl;
    return false;
}

/* Procedimiento para realizar transferencias */
void realizarTransferencia()
{
    if (usuarioActual == nullptr)
    {
        cout << "Debe iniciar sesion para realizar una transferencia." << endl;
        return;
    }

    char nombreDestino[50];
    float monto;

    cout << "TRANSFERENCIA"<< endl << endl;
    cout << "Ingrese el nombre de usuario destino: ";
    cin >> nombreDestino;
    cout << "Ingrese el monto a transferir: ";
    cin >> monto;

    Usuario *destinatario = nullptr;
    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(usuarios[i].nombre, nombreDestino) == 0)
        {
            destinatario = &usuarios[i];
            break;
        }
    }

    if (destinatario != nullptr)
    {
        if (usuarioActual->saldo >= monto)
        {
            usuarioActual->saldo -= monto;
            destinatario->saldo += monto;
            cout << "Transferencia realizada exitosamente." << endl;
        }
        else
        {
            cout << "Saldo insuficiente para realizar la transferencia." << endl;
        }
    }
    else
    {
        cout << "Usuario destino no encontrado." << endl;
    }
}

/* Procedimiento para realizar depositos */
void realizarDeposito()
{
    if (usuarioActual == nullptr)
    {
        cout << "Debe iniciar sesion para realizar un deposito." << endl;
        return;
    }

    float monto;
    cout << "DEPOSITO" << endl;
    cout << "Ingrese el monto a depositar: ";
    cin >> monto;

    usuarioActual->saldo += monto;
    cout << "Deposito realizado exitosamente." << endl;
}

/* Procedimiento para realizar retiros */
void realizarRetiro()
{
    if (usuarioActual == nullptr)
    {
        cout << "Debe iniciar sesion para realizar un retiro." << endl;
        return;
    }

    float monto;
    cout << "RETIRO" << endl << endl;
    cout << "Ingrese el monto a retirar: ";
    cin >> monto;
    if (usuarioActual->saldo >= monto)
    {
        usuarioActual->saldo -= monto;
        cout << "Retiro realizado exitosamente." << endl;
    }
    else
    {
        cout << "Saldo insuficiente para realizar el retiro." << endl;
    }
}

/* Procedimiento para consultar saldos */
void consultarSaldo()
{
    if (usuarioActual == nullptr)
    {
        cout << "Debe iniciar sesion para consultar el saldo." << endl;
        return;
    }
    cout << "Saldo actual: $" << usuarioActual->saldo << endl;
}

int main()
{
    int opcion;
    while (true)
    {
        usleep(DELAY);
        limpiarTerminal();
        cout << "SISTEMA BANCARIO" << endl << endl;
        cout << "1. Crear usuario" << endl;
        cout << "2. Iniciar sesion" << endl;
        cout << "3. Salir" << endl << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            usleep(DELAY);
            limpiarTerminal();
            crearUsuario();
            break;

        /* Opciones bancarias */
        case 2:
            if (logearse())
            {
                while (true)
                {
                    usleep(DELAY);
                    limpiarTerminal();
                    cout << "Bienvenido, " << usuarioActual->nombre << endl << endl;
                    cout << "1. Transferencia" << endl;
                    cout << "2. Deposito" << endl;
                    cout << "3. Retiro" << endl;
                    cout << "4. Consultar saldo" << endl;
                    cout << "5. Cerrar sesion" << endl << endl;
                    cout << "Ingrese su opcion: ";
                    cin >> opcion;

                    switch (opcion)
                    {
                    case 1:
                        usleep(DELAY);
                        limpiarTerminal();
                        realizarTransferencia();
                        break;

                    case 2:
                        usleep(DELAY);
                        limpiarTerminal();                        
                        realizarDeposito();
                        break;

                    case 3:
                        usleep(DELAY);
                        limpiarTerminal();
                        realizarRetiro();
                        break;

                    case 4:
                        usleep(DELAY);
                        limpiarTerminal();
                        consultarSaldo();
                        break;

                    case 5:
                        usuarioActual = nullptr;
                        usleep(DELAY);
                        limpiarTerminal();
                        cout << "Sesion cerrada exitosamente." << endl;
                        break;
                    default:
                        usleep(DELAY);
                        limpiarTerminal();
                        cout << "Opcion invalida." << endl;
                        break;
                    }

                    if (opcion == 5)
                    {
                        break;
                    }
                }
            }
            break;

        case 3:
            usleep(DELAY);
            limpiarTerminal();
            cout << "Saliendo del sistema..." << endl;
            return 0;

        default:
        usleep(DELAY);
        limpiarTerminal();
            cout << "Opcion invalida." << endl;
            break;
        }
    }
    return 0;
}