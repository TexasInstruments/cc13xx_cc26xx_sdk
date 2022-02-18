/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-K04
 */

/*
 * ======== GENERATED SECTIONS ========
 *
 *     PROLOGUE
 *     INCLUDES
 *
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_heaps_HeapMem__include
#define ti_sysbios_heaps_HeapMem__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_heaps_HeapMem__top__
#endif

#ifndef __extern
#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif
#endif

#define ti_sysbios_heaps_HeapMem___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/heaps/package/package.defs.h>

#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/IGateProvider.h>
#include <ti/sysbios/heaps/package/HeapMem_Module_GateProxy.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* ExtendedStats */
struct ti_sysbios_heaps_HeapMem_ExtendedStats {
    xdc_Ptr buf;
    xdc_SizeT size;
};


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* Header */
struct ti_sysbios_heaps_HeapMem_Header {
    ti_sysbios_heaps_HeapMem_Header *next;
    xdc_runtime_Memory_Size size;
};

/* Instance_State */
typedef xdc_Char __T1_ti_sysbios_heaps_HeapMem_Instance_State__buf;
typedef xdc_Char *ARRAY1_ti_sysbios_heaps_HeapMem_Instance_State__buf;
typedef const xdc_Char *CARRAY1_ti_sysbios_heaps_HeapMem_Instance_State__buf;
typedef ARRAY1_ti_sysbios_heaps_HeapMem_Instance_State__buf __TA_ti_sysbios_heaps_HeapMem_Instance_State__buf;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_heaps_HeapMem_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsEnabled ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__diagsEnabled__CR
#define ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C (*((CT__ti_sysbios_heaps_HeapMem_Module__diagsEnabled*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__diagsEnabled (ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C)
#endif

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_heaps_HeapMem_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsIncluded ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__diagsIncluded__CR
#define ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C (*((CT__ti_sysbios_heaps_HeapMem_Module__diagsIncluded*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__diagsIncluded (ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C)
#endif

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_heaps_HeapMem_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsMask ti_sysbios_heaps_HeapMem_Module__diagsMask__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__diagsMask__CR
#define ti_sysbios_heaps_HeapMem_Module__diagsMask__C (*((CT__ti_sysbios_heaps_HeapMem_Module__diagsMask*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__diagsMask__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__diagsMask (ti_sysbios_heaps_HeapMem_Module__diagsMask__C)
#endif

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_heaps_HeapMem_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gateObj ti_sysbios_heaps_HeapMem_Module__gateObj__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__gateObj__CR
#define ti_sysbios_heaps_HeapMem_Module__gateObj__C (*((CT__ti_sysbios_heaps_HeapMem_Module__gateObj*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__gateObj__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__gateObj (ti_sysbios_heaps_HeapMem_Module__gateObj__C)
#endif

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_heaps_HeapMem_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gatePrms ti_sysbios_heaps_HeapMem_Module__gatePrms__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__gatePrms__CR
#define ti_sysbios_heaps_HeapMem_Module__gatePrms__C (*((CT__ti_sysbios_heaps_HeapMem_Module__gatePrms*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__gatePrms__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__gatePrms (ti_sysbios_heaps_HeapMem_Module__gatePrms__C)
#endif

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_heaps_HeapMem_Module__id;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module__id__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__id__CR
#define ti_sysbios_heaps_HeapMem_Module__id__C (*((CT__ti_sysbios_heaps_HeapMem_Module__id*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__id__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__id (ti_sysbios_heaps_HeapMem_Module__id__C)
#endif

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_heaps_HeapMem_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerDefined ti_sysbios_heaps_HeapMem_Module__loggerDefined__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__loggerDefined__CR
#define ti_sysbios_heaps_HeapMem_Module__loggerDefined__C (*((CT__ti_sysbios_heaps_HeapMem_Module__loggerDefined*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__loggerDefined__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__loggerDefined (ti_sysbios_heaps_HeapMem_Module__loggerDefined__C)
#endif

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_heaps_HeapMem_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerObj ti_sysbios_heaps_HeapMem_Module__loggerObj__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__loggerObj__CR
#define ti_sysbios_heaps_HeapMem_Module__loggerObj__C (*((CT__ti_sysbios_heaps_HeapMem_Module__loggerObj*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__loggerObj__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__loggerObj (ti_sysbios_heaps_HeapMem_Module__loggerObj__C)
#endif

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__loggerFxn0__CR
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C (*((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn0 (ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C)
#endif

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__loggerFxn1__CR
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C (*((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn1 (ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C)
#endif

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__loggerFxn2__CR
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C (*((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn2 (ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C)
#endif

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__loggerFxn4__CR
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C (*((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn4 (ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C)
#endif

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C;
#ifdef ti_sysbios_heaps_HeapMem_Module__loggerFxn8__CR
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C (*((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Module__loggerFxn8 (ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C)
#endif

/* Object__count */
typedef xdc_Int CT__ti_sysbios_heaps_HeapMem_Object__count;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__count ti_sysbios_heaps_HeapMem_Object__count__C;
#ifdef ti_sysbios_heaps_HeapMem_Object__count__CR
#define ti_sysbios_heaps_HeapMem_Object__count__C (*((CT__ti_sysbios_heaps_HeapMem_Object__count*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Object__count__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Object__count (ti_sysbios_heaps_HeapMem_Object__count__C)
#endif

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_heaps_HeapMem_Object__heap;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__heap ti_sysbios_heaps_HeapMem_Object__heap__C;
#ifdef ti_sysbios_heaps_HeapMem_Object__heap__CR
#define ti_sysbios_heaps_HeapMem_Object__heap__C (*((CT__ti_sysbios_heaps_HeapMem_Object__heap*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Object__heap__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Object__heap (ti_sysbios_heaps_HeapMem_Object__heap__C)
#endif

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_heaps_HeapMem_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__sizeof ti_sysbios_heaps_HeapMem_Object__sizeof__C;
#ifdef ti_sysbios_heaps_HeapMem_Object__sizeof__CR
#define ti_sysbios_heaps_HeapMem_Object__sizeof__C (*((CT__ti_sysbios_heaps_HeapMem_Object__sizeof*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Object__sizeof__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Object__sizeof (ti_sysbios_heaps_HeapMem_Object__sizeof__C)
#endif

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_heaps_HeapMem_Object__table;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__table ti_sysbios_heaps_HeapMem_Object__table__C;
#ifdef ti_sysbios_heaps_HeapMem_Object__table__CR
#define ti_sysbios_heaps_HeapMem_Object__table__C (*((CT__ti_sysbios_heaps_HeapMem_Object__table*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Object__table__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_Object__table (ti_sysbios_heaps_HeapMem_Object__table__C)
#endif

/* A_zeroBlock */
typedef xdc_runtime_Assert_Id CT__ti_sysbios_heaps_HeapMem_A_zeroBlock;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_A_zeroBlock ti_sysbios_heaps_HeapMem_A_zeroBlock__C;
#ifdef ti_sysbios_heaps_HeapMem_A_zeroBlock__CR
#define ti_sysbios_heaps_HeapMem_A_zeroBlock (*((CT__ti_sysbios_heaps_HeapMem_A_zeroBlock*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_A_zeroBlock__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_A_zeroBlock (ti_sysbios_heaps_HeapMem_A_zeroBlock__C)
#endif

/* A_heapSize */
typedef xdc_runtime_Assert_Id CT__ti_sysbios_heaps_HeapMem_A_heapSize;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_A_heapSize ti_sysbios_heaps_HeapMem_A_heapSize__C;
#ifdef ti_sysbios_heaps_HeapMem_A_heapSize__CR
#define ti_sysbios_heaps_HeapMem_A_heapSize (*((CT__ti_sysbios_heaps_HeapMem_A_heapSize*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_A_heapSize__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_A_heapSize (ti_sysbios_heaps_HeapMem_A_heapSize__C)
#endif

/* A_align */
typedef xdc_runtime_Assert_Id CT__ti_sysbios_heaps_HeapMem_A_align;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_A_align ti_sysbios_heaps_HeapMem_A_align__C;
#ifdef ti_sysbios_heaps_HeapMem_A_align__CR
#define ti_sysbios_heaps_HeapMem_A_align (*((CT__ti_sysbios_heaps_HeapMem_A_align*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_A_align__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_A_align (ti_sysbios_heaps_HeapMem_A_align__C)
#endif

/* E_memory */
typedef xdc_runtime_Error_Id CT__ti_sysbios_heaps_HeapMem_E_memory;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_E_memory ti_sysbios_heaps_HeapMem_E_memory__C;
#ifdef ti_sysbios_heaps_HeapMem_E_memory__CR
#define ti_sysbios_heaps_HeapMem_E_memory (*((CT__ti_sysbios_heaps_HeapMem_E_memory*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_E_memory__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_E_memory (ti_sysbios_heaps_HeapMem_E_memory__C)
#endif

/* A_invalidFree */
typedef xdc_runtime_Assert_Id CT__ti_sysbios_heaps_HeapMem_A_invalidFree;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_A_invalidFree ti_sysbios_heaps_HeapMem_A_invalidFree__C;
#ifdef ti_sysbios_heaps_HeapMem_A_invalidFree__CR
#define ti_sysbios_heaps_HeapMem_A_invalidFree (*((CT__ti_sysbios_heaps_HeapMem_A_invalidFree*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_A_invalidFree__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_A_invalidFree (ti_sysbios_heaps_HeapMem_A_invalidFree__C)
#endif

/* primaryHeapBaseAddr */
typedef xdc_Char *CT__ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C;
#ifdef ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__CR
#define ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr (*((CT__ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr (ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C)
#endif

/* primaryHeapEndAddr */
typedef xdc_Char *CT__ti_sysbios_heaps_HeapMem_primaryHeapEndAddr;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_primaryHeapEndAddr ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C;
#ifdef ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__CR
#define ti_sysbios_heaps_HeapMem_primaryHeapEndAddr (*((CT__ti_sysbios_heaps_HeapMem_primaryHeapEndAddr*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C_offset)))
#else
#define ti_sysbios_heaps_HeapMem_primaryHeapEndAddr (ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C)
#endif

/* reqAlign */
typedef xdc_SizeT CT__ti_sysbios_heaps_HeapMem_reqAlign;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapMem_reqAlign ti_sysbios_heaps_HeapMem_reqAlign__C;
#ifdef ti_sysbios_heaps_HeapMem_reqAlign__CR
#define ti_sysbios_heaps_HeapMem_reqAlign (*((CT__ti_sysbios_heaps_HeapMem_reqAlign*)(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_reqAlign__C_offset)))
#else
#ifdef ti_sysbios_heaps_HeapMem_reqAlign__D
#define ti_sysbios_heaps_HeapMem_reqAlign (ti_sysbios_heaps_HeapMem_reqAlign__D)
#else
#define ti_sysbios_heaps_HeapMem_reqAlign (ti_sysbios_heaps_HeapMem_reqAlign__C)
#endif
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_heaps_HeapMem_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_SizeT minBlockAlign;
    xdc_Ptr buf;
    xdc_runtime_Memory_Size size;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_heaps_HeapMem_Struct {
    const ti_sysbios_heaps_HeapMem_Fxns__ *__fxns;
    xdc_runtime_Memory_Size f0;
    __TA_ti_sysbios_heaps_HeapMem_Instance_State__buf f1;
    ti_sysbios_heaps_HeapMem_Header f2;
    xdc_SizeT f3;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_heaps_HeapMem_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Ptr (*alloc)(ti_sysbios_heaps_HeapMem_Handle inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb);
    xdc_Void (*free)(ti_sysbios_heaps_HeapMem_Handle inst, xdc_Ptr block, xdc_SizeT size);
    xdc_Bool (*isBlocking)(ti_sysbios_heaps_HeapMem_Handle inst);
    xdc_Void (*getStats)(ti_sysbios_heaps_HeapMem_Handle inst, xdc_runtime_Memory_Stats* stats);
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef ti_sysbios_heaps_HeapMem_Module__FXNS__CR

/* Module__FXNS__C */
__extern const ti_sysbios_heaps_HeapMem_Fxns__ ti_sysbios_heaps_HeapMem_Module__FXNS__C;
#else
#define ti_sysbios_heaps_HeapMem_Module__FXNS__C (*(xdcRomConstPtr + ti_sysbios_heaps_HeapMem_Module__FXNS__C_offset))
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_heaps_HeapMem_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Instance_init__E, "ti_sysbios_heaps_HeapMem_Instance_init")
__extern xdc_Void ti_sysbios_heaps_HeapMem_Instance_init__E(ti_sysbios_heaps_HeapMem_Object *obj, const ti_sysbios_heaps_HeapMem_Params *prms);

/* create */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_create, "ti_sysbios_heaps_HeapMem_create")
__extern ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_create( const ti_sysbios_heaps_HeapMem_Params *prms, xdc_runtime_Error_Block *eb);

/* construct */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_construct, "ti_sysbios_heaps_HeapMem_construct")
__extern void ti_sysbios_heaps_HeapMem_construct(ti_sysbios_heaps_HeapMem_Struct *obj, const ti_sysbios_heaps_HeapMem_Params *prms);

/* delete */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_delete, "ti_sysbios_heaps_HeapMem_delete")
__extern void ti_sysbios_heaps_HeapMem_delete(ti_sysbios_heaps_HeapMem_Handle *instp);

/* destruct */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_destruct, "ti_sysbios_heaps_HeapMem_destruct")
__extern void ti_sysbios_heaps_HeapMem_destruct(ti_sysbios_heaps_HeapMem_Struct *obj);

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Handle__label__S, "ti_sysbios_heaps_HeapMem_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_heaps_HeapMem_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab);

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Module__startupDone__S, "ti_sysbios_heaps_HeapMem_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_heaps_HeapMem_Module__startupDone__S( void);

/* Object__create__S */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Object__create__S, "ti_sysbios_heaps_HeapMem_Object__create__S")
__extern xdc_Ptr ti_sysbios_heaps_HeapMem_Object__create__S( xdc_CPtr aa, const xdc_UChar *pa, xdc_SizeT psz, xdc_runtime_Error_Block *eb);

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Object__delete__S, "ti_sysbios_heaps_HeapMem_Object__delete__S")
__extern xdc_Void ti_sysbios_heaps_HeapMem_Object__delete__S( xdc_Ptr instp);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Object__get__S, "ti_sysbios_heaps_HeapMem_Object__get__S")
__extern xdc_Ptr ti_sysbios_heaps_HeapMem_Object__get__S( xdc_Ptr oarr, xdc_Int i);

/* Object__first__S */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Object__first__S, "ti_sysbios_heaps_HeapMem_Object__first__S")
__extern xdc_Ptr ti_sysbios_heaps_HeapMem_Object__first__S( void);

/* Object__next__S */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Object__next__S, "ti_sysbios_heaps_HeapMem_Object__next__S")
__extern xdc_Ptr ti_sysbios_heaps_HeapMem_Object__next__S( xdc_Ptr obj);

/* Params__init__S */
xdc__CODESECT(ti_sysbios_heaps_HeapMem_Params__init__S, "ti_sysbios_heaps_HeapMem_Params__init__S")
__extern xdc_Void ti_sysbios_heaps_HeapMem_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz);

/* enter__E */
#define ti_sysbios_heaps_HeapMem_enter ti_sysbios_heaps_HeapMem_enter__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_enter__E, "ti_sysbios_heaps_HeapMem_enter")
__extern xdc_IArg ti_sysbios_heaps_HeapMem_enter__E( void);

/* leave__E */
#define ti_sysbios_heaps_HeapMem_leave ti_sysbios_heaps_HeapMem_leave__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_leave__E, "ti_sysbios_heaps_HeapMem_leave")
__extern xdc_Void ti_sysbios_heaps_HeapMem_leave__E( xdc_IArg key);

/* alloc__E */
#define ti_sysbios_heaps_HeapMem_alloc ti_sysbios_heaps_HeapMem_alloc__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_alloc__E, "ti_sysbios_heaps_HeapMem_alloc")
__extern xdc_Ptr ti_sysbios_heaps_HeapMem_alloc__E( ti_sysbios_heaps_HeapMem_Handle instp, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb);

/* allocUnprotected__E */
#define ti_sysbios_heaps_HeapMem_allocUnprotected ti_sysbios_heaps_HeapMem_allocUnprotected__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_allocUnprotected__E, "ti_sysbios_heaps_HeapMem_allocUnprotected")
__extern xdc_Ptr ti_sysbios_heaps_HeapMem_allocUnprotected__E( ti_sysbios_heaps_HeapMem_Handle instp, xdc_SizeT size, xdc_SizeT align);

/* free__E */
#define ti_sysbios_heaps_HeapMem_free ti_sysbios_heaps_HeapMem_free__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_free__E, "ti_sysbios_heaps_HeapMem_free")
__extern xdc_Void ti_sysbios_heaps_HeapMem_free__E( ti_sysbios_heaps_HeapMem_Handle instp, xdc_Ptr block, xdc_SizeT size);

/* freeUnprotected__E */
#define ti_sysbios_heaps_HeapMem_freeUnprotected ti_sysbios_heaps_HeapMem_freeUnprotected__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_freeUnprotected__E, "ti_sysbios_heaps_HeapMem_freeUnprotected")
__extern xdc_Void ti_sysbios_heaps_HeapMem_freeUnprotected__E( ti_sysbios_heaps_HeapMem_Handle instp, xdc_Ptr block, xdc_SizeT size);

/* isBlocking__E */
#define ti_sysbios_heaps_HeapMem_isBlocking ti_sysbios_heaps_HeapMem_isBlocking__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_isBlocking__E, "ti_sysbios_heaps_HeapMem_isBlocking")
__extern xdc_Bool ti_sysbios_heaps_HeapMem_isBlocking__E( ti_sysbios_heaps_HeapMem_Handle instp);

/* getStats__E */
#define ti_sysbios_heaps_HeapMem_getStats ti_sysbios_heaps_HeapMem_getStats__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_getStats__E, "ti_sysbios_heaps_HeapMem_getStats")
__extern xdc_Void ti_sysbios_heaps_HeapMem_getStats__E( ti_sysbios_heaps_HeapMem_Handle instp, xdc_runtime_Memory_Stats *stats);

/* restore__E */
#define ti_sysbios_heaps_HeapMem_restore ti_sysbios_heaps_HeapMem_restore__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_restore__E, "ti_sysbios_heaps_HeapMem_restore")
__extern xdc_Void ti_sysbios_heaps_HeapMem_restore__E( ti_sysbios_heaps_HeapMem_Handle instp);

/* getExtendedStats__E */
#define ti_sysbios_heaps_HeapMem_getExtendedStats ti_sysbios_heaps_HeapMem_getExtendedStats__E
xdc__CODESECT(ti_sysbios_heaps_HeapMem_getExtendedStats__E, "ti_sysbios_heaps_HeapMem_getExtendedStats")
__extern xdc_Void ti_sysbios_heaps_HeapMem_getExtendedStats__E( ti_sysbios_heaps_HeapMem_Handle instp, ti_sysbios_heaps_HeapMem_ExtendedStats *stats);

/* init__I */
#define ti_sysbios_heaps_HeapMem_init ti_sysbios_heaps_HeapMem_init__I
xdc__CODESECT(ti_sysbios_heaps_HeapMem_init__I, "ti_sysbios_heaps_HeapMem_init")
__extern xdc_Void ti_sysbios_heaps_HeapMem_init__I( void);

/* initPrimary__I */
#define ti_sysbios_heaps_HeapMem_initPrimary ti_sysbios_heaps_HeapMem_initPrimary__I
xdc__CODESECT(ti_sysbios_heaps_HeapMem_initPrimary__I, "ti_sysbios_heaps_HeapMem_initPrimary")
__extern xdc_Void ti_sysbios_heaps_HeapMem_initPrimary__I( void);


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_IHeap_Module ti_sysbios_heaps_HeapMem_Module_upCast(void);
static inline xdc_runtime_IHeap_Module ti_sysbios_heaps_HeapMem_Module_upCast(void)
{
    return (xdc_runtime_IHeap_Module)&ti_sysbios_heaps_HeapMem_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IHeap */
#define ti_sysbios_heaps_HeapMem_Module_to_xdc_runtime_IHeap ti_sysbios_heaps_HeapMem_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_IHeap_Handle ti_sysbios_heaps_HeapMem_Handle_upCast(ti_sysbios_heaps_HeapMem_Handle i);
static inline xdc_runtime_IHeap_Handle ti_sysbios_heaps_HeapMem_Handle_upCast(ti_sysbios_heaps_HeapMem_Handle i)
{
    return (xdc_runtime_IHeap_Handle)i;
}

/* Handle_to_xdc_runtime_IHeap */
#define ti_sysbios_heaps_HeapMem_Handle_to_xdc_runtime_IHeap ti_sysbios_heaps_HeapMem_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_Handle_downCast(xdc_runtime_IHeap_Handle i);
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_Handle_downCast(xdc_runtime_IHeap_Handle i)
{
    xdc_runtime_IHeap_Handle i2 = (xdc_runtime_IHeap_Handle)i;
    return ((const void*)i2->__fxns == (const void*)&ti_sysbios_heaps_HeapMem_Module__FXNS__C) ? (ti_sysbios_heaps_HeapMem_Handle)i : (ti_sysbios_heaps_HeapMem_Handle)NULL;
}

/* Handle_from_xdc_runtime_IHeap */
#define ti_sysbios_heaps_HeapMem_Handle_from_xdc_runtime_IHeap ti_sysbios_heaps_HeapMem_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_heaps_HeapMem_Module_startupDone() ti_sysbios_heaps_HeapMem_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_heaps_HeapMem_Object_heap() ti_sysbios_heaps_HeapMem_Object__heap__C

/* Module_heap */
#define ti_sysbios_heaps_HeapMem_Module_heap() ti_sysbios_heaps_HeapMem_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module_id(void);
static inline CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module_id( void ) 
{
    return ti_sysbios_heaps_HeapMem_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_heaps_HeapMem_Module_hasMask(void);
static inline xdc_Bool ti_sysbios_heaps_HeapMem_Module_hasMask(void)
{
    return (xdc_Bool)(ti_sysbios_heaps_HeapMem_Module__diagsMask__C != (CT__ti_sysbios_heaps_HeapMem_Module__diagsMask)NULL);
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_heaps_HeapMem_Module_getMask(void);
static inline xdc_Bits16 ti_sysbios_heaps_HeapMem_Module_getMask(void)
{
    return (ti_sysbios_heaps_HeapMem_Module__diagsMask__C != (CT__ti_sysbios_heaps_HeapMem_Module__diagsMask)NULL) ? *ti_sysbios_heaps_HeapMem_Module__diagsMask__C : (xdc_Bits16)0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_heaps_HeapMem_Module_setMask(xdc_Bits16 mask);
static inline xdc_Void ti_sysbios_heaps_HeapMem_Module_setMask(xdc_Bits16 mask)
{
    if (ti_sysbios_heaps_HeapMem_Module__diagsMask__C != (CT__ti_sysbios_heaps_HeapMem_Module__diagsMask)NULL) {
        *ti_sysbios_heaps_HeapMem_Module__diagsMask__C = mask;
    }
}

/* Params_init */
static inline void ti_sysbios_heaps_HeapMem_Params_init(ti_sysbios_heaps_HeapMem_Params *prms);
static inline void ti_sysbios_heaps_HeapMem_Params_init( ti_sysbios_heaps_HeapMem_Params *prms ) 
{
    if (prms != NULL) {
        ti_sysbios_heaps_HeapMem_Params__init__S(prms, NULL, sizeof(ti_sysbios_heaps_HeapMem_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_heaps_HeapMem_Params_copy(ti_sysbios_heaps_HeapMem_Params *dst, const ti_sysbios_heaps_HeapMem_Params *src);
static inline void ti_sysbios_heaps_HeapMem_Params_copy(ti_sysbios_heaps_HeapMem_Params *dst, const ti_sysbios_heaps_HeapMem_Params *src) 
{
    if (dst != NULL) {
        ti_sysbios_heaps_HeapMem_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_heaps_HeapMem_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_heaps_HeapMem_Object_count() ti_sysbios_heaps_HeapMem_Object__count__C

/* Object_sizeof */
#define ti_sysbios_heaps_HeapMem_Object_sizeof() ti_sysbios_heaps_HeapMem_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_Object_get(ti_sysbios_heaps_HeapMem_Object *oarr, int i);
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_Object_get(ti_sysbios_heaps_HeapMem_Object *oarr, int i) 
{
    return (ti_sysbios_heaps_HeapMem_Handle)ti_sysbios_heaps_HeapMem_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_Object_first(void);
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_Object_first(void)
{
    return (ti_sysbios_heaps_HeapMem_Handle)ti_sysbios_heaps_HeapMem_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_Object_next(ti_sysbios_heaps_HeapMem_Object *obj);
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_Object_next(ti_sysbios_heaps_HeapMem_Object *obj)
{
    return (ti_sysbios_heaps_HeapMem_Handle)ti_sysbios_heaps_HeapMem_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_heaps_HeapMem_Handle_label(ti_sysbios_heaps_HeapMem_Handle inst, xdc_runtime_Types_Label *lab);
static inline xdc_runtime_Types_Label *ti_sysbios_heaps_HeapMem_Handle_label(ti_sysbios_heaps_HeapMem_Handle inst, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_heaps_HeapMem_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_heaps_HeapMem_Handle_name(ti_sysbios_heaps_HeapMem_Handle inst);
static inline xdc_String ti_sysbios_heaps_HeapMem_Handle_name(ti_sysbios_heaps_HeapMem_Handle inst)
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_heaps_HeapMem_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_handle(ti_sysbios_heaps_HeapMem_Struct *str);
static inline ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_handle(ti_sysbios_heaps_HeapMem_Struct *str)
{
    return (ti_sysbios_heaps_HeapMem_Handle)str;
}

/* struct */
static inline ti_sysbios_heaps_HeapMem_Struct *ti_sysbios_heaps_HeapMem_struct(ti_sysbios_heaps_HeapMem_Handle inst);
static inline ti_sysbios_heaps_HeapMem_Struct *ti_sysbios_heaps_HeapMem_struct(ti_sysbios_heaps_HeapMem_Handle inst)
{
    return (ti_sysbios_heaps_HeapMem_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_heaps_HeapMem__top__
#undef __nested__
#endif

#endif /* ti_sysbios_heaps_HeapMem__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_heaps_HeapMem__internalaccess))

#ifndef ti_sysbios_heaps_HeapMem__include_state
#define ti_sysbios_heaps_HeapMem__include_state

/* Object */
struct ti_sysbios_heaps_HeapMem_Object {
    const ti_sysbios_heaps_HeapMem_Fxns__ *__fxns;
    xdc_runtime_Memory_Size align;
    __TA_ti_sysbios_heaps_HeapMem_Instance_State__buf buf;
    ti_sysbios_heaps_HeapMem_Header head;
    xdc_SizeT minBlockAlign;
};

#endif /* ti_sysbios_heaps_HeapMem__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_heaps_HeapMem__nolocalnames)

#ifndef ti_sysbios_heaps_HeapMem__localnames__done
#define ti_sysbios_heaps_HeapMem__localnames__done

/* module prefix */
#define HeapMem_Instance ti_sysbios_heaps_HeapMem_Instance
#define HeapMem_Handle ti_sysbios_heaps_HeapMem_Handle
#define HeapMem_Module ti_sysbios_heaps_HeapMem_Module
#define HeapMem_Object ti_sysbios_heaps_HeapMem_Object
#define HeapMem_Struct ti_sysbios_heaps_HeapMem_Struct
#define HeapMem_ExtendedStats ti_sysbios_heaps_HeapMem_ExtendedStats
#define HeapMem_Header ti_sysbios_heaps_HeapMem_Header
#define HeapMem_Instance_State ti_sysbios_heaps_HeapMem_Instance_State
#define HeapMem_A_zeroBlock ti_sysbios_heaps_HeapMem_A_zeroBlock
#define HeapMem_A_heapSize ti_sysbios_heaps_HeapMem_A_heapSize
#define HeapMem_A_align ti_sysbios_heaps_HeapMem_A_align
#define HeapMem_E_memory ti_sysbios_heaps_HeapMem_E_memory
#define HeapMem_A_invalidFree ti_sysbios_heaps_HeapMem_A_invalidFree
#define HeapMem_primaryHeapBaseAddr ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr
#define HeapMem_primaryHeapEndAddr ti_sysbios_heaps_HeapMem_primaryHeapEndAddr
#define HeapMem_reqAlign ti_sysbios_heaps_HeapMem_reqAlign
#define HeapMem_Params ti_sysbios_heaps_HeapMem_Params
#define HeapMem_enter ti_sysbios_heaps_HeapMem_enter
#define HeapMem_leave ti_sysbios_heaps_HeapMem_leave
#define HeapMem_alloc ti_sysbios_heaps_HeapMem_alloc
#define HeapMem_allocUnprotected ti_sysbios_heaps_HeapMem_allocUnprotected
#define HeapMem_free ti_sysbios_heaps_HeapMem_free
#define HeapMem_freeUnprotected ti_sysbios_heaps_HeapMem_freeUnprotected
#define HeapMem_isBlocking ti_sysbios_heaps_HeapMem_isBlocking
#define HeapMem_getStats ti_sysbios_heaps_HeapMem_getStats
#define HeapMem_restore ti_sysbios_heaps_HeapMem_restore
#define HeapMem_getExtendedStats ti_sysbios_heaps_HeapMem_getExtendedStats
#define HeapMem_Module_name ti_sysbios_heaps_HeapMem_Module_name
#define HeapMem_Module_id ti_sysbios_heaps_HeapMem_Module_id
#define HeapMem_Module_startup ti_sysbios_heaps_HeapMem_Module_startup
#define HeapMem_Module_startupDone ti_sysbios_heaps_HeapMem_Module_startupDone
#define HeapMem_Module_hasMask ti_sysbios_heaps_HeapMem_Module_hasMask
#define HeapMem_Module_getMask ti_sysbios_heaps_HeapMem_Module_getMask
#define HeapMem_Module_setMask ti_sysbios_heaps_HeapMem_Module_setMask
#define HeapMem_Object_heap ti_sysbios_heaps_HeapMem_Object_heap
#define HeapMem_Module_heap ti_sysbios_heaps_HeapMem_Module_heap
#define HeapMem_construct ti_sysbios_heaps_HeapMem_construct
#define HeapMem_create ti_sysbios_heaps_HeapMem_create
#define HeapMem_handle ti_sysbios_heaps_HeapMem_handle
#define HeapMem_struct ti_sysbios_heaps_HeapMem_struct
#define HeapMem_Handle_label ti_sysbios_heaps_HeapMem_Handle_label
#define HeapMem_Handle_name ti_sysbios_heaps_HeapMem_Handle_name
#define HeapMem_Instance_init ti_sysbios_heaps_HeapMem_Instance_init
#define HeapMem_Object_count ti_sysbios_heaps_HeapMem_Object_count
#define HeapMem_Object_get ti_sysbios_heaps_HeapMem_Object_get
#define HeapMem_Object_first ti_sysbios_heaps_HeapMem_Object_first
#define HeapMem_Object_next ti_sysbios_heaps_HeapMem_Object_next
#define HeapMem_Object_sizeof ti_sysbios_heaps_HeapMem_Object_sizeof
#define HeapMem_Params_copy ti_sysbios_heaps_HeapMem_Params_copy
#define HeapMem_Params_init ti_sysbios_heaps_HeapMem_Params_init
#define HeapMem_delete ti_sysbios_heaps_HeapMem_delete
#define HeapMem_destruct ti_sysbios_heaps_HeapMem_destruct
#define HeapMem_Module_upCast ti_sysbios_heaps_HeapMem_Module_upCast
#define HeapMem_Module_to_xdc_runtime_IHeap ti_sysbios_heaps_HeapMem_Module_to_xdc_runtime_IHeap
#define HeapMem_Handle_upCast ti_sysbios_heaps_HeapMem_Handle_upCast
#define HeapMem_Handle_to_xdc_runtime_IHeap ti_sysbios_heaps_HeapMem_Handle_to_xdc_runtime_IHeap
#define HeapMem_Handle_downCast ti_sysbios_heaps_HeapMem_Handle_downCast
#define HeapMem_Handle_from_xdc_runtime_IHeap ti_sysbios_heaps_HeapMem_Handle_from_xdc_runtime_IHeap

/* proxies */
#include <ti/sysbios/heaps/package/HeapMem_Module_GateProxy.h>

#endif /* ti_sysbios_heaps_HeapMem__localnames__done */
#endif
