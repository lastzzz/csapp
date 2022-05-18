// include guards to prevnet double declaration of any identifiers
// such as types ,enums and static variables
#ifndef MEMORY_GUARD
#define MEMORY_GUARD

#include <stdint.h>
#include <header/cpu.h>


/*==============================================*/
/*          physical memory on dram chips       */
/* =============================================*/


// physical memory space is decided by the physical address
// in this simulator, there are 4 + 6 + 6 = 16 bit physical adderss
// then the physical space is (1 << 16) = 65536
// total 16 physical memory


#define PHYSICAL_MEMORY_SPACE (65536)
#define MAX_NUM_PHYSICAL_PAGE (16)    // 1 + MAX_INDEX_PHYSICAL_PAGE


// physical memory
// 16 physical memory pages
uint8_t pm[PHYSICAL_MEMORY_SPACE];





/*======================================*/
/*      memory R/W                      */
/*======================================*/

// used by instructions: read or write uint64_t to DRAM
uint64_t cpu_read64bits_dram(uint64_t paddr, core_t *cr);
void cpu_write64bits_dram(uint64_t paddr, uint64_t data, core_t *cr);
void cpu_readinst_dram(uint64_t paddr, char *buf, core_t *cr);
void cpu_writeinst_dram(uint64_t paddr, const char *str, core_t *cr);


void bus_read(uint64_t paddr, uint8_t *block);
void bus_write(uint64_t paddr, uint8_t *block);



#endif