#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

test_compra_con_descuento() {
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200,  3};  /* 200 x 3 = 600 */
    carrito_agregar(&c, p);
    Producto l = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    carrito_agregar(&c, l);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

test_agregar_hasta_llenar(){
    printf("\n[agregar productos hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};
    for(int i= 0; i < MAX_ITEMS; i++){
        carrito_agregar(&c, p);
    }
    ASSERT_VERDADERO(carrito_contar(&c) == MAX_ITEMS);
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    ASSERT_VERDADERO(carrito_contar(&c) == MAX_ITEMS);
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
