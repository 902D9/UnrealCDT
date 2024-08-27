// Copyright DaiZengTao

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CDT.h"
#include "CDTLibrary.generated.h"

#define VECTOR_TO_CDT_V2D(In) CDT::V2d<double>(In.X, In.Y)

UENUM(BlueprintType)
enum class ETriangulationType : uint8
{
	/**
	 * Produce a convex-hull
	 */
	EraseSuperTriangle UMETA(DisplayName="Erase Super Triangle"),
	/**
	 * Remove all outer triangles until a boundary defined by constraint edges
	 */
	EraseOuterTriangles UMETA(DisplayName="Erase Outer Triangles"),
	/**
	 * Remove outer triangles and automatically detected holes.
	 * Starts from super-triangle and traverses triangles until outer boundary.
	 * Triangles outside outer boundary will be removed.
	 * Then traversal continues until next boundary.
	 * Triangles between two boundaries will be kept.
	 * Traversal to next boundary continues (this time removing triangles).
	 * Stops when all triangles are traversed.
	 */
	EraseOuterTrianglesAndHoles UMETA(DisplayName="Erase Outer Triangles And Holes"),
};

/**
 * 
 */
UCLASS()
class UNREALCDT_API UCDTLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CDT")
	static void RemoveDuplicates(TArray<FVector2D>& Vertices);
	// UFUNCTION(BlueprintCallable, Category = "CDT")
	// static void RemapEdges(TArray<FVector>& Vertices);
	// UFUNCTION(BlueprintCallable, Category = "CDT")
	// static void RemoveDuplicatesAndRemapEdges(TArray<FVector>& Vertices);
	//
	// UFUNCTION(BlueprintCallable, Category = "CDT")
	// static void EraseSuperTriangle2D(TArray<FVector2D> Vertices, TArray<int32>& Triangles);
};
