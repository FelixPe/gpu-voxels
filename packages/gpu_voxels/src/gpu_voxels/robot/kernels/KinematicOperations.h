// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of the GPU Voxels Software Library.
//
// This program is free software licensed under the CDDL
// (COMMON DEVELOPMENT AND DISTRIBUTION LICENSE Version 1.0).
// You can find a copy of this license in LICENSE.txt in the top
// directory of the source code.
//
// © Copyright 2014 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Sebastian Klemm
 * \date    2012-09-13
 *
 */
//----------------------------------------------------------------------
#ifndef GPU_VOXELS_ROBOT_KERNELS_KINEMATIC_OPERATIONS_H_INCLUDED
#define GPU_VOXELS_ROBOT_KERNELS_KINEMATIC_OPERATIONS_H_INCLUDED

#include <cuda_runtime.h>
#include <gpu_voxels/helpers/cuda_datatypes.h>

namespace gpu_voxels {

/* kernels */

/*!  Transformations of PointClouds along a kinematic chain.
 *  The kernel has to be called for each joint within a chain
 *  and should be configured by
 *  point_cloud_sizes[joint_to_transform].
 *
 *  This way all points within a point cloud are transformed along the
 *  kinematic chain stored in dh_transformations up to joint_to_transform
 */
__global__
void kernelKinematicChainTransform(uint8_t chain_size, uint8_t joint_to_transform, const Matrix4f* basis_transformation,
                                   const Matrix4f* dh_transformations, const Matrix4f* local_transformations,
                                   const uint32_t* point_cloud_sizes, const Vector3f** point_clouds, Vector3f** transformed_point_clouds);

/*!
 * Same as kernelUpdateTransformations, but the Transformation is not computed inside the kernel *
 */
__global__
void kernelKinematicChainTransform(uint8_t joint_to_transform, const Matrix4f* transformation, const MetaPointCloudStruct *point_clouds, MetaPointCloudStruct *transformed_point_clouds);





/*! Transform one point along kinematic chain.
 * The kernel has to be called for each joint within a chain
 * and should be configured << 1, 1 >>
 */
__global__
void kernelTransformPoseAlongChain(uint8_t chain_size, uint8_t joint_to_transform,
                                   const Matrix4f* basis_transformation, Matrix4f* dh_transformations,
                                   Vector3f* dev_point, Vector3f* dev_result);

} // end of namespace gpu_voxels
#endif
