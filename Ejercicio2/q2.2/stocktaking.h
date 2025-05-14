#ifndef STOCKTAKING_H
#define STOCKTAKING_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

// Enumeración para categorizar productos
enum class Categoria {
    ELECTRONICA,
    ROPA,
    ALIMENTOS,
    HOGAR
};

// Clase para representar errores del inventario
class InventarioException : public std::runtime_error {
public:
    InventarioException(const std::string& mensaje) : std::runtime_error(mensaje) {}
};

// Estructura para representar un producto
struct Producto {
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    Categoria categoria;

    Producto(int _id, std::string _nombre, double _precio, int _cantidad, Categoria _categoria);
};

// Clase para manejar la lista de productos
class Inventario {
private:
    std::vector<Producto> productos;

public:
    void agregarProducto(const Producto& producto);
    void mostrarInventario();
    void mostrarPorCategoria(Categoria categoria);
    double calcularValorTotal();
    void actualizarCantidad(int id, int nuevaCantidad);
    void actualizarPrecio(int id, double nuevoPrecio);
    void eliminarProducto(int id);
    Producto buscarPorId(int id);
};

#endif
