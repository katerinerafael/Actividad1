// q1.h
#ifndef Q1_H
#define Q1_H

#include <string>
#include <vector>

class ElectoralDistrict {
private:
    std::string districtName;         // Nombre del distrito (ej: "Norte")
    int registeredVoters;             // Total de votantes registrados
    std::vector<int> candidateVotes;  // Lista de votos para cada candidato

public:
    // Constructor
    ElectoralDistrict(std::string name, int voters);

    // Agregar votos a un candidato
    void addCandidateVotes(int votes);

    // Calcular tasa de participación (votos emitidos / registrados)
    double calculateParticipationRate() const;

    // Verifica si participación >= 50%
    bool meetsParticipationThreshold() const;

    // Devuelve el índice del candidato con más votos
    int findWinningCandidateIndex() const;

    // Devuelve el nombre del distrito
    std::string getDistrictName() const;
};

#endif

