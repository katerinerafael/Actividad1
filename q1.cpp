// q1.cpp
#include "q1.h"

// Constructor de la clase ElectoralDistrict
// Inicializa el nombre del distrito y la cantidad de votantes registrados
ElectoralDistrict::ElectoralDistrict(std::string name, int voters) {
    districtName = name;
    registeredVoters = voters;
}

// Agrega votos para un candidato a la lista de votos
void ElectoralDistrict::addCandidateVotes(int votes) {
    candidateVotes.push_back(votes);  // Inserta el número de votos al final del vector
}

// Calcula la tasa de participación: total de votos emitidos dividido entre votantes registrados
double ElectoralDistrict::calculateParticipationRate() const {
    int totalVotes = 0;
    
    // Suma los votos de todos los candidatos
    for (int votes : candidateVotes) {
        totalVotes += votes;
    }
    
    // Si no hay votantes registrados, retorna 0.0 para evitar división por cero
    if (registeredVoters == 0) return 0.0;  // Evita división por 0
    // Retorna la tasa como un número decimal (por ejemplo, 0.75 si es 75%)
    return static_cast<double>(totalVotes) / registeredVoters;
}

// Verifica si la tasa de participación es igual o superior al 50%
bool ElectoralDistrict::meetsParticipationThreshold() const {
    return calculateParticipationRate() >= 0.5;
}

// Encuentra el índice del candidato con más votos
int ElectoralDistrict::findWinningCandidateIndex() const {
    if (candidateVotes.empty()) return -1;      // Si no hay candidatos, devuelve -1

    int maxVotes = candidateVotes[0]; // Supone que el primer candidato tiene la mayor cantidad de votos
    int winnerIndex = 0; // Guarda el índice del candidato con más votos

    // Recorre el resto de los candidatos para encontrar al que tiene más votos
    for (size_t i = 1; i < candidateVotes.size(); ++i) {
        if (candidateVotes[i] > maxVotes) {
            maxVotes = candidateVotes[i];
            winnerIndex = i;
        }
    }

    return winnerIndex;  // Retorna el índice del ganador
}

// Devuelve el nombre del distrito electoral
std::string ElectoralDistrict::getDistrictName() const {
    return districtName;
}

