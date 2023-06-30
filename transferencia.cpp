//codigo para realizar una transferencia
void realizarTransferencia()
{
    if (usuarioActual == nullptr)
    {
        cout << "Debe iniciar sesión para realizar una transferencia." << endl;
        return;
    }

    char nombreDestino[50];
    float monto;

    cout << "Transferencia" << endl;
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

/* Procedimiento para realizar depósitos */
void realizarDeposito()
{
    if (usuarioActual == nullptr)
    {
        cout << "Debe iniciar sesión para realizar un depósito." << endl;
        return;
    }

    float monto;
    cout << "Depósito" << endl;
    cout << "Ingrese el monto a depositar: ";
    cin >> monto;

    usuarioActual->saldo += monto;
    cout << "Depósito realizado exitosamente." << endl;
}
