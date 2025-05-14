#include "task_manager.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Tarea::Tarea(int id, const std::string& titulo, const std::string& descripcion, int prioridad)
    : id(id), titulo(titulo), descripcion(descripcion), prioridad(prioridad), estado(PENDIENTE) {
    if (prioridad < 1 || prioridad > 5) {
        throw TareaException("La prioridad debe estar entre 1 y 5.");
    }
}

std::string Tarea::obtenerEstadoComoTexto() const {
    switch (estado) {
        case PENDIENTE: return "Pendiente";
        case EN_PROGRESO: return "En Progreso";
        case COMPLETADA: return "Completada";
        default: return "Desconocido";
    }
}

GestorTareas::GestorTareas() : siguienteId(1) {}

void GestorTareas::agregarTarea(const std::string& titulo, const std::string& descripcion, int prioridad) {
    tareas.emplace_back(siguienteId++, titulo, descripcion, prioridad);
    std::cout << "Tarea agregada exitosamente." << std::endl;
}

void GestorTareas::listarTareas() const {
    if (tareas.empty()) {
        std::cout << "No hay tareas registradas." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(20) << "Título"
              << std::setw(30) << "Descripción"
              << std::setw(10) << "Prioridad"
              << std::setw(15) << "Estado" << std::endl;

    for (const auto& tarea : tareas) {
        std::cout << std::left << std::setw(5) << tarea.id
                  << std::setw(20) << tarea.titulo
                  << std::setw(30) << tarea.descripcion
                  << std::setw(10) << tarea.prioridad
                  << std::setw(15) << tarea.obtenerEstadoComoTexto() << std::endl;
    }
}

void GestorTareas::actualizarEstado(int id, Tarea::Estado nuevoEstado) {
    auto it = std::find_if(tareas.begin(), tareas.end(), [id](const Tarea& t) { return t.id == id; });

    if (it == tareas.end()) {
        throw TareaException("Tarea no encontrada.");
    }

    it->estado = nuevoEstado;
    std::cout << "Estado actualizado exitosamente." << std::endl;
}

void GestorTareas::eliminarTarea(int id) {
    auto it = std::remove_if(tareas.begin(), tareas.end(), [id](const Tarea& t) { return t.id == id; });

    if (it == tareas.end()) {
        throw TareaException("Tarea no encontrada.");
    }

    tareas.erase(it, tareas.end());
    std::cout << "Tarea eliminada exitosamente." << std::endl;
}

void GestorTareas::filtrarPorEstado(Tarea::Estado estado) const {
    bool encontrado = false;

    for (const auto& tarea : tareas) {
        if (tarea.estado == estado) {
            if (!encontrado) {
                std::cout << std::left << std::setw(5) << "ID"
                          << std::setw(20) << "Título"
                          << std::setw(30) << "Descripción"
                          << std::setw(10) << "Prioridad"
                          << std::setw(15) << "Estado" << std::endl;
                encontrado = true;
            }

            std::cout << std::left << std::setw(5) << tarea.id
                      << std::setw(20) << tarea.titulo
                      << std::setw(30) << tarea.descripcion
                      << std::setw(10) << tarea.prioridad
                      << std::setw(15) << tarea.obtenerEstadoComoTexto() << std::endl;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron tareas con ese estado." << std::endl;
    }
}
