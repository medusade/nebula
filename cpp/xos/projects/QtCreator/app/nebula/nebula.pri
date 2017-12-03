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
#   File: nebula.pri
#
# Author: $author$
#   Date: 11/19/2017
#
# QtCreator .pri file for nebula executable nebula
########################################################################

nebula_exe_TARGET = nebula

########################################################################
nebula_exe_INCLUDEPATH += \
$${nebula_INCLUDEPATH} \

nebula_exe_DEFINES += \
$${nebula_DEFINES} \

########################################################################
# fila
nebula_exe_HEADERS += \
$${FILA_SRC}/xos/console/mt/Main_main.hpp \

nebula_exe_SOURCES += \

#$${FILA_SRC}/xos/console/mt/Main_main.cpp \

########################################################################
# rete
nebula_exe_HEADERS += \
$${RETE_SRC}/xos/network/ethernet/actual/Address.hpp \
$${RETE_SRC}/xos/network/sockets/posix/interfaces/Addresses.hpp \
$${RETE_SRC}/xos/network/sockets/interfaces/Addresses.hpp \
$${RETE_SRC}/xos/network/os/Sockets.hpp \
$${RETE_SRC}/xos/network/apple/osx/Sockets.hpp \
$${RETE_SRC}/xos/network/posix/Sockets.hpp \
$${RETE_SRC}/xos/network/os/Socket.hpp \
$${RETE_SRC}/xos/network/apple/osx/Socket.hpp \
$${RETE_SRC}/xos/network/Socket.hpp \
$${RETE_SRC}/xos/network/os/Os.hpp \

nebula_exe_SOURCES += \
$${RETE_SRC}/xos/network/ethernet/actual/Address.cpp \
$${RETE_SRC}/xos/network/sockets/posix/interfaces/Addresses.cpp \
$${RETE_SRC}/xos/network/os/Sockets.cpp \
$${RETE_SRC}/xos/network/os/Socket.cpp \
$${RETE_SRC}/xos/network/os/Os.cpp \

########################################################################
# nebula
nebula_exe_HEADERS += \
$${NEBULA_SRC}/xos/network/sockets/stream/Connections.hpp \
$${NEBULA_SRC}/xos/app/console/nebula/daemon/Main.hpp \
$${NEBULA_SRC}/xos/app/console/nebula/daemon/MainOpt.hpp \

nebula_exe_SOURCES += \
$${NEBULA_SRC}/xos/network/sockets/stream/Connections.cpp \
$${NEBULA_SRC}/xos/app/console/nebula/daemon/Main.cpp \
$${NEBULA_SRC}/xos/app/console/nebula/daemon/MainOpt.cpp \

########################################################################
nebula_exe_LIBS += \
$${nebula_LIBS} \


