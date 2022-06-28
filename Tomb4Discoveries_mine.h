
// FOR_YOU: here you can type your discoveries about tomb4 procedures
// if you mean use the C language to call them, you can create the
// prototypes of them like it has been done in the "DefTomb4Funct.h" file
// and "functions.h" file.
// While if you wish use only assembly code, you can type here
// the #define ADR_NOME_PROC 0x404040  to remember and use in the asm
// code all addresses of the tomb4 procedures

// TYPE_HERE: prototype (c++ language), mnemonic constants for 
// addresses (assembly)


typedef int (__cdecl *TYPE_TestLaraSlide) (Tr4ItemInfo *pLara, Tr4CollInfo *pCollision);
typedef void (__cdecl *TYPE_LaraSlideSlope) (Tr4ItemInfo *pLara, Tr4CollInfo *pCollision);
typedef void (__cdecl *TYPE_GetLaraCollisionInfo) (Tr4ItemInfo *pLara, Tr4CollInfo *pCollision);
typedef int (__cdecl *TYPE_TestWall) (Tr4ItemInfo *pItem, int Front, int Right, int Down);
typedef void (__cdecl *TYPE_LaraCollideStop) (Tr4ItemInfo *pLara, Tr4CollInfo *pCollision);
typedef void (__cdecl *TYPE_ShiftItem) (Tr4ItemInfo *pItem, Tr4CollInfo *pCollision);
typedef int (__cdecl *TYPE_CheckNoColFloorTriangle) (Tr4FloorInfo *floor, int x, int z);
typedef int (__cdecl *TYPE_CheckNoColCeilingTriangle) (Tr4FloorInfo *floor, int x, int z);
typedef int (__cdecl *TYPE_LaraHitCeiling) (Tr4ItemInfo *pLara, Tr4CollInfo *pCollision);
typedef int (__cdecl *TYPE_LaraDeflectEdge) (Tr4ItemInfo *pLara, Tr4CollInfo *pCollision);

TYPE_TestLaraSlide TestLaraSlide = (TYPE_TestLaraSlide) 0x420CD0; 
TYPE_LaraSlideSlope LaraSlideSlope = (TYPE_LaraSlideSlope) 0x428150; 
TYPE_GetLaraCollisionInfo GetLaraCollisionInfo = (TYPE_GetLaraCollisionInfo) 0x422180;
TYPE_TestWall TestWall = (TYPE_TestWall) 0x4226F0;
TYPE_LaraCollideStop LaraCollideStop = (TYPE_LaraCollideStop) 0x4227F0;
TYPE_ShiftItem ShiftItem = (TYPE_ShiftItem) 0x446700;
TYPE_CheckNoColFloorTriangle CheckNoColFloorTriangle = (TYPE_CheckNoColFloorTriangle) 0x44BEB0;
TYPE_CheckNoColCeilingTriangle CheckNoColCeilingTriangle = (TYPE_CheckNoColCeilingTriangle) 0x44BF60;
TYPE_LaraHitCeiling LaraHitCeiling = (TYPE_LaraHitCeiling) 0x4221C0;
TYPE_LaraDeflectEdge LaraDeflectEdge = (TYPE_LaraDeflectEdge) 0x422230;

#define floor_data (*(short**)0x533948)
#define anims (*(Tr4AnimStruct**)0x533938)
#define rooms (*(Tr4RoomInfo**)0x533934)
#define move_angle (*(short*)0x80DF64)