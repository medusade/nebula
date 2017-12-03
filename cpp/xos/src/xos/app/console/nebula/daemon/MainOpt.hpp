///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: MainOpt.hpp
///
/// Author: $author$
///   Date: 11/19/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_NEBULA_DAEMON_MAINOPT_HPP
#define _XOS_APP_CONSOLE_NEBULA_DAEMON_MAINOPT_HPP

#include "xos/console/getopt/MainOpt.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NEBULA_DAEMON_MAIN_START_OPT "start"
#define NEBULA_DAEMON_MAIN_START_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define NEBULA_DAEMON_MAIN_START_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_START_OPTARG ""
#define NEBULA_DAEMON_MAIN_START_OPTUSE "Start daemon"
#define NEBULA_DAEMON_MAIN_START_OPTVAL_S "s"
#define NEBULA_DAEMON_MAIN_START_OPTVAL_C 's'
#define NEBULA_DAEMON_MAIN_START_OPTION \
   {NEBULA_DAEMON_MAIN_START_OPT, \
    NEBULA_DAEMON_MAIN_START_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_START_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_START_OPTVAL_C}, \

#define NEBULA_DAEMON_MAIN_STOP_OPT "stop"
#define NEBULA_DAEMON_MAIN_STOP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define NEBULA_DAEMON_MAIN_STOP_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_STOP_OPTARG ""
#define NEBULA_DAEMON_MAIN_STOP_OPTUSE "Stop daemon"
#define NEBULA_DAEMON_MAIN_STOP_OPTVAL_S "t"
#define NEBULA_DAEMON_MAIN_STOP_OPTVAL_C 't'
#define NEBULA_DAEMON_MAIN_STOP_OPTION \
   {NEBULA_DAEMON_MAIN_STOP_OPT, \
    NEBULA_DAEMON_MAIN_STOP_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_STOP_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_STOP_OPTVAL_C}, \

#define NEBULA_DAEMON_MAIN_RESTART_OPT "restart"
#define NEBULA_DAEMON_MAIN_RESTART_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define NEBULA_DAEMON_MAIN_RESTART_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_RESTART_OPTARG ""
#define NEBULA_DAEMON_MAIN_RESTART_OPTUSE "Restart daemon"
#define NEBULA_DAEMON_MAIN_RESTART_OPTVAL_S "r"
#define NEBULA_DAEMON_MAIN_RESTART_OPTVAL_C 'r'
#define NEBULA_DAEMON_MAIN_RESTART_OPTION \
   {NEBULA_DAEMON_MAIN_RESTART_OPT, \
    NEBULA_DAEMON_MAIN_RESTART_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_RESTART_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_RESTART_OPTVAL_C}, \

#define NEBULA_DAEMON_MAIN_HOST_OPT "host"
#define NEBULA_DAEMON_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define NEBULA_DAEMON_MAIN_HOST_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_HOST_OPTARG "{name | ddd.ddd.ddd.ddd | *}"
#define NEBULA_DAEMON_MAIN_HOST_OPTUSE "Network host name or address"
#define NEBULA_DAEMON_MAIN_HOST_OPTVAL_S "h:"
#define NEBULA_DAEMON_MAIN_HOST_OPTVAL_C 'h'
#define NEBULA_DAEMON_MAIN_HOST_OPTION \
   {NEBULA_DAEMON_MAIN_HOST_OPT, \
    NEBULA_DAEMON_MAIN_HOST_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_HOST_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_HOST_OPTVAL_C}, \

#define NEBULA_DAEMON_MAIN_PORT_OPT "port"
#define NEBULA_DAEMON_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define NEBULA_DAEMON_MAIN_PORT_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_PORT_OPTARG "[1..2^16-1]"
#define NEBULA_DAEMON_MAIN_PORT_OPTUSE "Network port number"
#define NEBULA_DAEMON_MAIN_PORT_OPTVAL_S "p:"
#define NEBULA_DAEMON_MAIN_PORT_OPTVAL_C 'p'
#define NEBULA_DAEMON_MAIN_PORT_OPTION \
   {NEBULA_DAEMON_MAIN_PORT_OPT, \
    NEBULA_DAEMON_MAIN_PORT_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_PORT_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_PORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NEBULA_DAEMON_MAIN_FAMILY_OPT "family"
#define NEBULA_DAEMON_MAIN_FAMILY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define NEBULA_DAEMON_MAIN_FAMILY_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_FAMILY_OPTARG "{(4)ipv4 | (6)ipv6 | (l)local}"
#define NEBULA_DAEMON_MAIN_FAMILY_OPTUSE "Network address family"
#define NEBULA_DAEMON_MAIN_FAMILY_OPTVAL_S "a:"
#define NEBULA_DAEMON_MAIN_FAMILY_OPTVAL_C 'a'
#define NEBULA_DAEMON_MAIN_FAMILY_OPTION \
   {NEBULA_DAEMON_MAIN_FAMILY_OPT, \
    NEBULA_DAEMON_MAIN_FAMILY_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_FAMILY_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_FAMILY_OPTVAL_C}, \

#define NEBULA_DAEMON_MAIN_TRANSPORT_OPT "transport"
#define NEBULA_DAEMON_MAIN_TRANSPORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define NEBULA_DAEMON_MAIN_TRANSPORT_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_TRANSPORT_OPTARG "{(d)dgram | (s)stream | (t)tcp | (u)udp}"
#define NEBULA_DAEMON_MAIN_TRANSPORT_OPTUSE "Network transport type"
#define NEBULA_DAEMON_MAIN_TRANSPORT_OPTVAL_S "o:"
#define NEBULA_DAEMON_MAIN_TRANSPORT_OPTVAL_C 'o'
#define NEBULA_DAEMON_MAIN_TRANSPORT_OPTION \
   {NEBULA_DAEMON_MAIN_TRANSPORT_OPT, \
    NEBULA_DAEMON_MAIN_TRANSPORT_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_TRANSPORT_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_TRANSPORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NEBULA_DAEMON_MAIN_THREADS_OPT "threads"
#define NEBULA_DAEMON_MAIN_THREADS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define NEBULA_DAEMON_MAIN_THREADS_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_THREADS_OPTARG "[0..n]"
#define NEBULA_DAEMON_MAIN_THREADS_OPTUSE "Number of threads"
#define NEBULA_DAEMON_MAIN_THREADS_OPTVAL_S "n:"
#define NEBULA_DAEMON_MAIN_THREADS_OPTVAL_C 'n'
#define NEBULA_DAEMON_MAIN_THREADS_OPTION \
   {NEBULA_DAEMON_MAIN_THREADS_OPT, \
    NEBULA_DAEMON_MAIN_THREADS_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_THREADS_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_THREADS_OPTVAL_C}, \

#define NEBULA_DAEMON_MAIN_PROCESSES_OPT "processes"
#define NEBULA_DAEMON_MAIN_PROCESSES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define NEBULA_DAEMON_MAIN_PROCESSES_OPTARG_RESULT 0
#define NEBULA_DAEMON_MAIN_PROCESSES_OPTARG "[0..n]"
#define NEBULA_DAEMON_MAIN_PROCESSES_OPTUSE "Number of processes"
#define NEBULA_DAEMON_MAIN_PROCESSES_OPTVAL_S "e:"
#define NEBULA_DAEMON_MAIN_PROCESSES_OPTVAL_C 'e'
#define NEBULA_DAEMON_MAIN_PROCESSES_OPTION \
   {NEBULA_DAEMON_MAIN_PROCESSES_OPT, \
    NEBULA_DAEMON_MAIN_PROCESSES_OPTARG_REQUIRED, \
    NEBULA_DAEMON_MAIN_PROCESSES_OPTARG_RESULT, \
    NEBULA_DAEMON_MAIN_PROCESSES_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NEBULA_DAEMON_MAIN_OPTIONS_CHARS \
    NEBULA_DAEMON_MAIN_START_OPTVAL_S \
    NEBULA_DAEMON_MAIN_STOP_OPTVAL_S \
    NEBULA_DAEMON_MAIN_RESTART_OPTVAL_S \
    NEBULA_DAEMON_MAIN_HOST_OPTVAL_S \
    NEBULA_DAEMON_MAIN_PORT_OPTVAL_S \
    NEBULA_DAEMON_MAIN_FAMILY_OPTVAL_S \
    NEBULA_DAEMON_MAIN_TRANSPORT_OPTVAL_S \
    NEBULA_DAEMON_MAIN_THREADS_OPTVAL_S \
    NEBULA_DAEMON_MAIN_PROCESSES_OPTVAL_S \
    CRONO_CONSOLE_MAIN_OPTIONS_CHARS

#define NEBULA_DAEMON_MAIN_OPTIONS_OPTIONS \
    NEBULA_DAEMON_MAIN_START_OPTION \
    NEBULA_DAEMON_MAIN_STOP_OPTION \
    NEBULA_DAEMON_MAIN_RESTART_OPTION \
    NEBULA_DAEMON_MAIN_HOST_OPTION \
    NEBULA_DAEMON_MAIN_PORT_OPTION \
    NEBULA_DAEMON_MAIN_FAMILY_OPTION \
    NEBULA_DAEMON_MAIN_TRANSPORT_OPTION \
    NEBULA_DAEMON_MAIN_THREADS_OPTION \
    NEBULA_DAEMON_MAIN_PROCESSES_OPTION \
    CRONO_CONSOLE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define NEBULA_DAEMON_MAIN_ARGS 0
#define NEBULA_DAEMON_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
namespace xos {
namespace app {
namespace console {
namespace nebula {
namespace daemon {

typedef xos::console::getopt::MainOpt MainOptTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainOptT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainOptTImplements>

class _EXPORT_CLASS MainOptT: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnStartOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnStopOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnRestartOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnHostOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnPortOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnFamilyOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnTransportOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnThreadsOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int OnProcessesOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case NEBULA_DAEMON_MAIN_START_OPTVAL_C:
            err = OnStartOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case NEBULA_DAEMON_MAIN_STOP_OPTVAL_C:
            err = OnStopOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case NEBULA_DAEMON_MAIN_RESTART_OPTVAL_C:
            err = OnRestartOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        case NEBULA_DAEMON_MAIN_HOST_OPTVAL_C:
            err = OnHostOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case NEBULA_DAEMON_MAIN_PORT_OPTVAL_C:
            err = OnPortOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        case NEBULA_DAEMON_MAIN_FAMILY_OPTVAL_C:
            err = OnFamilyOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case NEBULA_DAEMON_MAIN_TRANSPORT_OPTVAL_C:
            err = OnTransportOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        case NEBULA_DAEMON_MAIN_THREADS_OPTVAL_C:
            err = OnThreadsOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case NEBULA_DAEMON_MAIN_PROCESSES_OPTVAL_C:
            err = OnProcessesOption
            (optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = Implements::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case NEBULA_DAEMON_MAIN_START_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_START_OPTARG;
            chars = NEBULA_DAEMON_MAIN_START_OPTUSE;
            break;
        case NEBULA_DAEMON_MAIN_STOP_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_STOP_OPTARG;
            chars = NEBULA_DAEMON_MAIN_STOP_OPTUSE;
            break;
        case NEBULA_DAEMON_MAIN_RESTART_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_RESTART_OPTARG;
            chars = NEBULA_DAEMON_MAIN_RESTART_OPTUSE;
            break;

        case NEBULA_DAEMON_MAIN_HOST_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_HOST_OPTARG;
            chars = NEBULA_DAEMON_MAIN_HOST_OPTUSE;
            break;
        case NEBULA_DAEMON_MAIN_PORT_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_PORT_OPTARG;
            chars = NEBULA_DAEMON_MAIN_PORT_OPTUSE;
            break;

        case NEBULA_DAEMON_MAIN_FAMILY_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_FAMILY_OPTARG;
            chars = NEBULA_DAEMON_MAIN_FAMILY_OPTUSE;
            break;
        case NEBULA_DAEMON_MAIN_TRANSPORT_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_TRANSPORT_OPTARG;
            chars = NEBULA_DAEMON_MAIN_TRANSPORT_OPTUSE;
            break;

        case NEBULA_DAEMON_MAIN_THREADS_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_THREADS_OPTARG;
            chars = NEBULA_DAEMON_MAIN_THREADS_OPTUSE;
            break;
        case NEBULA_DAEMON_MAIN_PROCESSES_OPTVAL_C:
            optarg = NEBULA_DAEMON_MAIN_PROCESSES_OPTARG;
            chars = NEBULA_DAEMON_MAIN_PROCESSES_OPTUSE;
            break;

        default:
            chars = Implements::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = NEBULA_DAEMON_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            NEBULA_DAEMON_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = NEBULA_DAEMON_MAIN_ARGS;
        static const char_t* _argv[] = {
            NEBULA_DAEMON_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainOptT<> MainOpt;

} // namespace daemon 
} // namespace nebula 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_NEBULA_DAEMON_MAINOPT_HPP 
