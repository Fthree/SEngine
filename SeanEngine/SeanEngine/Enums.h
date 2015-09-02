#ifndef __ENUMS__
#define __ENUMS__

enum playerKeyPresses
{
	NO_KEY = -1,

	UP_KEY = 180,
	DOWN_KEY = 0,
	LEFT_KEY = 90,
	RIGHT_KEY = 270,

	UPRIGHT_KEY = 225,
	UPLEFT_KEY = 135,
	DOWNRIGHT_KEY = 315,
	DOWNLEFT_KEY = 45,
};

enum playerClick
{
	NO_CLICK = 400,
	LEFT_BTN = 401,
	RIGHT_BTN = 402
};

enum playerStates
{
	PLAYER_IDLE = 0,
	PLAYER_WALK = 1,
	PLAYER_ATTACK = 2,
	PLAYER_NOATTACK = 3,
	PLAYER_KILLED = 4
};

enum NPCStates
{
	NPC_NO_EVENT = 0,
	NPC_IS_IN_MOTION = 1,
	NPC_HAS_REACHED_GOAL = 2,
	NPC_KILLED = 3
};


enum AnimationInfo
{
	INBRIDGE,
	INBRIGEREV,
	ONANIM
};

enum AnimationStates
{
	NONE,
	CHANGING
};


#endif