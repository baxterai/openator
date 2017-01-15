/*******************************************************************************
 * 
 * This file is part of BAIPROJECT.
 * 
 * BAIPROJECT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License version 3
 * only, as published by the Free Software Foundation.
 * 
 * BAIPROJECT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 * 
 * You should have received a copy of the GNU Affero General Public License
 * version 3 along with BAIPROJECT.  If not, see <http://www.gnu.org/licenses/>
 * for a copy of the AGPLv3 License.
 * 
 *******************************************************************************/

/*******************************************************************************
 *
 * File Name: ORmethod3DOD.h
 * Author: Richard Bruce Baxter - Copyright (c) 2005-2012 Baxter AI (baxterai.com)
 * Project: ATOR (Axis Transformation Object Recognition) Functions
 * Project Version: 3a12a 31-July-2012
 *
 *******************************************************************************/

#ifndef HEADER_OR_METHOD_3DOD
#define HEADER_OR_METHOD_3DOD

#include "ORpolygonList.h"
#include "RTviewinfo.h"
#include "ORglobalDefs.h"
#include "LDreferenceClass.h"
#include "ORfeature.h"

#define TRAIN_STRING ".train"
#define TEST_STRING ".test"

#define OR_SNAPSHOT_SCALE_FACTOR (10)	//10 looks good -  CHECK THIS - why is this not 1.0? I forget

//not currently used;
#ifndef USE_OPENGL
	//#define OR_CONSTANT_DISTANCE_EYE_TO_POLYGON_FOR_NN_SNAPSHOT_U_OPENGL (1.0);	//not used as orthogonal 3d viewport used
	#define OR_CONSTANT_DISTANCE_EYE_TO_POLYGON_FOR_NN_SNAPSHOT_U (25.0)
#endif


void transformObjectData3DOD(Reference * firstReferenceInInterpolated3DRGBMap, PolygonBAI * currentPolygonInList, int side, bool first, Feature * firstFeatureInList);

void calculateEyePositionAndOrientation3DOD(vec * eyeFacingPoly, vec * viewatFacingPoly, vec * viewupFacingPoly, vec * viewportWidthHeightDepth, PolygonBAI * pol, int side);


void create3DMeshUsingPointMap3DOD(int imageWidth, int imageHeight, double * pointMap, double * depthMap, unsigned char * rgbMap, MeshPoint * firstMeshPointInMeshList, MeshPoint * meshPointArray[], bool useEdgeZeroCrossingMap, int contrastValChosen, view_info * vi);

void createInterpolated3DMeshReferenceListUsingPointMap(int imageWidth, int imageHeight, double * pointMap, double * pointMapInterpolated, unsigned char * rgbMap, Reference * firstReferenceInInterpolated3DMap);


#ifdef OR_METHOD_3DOD_USE_OLD_TESTED_BUT_BASIC_FEATURE_DETECTION
bool generateFeatureList3DOD(view_info * vi, double * depthMap, double * pointMap, bool * depthContrastBooleanMap, bool * luminosityContrastBooleanMap, bool * luminosityContrastMapMinusDepthContrastMap, Feature * firstFeatureInList, int trainOrTest);

void reconcileFeaturesMap(int imageWidth, int imageHeight, bool * featuresBooleanMap);
void createFeaturesUsingBooleanMap(int imageWidth, int imageHeight, bool * booleanMap, bool * featuresUsingContrastMap, bool * featuresUsingContrastMapComplete, int maxDotProductResultXposArrayComplete[3][3][3], int maxDotProductResultYposArrayComplete[3][3][3], view_info * vi);
void createFeaturesUsingBooleanMapUsingDepthMap(int imageWidth, int imageHeight, bool * booleanMap, double * depthMap, bool * featuresUsingContrastMap, bool * featuresUsingContrastMapComplete, int maxDotProductResultXposArrayComplete[3][3][3], int maxDotProductResultYposArrayComplete[3][3][3], view_info * vi, double * pointMap);
void createFeaturesUsingBooleanMapUsingPointMap(int imageWidth, int imageHeight, bool * booleanMap, double * pointMap, bool * featuresUsingContrastMap, bool * featuresUsingContrastMapComplete, int maxDotProductResultXposArrayComplete[3][3][3], int maxDotProductResultYposArrayComplete[3][3][3]);
	//void createFeaturesUsingBooleanMap(int imageWidth, int imageHeight, bool * booleanMap, double * depthMap, bool * featuresUsingDepthContrastMap, bool * featuresUsingDepthContrastMapComplete);

void generateFeatureListUsingFeatureArrays(int imageWidth, int imageHeight, int maxDotProductResultXposArrayComplete[3][3][3], int maxDotProductResultYposArrayComplete[3][3][3], Feature * firstFeatureInList, view_info * vi);
void generateFeatureListUsingFeatureArraysUsingDepthMap(int imageWidth, int imageHeight, double * depthMap, int maxDotProductResultXposArrayComplete[3][3][3], int maxDotProductResultYposArrayComplete[3][3][3], Feature * firstFeatureInList, view_info * vi);
void generateFeatureListUsingFeatureArraysUsingPointMap(int imageWidth, int imageHeight, double * pointMap, int maxDotProductResultXposArrayComplete[3][3][3], int maxDotProductResultYposArrayComplete[3][3][3], Feature * firstFeatureInList);

#endif


#endif
