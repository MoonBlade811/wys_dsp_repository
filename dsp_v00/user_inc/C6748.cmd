/****************************************************************************/
/*  C6748.cmd                                                               */
/*  Copyright (c) 2010 Texas Instruments Incorporated                       */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on a C6748               */
/*                 device.  Use it as a guideline.  You will want to        */
/*                 change the memory layout to match your specific C6xxx    */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/

-stack 0x1000    /* Software Stack Size */
-heap 0x1000     /* Heap Area Size */

MEMORY
{
    DSPL2ROM     o = 0x00700000  l = 0x00100000   /* 1MB L2 Internal ROM */
    //DSPL2RAM     o = 0x00800000  l = 0x00040000   /* 256kB L2 Internal RAM */
    DSPL2RAM     o = 0x00800000  l = 0x00038000   /* 224kB L2 Internal RAM */
    DSPL2CACHE   o = 0x00838000  l = 0x00008000   /* 32kB L2 Internal CACHE */
    DSPL1PRAM    o = 0x00E00000  l = 0x00008000   /* 32kB L1 Internal Program RAM */
    DSPL1DRAM    o = 0x00F00000  l = 0x00008000   /* 32kB L1 Internal Data RAM */
    SHDSPL2ROM   o = 0x11700000  l = 0x00100000   /* 1MB L2 Shared Internal ROM */
    SHDSPL2RAM   o = 0x11800000  l = 0x00040000   /* 256kB L2 Shared Internal RAM */
    SHDSPL1PRAM  o = 0x11E00000  l = 0x00008000   /* 32kB L1 Shared Internal Program RAM */
    SHDSPL1DRAM  o = 0x11F00000  l = 0x00008000   /* 32kB L1 Shared Internal Data RAM */
    EMIFACS0     o = 0x40000000  l = 0x20000000   /* 512MB SDRAM Data (CS0) */
    EMIFACS2     o = 0x60000000  l = 0x02000000   /* 32MB Async Data (CS2) */
    EMIFACS3     o = 0x62000000  l = 0x02000000   /* 32MB Async Data (CS3) */
    EMIFACS4     o = 0x64000000  l = 0x02000000   /* 32MB Async Data (CS4) */
    EMIFACS5     o = 0x66000000  l = 0x02000000   /* 32MB Async Data (CS5) */
    SHRAM        o = 0x80000000  l = 0x00020000   /* 128kB Shared RAM */
    DDR2         o = 0xC0000000  l = 0x06000000   /* 96MB DDR2 */
    DDR2_DATA    o = 0xC6000000  l = 0x02000000   /* 32MB DDR2 */
}                                              

SECTIONS                                       
{
    /* COFF sections */
    .cinit         >  DSPL2RAM    /* Initialization Tables */
    .pinit         >  DSPL2RAM    /* Constructor Tables */

    /* EABI sections */
    .binit         >  DSPL2RAM    /* Boot Tables */
    .init_array    >  DSPL2RAM
    GROUP (NEARDP_DATA)       /* group near data */
    {
       .neardata
       .rodata
       .bss                   /* note: removed fill = 0 */
    }              >  DSPL2RAM
    .far: fill = 0x0, load > DSPL2RAM    /* Far Global & Static Variables */
    .fardata       >  DSPL2RAM    /* Far RW Data */
    .c6xabi.exidx  >  DSPL2RAM
    .c6xabi.extab  >  DSPL2RAM

    .text          >  DSPL2RAM
    .text:_c_int00: align=1024 > DSPL2RAM    /* Entrypoint */
    .stack         >  DSPL2RAM    /* Software System Stack */
    .cio           >  DSPL2RAM    /* C I/O Buffer */
    .const         >  DSPL2RAM    /* Constant Data */
    .data          >  DSPL2RAM
    .switch        >  DSPL2RAM    /* Jump Tables */
    .sysmem        >  DSPL2RAM    /* Dynamic Memory Allocation Area */
    .vecs          >  DSPL2RAM    /* Interrupt Vectors */
    .args          >  DSPL2RAM
    .ppinfo        >  DSPL2RAM
    .ppdata        >  DSPL2RAM

    mvb_prog       >  DSPL2RAM
    logic_prog     >  DSPL2RAM
    ddr2_data      >  DSPL2RAM
}



