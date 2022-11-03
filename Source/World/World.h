/**
 *--------------------------------------------
 * World.h <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */

#pragma once

#include "Core/Math/Math.h"

struct FCamera
{
	FVector3    Position;
	FVector3    Target;
	float       AspectRatio;
	float       VerticalFOV;
};

struct FSphere
{
	FVector3    Position;
	float       Radius;
	uint32      MaterialIndex;
};

struct FPlane
{
	FVector3    Normal;
	float       Distance;
	uint32      MaterialIndex;
};

struct FMaterial
{
	uint8       AbstractMaterialData[12];
	uint32      MaterialTypeID;
};

struct FMaterialDefault
{
	FVector3    Color;
};

struct FWorld
{
	FCamera     Camera;

	FSphere*    Spheres;
	uint32      SphereCount;

	FPlane*     Planes;
	uint32      PlaneCount;

	FMaterial*  Materials;
	uint32      MaterialCount;
};