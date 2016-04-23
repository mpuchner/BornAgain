#################################################################################
#
#  BornAgain: simulate and fit scattering at grazing incidence
#
#  @file      cmake/modules/UnitTests
#  @brief     Implements function UNIT_TESTS(..)
#
#  @homepage  http://www.bornagainproject.org
#  @license   GNU General Public License v3 or higher (see COPYING)
#  @copyright Forschungszentrum Jülich GmbH 2016
#  @authors   Scientific Computing Group at MLZ Garching
#  @authors   J. Fisher, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
#
##################################################################################

#  @brief Compile tests given as .h files in SUBDIR, link with LINK_LIB, and execute

function(UNIT_TESTS TEST_NAME SUBDIR LINK_LIB)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    file(GLOB INCLUDE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${SUBDIR}/*.h")
    list(SORT INCLUDE_FILES)

    # Compose main program (C++ snippets plus #include's of test code from SUBDIR)
    file(READ "${CMAKE_MODULE_PATH}/unitTests.cpp.header" TMP)
    foreach(FILE ${INCLUDE_FILES})
        set(TMP "${TMP}#include \"${FILE}\"\n")
    endforeach()
    file(READ "${CMAKE_MODULE_PATH}/unitTests.cpp.footer" TMPTMP)
    set(TMP "${TMP}\n${TMPTMP}")
    set(TEST_SRC "_${TEST_NAME}.cpp")
    file(WRITE ${TEST_SRC} "${TMP}")

    set(EXE ${TEST_NAME})
    add_executable(${EXE} ${TEST_SRC})
    target_link_libraries(${EXE} gtest ${LINK_LIB})

    # build executable in lib directory,
    # to prevent problems with finding libBornAgainCore.dll under Windows
    set_property(TARGET ${EXE} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

    add_test(${TEST_NAME} ${EXE})

    # add execution of TestCore just after compilation
    add_custom_command(TARGET ${TEST_NAME} POST_BUILD COMMAND ${EXE})

endfunction()
