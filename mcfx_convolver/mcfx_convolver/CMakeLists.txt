SET ( SPECIFIC_SOURE_DIR ${SRC_DIR}/mcfx_convolver )
SET ( WITH_LIBSOXR TRUE )

SET(OSX_COPY_LIB libsoxr.0.1.0.dylib)

IF(WITH_ZITA_CONVOLVER)
	SET(OSX_COPY_LIB libfftw3f.3.dylib)
ENDIF(WITH_ZITA_CONVOLVER)

IF(WITH_ZITA_CONVOLVER OR NOT APPLE)
	SET ( WITH_FFTW3 TRUE )
ENDIF(WITH_ZITA_CONVOLVER OR NOT APPLE)

INCLUDE(${SRC_DIR}/CMakeLists_subprojects.txt.inc)
