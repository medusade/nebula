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
///   File: Connections.hpp
///
/// Author: $author$
///   Date: 11/27/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_STREAM_CONNECTIONS_HPP
#define _XOS_NETWORK_SOCKETS_STREAM_CONNECTIONS_HPP

#include "xos/network/os/Socket.hpp"
#include "xos/mt/os/Semaphore.hpp"
#include "xos/mt/os/Mutex.hpp"
#include <queue>

namespace xos {
namespace network {
namespace sockets {
namespace stream {

typedef ImplementBase ConnectionsTImplements;
typedef Base ConnectionsTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ConnectionsT
///////////////////////////////////////////////////////////////////////
template
<typename TSocket = os::Socket,
 typename TSocketPtr = TSocket*,class TQueue = ::std::queue<TSocketPtr>,
 class TLocked = mt::os::Mutex, class TWaited = mt::os::Semaphore,
 class TImplements = ConnectionsTImplements, class TExtends = ConnectionsTExtends>

class _EXPORT_CLASS ConnectionsT: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    /// Class: Events
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Events: public ImplementBase {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual void OnClear(TSocket& accept, TSocketPtr& connection) {
            connection->Shutdown();
            connection->Close();
            delete connection;
            connection = 0;
        }
        virtual void OnCleared(TSocket& accept) {
            accept.Shutdown();
            accept.Close();
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    };

    ///////////////////////////////////////////////////////////////////////
    /// Constructor: ConnectionsT
    ///////////////////////////////////////////////////////////////////////
    ConnectionsT(Events& events, TSocket& accept, TSocketPtr connection)
    : m_events(events), m_accept(accept), m_cleared(false) {
        Queue(connection);
    }
    ConnectionsT(Events& events, TSocket& accept)
    : m_events(events), m_accept(accept), m_cleared(false) {
    }
    ConnectionsT(TSocket& accept)
    : m_events(m_thisEvents), m_accept(accept), m_cleared(false) {
    }
    virtual ~ConnectionsT() {
        Clear();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TSocketPtr Queue(TSocketPtr connection) {
        Lock lock(m_locked);

        XOS_LOG_TRACE("...queue connection...");
        m_queue.push(connection);
        m_waited.Continue();
        return connection;
    }
    virtual TSocketPtr Dequeue()  {
        TSocketPtr connection = 0;
        Wait wait(m_waited);
        Lock lock(m_locked);

        if (0 < (m_queue.size())) {
            connection = m_queue.front();
            m_queue.pop();
            XOS_LOG_TRACE("...dequeued connection...");
        } else {
            XOS_LOG_TRACE("...queue empty...");
            if ((m_cleared)) {
                m_waited.Continue();
            }
        }
        return connection;
    }
    virtual size_t Clear() {
        size_t count = 0;
        Lock lock(m_locked);

        for (; 0 < (m_queue.size()); ++count) {
            TSocketPtr connection = m_queue.front();
            m_queue.pop();
            OnClear(m_accept, connection);
        }
        m_cleared = true;
        OnCleared(m_accept);
        m_waited.Continue();
        return count;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void OnClear(TSocket& accept, TSocketPtr& connection) {
        m_events.OnClear(accept, connection);
    }
    virtual void OnCleared(TSocket& accept) {
        m_events.OnCleared(accept);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Events m_thisEvents, &m_events;
    TSocket& m_accept;
    bool m_cleared;
    TLocked m_locked;
    TWaited m_waited;
    TQueue m_queue;
};
typedef ConnectionsT<> Connections;

} // namespace stream 
} // namespace sockets 
} // namespace network 
} // namespace xos 

#endif // _XOS_NETWORK_SOCKETS_STREAM_CONNECTIONS_HPP 
