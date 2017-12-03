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
#   File: libnebula.pri
#
# Author: $author$
#   Date: 11/19/2017
#
# QtCreator .pri file for nebula library libnebula
########################################################################

libnebula_TARGET = nebula

########################################################################
libnebula_INCLUDEPATH += \
$${nebula_INCLUDEPATH} \

libnebula_DEFINES += \
$${nebula_DEFINES} \

########################################################################
# nebula
libnebula_HEADERS += \
$${NADIR_SRC}/xos/base/Base.hpp \

libnebula_SOURCES += \
$${NADIR_SRC}/xos/base/Base.cpp \

########################################################################




