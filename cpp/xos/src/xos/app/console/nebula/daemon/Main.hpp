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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 11/19/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_NEBULA_DAEMON_MAIN_HPP
#define _XOS_APP_CONSOLE_NEBULA_DEAMON_MAIN_HPP

#include "xos/app/console/nebula/daemon/MainOpt.hpp"
#include "xos/network/sockets/stream/Connections.hpp"
#include "xos/network/sockets/posix/interfaces/Addresses.hpp"
#include "xos/network/sockets/ip/v6/Endpoint.hpp"
#include "xos/network/sockets/ip/v4/Endpoint.hpp"
#include "xos/network/sockets/ip/udp/Transport.hpp"
#include "xos/network/sockets/ip/tcp/Transport.hpp"
#include "xos/network/os/Sockets.hpp"
#include "xos/console/getopt/Main.hpp"
#include "xos/mt/Thread.hpp"

namespace xos {
namespace app {
namespace console {
namespace nebula {
namespace daemon {

typedef xos::console::getopt::MainImplements MainTImplements;
typedef xos::console::getopt::Main MainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TOptImplements = MainOpt, 
 class TImplements = MainTImplements, class TExtends = MainTExtends>

class _EXPORT_CLASS MainT
: virtual public TOptImplements, 
  virtual public TImplements, public TExtends {
public:
    typedef TOptImplements OptImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef MainT Derives;
    
    typedef StringT<char_t> string_t;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT()
    : m_run(0), m_start(0), 
      m_endpoint(0), m_transport(0),
      m_host("localhost"), m_port("8080"), m_portNo(8080), 
      m_threads(0), m_processes(0),
      m_socketConnections(m_socket) {
    }
    virtual ~MainT() {
    }

protected:
    int (Derives::*m_run)(int argc, char_t** argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->m_run)) {
            err = (this->*m_run)(argc, argv, env);
        } else {
            err = this->Usage(argc, argv, env);
        }
        return err;
    }

    int (Derives::*m_start)(int argc, char_t** argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Start(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->m_start)) {
            err = (this->*m_start)(argc, argv, env);
        } else {
            err = this->DefaultStart(argc, argv, env);
        }
        return err;
    }
    virtual int SocketsStart(int argc, char_t** argv, char_t** env) {
        int err = 0;
        
        if ((m_sockets.Startup())) {
            network::Transport& tp = this->Transport(argc, argv, env);
            network::Endpoint& ep = this->Endpoint(argc, argv, env);

            network::sockets::address::Family family = AF_UNSPEC;
            network::sockets::posix::interfaces::Addresses::AddressAt addrAt = 0;
            const network::sockets::posix::interfaces::Addresses::Address* addr = 0;
            network::sockets::posix::interfaces::Addresses addrs;
            
            if ((addr = addrs.GetFirst(addrAt, family))) {
                do {
                    XOS_LOG_DEBUG("...got address family = " << addr->Family());
                } while ((addr = addrs.GetNext(addrAt, family)));
            }
            m_sockets.Cleanup();
        }
        return err;
    }
    virtual int DefaultStart(int argc, char_t** argv, char_t** env) {
        int err = this->SocketsStart(argc, argv, env);
        return err;
    }

    network::Endpoint& (Derives::*m_endpoint)(int argc, char_t** argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Endpoint& Endpoint(int argc, char_t** argv, char_t** env) {
        if ((this->m_endpoint)) {
            return (this->*m_endpoint)(argc, argv, env);
        }
        return DefaultEndpoint(argc, argv, env);
    }
    virtual network::Endpoint& SocketIpV4Endpoint(int argc, char_t** argv, char_t** env) {
        return m_socketIpV4Endpoint;
    }
    virtual network::Endpoint& SocketIpV6Endpoint(int argc, char_t** argv, char_t** env) {
        return m_socketIpV6Endpoint;
    }
    virtual network::Endpoint& DefaultEndpoint(int argc, char_t** argv, char_t** env) {
        return SocketIpV4Endpoint(argc, argv, env);
    }

    network::Transport& (Derives::*m_transport)(int argc, char_t** argv, char_t** env);
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual network::Transport& Transport(int argc, char_t** argv, char_t** env) {
        if ((this->m_endpoint)) {
            return (this->*m_transport)(argc, argv, env);
        }
        return DefaultTransport(argc, argv, env);
    }
    virtual network::Transport& SocketIpTcpTransport(int argc, char_t** argv, char_t** env) {
        return m_socketIpTcpTransport;
    }
    virtual network::Transport& SocketIpUdpTransport(int argc, char_t** argv, char_t** env) {
        return m_socketIpUdpTransport;
    }
    virtual network::Transport& DefaultTransport(int argc, char_t** argv, char_t** env) {
        return SocketIpTcpTransport(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int OnStartOption
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        m_run = &Derives::Start;
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
            m_host.Assign(optarg);
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
            m_port.Assign(optarg);
            m_portNo = m_port.ToUnsigned();
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
            m_threads = string_t(optarg).ToUnsigned();
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
            m_processes = string_t(optarg).ToUnsigned();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String m_host, m_port; unsigned m_portNo;
    unsigned m_threads, m_processes;
    network::os::Sockets m_sockets;
    network::os::Socket m_socket;
    network::sockets::stream::Connections m_socketConnections;
    network::sockets::ip::v4::Endpoint m_socketIpV4Endpoint;
    network::sockets::ip::v6::Endpoint m_socketIpV6Endpoint;
    network::sockets::ip::tcp::Transport m_socketIpTcpTransport;
    network::sockets::ip::udp::Transport m_socketIpUdpTransport;
};
typedef MainT<> Main;

} // namespace daemon 
} // namespace nebula 
} // namespace console 
} // namespace app 
} // namespace xos 

#endif // _XOS_APP_CONSOLE_NEBULA_DAEMON_MAIN_HPP 
