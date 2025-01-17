/* 
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

//#include "sys/alt_stdio.h"
#include <stdio.h>
#include <io.h>
#include <system.h>

int main(){

	printf("Start computing!\n");

	unsigned int from_acel = 0;

	//unsigned int req_leit = 512;	// req_leit = 1
	unsigned int address = 3;
	//unsigned int ack;
	//unsigned int dado_ptr;

	// requisita leitura (write implicito) e manda endere�o
	//IOWR(HANDSHAKE_MEMORY_0_BASE, 0, req_leit);
	IOWR(HANDSHAKE_MEMORY_0_BASE, 0, address);

	// espera bit[9] ack ligar
	while ((from_acel = IORD(HANDSHAKE_MEMORY_0_BASE, 0)) <= 128);
	//ack = (int)from_acel - 256;

	// baixa req leit
	//req_leit = 0;	// req_leit = 0
	//IOWR(HANDSHAKE_MEMORY_0_BASE, 0, );

	// espera bit[8] dado_ptr ligar

	//****
	//while ((from_acel = IORD(HANDSHAKE_MEMORY_0_BASE, 0)) <= 256);
	//****

	//****
	printf("Dado lido da memoria handshake: %u\n", (int)from_acel - 128);
	//****

	printf("End computing!\n");

	// ligar ack
	//ack = 256;	// ack = 1

	// esperar dado_ptr baixar
	//while ((from_acel = IORD(HANDSHAKE_MEMORY_0_BASE, 0)) < 128);

	// desligar ack
	//ack = 0;	// ack = 1
	//IOWR(HANDSHAKE_MEMORY_0_BASE, 0, ack);

	//unsigned int Op2 = 3;

	//unsigned int from_acel = 0;

	//printf("Start computing!\n");

	//IOWR(MULTCOMBWITHRESET_0_BASE, 0, Op1);

	//IOWR(MULTCOMBWITHRESET_0_BASE, 0, Op2);

	//while ((from_acel = IORD(MULTCOMBWITHRESET_0_BASE, 0)) < 128);

	//unsigned int respWithoutMSB = (int)from_acel - 128;
				   //respWithoutMSB = respWithoutMSB & 255;
	//unsigned int respWithMSB 	  = from_acel & 255;

	//printf("Complete (32 bits) final result from accelerator: %u\n", from_acel);
	//printf("8 bit result (DataReady & multiplier output): %u\n", respWithMSB);
	//printf("7 bit result (only multiplier output): %u\n", respWithoutMSB);
	return 0;

}
