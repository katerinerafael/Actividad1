#include "stocktaking.h"

// Constructor de Producto
Producto::Producto(int _id, std::string _nombre, double _precio, int _cantidad, Categoria _categoria)
    : id(_id), nombre(_nombre), precio(_precio), cantidad(_cantidad), categoria(_categoria) {}

// Agrega un producto, revisando errores básicos
void Inventario::agregarProducto(const Producto& producto) {
    for (const auto& p : productos) {
        if (p.id == producto.id) {
            throw InventarioException("ID duplicado.");
        }
    }
    if (producto.precio < 0) {
        throw InventarioException("Precio negativo.");
    }
    productos.push_back(producto);
}

// Muestra todos los productos
void Inventario::mostrarInventario() {
    for (const auto& p : productos) {
        std::cout << "ID: " << p.id << ", Nombre: " << p.nombre
                  << ", Precio: $" << p.precio << ", Cantidad: " << p.cantidad << std::endl;
    }
}

// Muestra productos según su categoría
void Inventario::mostrarPorCategoria(Categoria categoria) {
    for (const auto& p : productos) {
        if (p.categoria == categoria) {
            std::cout << "ID: " << p.id << ", Nombre: " << p.nombre
                      << ", Precio: $" << p.precio << ", Cantidad: " << p.cantidad << std::endl;
        }
    }
}

// Calcula el valor total del inventario (precio * cantidad de cada producto)
double Inventario::calcularValorTotal() {
    double total = 0;
    for (const auto& p : productos) {
        total += p.precio * p.cantidad;
    }
    return total;
}

// Cambia la cantidad de un producto
void Inventario::actualizarCantidad(int id, int nuevaCantidad) {
    for (auto& p : productos) {
        if (p.id == id) {
            p.cantidad = nuevaCantidad;
            return;
        }
    }
    throw InventarioException("Producto no encontrado.");
}

// Cambia el precio de un producto
void Inventario::actualizarPrecio(int id, double nuevoPrecio) {
    for (auto& p : productos) {
        if (p.id == id) {
            p.precio = nuevoPrecio;
            return;
        }
    }
    throw InventarioException("Producto no encontrado.");
}

// Elimina un producto del inventario
void Inventario::eliminarProducto(int id) {
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->id == id) {
            productos.erase(it);
            return;
        }
    }
    throw
