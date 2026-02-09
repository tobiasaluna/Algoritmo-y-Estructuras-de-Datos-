void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Inicializar el mayor como raíz
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Si el hijo izquierdo es mayor que la raíz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Si el hijo derecho es mayor que el mayor hasta ahora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si el mayor no es la raíz
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Recursivamente heapificar el subárbol afectado
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Construir heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        // Mover la raíz actual al final
        std::swap(arr[0], arr[i]);
        // Llamar heapify en el heap reducido
        heapify(arr, i, 0);
    }
}
