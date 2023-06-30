void crearUsuario()
{
    if (totalUsuarios >= MAX_USUARIOS)
    {
        cout << "Se ha alcanzado el límite máximo de usuarios." << endl;
        return;
    }

    Usuario nuevoUsuario;
    cout << "Creación de usuario" << endl;
    cout << "Ingrese el nombre: ";
    cin >> nuevoUsuario.nombre;
    cout << "Ingrese la contraseña: ";
    cin >> nuevoUsuario.contrasena;
    nuevoUsuario.saldo = 0.0;

    usuarios[totalUsuarios++] = nuevoUsuario;

    cout << "Usuario creado exitosamente." << endl;
}

/* Función booleana para logeo */
bool logearse()
{
    char nombre[50];
    char contrasena[50];

    cout << "Inicio de sesión" << endl;
    cout << "Nombre de usuario: ";
    cin >> nombre;
    cout << "Contraseña: ";
    cin >> contrasena;

    for (int i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(usuarios[i].nombre, nombre) == 0 && strcmp(usuarios[i].contrasena, contrasena) == 0)
        {
            usuarioActual = &usuarios[i];
            return true;
        }
    }

    cout << "Nombre de usuario o contraseña incorrectos." << endl;
    return false;
}
