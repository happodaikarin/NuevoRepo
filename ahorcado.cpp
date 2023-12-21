#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void mostrarTablero(string palabraOculta, int intentosRestantes) {
    cout << "\nPalabra: " << palabraOculta << endl;
    cout << "Intentos Restantes: " << intentosRestantes << endl;
}

int main() {
    vector<string> palabras = {"programacion", "ahorcado", "computadora", "juego", "codigo"};
    srand(time(0));
    string palabra = palabras[rand() % palabras.size()];

    string palabraOculta(palabra.length(), '_');
    int intentos = 6; // Número de intentos permitidos

    while (intentos > 0 && palabraOculta != palabra) {
        mostrarTablero(palabraOculta, intentos);
        cout << "\nIngrese una letra: ";
        char letra;
        cin >> letra;

        // Verificar si la letra está en la palabra
        bool acierto = false;
        for (int i = 0; i < palabra.length(); i++) {
            if (letra == palabra[i]) {
                palabraOculta[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            intentos--;
            cout << "¡Incorrecto! La letra '" << letra << "' no está en la palabra." << endl;
        }

        if (palabraOculta == palabra) {
            cout << "\n¡Felicidades! Has adivinado la palabra: " << palabra << endl;
        } else if (intentos == 0) {
            cout << "\nHas perdido. La palabra era: " << palabra << endl;
        }
    }

    return 0;
}
