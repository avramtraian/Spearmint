/**
 *--------------------------------------------
 * Renderer.h <-> Spearmint
 *--------------------------------------------
 * Copyright (c) to Avram Traian. 2022 - 2022.
 * File created on November 2 2022.
 */
#pragma once

#include "Core/Math/Math.h"
#include "World/World.h"

struct FImage
{
	uint32* Pixels;
	uint32  Width;
	uint32  Height;
};

class FRenderer
{
private:
	struct FCameraData
	{
		FVector3 AxisX;
		FVector3 AxisY;
		FVector3 AxisZ;
		float    FilmWidth;
		float    FilmHeight;
		FVector3 FilmCenter;
	};

	struct FHitPayload
	{
		uint32   ObjectIndex;
		float    HitDistance;
		FVector3 WorldPosition;
		FVector3 WorldNormal;
		uint32   MaterialIndex;
	};

public:
	FRenderer();

	void SetWorld(const FWorld* InWorld);
	void SetImageTarget(const FImage* InImageTarget);

public:
	void Render();

private:
	FVector4 PerPixel(uint32 PixelX, uint32 PixelY);

	FHitPayload TraceRay(const FRay& Ray);

	FHitPayload ClosestHit(const FRay& Ray, float HitDistance, uint32 ObjectIndex);

	FHitPayload Miss(const FRay& Ray);

private:
	const FWorld* World;
	const FImage* ImageTarget;
	FCameraData   CameraData;
};