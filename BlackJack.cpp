#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Colores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// Estructura para las cartas
struct carta {
    string palo;
    string figura;
    int valor;
};

// Inicializar la baraja
void inicializarBarajaCastellano(carta baraja[], int tBaraja) {
    int indice = 0;
    const string palos[] = { "Picas", "Corazones", "Treboles", "Rombos" };
    const string figuras[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            int v = (j >= 9) ? 10 : (j + 2);
            baraja[indice++] = { palos[i], figuras[j], v };
        }
    }
}

// Inicializar la baraja
void inicializarBarajaCatalan(carta baraja[], int tBaraja) {
    int indice = 0;
    const string palos[] = { "Piques", "Cors", "Trebols", "Rombes" };
    const string figuras[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            int v = (j >= 9) ? 10 : (j + 2);
            baraja[indice++] = { palos[i], figuras[j], v };
        }
    }
}
void inicializarBarajaIngles(carta baraja[], int tBaraja) {
    int indice = 0;
    const string palos[] = { "Spades", "Hearts", "Clubs", "Diamonds" };
    const string figuras[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            int v = (j >= 9) ? 10 : (j + 2);
            baraja[indice++] = { palos[i], figuras[j], v };
        }
    }
}
// Función para barajar las cartas
void barajar(carta baraja[], int tBaraja) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < tBaraja; ++i) {
        int indiceRandom = rand() % tBaraja;
        carta temp = baraja[i];
        baraja[i] = baraja[indiceRandom];
        baraja[indiceRandom] = temp;
    }
}

// Función para mostrar una mano de cartas
void mostrarMano(const carta mano[], int tamano, bool mostrarTodo = true) {
    for (int i = 0; i < tamano; ++i) {
        if (mostrarTodo || i == 0) {
            cout << RED << mano[i].figura << RESET << " | " << GREEN << mano[i].palo << RESET << endl;
        }
        else {
            cout << "" << endl;
        }
    }
}

// Función para sumar el valor de una mano de cartas
int sumarManoCastellano(carta mano[], int tamano, bool esCrupier = false) {
    int suma = 0;
    int ases = 0;

    for (int i = 0; i < tamano; ++i) {
        suma += mano[i].valor;

        // Contar los Ases
        if (mano[i].figura == "A") {
            ++ases;
        }
    }

    // Permitir al jugador elegir el valor del As para cada As en su mano
    if (!esCrupier) {
        for (int i = 0; i < ases; ++i) {
            int eleccion;
            cout << "Tienes un AS. Quieres que valga 1 o 11? ";
            cin >> eleccion;

            while (eleccion != 1 && eleccion != 11) {
                cout << "Elección no válida. Por favor, elige 1 o 11.\n";
                cout << "Tienes un AS. Quieres que valga 1 o 11? ";
                cin >> eleccion;
            }

            // Restar el valor actual del As y luego sumar la elección del jugador
            suma = suma - mano[i].valor + eleccion;
            mano[i].valor = eleccion; // Actualizar el valor del As en la estructura de la carta
        }
    }

    return suma;
}

int sumarManoCatalan(carta mano[], int tamano, bool esCrupier = false) {
    int suma = 0;
    int ases = 0;

    for (int i = 0; i < tamano; ++i) {
        suma += mano[i].valor;

        // Contar los Ases
        if (mano[i].figura == "A") {
            ++ases;
        }
    }

    // Permitir al jugador elegir el valor del As para cada As en su mano
    if (!esCrupier) {
        for (int i = 0; i < ases; ++i) {
            int eleccion;
            cout << "Tens un AS. Vols que valgui 1 o 11? ";
            cin >> eleccion;

            while (eleccion != 1 && eleccion != 11) {
                cout << "Elecció no vàlida. Si us plau, tria 1 o 11.\n";
                cout << "Tens un AS. Vols que valgui 1 o 11? ";
                cin >> eleccion;
            }

            // Restar el valor actual del As y luego sumar la elección del jugador
            suma = suma - mano[i].valor + eleccion;
            mano[i].valor = eleccion; // Actualizar el valor del As en la estructura de la carta
        }
    }

    return suma;
}

int sumarManoIngles(carta mano[], int tamano, bool esCrupier = false) {
    int suma = 0;
    int ases = 0;

    for (int i = 0; i < tamano; ++i) {
        suma += mano[i].valor;

        // Contar los Ases
        if (mano[i].figura == "A") {
            ++ases;
        }
    }

    // Permitir al jugador elegir el valor del As para cada As en su mano
    if (!esCrupier) {
        for (int i = 0; i < ases; ++i) {
            int eleccion;
            cout << "You have an Ace. Do you want it to be 1 or 11? ";
            cin >> eleccion;

            while (eleccion != 1 && eleccion != 11) {
                cout << "Invalid choice. Please choose 1 or 11.\n";
                cout << "You have an Ace. Do you want it to be 1 or 11? ";
                cin >> eleccion;
            }

            // Restar el valor actual del As y luego sumar la elección del jugador
            suma = suma - mano[i].valor + eleccion;
            mano[i].valor = eleccion; // Actualizar el valor del As en la estructura de la carta
        }
    }

    return suma;
}

// Función principal del juego castellano
void jugarBlackjackCastellano() {
    char jugarNuevamente;

    do {
        int tBaraja = 52;
        carta* baraja = new carta[tBaraja];

        // Inicializar y barajar
        inicializarBarajaCastellano(baraja, tBaraja);
        barajar(baraja, tBaraja);

        // Repartir cartas al crupier antes que al jugador
        carta manoCroupier[2];
        manoCroupier[0] = baraja[--tBaraja];
        manoCroupier[1] = baraja[--tBaraja];

        // Repartir cartas al jugador
        carta manoJugador[2];
        manoJugador[0] = baraja[--tBaraja];
        manoJugador[1] = baraja[--tBaraja];

        // Bienvenida al juego
        cout << BLUE << "Bienvenido al Blackjack!" << RESET << "\n";
        cout << "Estás listo para " << YELLOW << "desafiar al crupier" << RESET << " y alcanzar el " << RED << "21" << RESET << "?\n";
        cout << "Recuerda, elige sabiamente tus cartas y que la suerte esté de tu lado. " << GREEN << "Buena suerte!" << RESET << "\n";
        system("pause");

        // Mostrar la primera carta del crupier
        cout << "Primera carta del Crupier:" << endl;
        mostrarMano(manoCroupier, 1, true);

        // Mostrar las cartas del jugador
        cout << "Tus cartas:" << endl;
        mostrarMano(manoJugador, 2);

        // Valor del jugador
        int valorMano = sumarManoCastellano(manoJugador, 2);
        cout << "Valor actual de tu mano: " << valorMano << "\n";

        // Pedir cartas o plantarse
        char opcion;
        do {
            cout << "Quieres pedir otra carta (P) o plantarte (L)? ";
            cin >> opcion;

            if (opcion == 'P' || opcion == 'p') {
                // Pedir carta y mostrar
                manoJugador[0] = baraja[--tBaraja];
                cout << "Has recibido un ";
                cout << RED << manoJugador[0].figura << RESET << " de " << GREEN << manoJugador[0].palo << RESET << "\n";

                // Sumar el valor de la nueva carta a la mano del jugador
                valorMano += manoJugador[0].valor;

                // Mostrar el valor actual de la mano
                cout << "Valor actual de tu mano: " << valorMano << "\n";

                // Verificar si el jugador se pasa de 21
                if (valorMano > 21) {
                    cout << YELLOW << "Te has pasado de 21. Has perdido!" << RESET << "\n";
                    break;
                }
            }
            else if (opcion == 'L' || opcion == 'l') {
                // Mostrar las cartas del crupier
                cout << "Cartas del Crupier:" << endl;
                mostrarMano(manoCroupier, 1, true);

                // Valor del Crupier
                int valorManoCroupier = sumarManoCastellano(manoCroupier, 2, true);
                cout << "Valor actual de la mano del Crupier: " << valorManoCroupier << "\n";

                // Continuar sacando cartas hasta que alcance al menos 17 puntos
                while (valorManoCroupier < 17) {
                    manoCroupier[1] = baraja[--tBaraja];  // Corregir el índice
                    cout << "El Crupier ha recibido un " << RED << manoCroupier[1].figura << RESET
                        << " de " << GREEN << manoCroupier[1].palo << RESET << "\n";

                    // Sumar el valor de la nueva carta a la mano del Crupier
                    valorManoCroupier += manoCroupier[1].valor;
                    cout << "Nuevo valor de la mano del Crupier: " << valorManoCroupier << "\n";
                }

                // Determinar resultado final
                if (valorManoCroupier > 21) {
                    cout << YELLOW << "El Crupier se ha pasado de 21. ¡Ganaste!" << RESET << "\n";
                }
                else if (valorManoCroupier == valorMano) {
                    cout << "Empate. Nadie gana." << "\n";
                }
                else if (valorManoCroupier > valorMano) {
                    cout << YELLOW << "El Crupier gana. Has perdido." << RESET << "\n";
                }
                else {
                    cout << GREEN << "¡Felicidades! Has ganado." << RESET << "\n";
                }
                break;
            }
            else {
                cout << "Opción no válida. Por favor, elige 'P' para pedir carta o 'L' para plantarte.\n";
            }
        } while (true);

        delete[] baraja;  // Liberar memoria

        // Preguntar al usuario si quiere jugar otra vez
        cout << "Quieres jugar otra vez? (S para seguir jugando, N para salir): ";
        cin >> jugarNuevamente;
        system("cls");
    } while (jugarNuevamente == 'S' || jugarNuevamente == 's');

    cout << "¡Gracias por jugar! ¡Hasta luego!\n";
}

void jugarBlackjackIngles() {
    char jugarNuevamente;

    do {
        int tBaraja = 52;
        carta* baraja = new carta[tBaraja];

        // Inicializar y barajar
        inicializarBarajaIngles(baraja, tBaraja);
        barajar(baraja, tBaraja);

        // Repartir cartas al crupier antes que al jugador
        carta manoCroupier[2];
        manoCroupier[0] = baraja[--tBaraja];
        manoCroupier[1] = baraja[--tBaraja];

        // Repartir cartas al jugador
        carta manoJugador[2];
        manoJugador[0] = baraja[--tBaraja];
        manoJugador[1] = baraja[--tBaraja];

        // Bienvenida al juego
        cout << BLUE << "Welcome to Blackjack!" << RESET << "\n";
        cout << "Are you ready to " << YELLOW << "challenge the dealer" << RESET << " and reach " << RED << "21" << RESET << "?\n";
        cout << "Remember, choose your cards wisely, and may luck be on your side. " << GREEN << "Good luck!" << RESET << "\n";
        system("pause");

        // Mostrar la primera carta del crupier
        cout << "Dealer's First Card:" << endl;
        mostrarMano(manoCroupier, 1, true);

        // Mostrar las cartas del jugador
        cout << "Your Cards:" << endl;
        mostrarMano(manoJugador, 2);

        // Valor del jugador
        int valorMano = sumarManoIngles(manoJugador, 2);
        cout << "Current value of your hand: " << valorMano << "\n";

        // Pedir cartas o plantarse
        char opcion;
        do {
            cout << "Do you want to hit (H) or stand (S)? ";
            cin >> opcion;

            if (opcion == 'H' || opcion == 'h') {
                // Pedir carta y mostrar
                manoJugador[0] = baraja[--tBaraja];
                cout << "You received a ";
                cout << RED << manoJugador[0].figura << RESET << " de " << GREEN << manoJugador[0].palo << RESET << "\n";

                // Sumar el valor de la nueva carta a la mano del jugador
                valorMano += manoJugador[0].valor;

                // Mostrar el valor actual de la mano
                cout << "Current value of your hand: " << valorMano << "\n";

                // Verificar si el jugador se pasa de 21
                if (valorMano > 21) {
                    cout << YELLOW << "You have busted. You lose!" << RESET << "\n";
                    break;
                }
            }
            else if (opcion == 'S' || opcion == 's') {
                // Mostrar las cartas del crupier
                cout << "Dealer's Cards:" << endl;
                mostrarMano(manoCroupier, 1, true);

                // Valor del Crupier
                int valorManoCroupier = sumarManoIngles(manoCroupier, 2, true);
                cout << "Current value of the dealer's hand: " << valorManoCroupier << "\n";

                // Continuar sacando cartas hasta que alcance al menos 17 puntos
                while (valorManoCroupier < 17) {
                    manoCroupier[1] = baraja[--tBaraja];  // Corregir el índice
                    cout << "The dealer received a " << RED << manoCroupier[1].figura << RESET
                        << " | " << GREEN << manoCroupier[1].palo << RESET << "\n";

                    // Sumar el valor de la nueva carta a la mano del Crupier
                    valorManoCroupier += manoCroupier[1].valor;
                    cout << "New value of the dealer's hand: " << valorManoCroupier << "\n";
                }

                // Determinar resultado final
                if (valorManoCroupier > 21) {
                    cout << YELLOW << "The dealer has busted. You win!" << RESET << "\n";
                }
                else if (valorManoCroupier == valorMano) {
                    cout << "It's a tie. Nobody wins." << "\n";
                }
                else if (valorManoCroupier > valorMano) {
                    cout << YELLOW << "The dealer wins. You lose." << RESET << "\n";
                }
                else {
                    cout << GREEN << "Congratulations! You win." << RESET << "\n";
                }
                break;
            }
            else {
                cout << "Invalid option. Please choose 'H' to hit or 'S' to stand.\n";
            }
        } while (true);

        delete[] baraja;  // Liberar memoria

        // Preguntar al usuario si quiere jugar otra vez
        cout << "Do you want to play again? (Y to continue playing, N to exit): ";
        cin >> jugarNuevamente;
        system("cls");
    } while (jugarNuevamente == 'Y' || jugarNuevamente == 'y');

    cout << "Thanks for playing! Goodbye!\n";
}


// Función principal del juego castellano
void jugarBlackjackCatalan() {
    char jugarNuevamente;

    do {
        int tBaraja = 52;
        carta* baraja = new carta[tBaraja];

        // Inicializar y barajar
        inicializarBarajaCatalan(baraja, tBaraja);
        barajar(baraja, tBaraja);

        // Repartir cartas al crupier antes que al jugador
        carta manoCroupier[2];
        manoCroupier[0] = baraja[--tBaraja];
        manoCroupier[1] = baraja[--tBaraja];

        // Repartir cartas al jugador
        carta manoJugador[2];
        manoJugador[0] = baraja[--tBaraja];
        manoJugador[1] = baraja[--tBaraja];

        // Bienvenida al juego
        cout << BLUE << "Benvingut al Blackjack!" << RESET << "\n";
        cout << "Estas preparat per " << YELLOW << "desafiar al crupier" << RESET << " i aconseguir el " << RED << "21" << RESET << "?\n";
        cout << "Recorda, tria saviament les teves cartes i que la sort estigui de la teva banda. " << GREEN << "Bona sort!" << RESET << "\n";
        system("pause");

        // Mostrar la primera carta del crupier
        cout << "Primera carta del Crupier:" << endl;
        mostrarMano(manoCroupier, 1, true);

        // Mostrar las cartas del jugador
        cout << "Les teves cartes:" << endl;
        mostrarMano(manoJugador, 2);

        // Valor del jugador
        int valorMano = sumarManoCatalan(manoJugador, 2);
        cout << "Valor actual de la teva ma: " << valorMano << "\n";

        // Pedir cartas o plantarse
        char opcion;
        do {
            cout << "Vols demanar una altra carta (C) o plantar-te (P)? ";
            cin >> opcion;

            if (opcion == 'C' || opcion == 'c') {
                // Pedir carta y mostrar
                manoJugador[0] = baraja[--tBaraja];
                cout << "Has rebut un ";
                cout << RED << manoJugador[0].figura << RESET << " | " << GREEN << manoJugador[0].palo << RESET << "\n";

                // Sumar el valor de la nueva carta a la mano del jugador
                valorMano += manoJugador[0].valor;

                // Mostrar el valor actual de la mano
                cout << "Valor actual de la teva ma: " << valorMano << "\n";

                // Verificar si el jugador se pasa de 21
                if (valorMano > 21) {
                    cout << YELLOW << "T" << RESET << "\n";
                    break;
                }
            }
            else if (opcion == 'P' || opcion == 'p') {
                // Mostrar las cartas del crupier
                cout << "Cartes del Crupier:" << endl;
                mostrarMano(manoCroupier, 1, true);

                // Valor del Crupier
                int valorManoCroupier = sumarManoCatalan(manoCroupier, 2, true);
                cout << "Valor actual de la ma del Crupier: " << valorManoCroupier << "\n";

                // Continuar sacando cartas hasta que alcance al menos 17 puntos
                while (valorManoCroupier < 17) {
                    manoCroupier[1] = baraja[--tBaraja];  // Corregir el índice
                    cout << "El Crupier ha rebut un " << RED << manoCroupier[1].figura << RESET
                        << " de " << GREEN << manoCroupier[1].palo << RESET << "\n";

                    // Sumar el valor de la nueva carta a la mano del Crupier
                    valorManoCroupier += manoCroupier[1].valor;
                    cout << "Nou valor de la mà del Crupier: " << valorManoCroupier << "\n";
                }

                // Determinar resultado final
                if (valorManoCroupier > 21) {
                    cout << YELLOW << "El Crupier s'ha passat de 21. Has guanyat!" << RESET << "\n";
                }
                else if (valorManoCroupier == valorMano) {
                    cout << "Empat. Ningú guanya." << "\n";
                }
                else if (valorManoCroupier > valorMano) {
                    cout << YELLOW << "El Crupier guanya. Has perdut." << RESET << "\n";
                }
                else {
                    cout << GREEN << "Felicitats! Has guanyat." << RESET << "\n";
                }
                break;
            }
            else {
                cout << "Opció no valida. Si us plau, tria 'C' per demanar carta o 'P' per plantar-te.\n";
            }
        } while (true);

        delete[] baraja;  // Liberar memoria

        // Preguntar al usuario si quiere jugar otra vez
        cout << "Vols jugar de nou? (S per continuar jugant, N per sortir): ";
        cin >> jugarNuevamente;
        system("cls");

    } while (jugarNuevamente == 'S' || jugarNuevamente == 's');

    cout << "Gracies per jugar! Fins aviat!\n";
}

// mostrasr idiomas
int elegirIdioma() {
    int idioma;
    do {
        cout << "Elige tu idioma:\n";
        cout << YELLOW << "1. Catalan" << RESET << "\n";
        cout << RED << "2. Castellano" << RESET << "\n";
        cout << BLUE << "3. Ingles" << RESET << "\n";
        cout << "4. Salir\n";
        cout << "Seleccione el numero correspondiente al idioma: ";
        cin >> idioma;

        if (idioma < 1 || idioma > 4) {
            cout << "Opcion no valida. Por favor, elige una opción del 1 al 3.\n";
        }
    } while (idioma < 1 || idioma > 4);

    return idioma;
}

void establecerIdioma(int idioma) {
    switch (idioma) {
    case 1:  // Catalan
        cout << YELLOW << "Catalan" << RESET << "\n";
        jugarBlackjackCatalan();
        break;
    case 2:  // Castellano
        cout << RED << "Castellano" << RESET << "\n";
        jugarBlackjackCastellano();
        break;
    case 3:  // Ingles
        cout << BLUE << "English"<< RESET << "\n";
        jugarBlackjackIngles();
        break;
    case 4:
        cout << "Adios/Adeu/Bye";
        return;
        break;
    }
}

int main() {
    // usuario idioma
    int idiomaElegido = elegirIdioma();

    //establecer ese idioma
    establecerIdioma(idiomaElegido);

    return 0;
}
