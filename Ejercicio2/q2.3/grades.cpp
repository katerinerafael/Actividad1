#include "grades.h"
#include <iomanip>
#include <algorithm>

void SistemaCalificaciones::agregarEstudiante(const Estudiante& estudiante) {
    if (estudiantes.count(estudiante.id)) {
        throw CalificacionesException("El estudiante ya existe.");
    }
    estudiantes[estudiante.id] = estudiante;
}

void SistemaCalificaciones::eliminarEstudiante(int id) {
    if (!estudiantes.count(id)) {
        throw CalificacionesException("Estudiante no encontrado.");
    }
    estudiantes.erase(id);
    calificaciones.erase(id);
}

Estudiante SistemaCalificaciones::buscarEstudiante(int id) const {
    auto it = estudiantes.find(id);
    if (it == estudiantes.end()) {
        throw CalificacionesException("Estudiante no encontrado.");
    }
    return it->second;
}

void SistemaCalificaciones::mostrarTodosLosEstudiantes() const {
    for (const auto& par : estudiantes) {
        std::cout << par.second.id << ": " << par.second.nombre << " " << par.second.apellido << std::endl;
    }
}

void SistemaCalificaciones::agregarAsignatura(int idEstudiante, const std::string& asignatura) {
    if (!estudiantes.count(idEstudiante)) {
        throw CalificacionesException("Estudiante no encontrado.");
    }
    auto& asignaturas = calificaciones[idEstudiante];
    if (asignaturas.count(asignatura)) {
        throw CalificacionesException("Asignatura ya existe para el estudiante.");
    }
    asignaturas[asignatura] = {};
}

void SistemaCalificaciones::agregarCalificacion(int idEstudiante, const std::string& asignatura, double nota) {
    if (!estudiantes.count(idEstudiante)) {
        throw CalificacionesException("Estudiante no encontrado.");
    }
    if (nota < 0.0 || nota > 10.0) {
        throw CalificacionesException("Nota inválida. Debe estar entre 0 y 10.");
    }
    auto& asignaturas = calificaciones[idEstudiante];
    if (!asignaturas.count(asignatura)) {
        throw CalificacionesException("Asignatura no encontrada para el estudiante.");
    }
    asignaturas[asignatura].push_back(nota);
}

void SistemaCalificaciones::mostrarCalificacionesEstudiante(int idEstudiante) const {
    auto itEst = estudiantes.find(idEstudiante);
    if (itEst == estudiantes.end()) {
        throw CalificacionesException("Estudiante no encontrado.");
    }

    auto itCal = calificaciones.find(idEstudiante);
    if (itCal == calificaciones.end()) {
        std::cout << "Sin calificaciones." << std::endl;
        return;
    }

    for (const auto& par : itCal->second) {
        std::cout << par.first << ": ";
        for (double nota : par.second) {
            std::cout << std::fixed << std::setprecision(1) << nota << " ";
        }
        std::cout << std::endl;
    }
}

void SistemaCalificaciones::mostrarPromedioGeneral(int idEstudiante) const {
    auto it = calificaciones.find(idEstudiante);
    if (it == calificaciones.end() || it->second.empty()) {
        std::cout << "Sin calificaciones para calcular el promedio." << std::endl;
        return;
    }

    double suma = 0.0;
    int cantidad = 0;
    for (const auto& par : it->second) {
        for (double nota : par.second) {
            suma += nota;
            cantidad++;
        }
    }

    if (cantidad == 0) {
        std::cout << "Sin calificaciones para calcular el promedio." << std::endl;
    } else {
        double promedio = suma / cantidad;
        std::cout << "Promedio de " << estudiantes.at(idEstudiante).nombre << ": "
                  << std::fixed << std::setprecision(2) << promedio << std::endl;
    }
}

void SistemaCalificaciones::mostrarMejoresEstudiantes() const {
    double mejorPromedio = -1.0;
    std::vector<int> mejores;

    for (const auto& par : calificaciones) {
        int id = par.first;
        double suma = 0.0;
        int total = 0;
        for (const auto& asig : par.second) {
            for (double nota : asig.second) {
                suma += nota;
                total++;
            }
        }

        if (total == 0) continue;

        double promedio = suma / total;

        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            mejores = { id };
        } else if (promedio == mejorPromedio) {
            mejores.push_back(id);
        }
    }

    for (int id : mejores) {
        const auto& est = estudiantes.at(id);
        std::cout << est.nombre << " " << est.apellido << " con promedio " << std::fixed << std::setprecision(2) << mejorPromedio << std::endl;
    }
}
