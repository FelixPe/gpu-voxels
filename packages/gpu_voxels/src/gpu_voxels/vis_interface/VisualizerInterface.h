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
 * \author  Matthias Wagner
 * \date    2014-02-10
 *
 * \brief Contains some data structures, which are used for the visualization of an octree
 *       and the names of the used shared memory
 *
 */
//----------------------------------------------------------------------
#ifndef GPU_VOXELS_VISUALIZATION_OCTREEINTERFACE_H_INCLUDED
#define GPU_VOXELS_VISUALIZATION_OCTREEINTERFACE_H_INCLUDED

#include <gpu_voxels/helpers/cuda_datatypes.h>
#include <gpu_voxels/helpers/common_defines.h>

namespace gpu_voxels {
//namespace visualization {

// the names of the shared memory segments
static const std::string shm_segment_name_octrees = "OctreeSharedMemory";
static const std::string shm_segment_name_voxelmaps = "VoxelmapSharedMemory";
static const std::string shm_segment_name_primitive_array = "PrimitiveArraysSharedMemory";
static const std::string shm_segment_name_visualizer = "VisualizerSharedMemory";


// the names of the shared memory variables for the octrees
static const std::string shm_variable_name_octree_name = "octree_name_";
static const std::string shm_variable_name_octree_handler_dev_pointer = "octree_handler_dev_pointer_";
static const std::string shm_variable_name_occupancy_threshold = "octree_occupancy_threshold_";
static const std::string shm_variable_name_number_cubes = "octree_number_of_cubes_";
static const std::string shm_variable_name_buffer_swapped = "octree_buffer_swapped_";
static const std::string shm_variable_name_number_of_octrees = "number_of_octrees";

static const std::string shm_variable_name_super_voxel_size = "octree_super_voxel_size";
static const std::string shm_variable_name_view_start_voxel = "octree_view_start_voxel";
static const std::string shm_variable_name_view_end_voxel = "octree_view_end_voxel";

// the names of the shared memory variables for the voxel maps
static const std::string shm_variable_name_voxelmap_name = "voxel_map_name_";
static const std::string shm_variable_name_voxelmap_handler_dev_pointer = "voxel_map_handler_dev_pointer_";
static const std::string shm_variable_name_voxelmap_dimension = "voxel_map_dimensions_";
static const std::string shm_variable_name_voxel_side_length = "voxel_side_length_";
static const std::string shm_variable_name_voxelmap_data_changed = "voxel_map_data_changed_";
static const std::string shm_variable_name_voxelmap_type = "voxel_map_type_";
static const std::string shm_variable_name_number_of_voxelmaps = "number_of_voxelmaps";

// the names of the shared memory variables for the primitive arrays
static const std::string shm_variable_name_primitive_array_name = "prim_array_name_";
static const std::string shm_variable_name_primitive_array_handler_dev_pointer = "prim_array_handler_dev_pointer_";
static const std::string shm_variable_name_primitive_array_number_of_primitives = "prim_array_number_of_prims_";
static const std::string shm_variable_name_primitive_array_prim_diameter = "prim_array_prim_diameter_";
static const std::string shm_variable_name_primitive_array_data_changed = "prim_array_data_changed_";
static const std::string shm_variable_name_primitive_array_type = "prim_array_prim_type_";
static const std::string shm_variable_name_number_of_primitive_arrays = "number_of_prim_arrays"; // not yet in use!

// the names of the shared memory variables for the visualizer
static const std::string shm_variable_name_target_point = "target_point";
static const std::string shm_variable_name_set_draw_types = "toggle_draw_types";


struct Cube
{
  // Default constructor is needed
  __device__ __host__ Cube()
  {
    m_side_length = 0;
    m_position = Vector3ui(0);
    m_type = eVT_UNDEFINED;
  }

  __device__ __host__ Cube(uint32_t side_length, Vector3ui position, VoxelType type)
  {
    m_side_length = side_length;
    m_position = position;
    m_type = type;
  }
  // the length of the edges
  uint32_t m_side_length;
  // the position of the lower left front corner of the cube
  Vector3ui m_position;
  // the type of the cube
  VoxelType m_type;

};

struct DrawTypes
{
public:
  DrawTypes()
  {
    for(int i = 0; i < 256; ++i)
      draw_types[i] = 0;
  }
  uint8_t draw_types[256];
};

//} // end of namespace visualization
} // end of namespace gpu_voxels

#endif
