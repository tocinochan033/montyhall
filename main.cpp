#include <iostream>
#include <random>
int main() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> puerta(0,2);

    const int N = 10000;
    int rutaA = 0; //ruta del 33%
    int rutaB = 0;  //ruta del 66%

    for (int i = 0; i < N; ++i) {
        int premioCoche = puerta(gen);
        int jugadorEleccion = puerta(gen);

        //GANA RUTA A
        if (jugadorEleccion == premioCoche){
            ++rutaA;
        }

        //si fallas
        //el presentador abre otra puerta
        int puertaAbierta = -1;
        for (int j = 0; j < 3; ++j) {
            if (j != premioCoche && j != jugadorEleccion) { //si la puerta abierta no es ni la del coche ni la respuesta del jugador
                puertaAbierta = j; break; //ruta B gano
            }
        }

        //la puerta que escoge si entra a la ruta B
        int caksmasd = 3 - jugadorEleccion - puertaAbierta;
        if (caksmasd == premioCoche) {
            ++rutaB;
        }
    }
    std::cout << "Ganador A: " << (100.0 * rutaA / N) << "%\n";
    std::cout << "Ganador B: " << (100.0 * rutaB / N) << "%\n";
    return 0;
}
