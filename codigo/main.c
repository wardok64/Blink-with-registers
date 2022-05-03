/*
 * Eduardo Martinez
 * Diseno con microcontroladores
 * Catedratico : Jose Luis Pizano Escalante.
 * Diplomado: Programacion y pruebas para procesadores.
 * CINVESTAV 2022.
 */
#include <stdint.h>
#include "MK64F12.h"

int main(void) {

		SIM->SCGC5 = 0x2400; // inicializamos la senal de reloj para el puerto B y E

		PORTB->PCR[21] = 0x00000100; // establecemos el bit 21 del puerto B como funcion GPIO
		PORTB->PCR[22] = 0x00000100;
		PORTE->PCR[26] = 0x00000100;

		GPIOB->PDDR = 0x00600000; // establecemos el bit 21 y 22 del puerto B como salidas GPIO
		GPIOB->PDOR = 0xFFFFFFF; // escribimos un valor alto en todos los bits del puerto B
		//(Esto apaga los leds asociados al puerto B, debido a la logica inversa)

		GPIOE->PDDR = 0x04000000;// establecemos el bit 26 del puerto E como salida GPIO
		GPIOE->PDOR = 0xFFFFFFF;// esbribimos un 1 logico, en todos los bits del puerto E
		//(Esto apaga los leds asociados al puerto E, debido a la logica inversa)

		// LEDs K64
		// 1 logico -  apaga el LED.
		// 0 logico -  enciende el LED.


    while(1) { // buble o ciclo infinito


    			GPIOB->PDOR &= ~(0x00200000); //Manipulacion del puerto mediante mascaras
    			// 0x00200000 a binario es: 1 en el bit 21 (corresponde al led azul),
    			// luego negamos bit a bit con ~
    			// lo cual nos quedan todos los bits en 1 y el bit 21 en 0
    			// enmascaramos con & para cambiar de estado solo los bits que son
    			// diferentes al estado anterior, esto pone un 0 logico en el pin 21 del puerto B
    			// fisicamente se enciente el led azul asociado al pin GPIO.

    			GPIOB->PDOR |= 0x00200000; // Manipulacion del puerto mediante mascaras.
    			// Aqui utilizamos el OR bit a bit, o bitwise, nos permite poner un valor 1 en una
    			// posicion de un conjunto de bits que tenga un valor
    			// cero en el estado anterior y el resto de los bits que sean 0 y 1 se mantienen.
    			// es decir apagamos el led azul.

    			GPIOB->PDOR &= ~(0x00400000); //Manipulacion del puerto mediante mascaras
    			// 0x00200000 a binario es: 1 en el bit 22 (corresponde al led rojo),
    			// luego negamos bit a bit con ~
    			// lo cual nos quedan todos los bits en 1 y el bit 22 en 0
    			// enmascaramos con & para cambiar de estado solo los bits que son
    			// diferentes al estado anterior, esto pone un 0 logico en el pin 22 del puerto B
    			// fisicamente se enciente el led azul asociado al pin GPIO.

    			GPIOB->PDOR |= 0x00400000;// Manipulacion del puerto mediante mascaras.
    			// Aqui utilizamos el OR bit a bit, o bitwise, nos permite poner un valor 1 en una
    			// posicion de un conjunto de bits que tenga un valor
    			// cero en el estado anterior y el resto de los bits que sean 0 y 1 se mantienen.
    			// es decir apagamos el led rojo.


    			GPIOE -> PDOR = 0X00; // manipulacion del puerto
    			// escribimos en todos los bits del puerto E un valor logico 0
    			// esto encendera el LED verde, que se ubica en el puerto E
    			// NOTA: debemos tener cuidado, ya que esta instruccion, va a poner en 0
    			// todos los bits del puerto E.
    			GPIOE -> PDOR = 0X4000000;
    			// Escribimos un 1 logico en el bit 26 del puerto E
    			// esta instruccion apagara el led verde que se encuentra en esa direccion.
    			//NOTA: tambien estamos sobre-escribiendo nuevamente un valor logico 0 en
    			// el resto de los bits del puerto E.

    }
    return 0 ;
}


