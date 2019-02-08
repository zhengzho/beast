//
// Copyright (c) 2018 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

#ifndef BOOST_BEAST_CORE_DETAIL_STRANDED_SOCKET_HPP
#define BOOST_BEAST_CORE_DETAIL_STRANDED_SOCKET_HPP

#include <boost/beast/core/detail/bind_default_executor.hpp>
#include <boost/asio/basic_stream_socket.hpp>
#include <utility>

namespace boost {
namespace beast {
namespace detail {

template<class Protocol>
class stranded_socket_base
{
protected:
    net::basic_stream_socket<Protocol> socket_;

    template<class... Args>
    explicit
    stranded_socket_base(Args&&... args)
        : socket_(std::forward<Args>(args)...)
    {
    }

    stranded_socket_base(stranded_socket_base&&) = default;
    stranded_socket_base& operator=(stranded_socket_base&&) = delete;
};

} // detail
} // beast
} // boost

#endif