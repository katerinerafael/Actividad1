#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>

class CalificacionesException : public std::exception {
private:
    std::string mensaje;
public:
    explicit CalificacionesException(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

struct Estudiante {
    int id;
    std::string nombre;
    std::string apellido;

    Estudiante() : id(0), nombre(""), apellido("") {} // Constructor por defecto

    Estudiante(int id, const std::string& nombre, const std::string& apellido)
        : id(id), nombre(nombre), apellido(apellido) {}
};

class SistemaCalificaciones {
private:
    std::map<int, Estudiante> estudiantes;
    std::map<int, std::map<std::string, std::vector<double>>> calificaciones;

public:
    void agregarEstudiante(const Estudiante& estudiante);
    void eliminarEstudiante(int id);
    Estudiante buscarEstudiante(int id) const;
    void mostrarTodosLosEstudiantes() const;

    void agregarAsignatura(int idEstudiante, const std::string& asignatura);
    void agregarCalificacion(int idEstudiante, const std::string& asignatura, double nota);
    void mostrarCalificacionesEstudiante(int idEstudiante) const;
    void mostrarPromedioGeneral(int idEstudiante) const;
    void mostrarMejoresEstudiantes() const;
};

#endif
