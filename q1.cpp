// q1.cpp
#include "q1.h"

// Constructor
ElectoralDistrict::ElectoralDistrict(std::string name, int voters) {
    districtName = name;
    registeredVoters = voters;
}

// Agrega votos a la lista
void ElectoralDistrict::addCandidateVotes(int votes) {
    candidateVotes.push_back(votes);  // Agrega un candidato con sus votos
}

// Calcula votos emitidos / registrados
double ElectoralDistrict::calculateParticipationRate() const {
    int totalVotes = 0;

    for (int votes : candidateVotes) {
        totalVotes += votes;
    }

    if (registeredVoters == 0) return 0.0;  // Evita división por 0
    return static_cast<double>(totalVotes) / registeredVoters;
}

// Verifica si participación es al menos 50%
bool ElectoralDistrict::meetsParticipationThreshold() const {
    return calculateParticipationRate() >= 0.5;
}

// Busca el índice del candidato con más votos
int ElectoralDistrict::findWinningCandidateIndex() const {
    if (candidateVotes.empty()) return -1;  // No hay candidatos

    int maxVotes = candidateVotes[0];
    int winnerIndex = 0;

    for (size_t i = 1; i < candidateVotes.size(); ++i) {
        if (candidateVotes[i] > maxVotes) {
            maxVotes = candidateVotes[i];
            winnerIndex = i;
        }
    }

    return winnerIndex;
}

// Devuelve el nombre del distrito
std::string ElectoralDistrict::getDistrictName() const {
    return districtName;
}

