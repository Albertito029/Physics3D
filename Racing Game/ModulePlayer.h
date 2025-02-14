#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f
#define INITIAL_POS 380, 2, 0

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void CameraToPlayer();

	void MySetPos(vec3 newPos);
	void Respawn(vec3 respawn_pos);

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;

	float CarPosX;
	float CarPosZ;

	btTransform		newCarPos;
	vec3			initialCarPos;
	vec3			newCarDirection;
	vec3			newCameraPos;
	vec3			viewCar;

	int				laps = 0;
	int				laps_time = 0;
	int				lap_sec;
	int				lap_min;
	int				final_sec;
	int				final_min;
	char*			message;
	Timer			timer;
	Timer			LapTimer;

	bool			win = false;
	bool			lose = false;
	bool			lapCounted = false;

	mat4x4			initialPosMatrix;
};