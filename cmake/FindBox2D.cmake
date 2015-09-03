# Locate Box2D library 
# This module defines 
# Box2D_FOUND, if false, do not try to link to Box2D
# Box2D_LIBRARIES, the name of the library to link against
# Box2D_INCLUDE_DIRS, where to find Box2D headers
# 
# Created by Sven-Hendrik Haase. Based on the FindZLIB.cmake module.

IF(BOX2D_INCLUDE_DIR)
  # Already in cache, be silent
  SET(BOX2D_FIND_QUIETLY TRUE)
ENDIF(BOX2D_INCLUDE_DIR)

FIND_PATH(BOX2D_INCLUDE_DIR Box2D.h PATH_SUFFIXES include/Box2D include)

SET(BOX2D_NAMES box2d Box2d BOX2D Box2D)
FIND_LIBRARY(BOX2D_LIBRARY NAMES ${BOX2D_NAMES})
MARK_AS_ADVANCED(BOX2D_LIBRARY BOX2D_INCLUDE_DIR)

# Per-recommendation
SET(Box2D_INCLUDE_DIRS "${BOX2D_INCLUDE_DIR}")
SET(Box2D_LIBRARIES    "${BOX2D_LIBRARY}")

# handle the QUIETLY and REQUIRED arguments and set BOX2D_FOUND to TRUE if 
# all listed variables are TRUE

INCLUDE(FindPackageHandleStandardArgs) 
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Box2D DEFAULT_MSG Box2D_LIBRARIES Box2D_INCLUDE_DIRS) 
