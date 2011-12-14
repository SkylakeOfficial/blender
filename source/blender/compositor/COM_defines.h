/*
 * Copyright 2011, Blender Foundation.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor: 
 *		Jeroen Bakker 
 *		Monique Dewanchand
 */

#ifndef _COM_defines_h_
#define _COM_defines_h_

/**
  * @brief possible data types for SocketConnection
  * @ingroup Model
  */
typedef enum DataType {
	/** @brief Unknown data type (or not yet known) */
	COM_DT_UNKNOWN = 0,
	/** @brief Value data type */
	COM_DT_VALUE   = 1,
	/** @brief Vector data type */
	COM_DT_VECTOR  = 2,
	/** @brief Color data type */
	COM_DT_COLOR   = 4
} DataType;

/**
  * @brief Possible quality settings
  * @see CompositorContext.quality
  * @ingroup Execution
  */
typedef enum CompositorQuality {
	/** @brief High quality setting */
	COM_QUALITY_HIGH   = 0 ,
	/** @brief Medium quality setting */
	COM_QUALITY_MEDIUM = 1,
	/** @brief Low quality setting */
	COM_QUALITY_LOW    = 2
} CompositorQuality;

// configurable items

// chunk size determination
#define COM_PREVIEW_SIZE 140.0f
#define COM_OPENCL_ENABLED true
#define COM_PREVIEW_ENABLED true
// workscheduler threading models
/**
  * COM_TM_PTHREAD is a threading model based on pthread library. where the control (picking new work) is done by each thread
  */
#define COM_TM_PTHREAD 1

/**
  * COM_TM_NOTHREAD is a single threading model, everything is executed in the caller thread. easy for debugging
  */
#define COM_TM_NOTHREAD 2

/**
  * COM_CURRENT_THREADING_MODEL can be one of the above, COM_PTHREAD is currently default.
  */
#define COM_CURRENT_THREADING_MODEL COM_TM_PTHREAD


// chunk order
/**
  * @brief The order of chunks to be scheduled
  * @ingroup Execution
  */
typedef enum OrderOfChunks {
	/** @brief order from a distance to centerX/centerY */
	COM_TO_CENTER_OUT = 0,
	/** @brief order randomly */
	COM_TO_RANDOM = 1,
	/** @brief no ordering */
	COM_TO_TOP_DOWN = 2,
	/** @brief experimental ordering with 9 hotspots */
	COM_TO_RULE_OF_THIRDS = 3
} OrderOfChunks;

#define COM_RULE_OF_THIRDS_DIVIDER 100.0f
#define COM_MM_MAX_ALLOCATED_MEMORY 1*1024*1024*1024

#define COM_NUMBER_OF_CHANNELS 4
/**
  * enable the balancing of memory (saving MemoryBuffer to disc) to free memory
  */
#define COM_MM_ENABLE FALSE

#define COM_RM_NORMAL 0
#define COM_RM_LINEAR 1
#define COM_DEFAULT_RESOLUTION_WIDTH 640
#define COM_DEFAULT_RESOLUTION_HEIGHT 480

#endif
