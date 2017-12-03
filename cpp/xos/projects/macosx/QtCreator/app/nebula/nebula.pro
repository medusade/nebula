########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: nebula.pro
#
# Author: $author$
#   Date: 11/19/2017
#
# QtCreator .pro file for nebula executable nebula
########################################################################
include(../../../../../build/QtCreator/nebula.pri)
include(../../../../QtCreator/nebula.pri)
include(../../nebula.pri)
include(../../../../QtCreator/app/nebula/nebula.pri)

TARGET = $${nebula_exe_TARGET}


########################################################################
INCLUDEPATH += \
$${nebula_exe_INCLUDEPATH} \

DEFINES += \
$${nebula_exe_DEFINES} \

########################################################################
HEADERS += \
$${nebula_exe_HEADERS} \

SOURCES += \
$${nebula_exe_SOURCES} \

########################################################################
LIBS += \
$${nebula_exe_LIBS} \


