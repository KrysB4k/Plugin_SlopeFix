
// FOR_YOU: here you can type your discoveries about tomb4 procedures
// if you mean use the C language to call them, you can create the
// prototypes of them like it has been done in the "DefTomb4Funct.h" file
// and "functions.h" file.
// While if you wish use only assembly code, you can type here
// the #define ADR_NOME_PROC 0x404040  to remember and use in the asm
// code all addresses of the tomb4 procedures

// TYPE_HERE: prototype (c++ language), mnemonic constants for 
// addresses (assembly)

typedef void (__cdecl *TYPE_ShiftItem) (Tr4ItemInfo *pItem, Tr4CollInfo *pCollision);
typedef int (__cdecl *TYPE_TestLaraSlide) (Tr4ItemInfo *pLara, Tr4CollInfo *pCollision);
typedef void (__cdecl *TYPE_lara_slide_slope) (Tr4ItemInfo *pLara, Tr4CollInfo *pCollision);
TYPE_ShiftItem ShiftItem = (TYPE_ShiftItem) 0x446700;
TYPE_TestLaraSlide TestLaraSlide = (TYPE_TestLaraSlide) 0x420CD0; 
TYPE_lara_slide_slope lara_slide_slope = (TYPE_lara_slide_slope) 0x428150; 

#define anims (*(Tr4AnimStruct**)0x533938)
#define move_angle (*(short*)0x80DF64)