#include <iostream>
#include <vector>

/*
implementaciones básicas de la clase vector
un vector es como un arreglo pero con la posibilidad de manipularla
en tiempo de ejecución
*/

int main() {
    // 1. CREACIÓN E INICIALIZACIÓN
    // Constructor por defecto - crea vector vacío
    std::vector<int> vec;
    
    // Vector con tamaño inicial y valor por defecto
    std::vector<int> vec_sized(10, 5); // 10 elementos, todos con valor 5
    
    // Vector inicializado con lista
    std::vector<int> vec_init = {1, 2, 3, 4, 5};

    // 2. OPERACIONES DE INSERCIÓN
    // push_back() - Complejidad: O(1) amortizado
    std::cout << "=== INSERTANDO ELEMENTOS ===" << std::endl;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i); // Agrega 0, 1, 2, 3, 4
        std::cout << "Agregado: " << i << ", Tamaño: " << vec.size() 
                  << ", Capacidad: " << vec.capacity() << std::endl;
    }
    
    // 3. ACCESO A ELEMENTOS
    std::cout << "\n=== ACCESO A ELEMENTOS ===" << std::endl;
    
    // Acceso mediante índice (sin verificación de límites)
    std::cout << "Elementos del vector (operator[]): ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " "; // O(1) - acceso directo
    }
    std::cout << std::endl;

    // 4. ITERADORES
    std::cout << "\n=== USANDO ITERADORES ===" << std::endl;
    
    // Iterador tradicional
    std::cout << "Elementos (iterador tradicional): ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Iterador auto (C++11+)
    std::cout << "Elementos (auto iterator): ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Range-based for loop (C++11+)
    std::cout << "Elementos (range-based for): ";
    for (const auto& elemento : vec) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;

    // 5. INFORMACIÓN DE CAPACIDAD
    std::cout << "\n=== INFORMACIÓN DEL VECTOR ===" << std::endl;
    std::cout << "Tamaño actual: " << vec.size() << std::endl;
    std::cout << "Capacidad: " << vec.capacity() << std::endl;
    std::cout << "Tamaño máximo teórico: " << vec.max_size() << std::endl;
    std::cout << "¿Está vacío?: " << (vec.empty() ? "Sí" : "No") << std::endl;
    
    // 6. GESTIÓN DE CAPACIDAD
    std::cout << "\n=== GESTIÓN DE CAPACIDAD ===" << std::endl;
    size_t capacidad_inicial = vec.capacity();
    
    // reserve() - reserva espacio sin cambiar el tamaño
    vec.reserve(20);
    std::cout << "Después de reserve(20) - Tamaño: " << vec.size() 
              << ", Capacidad: " << vec.capacity() << std::endl;
    
    // resize() - cambia el tamaño del vector
    vec.resize(8); // Reduce a 8 elementos
    std::cout << "Después de resize(8) - Tamaño: " << vec.size() 
              << ", Capacidad: " << vec.capacity() << std::endl;

    // 7. MÉTODOS DE ACCESO ESPECÍFICOS
    std::cout << "\n=== MÉTODOS DE ACCESO ===" << std::endl;
    
    if (!vec.empty()) {
        // Acceso seguro con verificación de límites
        try {
            std::cout << "vec[2]: " << vec[2] << std::endl;                    // Acceso directo
            std::cout << "vec.at(3): " << vec.at(3) << std::endl;             // Acceso con verificación
            std::cout << "vec.front(): " << vec.front() << std::endl;         // Primer elemento
            std::cout << "vec.back(): " << vec.back() << std::endl;           // Último elemento
            
            // Acceso al array subyacente
            int* ptr = vec.data();
            std::cout << "Primer elemento via data(): " << *ptr << std::endl;
            
        } catch (const std::out_of_range& e) {
            std::cout << "Error de acceso: " << e.what() << std::endl;
        }
    }
    
    // 8. OPERACIONES DE MODIFICACIÓN AVANZADAS
    std::cout << "\n=== OPERACIONES AVANZADAS ===" << std::endl;
    
    // insert() - insertar en posición específica
    auto it_insert = vec.begin() + 2;
    vec.insert(it_insert, 99); // Inserta 99 en la posición 2
    
    std::cout << "Después de insertar 99 en posición 2: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // erase() - eliminar elemento específico
    auto it_erase = vec.begin() + 2;
    vec.erase(it_erase); // Elimina el elemento en posición 2
    
    std::cout << "Después de eliminar elemento en posición 2: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // 9. COMPARACIÓN DE RENDIMIENTO
    std::cout << "\n=== ANÁLISIS DE RENDIMIENTO ===" << std::endl;
    
    // Demostración del crecimiento de capacidad
    std::vector<int> vec_growth;
    std::cout << "Crecimiento de capacidad:" << std::endl;
    
    for (int i = 0; i < 10; ++i) {
        size_t old_capacity = vec_growth.capacity();
        vec_growth.push_back(i);
        size_t new_capacity = vec_growth.capacity();
        
        if (new_capacity != old_capacity) {
            std::cout << "Realocación: de " << old_capacity 
                      << " a " << new_capacity << " elementos" << std::endl;
        }
    }

    return 0;
}
