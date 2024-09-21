#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int codigo;
    float nota;
    Estudiante* siguiente;
};

Estudiante* crearEstudiante(string nombre, int codigo, float nota) {
    Estudiante* nuevo = new Estudiante();
    nuevo->nombre = nombre;
    nuevo->codigo = codigo;
    nuevo->nota = nota;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertarEstudiante(Estudiante*& cabeza, string nombre, int codigo, float nota) {
    Estudiante* nuevo = crearEstudiante(nombre, codigo, nota);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void mostrarEstudiantes(Estudiante* cabeza) {
    Estudiante* actual = cabeza;
    while (actual != NULL) {
        cout << "Nombre: " << actual->nombre << ", Código: " << actual->codigo << ", Nota: " << actual->nota << endl;
        actual = actual->siguiente;
    }
}

void ordenarPorCodigo(Estudiante*& cabeza) {
    if (cabeza == NULL) return;
    bool ordenado;
    do {
        ordenado = true;
        Estudiante* actual = cabeza;
        while (actual->siguiente != NULL) {
            if (actual->codigo > actual->siguiente->codigo) {
                swap(*actual, *actual->siguiente);
                ordenado = false;
            }
            actual = actual->siguiente;
        }
    } while (!ordenado);
}

void ordenarPorNota(Estudiante*& cabeza) {
    if (cabeza == NULL) return;
    bool ordenado;
    do {
        ordenado = true;
        Estudiante* actual = cabeza;
        while (actual->siguiente != NULL) {
            if (actual->nota < actual->siguiente->nota) {
                swap(*actual, *actual->siguiente);
                ordenado = false;
            }
            actual = actual->siguiente;
        }
    } while (!ordenado);
}

void mayorNota(Estudiante* cabeza) {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Estudiante* mayor = cabeza;
    Estudiante* actual = cabeza->siguiente;
    while (actual != NULL) {
        if (actual->nota > mayor->nota) {
            mayor = actual;
        }
        actual = actual->siguiente;
    }
    cout << "La mayor nota es de: " << mayor->nombre << " con " << mayor->nota << endl;
}

void menorNota(Estudiante* cabeza) {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Estudiante* menor = cabeza;
    Estudiante* actual = cabeza->siguiente;
    while (actual != NULL) {
        if (actual->nota < menor->nota) {
            menor = actual;
        }
        actual = actual->siguiente;
    }
    cout << "La menor nota es de: " << menor->nombre << " con " << menor->nota << endl;
}

void promedioNotas(Estudiante* cabeza) {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }
    float suma = 0;
    int contador = 0;
    Estudiante* actual = cabeza;
    while (actual != NULL) {
        suma += actual->nota;
        contador++;
        actual = actual->siguiente;
    }
    cout << "El promedio de notas es: " << (suma / contador) << endl;
}

void menu(Estudiante*& cabeza) {
    int opcion;
    do {
        cout << "\n--- Menú de Gestión de Estudiantes ---\n";
        cout << "1. Ingresar datos de estudiante\n";
        cout << "2. Ordenar lista por Código Estudiantil (menor a mayor)\n";
        cout << "3. Ordenar lista por Nota (mayor a menor)\n";
        cout << "4. Mostrar la mayor nota del curso\n";
        cout << "5. Mostrar la menor nota del curso\n";
        cout << "6. Mostrar promedio de notas\n";
        cout << "7. Mostrar lista de estudiantes\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int codigo;
                float nota;

                cin.ignore();
                cout << "Ingrese el nombre del estudiante: ";
                getline(cin, nombre);

                cout << "Ingrese el código del estudiante: ";
                cin >> codigo;

                do {
                    cout << "Ingrese la nota del estudiante (0-100): ";
                    cin >> nota;
                    if (nota < 0 || nota > 100) {
                        cout << "Nota inválida. Debe estar entre 0 y 100.\n";
                    }
                } while (nota < 0 || nota > 100);

                insertarEstudiante(cabeza, nombre, codigo, nota);
                break;
            }
            case 2:
                ordenarPorCodigo(cabeza);
                cout << "Lista ordenada por código.\n";
                mostrarEstudiantes(cabeza);
                break;
            case 3:
                ordenarPorNota(cabeza);
                cout << "Lista ordenada por nota.\n";
                mostrarEstudiantes(cabeza);
                break;
            case 4:
                mayorNota(cabeza);
                break;
            case 5:
                menorNota(cabeza);
                break;
            case 6:
                promedioNotas(cabeza);
                break;
            case 7:
                mostrarEstudiantes(cabeza);
                break;
            case 8:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 8);
}

int main() {
    Estudiante* listaEstudiantes = NULL;
    menu(listaEstudiantes);
    return 0;
}