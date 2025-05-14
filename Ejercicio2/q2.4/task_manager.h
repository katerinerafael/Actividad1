#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class TareaException : public std::exception {
private:
    std::string mensaje;
public:
    explicit TareaException(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class Tarea {
public:
    enum Estado { PENDIENTE, EN_PROGRESO, COMPLETADA };

    int id;
    std::string titulo;
    std::string descripcion;
    int prioridad; // 1 (baja) a 5 (alta)
    Estado estado;

    Tarea(int id, const std::string& titulo, const std::string& descripcion, int prioridad);
    std::string obtenerEstadoComoTexto() const;
};

class GestorTareas {
private:
    std::vector<Tarea> tareas;
    int siguienteId;

public:
    GestorTareas();

    void agregarTarea(const std::string& titulo, const std::string& descripcion, int prioridad);
    void listarTareas() const;
    void actualizarEstado(int id, Tarea::Estado nuevoEstado);
    void eliminarTarea(int id);
    void filtrarPorEstado(Tarea::Estado estado) const;
};

#endif
