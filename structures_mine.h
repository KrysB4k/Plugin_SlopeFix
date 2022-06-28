// let below pragma directive at top of this source
#pragma pack(1)

// TYPE_HERE: here you can type your structure definitions like it has been done
// in the "structures.h" file for trng dll

// --------------- PRESET STRUCTURE ZONE -----------------------------
// Please, don't remove structures and fields you find in this "PRESET ZONE". They will be used by some
// preset functions of your plugin sources
// However, you can add new fields and structures in following structures, of course
typedef struct StrSavegameGlobalData {
	// FOR_YOU:
	// define here your variables that you wish were saved (and then restored) to/from savegame in GLOBAL section 
	//           (only one for all levels)
	// note: the size of this structure should be always even (if you add BYTE variable, remember to compensate that 
	//       with another BYTE vairable or placefolder)

	
}SavegameGlobalDataFields;

typedef struct StrSavegameLocalData {
	// FOR_YOU:
	// define here your variables that you wish were saved (and then restored) to/from savegame in LOCAL section (one for each different level)
	// note: the size of this structure should be always even (if you add BYTE variable, compensate it with another BYTE vairable or placefolder)

}SavegameLocalDataFields;


typedef struct StrSavegameData {
	StrSavegameGlobalData Global;
	StrSavegameLocalData  Local;
}SavegameDataFields;


typedef struct StrBaseAssignSlotMine {
	int TotAssign;
	StrRecordAssSlot VetAssignSlot[MAX_ASSIGN_SLOT_MINE];
}BaseAssignSlotMineFields;

typedef struct StrMyData {
	StrSavegameData Save;  // variable that it will be saved and restored to/from savegame
	// FOR_YOU:
	// define here all your global variables, i.e. those variables that will be seen from all procedures and keep 
	// their value between all cycles of the game.
	// after you defined a variabile like:
	// int  Alfa;
	// then you'll be able to access to them using syntax like:
	// MyData.Alfa = 3;
	// if (MyData.Alfa == 5) .
	int TotProgrActions;
	int LastProgrActionIndex; // used in case of overloading

	StrProgressiveAction VetProgrActions[MAX_MYPROGR_ACTIONS];
	StrBaseGenericCustomize BaseCustomizeMine;  // stored all your customize script commands for current level
	StrBaseGenericParameters BaseParametersMine; // store of all your parameters= script commands of current level
	StrBaseAssignSlotMine BaseAssignSlotMine; // stored all AssignSlot= command script commands of current level
}MyDataFields;
// ----------------- END PRESET STRUCTURE ZONE ---------------------------------------


typedef struct
{
	int x, y, z;
} phd_vector;


typedef struct
{
	int x_pos, y_pos, z_pos;
	short x_rot, y_rot, z_rot;
} phd_3dpos;


enum floor_types {
	FLOOR_TYPE, DOOR_TYPE, TILT_TYPE, ROOF_TYPE, TRIGGER_TYPE, LAVA_TYPE, CLIMB_TYPE, SPLIT1, SPLIT2, SPLIT3, SPLIT4,
	NOCOLF1T, NOCOLF1B, NOCOLF2T, NOCOLF2B, NOCOLC1T, NOCOLC1B, NOCOLC2T, NOCOLC2B,
	MONKEY_TYPE, TRIGTRIGGER_TYPE, MINER_TYPE
};


typedef struct
{
	WORD index;
	WORD box_flags;
	BYTE pit_room;
	char floor;
	BYTE sky_room;
	char ceiling;
}Tr4FloorInfo;


typedef struct
{
	short* data;
	short* door;

	Tr4FloorInfo* floor;

	void* light;
	void* mesh;

	int x;
	int y;
	int z;
	int minfloor;
	int maxceiling;

	short x_size;
	short y_size;

	int ambient;
	short num_lights;
	short num_meshes;

	BYTE ReverbType;
	BYTE FlipNumber;
	char MeshEffect;
	char bound_active;

	short left;
	short right;
	short top;
	short bottom;
	short test_left;
	short test_right;
	short test_top;
	short test_bottom;
	short item_number;
	short fx_number;
	short flipped_room;

	WORD flags;

	int nVerts;
	int nWaterVerts;
	int nShoreVerts;

	void* SourceVB;
	short* FaceData;

	float posx;
	float posy;
	float posz;

	void* vnormals;
	void* fnormals;
	int* prelight;
	int* prelightwater;

	int watercalc;

	void* verts;

	int gt3cnt;
	int gt4cnt;

	void* pclight;
}Tr4RoomInfo;


typedef struct
{
	short* frame_ptr;
	BYTE frame_rate;
	BYTE frame_size;

	short current_anim_state;

	int velocity;
	int acceleration;
	int Xvelocity;
	int Xacceleration;

	short frame_base;
	short frame_end;
	short jump_anim_num;
	short jump_frame_num;
	short number_changes;
	short change_index;
	short number_commands;
	short command_index;

}Tr4AnimStruct; // 28


typedef struct
{
	int mid_floor, mid_ceiling, mid_type;
	int front_floor, front_ceiling, front_type;
	int left_floor, left_ceiling, left_type;
	int right_floor, right_ceiling, right_type;
	int left_floor2, left_ceiling2, left_type2;
	int right_floor2, right_ceiling2, right_type2;

	int radius;
	int bad_pos, bad_neg, bad_ceiling;

	phd_vector shift, old;

	short old_anim_state;
	short old_anim_number;
	short old_frame_number;

	short facing;
	short quadrant;

	short coll_type;
	short* trigger;

	char tilt_x;
	char tilt_z;

	char hit_by_baddie;
	char hit_static;

	WORD slopes_are_walls : 2;
	WORD slopes_are_pits : 1;
	WORD lava_is_pit : 1;
	WORD enable_baddie_push : 1;
	WORD enable_spaz : 1;
	WORD hit_ceiling : 1;

}Tr4CollInfo; //86


typedef struct
{
	int floor;
	DWORD touch_bits;
	DWORD mesh_bits;
	short object_number;
	short current_anim_state;
	short goal_anim_state;
	short required_anim_state;
	short anim_number;
	short frame_number;
	short room_number;
	short next_item;
	short next_active;
	short speed;
	short fallspeed;
	short hit_points;
	WORD box_number;
	short timer;
	short flags;
	short shade;
	short trigger_flags;
	short carried_item;
	short after_death;
	WORD fired_weapon;
	short item_flags[4];
	void* data;
	phd_3dpos pos;
	BYTE lightdata[5528];
	DWORD active : 1;
	DWORD status : 2;
	DWORD gravity_status : 1;
	DWORD hit_status : 1;
	DWORD collidable : 1;
	DWORD looked_at : 1;
	DWORD dynamic_light : 1;
	DWORD poisoned : 1;
	DWORD ai_bits : 5;
	DWORD really_active : 1;
	DWORD InDrawRoom : 1;
	DWORD meshswap_meshbits;
	short draw_room;
	short TOSSPAD;

}Tr4ItemInfo; // 15F6

typedef struct
{
	short nmeshes;
	short mesh_index;
	int bone_index;

	short* frame_base;

	void (*initialise)(short item_number);
	void (*control)(short item_number);
	void (*floor)(Tr4ItemInfo* item, int x, int y, int z, int* height);
	void (*ceiling)(Tr4ItemInfo* item, int x, int y, int z, int* height);
	void (*draw_routine)(Tr4ItemInfo* item);
	void (*collision)(short item_num, Tr4ItemInfo* laraitem, Tr4CollInfo* coll);

	short object_mip;
	short anim_index;
	short hit_points;
	short pivot_length;
	short radius;
	short shadow_size;

	WORD bite_offset;
	WORD loaded : 1;
	WORD intelligent : 1;
	WORD non_lot : 1;
	WORD save_position : 1;
	WORD save_hitpoints : 1;
	WORD save_flags : 1;
	WORD save_anim : 1;
	WORD semi_transparent : 1;
	WORD water_creature : 1;
	WORD using_drawanimating_item : 1;
	WORD HitEffect : 2;
	WORD undead : 1;
	WORD save_mesh : 1;

	void (*draw_routine_extra)(Tr4ItemInfo* item);
	DWORD explodable_meshbits;
	DWORD pad;

}Tr4SlotInfo; // 40


struct SlopeTilts
{
	signed char tilt_x;
	signed char tilt_z;

	SlopeTilts(WORD tilts) : tilt_x(tilts&0xFF), tilt_z(tilts >> 8) {}
};


// let below pragma directive at bottom of this source
#pragma pack(2)