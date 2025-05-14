#include "library_management.h"
#include <iostream>

Libro::Libro(int _id, std::string _titulo, std::string _autor, bool _disponible) {
    id = _id;
    titulo = _titulo;
    autor = _autor;
    disponible = _disponible;
}

void Biblioteca::agregarLibro(const Libro& libro) {
    for (const Libro& l : catalogo) {
        if (l.id == libro.id) {
            std::cout << "Error: El libro con ID " << libro.id << " ya existe.\n";
            return;
        }
    }
    catalogo.push_back(libro);
}

void Biblioteca::mostrarCatalogo() {
    for (const Libro& l : catalogo) {
        std::cout << "ID: " << l.id
                  << ", Titulo: " << l.titulo
                  << ", Autor: " << l.autor
                  << ", Estado: " << (l.disponible ? "Disponible" : "Prestado") << "\n";
    }
}

void Biblioteca::prestarLibro(int id) {
    for (Libro& l : catalogo) {
        if (l.id == id) {
            if (!l.disponible) {
                std::cout << "Error: El libro ya está prestado.\n";
                return;
            }
            l.disponible = false;
            std::cout << "Libro prestado correctamente.\n";
            return;
        }
    }
    std::cout << "Error: Libro no encontrado.\n";
}

void Biblioteca::devolverLibro(int id) {
    for (Libro& l : catalogo) {
        if (l.id == id) {
            if (l.disponible) {
                std::cout << "Error: El libro ya estaba disponible.\n";
                return;
            }
            l.disponible = true;
            std::cout << "Libro devuelto correctamente.\n";
            return;
        }
    }
    std::cout << "Error: Libro no encontrado.\n";
}

Libro Biblioteca::buscarPorId(int id) {
    for (const Libro& l : catalogo) {
        if (l.id == id) {
            return l;
        }
    }
    std::cout << "Error: Libro no encontrado.\n";
    return Libro(-1, "No encontrado", "Desconocido", false);
}

int Biblioteca::contarDisponibles() {
    int contador = 0;
    for (const Libro& l : catalogo) {
        if (l.disponible) {
            contador++;
        }
    }
    return contador;
}
