// Copyright DaiZengTao


#include "CDTLibrary.h"

void UCDTLibrary::RemoveDuplicates(TArray<FVector2D>& Vertices)
{
	std::vector<CDT::V2d<double>> cdtNewVertices = {};
	for (int i = 0; i < Vertices.Num(); i++)
	{
		cdtNewVertices.push_back(VECTOR_TO_CDT_V2D(Vertices[i]));
	}
	CDT::RemoveDuplicates(cdtNewVertices);
}
